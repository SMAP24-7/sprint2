#include "send_files.h"

Send_Files::Send_Files(QString root, QStringList F, QHostAddress Host, quint16 Port, bool SSL):
Files(F),
Dir_actual(root),
m_port(Port),
m_host(Host),
Cifrado(SSL)
{
    qDebug()<<"objeto creado";
}

void Send_Files::disconnect()
{
    qDebug() << "disconnected!";
}

void Send_Files::run(){

    qDebug()<<"Empezar envio";
    QTcpSocket *socket;
    QSslSocket *sslSocket;

    if(Cifrado){
        sslSocket = new QSslSocket;
        sslSocket->addCaCertificates(":/ssl/sslserver.pem");
        sslSocket->connectToHostEncrypted(m_host.toString(),m_port+1);
        sslSocket->waitForConnected(-1);
        sslSocket->startClientEncryption();
        sslSocket->waitForEncrypted(-1);

        connect(sslSocket, SIGNAL(disconnected()), sslSocket, SLOT(deleteLater()));
        connect(sslSocket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    }
    else {
        socket = new QTcpSocket;
        socket->connectToHost(m_host, m_port);
        socket->waitForConnected(-1);

        connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    }

    if(Cifrado){
        if (sslSocket->state() != QAbstractSocket::ConnectedState) {
                qDebug() << "Socket no conectado";
                delete sslSocket;
                return;
        }
        qDebug()<<sslSocket->state();
    }

    else{
        if (socket->state() != QAbstractSocket::ConnectedState) {
                qDebug() << "Socket no conectado";
                delete socket;
                return;
         }
    }

    qDebug()<<"hola";

    QListIterator<QString> itr (Files);
        while (itr.hasNext()) {
            QString current = itr.next();

            m_file = new QFile(current);
            if(!(m_file->open(QIODevice::ReadOnly))){
                   qDebug("Archivo no abierto");
                   exit(0);
            }

            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_5_8);

            //Tipo conexion
            out << (quint64)1;

            //Tamaño archivo
            out << (quint64)(m_file->size());

            //Nombre archivo
            current.remove(0,Dir_actual.size());
            out << current;
            qDebug()<< current;

            qDebug()<<(quint64)(m_file->size());
            qint64 x = 0;
            while (x < block.size()) {
                if(Cifrado){
                    qint64 y = sslSocket->write(block);
                    x += y;
                    sslSocket->waitForBytesWritten();
                }

                else{
                    qint64 y = socket->write(block);
                    x += y;
                    socket->waitForBytesWritten();
                }
            }
            if(Cifrado){
                sslSocket->waitForReadyRead(-1);
                //sslSocket->flush();
                qDebug()<<"1";
            }
            else{
                socket->waitForReadyRead(-1);
                socket->flush();
                qDebug()<<"1";
            }

            QByteArray read;
            while(1)
            {
                read.clear();
                read = m_file->read(32768*8);
                qDebug() << "Read : " << read.size();
                if(read.size()==0)
                    break;

                if(Cifrado){
                    qDebug() << "Written : " << sslSocket->write(read);
                    sslSocket->waitForBytesWritten(-1);
                    qDebug()<<sslSocket->encryptedBytesToWrite();
                }
                else {
                    qDebug() << "Written : " << socket->write(read);
                    socket->waitForBytesWritten(-1);
                }
                read.clear();
            }
            m_file->close();
            delete m_file;

            if(Cifrado){
                sslSocket->waitForReadyRead(-1);
                //sslSocket->flush();
                qDebug()<<"2";
            }
            else{
                socket->waitForReadyRead(-1);
                socket->flush();
                qDebug()<<"2";
            }
        }

        if(Cifrado){
            sslSocket->disconnectFromHost();
            sslSocket->waitForDisconnected(-1);
            qDebug()<<sslSocket->state();
        }
        else
            socket->disconnectFromHost();
}
