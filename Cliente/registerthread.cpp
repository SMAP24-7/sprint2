#include "registerthread.h"

RegisterThread::RegisterThread(QObject *parent) : QObject(parent)
{

}

void RegisterThread::setName(QString name)
{
    qDebug() << "Guardando username";
    userName = name;

}

void RegisterThread::setHost(QString host)
{
    qDebug() << "host recibido";
    m_host = QHostAddress(host);

}

void RegisterThread::setPort(QString port)
{
   qDebug() << "puerto recibido";
   m_port = port.toInt();
}

void RegisterThread::setPassword(QString password)
{
    qDebug() << "Guardando contraseña";
    userPassword = password;
}

void RegisterThread::run()
{
    socket = new QTcpSocket();
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(socket, SIGNAL(readyRead()),    this, SLOT(onReadyRead()),    Qt::DirectConnection);

    socket->connectToHost(m_host, m_port);
    socket->waitForConnected();

    if (socket->state() != QAbstractSocket::ConnectedState) {
            qDebug() << "Socket no conectado";
            delete socket;
            return;
     }

    // Le enviaremos la información sobre el usuario y contraseña al servidor primero.
    QDataStream out(socket);
    out.setVersion(QDataStream::Qt_5_8);

    // Indicamos que debe queremos identificar al usuario.
    out << (quint64) 2;
    out << userName;
    out << userPassword;

    qDebug() << "Enviando nombre y contraseña" << userName << " " << userPassword;

}

void RegisterThread::onReadyRead()
{
    qDebug() << "Entrando en el readyRead del registrador";


    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_8);

    qint64 outputCode;
    in >> outputCode;

    qDebug() << outputCode;

    emit sendRegistrationOutput(outputCode);

    socket->disconnectFromHost();

}

void RegisterThread::disconnect()
{
    qDebug() << "desconectado";
    if(socket->state() == QAbstractSocket::ConnectedState ){
        socket->disconnectFromHost();
        delete socket;
    }
}
