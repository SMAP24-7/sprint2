#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QtSql>
#include <QTableWidgetItem>

#include "dbconnection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void initializeModel(QSqlRelationalTableModel *model);

    private slots:
            void on_actionSalir_triggered();
            void on_actionTama_o_triggered();
            void on_actionFecha_triggered();
            void on_actionNombre_triggered();

    private:
            Ui::MainWindow *ui;
            QSqlDatabase db_;
            QSqlRelationalTableModel *model;
            bool fecha;
            bool nombre;
            bool tamano;
};

#endif // MAINWINDOW_H
