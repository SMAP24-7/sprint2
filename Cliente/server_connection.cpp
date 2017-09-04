#include "server_connection.h"

Server_Connection::Server_Connection(QHostAddress host, quint16 port, QString path, QObject *parent):
    m_host(host),
    m_port(port),
    QTcpServer(parent),
    m_path(path)
{}

void Server_Connection::start()
{
    if ( this->listen(m_host, m_port) ){
        qDebug() << "Server started at " << m_host.toString() << ":" << m_port;
        log((QString)"Cliente iniciado en " + m_host.toString() + ":" + m_port);
    }
    else{
        qDebug() << "Can't start server";
        log((QString)"ERROR:No se puede conectar al servidor");
    }
}

void Server_Connection::incomingConnection(qintptr socketDescriptor){

    SocketThread *thread = new SocketThread(socketDescriptor, m_path, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();

}

void Server_Connection::log(QString data)
{
    QByteArray log;
    QString s = " ";
    QString h  = QTime::currentTime().toString("HH:mm");
    QString d =  QDate::currentDate().toString("dd-MM-yyyy");
    log.append("Cliente"  + s + d + s + h + s + data + '\n');
    log_file.setFileName("/var/log/Backup_log.log");
    if (log_file.open(QIODevice::Append)){
            log_file.write(log);
    }
}
