#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QTcpSocket>
#include <QNetworkInterface>
#include <QDataStream>
#include <QThread>
#include <QString>
#include <QFile>
#include <QDir>
#include <QSqlDatabase>
#include <QDate>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <QSsl>
#include <QSslCertificate>
#include <QSslKey>
#include <QDate>
#include <QTime>
#include <QSslSocket>
#include <QSslError>

class SocketThread : public QThread
{
    Q_OBJECT
public:
    SocketThread(qintptr socketDescriptor, QString path, QSqlDatabase &Db, QSslCertificate &sslLocalCertificate,
                 QSslKey &sslPrivateKey, QSsl::SslProtocol &sslProtocol , bool &SSL, int &n_archivos, int &n_paquetes,
                 int &n_bytes, QString &Id_user, QObject *parent = 0);
    ~SocketThread();

protected:
    void run() Q_DECL_OVERRIDE;
    void log(QString data);

signals:
    void onFinishRecieved();
    void error(QTcpSocket::SocketError socketError);

private slots:
    void onReadyRead();
    void onDisconnected();
    void onError(QList<QSslError> Error);

private:
    qintptr     m_socketDescriptor;
    QTcpSocket *m_socket;
    qint32      m_blockSize;
    qint64      m_filesize;
    QString     m_path;
    QSqlDatabase db_;
    bool autenticado;
    QFile log_file;
    QString id_user;

    //SSL
    QSslSocket *m_sslSocket;
    QSslCertificate m_sslLocalCertificate;
    QSslKey m_sslPrivateKey;
    QSsl::SslProtocol m_sslProtocol;
    bool Cifrado;

    //Estadisticas
    int N_archivos;
    int N_paquetes;
    int N_bytes;
};

#endif // SOCKETTHREAD_H
