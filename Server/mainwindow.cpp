#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    fecha(true),
    nombre(true),
    tamano(true),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ConecToDb(db_, "distributed_backup");
    model = new QSqlRelationalTableModel(this,db_);
    initializeModel(model);
    ui->Table_Sql->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeModel(QSqlRelationalTableModel *model)
{
    model->setTable("archivos");

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tamaño"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fecha Envío"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Usuario"));

    model->select();
}

void MainWindow::on_actionSalir_triggered()
{
    this->close();
}

void MainWindow::on_actionTama_o_triggered()
{
    if(tamano){
        model->setSort(2,Qt::AscendingOrder);
        tamano=false;
    }
    else{
        model->setSort(2,Qt::DescendingOrder);
        tamano=true;
    }
    model->select();
}

void MainWindow::on_actionFecha_triggered()
{
    if(fecha){
        model->setSort(3,Qt::AscendingOrder);
        fecha=false;
    }
    else{
        model->setSort(3,Qt::DescendingOrder);
        fecha=true;
    }
    model->select();
}

void MainWindow::on_actionNombre_triggered()
{
    if(nombre){
        model->setSort(1,Qt::AscendingOrder);
        nombre=false;
    }
    else{
        model->setSort(1,Qt::DescendingOrder);
        nombre=true;
    }
    model->select();
}
