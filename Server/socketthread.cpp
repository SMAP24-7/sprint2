#include "socketthread.h"

SocketThread::SocketThread(qintptr socketDescriptor, QString path, QSqlDatabase &Db, QSslCertificate &sslLocalCertificate,
                           QSslKey &sslPrivateKey, QSsl::SslProtocol &sslProtocol, bool &SSL, int &n_archivos, int &n_paquetes, int &n_bytes, QString &Id_user, QObject *parent):
    QThread(parent),
    m_socketDescriptor(socketDescriptor),
    m_blockSize(0),
    m_sslLocalCertificate(sslLocalCertificate),
    m_sslPrivateKey(sslPrivateKey),
    m_sslProtocol(sslProtocol),
    m_path(path)
{
    db_=Db;
    N_archivos=n_archivos;
    N_paquetes=n_paquetes;
    N_bytes=n_bytes;
    id_user=Id_user;
    Cifrado=SSL;
}

SocketThread::~SocketThread()
{
    delete m_socket;
    delete m_sslSocket;
}

void SocketThread::run()
{

    if(Cifrado){
        m_sslSocket = new QSslSocket;
        m_sslSocket->setSocketDescriptor(m_socketDescriptor);
        m_sslSocket->setLocalCertificate(m_sslLocalCertificate);
        m_sslSocket->setPrivateKey(m_sslPrivateKey);
        m_sslSocket->setProtocol(m_sslProtocol);
        m_sslSocket->startServerEncryption();
        m_sslSocket->waitForEncrypted(-1);
        connect(m_sslSocket, SIGNAL(readyRead()),    this, SLOT(onReadyRead()),    Qt::DirectConnection);
        connect(m_sslSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()), Qt::DirectConnection);
        connect(m_sslSocket, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(onDisconnected()), Qt::DirectConnection);


    }
    else {
        m_socket = new QTcpSocket;
        m_socket->setSocketDescriptor(m_socketDescriptor);
        connect(m_socket, SIGNAL(readyRead()),    this, SLOT(onReadyRead()),    Qt::DirectConnection);
        connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()), Qt::DirectConnection);
    }

    exec();
}

void SocketThread::onReadyRead() {

    QSqlQuery query(db_);
    QFile files;
    QDataStream in,out;
    if(Cifrado){
        in.setDevice(m_sslSocket);
        out.setDevice(m_sslSocket);
        qDebug()<<"Cifrado";
    }
    else{
        in.setDevice(m_socket);
        out.setDevice(m_socket);
        qDebug()<<"No Cifrado";
    }

    in.setVersion(QDataStream::Qt_5_8);
    out.setVersion(QDataStream::Qt_5_8);

    quint64 pepe;
    in >>pepe;

    if(pepe==0){
        QString user, password;
        in >> user;
        in >> password;

        qDebug() << "Usuario y contraseña recibidos: " << user << " " << password;

        qDebug() << query.prepare("select usuario, user_pass from usuarios where usuario='"+user+"';");
        if(query.exec()){
            QSqlRecord rec = query.record();
            qDebug() << "Number of columns: " << rec.count();
            int colName = rec.indexOf("user_pass");
            query.first();

            if(query.value(colName).toString() == password ){
                qDebug() << "Usuario identificado";
                out << (qint64) 0;
            }else{
                qDebug() << "Fallo en la autentificaión.";
                out << (qint64) -1;
                return;
            }

        }else{
            qDebug() << "Fallo en la autentificación.";
            out << (qint64) -1;
            return;
        }
    }
    else if(pepe == 2){
        qDebug() << "Hello";
        QString user, password;
        in >> user;
        in >> password;

        qDebug() << "usuario y contraseña recibidos para registro: " << user << " " << password;
        qDebug() << query.prepare("insert into usuarios (usuario, user_pass) values ('"+user+"', '"+password+"');");

        if(query.exec()){
            qDebug() << "Usuario registrado correctamente.";
            out << (qint64) 0;
        }else{
            qDebug() << "Fallo al registrar nuevo usuario.";
            out << (qint64) -1;
        }
    }
    else{

        QString fileName;
        QString path;
        QByteArray byteArray;
        QDataStream stream(&byteArray, QIODevice::WriteOnly);

        in >> m_filesize;
        qDebug()<<m_filesize;

        in >> fileName;
        path = fileName;
        qDebug()<<fileName;

        log((QString)"Archivo en proceso de envío " + fileName);

        stream<<1;

        if(Cifrado){
            m_sslSocket->write(byteArray);
        }
        else {
            m_socket->write(byteArray);
        }

        if(fileName.lastIndexOf("/")!=0){
            path.truncate(fileName.lastIndexOf("/"));
            QDir dir(m_path + path);
            if (!dir.exists()){
                 dir.mkpath(m_path + path);
            }
        }
        files.setFileName(m_path + fileName);
        if(!(files.open(QIODevice::Append))){
               qDebug("File cannot be opened.");
               log((QString)"ERROR::No se puede abrir archivo " + fileName);
               exit(0);
        }

        if(m_filesize!=0){
            QByteArray read;
            if(Cifrado){
                qDebug()<<N_archivos;
                while(m_sslSocket->waitForReadyRead()) {

                    read.clear();
                    if(m_sslSocket->bytesAvailable()>(m_filesize-files.size())){
                        read = m_sslSocket->read(m_filesize-files.size());
                    }
                    else{
                        read = m_sslSocket->read(m_sslSocket->bytesAvailable());
                    }

                    //qDebug() << "Read    : " << read.size();
                    files.write(read);
                    //qDebug() << "Written : " << files.size();
                    N_paquetes++;
                    N_bytes+=read.size();
                    if(files.size()==m_filesize){
                        qDebug()<<"Cerrado";
                        files.close();
                        N_archivos++;
                        break;
                    }
                }

            }
            else{
                while(m_socket->waitForReadyRead()) {

                    read.clear();
                    if(m_socket->bytesAvailable()>(m_filesize-files.size())){
                        read = m_socket->read(m_filesize-files.size());
                    }
                    else{
                        read = m_socket->read(m_socket->bytesAvailable());
                    }

                    qDebug() << "Read    : " << read.size();
                    files.write(read);
                    qDebug() << "Written : " << files.size();

                    N_paquetes++;
                    N_bytes+=read.size();
                    if(files.size()==m_filesize){
                        m_filesize=0;
                        files.close();
                        N_archivos++;
                        break;
                    }
                }
           }
        }
        else{
            files.close();
        }

        float tmp=m_filesize/1024;
        QDate fecha;
        fileName.remove(0,1);

        query = db_.exec("INSERT INTO archivos (nombre, tamano, fecha_envio, id_usuario) "
                 "VALUES ("+QString("'%1','%2','%3','%4');" )\
                 .arg(fileName)\
                 .arg(tmp)\
                 .arg(fecha.currentDate().toString(Qt::ISODate))\
                 .arg(id_user));

        if(Cifrado){
            m_sslSocket->write(byteArray);
        }
        else {
            m_socket->write(byteArray);
        }

    }
}

void SocketThread::onDisconnected()
{
    qDebug()<<"Desconectado";
    if(Cifrado)
        m_sslSocket->close();
    else
        m_socket->close();
    db_.removeDatabase("distributed_backup");
    emit onFinishRecieved();
}

void SocketThread::log(QString data)
{
    QByteArray log;
    QString s = " ";
    QString h  = QTime::currentTime().toString("HH:mm");
    QString d =  QDate::currentDate().toString("dd-MM-yyyy");
    log.append("Server"  + s + d + s + h + s + data + '\n');
    log_file.setFileName("/var/log/Backup_log.log");
    if (log_file.open(QIODevice::Append)){
            log_file.write(log);
    }
}

void SocketThread::onError(QList<QSslError> Error){

    for (int i = 0; i < Error.size(); ++i) {
        qDebug()<<Error.at(i).errorString();

    }

}
