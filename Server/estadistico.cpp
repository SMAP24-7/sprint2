#include "estadistico.h"
#include "ui_estadistico.h"

Estadistico::Estadistico(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estadistico)
{
    ui->setupUi(this);
}

Estadistico::~Estadistico()
{
    delete ui;
}

void Estadistico::get_data(QVector<int> tmp){


    if(tmp[0]==0){
        ui->Archivos->setText(QString(tmp[1]));
        ui->paquetes->setText(QString(tmp[2]));
        ui->bytes->setText(QString(tmp[3]));
    }
    else{
        ui->Archivos->setText(QString(tmp[1]/tmp[0]));
        ui->paquetes->setText(QString(tmp[2]/tmp[0]));
        ui->bytes->setText(QString(tmp[3]/tmp[0]));
    }
}
