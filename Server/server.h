#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QNetworkInterface>
#include <QFileDialog>
#include <QHostAddress>
#include <QVector>
#include <QStringList>

#include "server_connection.h"
#include "send_files.h"
#include "mainwindow.h"
#include "estadistico.h"
#include "mydaemon.h"

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

    public:
        explicit Server(QWidget *parent, QStringList *list);
        ~Server();
        void log(QString data);
        void startServerAsDaemon();


    private slots:
        void on_Conectar_btn_clicked();
        void on_Carpeta_btn_clicked();
        void on_actionResumen_triggered();
        void on_actionConexion_Cifrada_triggered();
        void on_actionEstadisticas_triggered();

public slots:
        void on_Client_Start();

    private:
            Ui::Server *ui;
            Server_Connection *Server_;
            Send_Files *Client;

            QString Sever_IP;
            QString Server_port;
            QString Server_dst_IP;
            QString Server_dst_port;
            QFile log_file;
            bool Cifrado;
};

#endif // SERVER_H
