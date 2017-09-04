#ifndef CLIENTE_H
#define CLIENTE_H

#include <QApplication>
#include <QLineEdit>
#include <QMainWindow>
#include <QFile>
#include <QTcpSocket>
#include <QDebug>
#include <QNetworkInterface>
#include <QFileDialog>
#include <QProcess>
#include <QThread>
#include <QDir>
#include <QDirIterator>
#include <QStringList>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <QMessageBox>

#include "send_files.h"
#include "server_connection.h"
#include "authenticationthread.h"
#include "registerthread.h"

#define AUTH_ERR -1

namespace Ui {
class Cliente;
}

class Cliente : public QMainWindow
{
    Q_OBJECT

    public:
        explicit Cliente(QWidget *parent, QStringList *list);
        ~Cliente();

        void put_server_ip(QString ip);
        void put_server_port(QString port);
        void put_server_dst_ip(QString ip);
        void put_server_dst_port(QString port);

        void log(QString data);

    private slots:
        void on_Open_clicked();
        void on_Send_bnt_clicked();
        void on_Open_2_clicked();
        void on_Send_bnt_2_clicked();
        void on_actionConexion_Segura_triggered();

        void on_authenticationButton_clicked();

        void on_RegisterButton_clicked();

    private:
        Ui::Cliente *ui;
        QString fileName;
        QStringList Lista_archivos;
        Send_Files *Pepe;
        Server_Connection *Server_;

        QString Sever_IP;
        QString Server_port;
        QString Server_dst_IP;
        QString Server_dst_port;
        QFile log_file;

        QString Setting_file;

        void cargar_configuracion();
        void guardar_configuracion();
        void escribir_configuracion();

        //SSL
        bool Cifrado;

        QString userName;
        QString userPassword;

        AuthenticationThread *auth;
        QThread *auth_thread;

        RegisterThread *reg;
        QThread *regThread;
        bool autenticado;

    signals:
        void sendName(QString);
        void sendPassword(QString);
        void sendHost(QString);
        void sendPort(QString);

    public slots:
        void getAuthentication(qint64 code);
        void getRegistrationOutput(qint64 code);
};

#endif // CLIENTE_H
