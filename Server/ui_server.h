/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QAction *actionResumen;
    QAction *actionSalir;
    QAction *actionConexion_Cifrada;
    QAction *actionEstadisticas;
    QWidget *centralWidget;
    QPushButton *Conectar_btn;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Puerto_text;
    QLineEdit *IP_text;
    QPushButton *Carpeta_btn;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *path;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *Puerto_text_2;
    QLineEdit *IP_text_2;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(490, 450);
        Server->setMinimumSize(QSize(490, 450));
        actionResumen = new QAction(Server);
        actionResumen->setObjectName(QStringLiteral("actionResumen"));
        actionSalir = new QAction(Server);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionConexion_Cifrada = new QAction(Server);
        actionConexion_Cifrada->setObjectName(QStringLiteral("actionConexion_Cifrada"));
        actionConexion_Cifrada->setCheckable(true);
        actionEstadisticas = new QAction(Server);
        actionEstadisticas->setObjectName(QStringLiteral("actionEstadisticas"));
        centralWidget = new QWidget(Server);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Conectar_btn = new QPushButton(centralWidget);
        Conectar_btn->setObjectName(QStringLiteral("Conectar_btn"));
        Conectar_btn->setGeometry(QRect(40, 230, 111, 25));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 160, 211, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        Puerto_text = new QLineEdit(formLayoutWidget);
        Puerto_text->setObjectName(QStringLiteral("Puerto_text"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Puerto_text);

        IP_text = new QLineEdit(formLayoutWidget);
        IP_text->setObjectName(QStringLiteral("IP_text"));

        formLayout->setWidget(0, QFormLayout::FieldRole, IP_text);

        Carpeta_btn = new QPushButton(centralWidget);
        Carpeta_btn->setObjectName(QStringLiteral("Carpeta_btn"));
        Carpeta_btn->setGeometry(QRect(40, 110, 89, 25));
        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(40, 50, 431, 61));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        path = new QLineEdit(formLayoutWidget_2);
        path->setObjectName(QStringLiteral("path"));

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, path);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 20, 101, 21));
        QFont font;
        font.setPointSize(15);
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 280, 211, 21));
        label_5->setFont(font);
        formLayoutWidget_3 = new QWidget(centralWidget);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(40, 310, 211, 61));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(formLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        Puerto_text_2 = new QLineEdit(formLayoutWidget_3);
        Puerto_text_2->setObjectName(QStringLiteral("Puerto_text_2"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, Puerto_text_2);

        IP_text_2 = new QLineEdit(formLayoutWidget_3);
        IP_text_2->setObjectName(QStringLiteral("IP_text_2"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, IP_text_2);

        Server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Server);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 490, 22));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        Server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Server);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Server);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Server->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionResumen);
        menuArchivo->addAction(actionEstadisticas);
        menuArchivo->addAction(actionConexion_Cifrada);
        menuArchivo->addAction(actionSalir);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", Q_NULLPTR));
        actionResumen->setText(QApplication::translate("Server", "Resumen", Q_NULLPTR));
        actionSalir->setText(QApplication::translate("Server", "Salir", Q_NULLPTR));
        actionConexion_Cifrada->setText(QApplication::translate("Server", "Conexion Cifrada", Q_NULLPTR));
        actionEstadisticas->setText(QApplication::translate("Server", "Estadisticas", Q_NULLPTR));
        Conectar_btn->setText(QApplication::translate("Server", "Conectar", Q_NULLPTR));
        label->setText(QApplication::translate("Server", "IP :  ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Server", "Puerto :", Q_NULLPTR));
        Puerto_text->setText(QApplication::translate("Server", "30000", Q_NULLPTR));
        IP_text->setText(QApplication::translate("Server", "127.0.0.1", Q_NULLPTR));
        Carpeta_btn->setText(QApplication::translate("Server", "Abrir", Q_NULLPTR));
        label_3->setText(QApplication::translate("Server", "Carpeta:", Q_NULLPTR));
        path->setText(QApplication::translate("Server", "/tmp", Q_NULLPTR));
        label_4->setText(QApplication::translate("Server", "Recepci\303\263n:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Server", "Envio: Cliente Destino", Q_NULLPTR));
        label_6->setText(QApplication::translate("Server", "IP :  ", Q_NULLPTR));
        label_7->setText(QApplication::translate("Server", "Puerto :", Q_NULLPTR));
        Puerto_text_2->setText(QApplication::translate("Server", "30010", Q_NULLPTR));
        IP_text_2->setText(QApplication::translate("Server", "127.0.0.1", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("Server", "Archivo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
