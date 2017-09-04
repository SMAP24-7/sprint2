#ifndef REGISTERTHREAD_H
#define REGISTERTHREAD_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QNetworkInterface>
#include <QProcess>
#include <QThread>
#include <QDataStream>

class RegisterThread : public QObject
{
    Q_OBJECT
public:
    explicit RegisterThread(QObject *parent = nullptr);

    void setName(QString name);
    void setHost(QString host);
    void setPort(QString port);
    void setPassword(QString password);

signals:
    void sendRegistrationOutput(qint64);

public slots:
    void run();
    void onReadyRead();
private slots:
    void disconnect();
private:
    QHostAddress m_host;
    quint16      m_port;
    QString userName, userPassword;
    QTcpSocket *socket;
};

#endif // REGISTERTHREAD_H
