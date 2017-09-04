#ifndef AUTHANDREGISTER_H
#define AUTHANDREGISTER_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QNetworkInterface>
#include <QProcess>
#include <QThread>
#include <QDataStream>

class AuthenticationThread : public QObject
{
    Q_OBJECT
public:
    explicit AuthenticationThread(QObject *parent = nullptr );
signals:
    void sendAuthenticationOutput(qint64);

public slots:

    void run();
    void onReadyRead();

    void setUserName(QString name);
    void setUserPassword(QString password);
    void setPort(QString port);
    void setHost(QString host);

private slots:
    void disconnect();

private:
    QHostAddress m_host;
    quint16      m_port;
    QString userName, userPassword;
    QTcpSocket *socket;
};


#endif // AUTHANDREGISTER_H
