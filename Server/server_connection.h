#ifndef SERVER_CONNECTION_H
#define SERVER_CONNECTION_H

#include <QMainWindow>
#include <QTcpServer>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QSsl>
#include <QSslCertificate>
#include <QSslKey>
#include <QString>
#include <QDate>
#include <QTime>
#include <QTimer>

#include "socketthread.h"
#include "dbconnection.h"

class Server_Connection : public QTcpServer
{
    Q_OBJECT

    public:
        Server_Connection(QHostAddress host, quint16 port, QString path, bool &SSL, QObject *parent = 0);
        void log(QString data);
        int get_minutos();
        int get_N_archivos();
        int get_N_paquetes();
        int get_N_bytes();

    public slots:
        void start();
        void Finished_Conection();
        void Estadistico();

    signals:
        void on_Finished_Conection();

    protected:
        void incomingConnection(qintptr socketDescriptor);

    private:
        QSqlDatabase db_;
        QHostAddress m_host;
        quint16 m_port;
        QString m_path;
        QFile log_file;
        bool Cifrado;
        QString id_user_conectado;

        //SSL

        QSslCertificate m_sslLocalCertificate;
        QSslKey m_sslPrivateKey;
        QSsl::SslProtocol m_sslProtocol;

        //Estadisticas
        int N_archivos;
        int N_paquetes;
        int N_bytes;
        int minutos;
        QTimer Interval;
};

#endif // SERVER_CONNECTION_H
