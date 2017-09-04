#include "authenticationthread.h"

AuthenticationThread::AuthenticationThread(QObject *parent)
    :QObject(parent)
{
}

void AuthenticationThread::run(){

    qDebug()<<"Empezar autenticación";

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

    // Indicamos que debe queremos identificaar al usuario.
    out << (quint64) 0;
    out << userName;
    out << userPassword;

    qDebug() << "Enviando nombre y contraseña" << userName << " " << userPassword;

}

void AuthenticationThread::onReadyRead()
{
    qDebug() << "Entrando en readyRead del autentificador.";

    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_8);

    qint64 outputCode;
    in >> outputCode;

    emit sendAuthenticationOutput(outputCode);

    socket->disconnectFromHost();
}

void AuthenticationThread::setUserName(QString name)
{
    qDebug() << "Recibiendo nombre del usuario: " << name;
    userName = name;
}

void AuthenticationThread::setUserPassword(QString password)
{
    qDebug() << "Recibiendo password del usuario: " << password;
    userPassword = password;
}

void AuthenticationThread::setPort(QString port)
{
    qDebug() << "Recibiendo puerto del usuario: " << port;
    m_port = port.toInt();
}

void AuthenticationThread::setHost(QString host)
{
    qDebug() << "Recibiendo host del usuario: " << host;
    m_host = QHostAddress(host);
}


void AuthenticationThread::disconnect(){
    qDebug() << "desconectado";
    if(socket->state() == QAbstractSocket::ConnectedState ){
        socket->disconnectFromHost();
        delete socket;
    }
}
