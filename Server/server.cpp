#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent, QStringList *list) :
    QMainWindow(parent),
    Cifrado(false),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    ui->IP_text->setEnabled(false);
    ui->Conectar_btn->setEnabled(false);
    ui->actionConexion_Cifrada->setEnabled(false);

    Sever_IP.clear();
    Server_port.clear();
    Server_dst_IP.clear();
    Server_dst_port.clear();
    if (list->size() > 1){
         for (QStringList::iterator it = list->begin(); it != list->end(); ++it)
            if (*it == (QString)"-ip")       Sever_IP = *++it;
            else if(*it == (QString)"-port")   Server_port = *++it;
            else if(*it == (QString)"-ip_dst")   Server_dst_IP = *++it;
            else if(*it == (QString)"-port_dst")   Server_dst_port = *++it;
            else ++it;
    }
    log((QString)"Server_Creado");
    ui->actionEstadisticas->setEnabled(false);

    if(!Sever_IP.isEmpty()){
        qDebug() << Sever_IP;
    }

    if(!Server_port.isEmpty()){
        qDebug() << Server_port;
    }
}

Server::~Server()
{
    delete ui;
    log((QString)"Server_Cerrado");
}

void Server::on_Conectar_btn_clicked()
{
    ui->actionEstadisticas->setEnabled(true);
        ui->actionConexion_Cifrada->setEnabled(true);
    ui->Conectar_btn->setEnabled(false);
    if (Sever_IP.isEmpty() && Server_port.isEmpty() )
        Server_ = new Server_Connection(QHostAddress(ui->IP_text->text()),ui->Puerto_text->text().toInt(), ui->path->text(), Cifrado, this);
    else if(!Sever_IP.isEmpty() && Server_port.isEmpty())
        Server_ = new Server_Connection(QHostAddress(Sever_IP),ui->Puerto_text->text().toInt(), ui->path->text(), Cifrado,this);
    else if(Sever_IP.isEmpty() && !Server_port.isEmpty())
        Server_ = new Server_Connection(QHostAddress(ui->IP_text->text()),Server_port.toInt(), ui->path->text(), Cifrado,this);
    else
        Server_ = new Server_Connection(QHostAddress(Sever_IP),Server_port.toInt(), ui->path->text(), Cifrado,this);

    Server_->start();
    connect(Server_,SIGNAL(on_Finished_Conection()),this,SLOT(on_Client_Start()));
}

void Server::on_Carpeta_btn_clicked()
{

    QString fileName = QFileDialog::getExistingDirectory(this, tr("Abrir Directorio"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (fileName != "") {
        ui->path->setText(fileName);
        ui->Conectar_btn->setEnabled(true);
        log((QString)"Carpeta_temporal_envio creada en " + fileName);
    }
    else {
        qDebug() << "No se puede abrir la carpeta";
        log((QString)"ERROR::Carpeta_temporal_envio no se puede abrir en " + fileName);
    }

}

void Server::on_Client_Start(){

    ui->actionEstadisticas->setEnabled(true);
    QStringList Lista_archivos;
    QDirIterator it(ui->path->text(), QStringList() << "*", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        Lista_archivos.push_back(it.next());
    }

    if (Server_dst_IP.isEmpty() && Server_dst_port.isEmpty() )
        Client = new Send_Files(ui->path->text(),Lista_archivos,QHostAddress(ui->IP_text_2->text()),ui->Puerto_text_2->text().toInt());
    else if(!Server_dst_port.isEmpty() && Server_dst_port.isEmpty())
        Client = new Send_Files(ui->path->text(),Lista_archivos,QHostAddress(Server_dst_IP),ui->Puerto_text_2->text().toInt());
    else if(Server_dst_port.isEmpty() && !Server_dst_port.isEmpty())
        Client = new Send_Files(ui->path->text(),Lista_archivos,QHostAddress(ui->IP_text_2->text()),Server_dst_port.toInt());
    else
        Client = new Send_Files(ui->path->text(),Lista_archivos,QHostAddress(Sever_IP),Server_dst_port.toInt());

    Client->start();
}

void Server::log(QString data)
{
    QByteArray log;
    QString s = " ";
    QString h  = QTime::currentTime().toString("HH:mm");
    QString d =  QDate::currentDate().toString("dd-MM-yyyy");
    log.append("Server"  + s + d + s + h + s + data + '\n');
    log_file.setFileName("/var/log/Backup_log.log");
    if (log_file.open(QIODevice::Append)){
            log_file.write(log);
    }
}

void Server::on_actionResumen_triggered()
{

    MainWindow *pepe = new MainWindow(this);
    pepe->setWindowModality(Qt::ApplicationModal);
    pepe->show();

}

void Server::on_actionConexion_Cifrada_triggered()
{
        if(Cifrado)
            Cifrado=false;
        else
            Cifrado=true;

        if(Server_!=NULL){

            if (Sever_IP.isEmpty() && Server_port.isEmpty() )
                Server_ = new Server_Connection(QHostAddress(ui->IP_text->text()),ui->Puerto_text->text().toInt()+1, ui->path->text(), Cifrado, this);
            else if(!Sever_IP.isEmpty() && Server_port.isEmpty())
                Server_ = new Server_Connection(QHostAddress(Sever_IP),ui->Puerto_text->text().toInt()+1, ui->path->text(), Cifrado,this);
            else if(Sever_IP.isEmpty() && !Server_port.isEmpty())
                Server_ = new Server_Connection(QHostAddress(ui->IP_text->text()),Server_port.toInt()+1, ui->path->text(), Cifrado,this);
            else
                Server_ = new Server_Connection(QHostAddress(Sever_IP),Server_port.toInt()+1, ui->path->text(), Cifrado,this);

            Server_->start();
            connect(Server_,SIGNAL(on_Finished_Conection()),this,SLOT(on_Client_Start()));
        }
}

void Server::on_actionEstadisticas_triggered()
{
    QVector<int> tmp;
    tmp.push_back(Server_->get_minutos());
    tmp.push_back(Server_->get_N_archivos());
    tmp.push_back(Server_->get_N_paquetes());
    tmp.push_back(Server_->get_N_bytes());

    Estadistico *pepe2 = new Estadistico(this);
    pepe2->setWindowModality(Qt::ApplicationModal);
    pepe2->get_data(tmp);
    pepe2->show();
}

void Server::startServerAsDaemon()
{
    this->on_Conectar_btn_clicked();
}
