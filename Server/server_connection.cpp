#include "server_connection.h"

Server_Connection::Server_Connection(QHostAddress host, quint16 port, QString path, bool &SSL, QObject *parent):
    m_host(host),
    m_port(port),
    QTcpServer(parent),
    m_sslProtocol(QSsl::TlsV1_2),
    m_path(path),
    N_bytes(0),
    N_archivos(0),
    N_paquetes(0),
    id_user_conectado("")
{
    ConecToDb(db_, "distributed_backup");

    db_.exec("CREATE TABLE 'main'.'usuarios' ("
                 "'id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "'usuario' TEXT NOT NULL UNIQUE,"
                 "'user_pass' TEXT NOT NULL"
             ");");

    db_.exec("CREATE TABLE IF NOT EXISTS archivos ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
              "nombre TEXT,"
              "tamano FLOAT,"
              "fecha_envio DATE,"
              "id_usuario TEXT"
              ");");
    Cifrado=SSL;
}

void Server_Connection::start()
{

    if(Cifrado){

        QFile certificateFile(":/certificados/sslserver.pem");

        if (certificateFile.open(QIODevice::ReadOnly))
            m_sslLocalCertificate = QSslCertificate(certificateFile.readAll(), QSsl::Pem);
        else
            qDebug()<<"Error Pem";
        certificateFile.close();

        QFile keyFile(":/certificados/sslserver.key");

        if (keyFile.open(QIODevice::ReadOnly))
            m_sslPrivateKey = QSslKey(keyFile.readAll(), QSsl::Rsa , QSsl::Pem , QSsl::PrivateKey, QByteArray());
        else
            qDebug()<<"Error key file";
        keyFile.close();
    }

    if ( this->listen(m_host, m_port) ){
        qDebug() << "Server started at " << m_host.toString() << ":" << m_port;
        log((QString)"inicializado en " + m_host.toString() + ":" + m_port);
    }
    else{
        qDebug() << "Can't start server";
        log((QString)"ERROR::El servidor no se puede iniciar");
    }

    connect(&Interval, SIGNAL(timeout()), this, SLOT(Estadistico()));
}

void Server_Connection::incomingConnection(qintptr socketDescriptor){

    qDebug()<<"Conexión entrante";
    if(!Interval.isActive()){
        Interval.start(60000);
    }

    SocketThread *thread = new SocketThread(socketDescriptor, m_path, db_,m_sslLocalCertificate ,
                                            m_sslPrivateKey, m_sslProtocol, Cifrado, N_archivos,N_paquetes,N_bytes,id_user_conectado, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();

    connect(thread,SIGNAL(onFinishRecieved()),this,SLOT(Finished_Conection()));
}

void Server_Connection::Finished_Conection(){
    qDebug()<<"Server_Connection";
    log((QString)"Servidor desconectado");
    //emit on_Finished_Conection();
    Interval.stop();
}

void Server_Connection::log(QString data)
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

void Server_Connection::Estadistico(){
    minutos++;
    qDebug()<<"Contador de minutos:"<<minutos;
}

int Server_Connection::get_minutos(){
    return minutos;
}

int Server_Connection::get_N_archivos(){
    return N_archivos;
}

int Server_Connection::get_N_paquetes(){
    return N_paquetes;
}

int Server_Connection::get_N_bytes(){
    return N_bytes;
}
