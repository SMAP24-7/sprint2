#include "cliente.h"
#include "ui_cliente.h"

Cliente::Cliente(QWidget *parent, QStringList *list) :
    QMainWindow(parent),
    Cifrado(false),
    ui(new Ui::Cliente)
{
    ui->setupUi(this);
    ui->Send_bnt->setEnabled(false);
    ui->Server_IP_text_2->setEnabled(false);

     Setting_file = QApplication::applicationDirPath() + "/settings.ini";

    Sever_IP.clear();
    Server_port.clear();
    Server_dst_IP.clear();
    Server_dst_port.clear();
    if (list->size() > 1){
         for (QStringList::iterator it = list->begin(); it != list->end(); ++it)
            if (*it == (QString)"-ip")       put_server_ip(*++it);
            else if(*it == (QString)"-port")   put_server_port(*++it);
            else if(*it == (QString)"-ip_dst")   put_server_dst_ip(*++it);
            else if(*it == (QString)"-port_dst")   put_server_dst_port(*++it);
            else ++it;
    }
    else{
        cargar_configuracion();
        escribir_configuracion();
    }

    log((QString)"Cliente_Creado");

    auth_thread = new QThread(this);
    auth = new AuthenticationThread();

    connect(auth_thread, SIGNAL(started()), auth, SLOT(run() ) );
    connect(auth, SIGNAL(sendAuthenticationOutput(qint64)), this, SLOT(getAuthentication(qint64)) );

    auth->moveToThread(auth_thread);


    regThread = new QThread(this);
    reg = new RegisterThread();

    connect(regThread, SIGNAL(started()), reg, SLOT(run()) );
    connect(reg, SIGNAL(sendRegistrationOutput(qint64)), this, SLOT(getRegistrationOutput(qint64)) );

    reg->moveToThread(regThread);


    ui->Send_bnt->setEnabled(false);
    ui->Send_bnt_2->setEnabled(false);

}

Cliente::~Cliente()
{
    guardar_configuracion();
    delete ui;
    log((QString)"Cliente_Cerrado");
}

void Cliente::put_server_ip(QString ip)
{
    Sever_IP = ip;
}

void Cliente::put_server_port(QString port)
{
    Server_port = port;
}

void Cliente::put_server_dst_ip(QString ip)
{
    Server_dst_IP = ip;
}

void Cliente::put_server_dst_port(QString port)
{
    Server_dst_port = port;
}

void Cliente::on_Open_clicked()
{
    fileName = QFileDialog::getExistingDirectory(this, tr("Abrir Directorio"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (fileName != "") {
        ui->Carpeta_text->setText(fileName);

        QDirIterator it(fileName, QStringList() << "*", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()){
            Lista_archivos.push_back(it.next());
        }
        ui->Send_bnt->setEnabled(true);
        log((QString)"Carpeta_recepción_creada en" + fileName);
    }
    else {
        log((QString)"ERROR::No se pudo abrir la carpeta " + fileName);
        qDebug() << "No se puede abrir la carpeta";
    }
}

void Cliente::on_Send_bnt_clicked()
{
    if(autenticado){
        log((QString)"Fichero_enviado " + fileName);
            if (Sever_IP.isEmpty() && Server_port.isEmpty() )
                Pepe = new Send_Files(fileName,Lista_archivos,QHostAddress (ui->Server_IP_text->text()),ui->Server_Puerto_text->text().toInt(),Cifrado);
            else if(!Sever_IP.isEmpty() && Server_port.isEmpty())
                Pepe = new Send_Files(fileName,Lista_archivos,QHostAddress (Sever_IP),ui->Server_Puerto_text->text().toInt(),Cifrado);
            else if(Sever_IP.isEmpty() && !Server_port.isEmpty())
                Pepe = new Send_Files(fileName,Lista_archivos,QHostAddress (ui->Server_IP_text->text()),Server_port.toInt(),Cifrado);
            else
                Pepe = new Send_Files(fileName,Lista_archivos,QHostAddress (Sever_IP),Server_port.toInt(),Cifrado);
            Pepe->start();
    }
}

void Cliente::on_Open_2_clicked()
{
    QString fileName2 = QFileDialog::getExistingDirectory(this, tr("Abrir Directorio"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (fileName2 != "") {
        ui->Carpeta_text_2->setText(fileName2);
        ui->Send_bnt_2->setEnabled(true);
        log((QString)"Carpeta_recepción_creada en" + fileName2);
    }
    else {
        log((QString)"ERROR::No se pudo abrir la carpeta " + fileName2);
        qDebug() << "No se puede abrir la carpeta";
    }

}

void Cliente::on_Send_bnt_2_clicked()
{
    if(autenticado){
    ui->Send_bnt_2->setEnabled(false);

        if (Server_dst_IP.isEmpty() && Server_dst_port.isEmpty() )
            Server_ = new Server_Connection(QHostAddress(ui->Server_IP_text_2->text()),ui->Server_Puerto_text_2->text().toInt(), ui->Carpeta_text_2->text(),this);
        else if(!Server_dst_port.isEmpty() && Server_dst_port.isEmpty())
            Server_ = new Server_Connection(QHostAddress(Server_dst_port),ui->Server_Puerto_text_2->text().toInt(), ui->Carpeta_text_2->text(),this);
        else if(Server_dst_port.isEmpty() && !Server_dst_port.isEmpty())
            Server_ = new Server_Connection(QHostAddress(ui->Server_IP_text_2->text()),Server_dst_port.toInt(), ui->Carpeta_text_2->text(),this);
        else
            Server_ = new Server_Connection(QHostAddress(Server_dst_port),Server_dst_port.toInt(), ui->Carpeta_text_2->text(),this);

        Server_->start();
    }
}

void Cliente::log(QString data)
{
    QByteArray log;
    QString s = " ";
    QString h  = QTime::currentTime().toString("HH:mm");
    QString d =  QDate::currentDate().toString("dd-MM-yyyy");
    log.append("Cliente"  + s + d + s + h + s + data + '\n');
    log_file.setFileName("/var/log/Backup_log.log");
    if (log_file.open(QIODevice::Append)){
            log_file.write(log);
    }
}

void Cliente::on_actionConexion_Segura_triggered()
{
    if(Cifrado)
        Cifrado=false;
    else
        Cifrado=true;
}

void Cliente::on_authenticationButton_clicked()
{
    if( !ui->user->text().isEmpty() && !ui->password->text().isEmpty() ){
        auth->setHost(ui->Server_IP_text->text());
        auth->setUserName(ui->user->text());
        auth->setUserPassword(ui->password->text());
        auth->setPort(ui->Server_Puerto_text->text());

        qDebug() << ui->user->text() << ui->password->text();

        auth_thread->start();
    }else{
        QMessageBox::warning(0, "Introduzca usuario y contraseña", "Introduzca usuario y constraseña por favor");
    }
}

void Cliente::getAuthentication(qint64 code)
{
    if(code == AUTH_ERR){
        QMessageBox::critical(0, "FALLO EN LA AUTENTIFICACIÓN DEL USUARIO.", "Introduzca usuario y constraseña de nuevo.\nTambién puede registrar un nuevo usuario.");

    }else{
        QMessageBox::about(0,"ÉXITO","Se ha identificado al usuario con éxito!");
        autenticado = true;
        ui->Send_bnt->setEnabled(true);
        ui->Send_bnt_2->setEnabled(true);
    }

    auth_thread->quit();
    auth_thread->wait();
}

void Cliente::getRegistrationOutput(qint64 code)
{
    if(code == AUTH_ERR ){
        QMessageBox::critical(0, "ERROR EN EL REGISTRO", "El proceso de registro de usuarios ha fallado.\nPruebe de nuevo.");
    }else{
        QMessageBox::about(this, "Registro completado", "El registro del usuario se ha realizado con éxito.");
    }

    regThread->quit();
    regThread->wait();
}

void Cliente::on_RegisterButton_clicked()
{
    if( !ui->user->text().isEmpty() && !ui->password->text().isEmpty() ){
        reg->setHost(ui->Server_IP_text->text());
        reg->setName(ui->user->text());
        reg->setPassword(ui->password->text());
        reg->setPort(ui->Server_Puerto_text->text());

        regThread->start();
    }else{
        QMessageBox::warning(0, "Introduzca usuario y contraseña", "Introduzca usuario y constraseña por favor");
    }
}

void Cliente::cargar_configuracion()
{
    QSettings settings(Setting_file, QSettings::NativeFormat);
    Sever_IP = settings.value("Server_ip", "").toString();
    Server_port = settings.value("Server_port", "").toString();
    Server_dst_IP = settings.value("Server_dst_IP", "").toString();
    Server_dst_port = settings.value("Server_dst_port", "").toString();
}

void Cliente::guardar_configuracion()
{
    QSettings settings(Setting_file, QSettings::NativeFormat);
    settings.setValue("Server_ip", ui->Server_IP_text->text());
    settings.setValue("Server_port", ui->Server_Puerto_text->text());
    settings.setValue("Server_dst_IP", ui->Server_IP_text_2->text());
    settings.setValue("Server_dst_port", ui->Server_Puerto_text_2->text());
}

void Cliente::escribir_configuracion()
{
    ui->Server_IP_text->setText(Sever_IP);
    ui->Server_Puerto_text->setText(Server_port);
    ui->Server_IP_text_2->setText(Server_dst_IP);
    ui->Server_Puerto_text_2->setText(Server_dst_port);
}
