/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTama_o;
    QAction *actionFecha;
    QAction *actionNombre;
    QAction *actionSalir;
    QWidget *centralwidget;
    QTableView *Table_Sql;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuOrdenar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionTama_o = new QAction(MainWindow);
        actionTama_o->setObjectName(QStringLiteral("actionTama_o"));
        actionFecha = new QAction(MainWindow);
        actionFecha->setObjectName(QStringLiteral("actionFecha"));
        actionNombre = new QAction(MainWindow);
        actionNombre->setObjectName(QStringLiteral("actionNombre"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Table_Sql = new QTableView(centralwidget);
        Table_Sql->setObjectName(QStringLiteral("Table_Sql"));
        Table_Sql->setGeometry(QRect(10, 10, 781, 491));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuOrdenar = new QMenu(menuArchivo);
        menuOrdenar->setObjectName(QStringLiteral("menuOrdenar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(menuOrdenar->menuAction());
        menuArchivo->addAction(actionSalir);
        menuOrdenar->addAction(actionFecha);
        menuOrdenar->addAction(actionNombre);
        menuOrdenar->addAction(actionTama_o);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Archivos", Q_NULLPTR));
        actionTama_o->setText(QApplication::translate("MainWindow", "Tama\303\261o", Q_NULLPTR));
        actionFecha->setText(QApplication::translate("MainWindow", "Fecha", Q_NULLPTR));
        actionNombre->setText(QApplication::translate("MainWindow", "Nombre", Q_NULLPTR));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", Q_NULLPTR));
        menuOrdenar->setTitle(QApplication::translate("MainWindow", "Ordenar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
