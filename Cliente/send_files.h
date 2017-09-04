#ifndef SEND_FILES_H
#define SEND_FILES_H

#include <QFile>
#include <QTcpSocket>
#include <QDebug>
#include <QNetworkInterface>
#include <QFileDialog>
#include <QProcess>
#include <QThread>
#include <QDir>
#include <QDirIterator>
#include <QSslSocket>

class Send_Files : public QThread
{
    Q_OBJECT

    private:
        QStringList Files;
        QString Dir_actual;
        QHostAddress m_host;
        quint16      m_port;
        QFile *m_file;
        bool Cifrado;

    public:
        Send_Files(QString root, QStringList F, QHostAddress Host, quint16 Port, bool SSL);
        void run();

    private slots:
        void disconnect();
    signals:
};

#endif // SEND_FILES_H
