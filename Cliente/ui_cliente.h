/********************************************************************************
** Form generated from reading UI file 'cliente.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTE_H
#define UI_CLIENTE_H

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

class Ui_Cliente
{
public:
    QAction *actionSalir;
    QAction *actionConexion_Segura;
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *Carpeta_text;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *Server_IP_text;
    QLabel *label_3;
    QLineEdit *Server_Puerto_text;
    QPushButton *Send_bnt;
    QPushButton *Open;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QLineEdit *Carpeta_text_2;
    QPushButton *Open_2;
    QPushButton *Send_bnt_2;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_7;
    QLineEdit *Server_IP_text_2;
    QLabel *label_8;
    QLineEdit *Server_Puerto_text_2;
    QWidget *formLayoutWidget_5;
    QFormLayout *formLayout_5;
    QLineEdit *user;
    QLineEdit *password;
    QPushButton *authenticationButton;
    QPushButton *RegisterButton;
    QLabel *Usuario;
    QLabel *Contrasenia;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Cliente)
    {
        if (Cliente->objectName().isEmpty())
            Cliente->setObjectName(QStringLiteral("Cliente"));
        Cliente->resize(576, 580);
        Cliente->setMinimumSize(QSize(505, 580));
        actionSalir = new QAction(Cliente);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionConexion_Segura = new QAction(Cliente);
        actionConexion_Segura->setObjectName(QStringLiteral("actionConexion_Segura"));
        actionConexion_Segura->setCheckable(true);
        centralWidget = new QWidget(Cliente);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 471, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        Carpeta_text = new QLineEdit(formLayoutWidget);
        Carpeta_text->setObjectName(QStringLiteral("Carpeta_text"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, Carpeta_text);

        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(20, 160, 221, 61));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        Server_IP_text = new QLineEdit(formLayoutWidget_2);
        Server_IP_text->setObjectName(QStringLiteral("Server_IP_text"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, Server_IP_text);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        Server_Puerto_text = new QLineEdit(formLayoutWidget_2);
        Server_Puerto_text->setObjectName(QStringLiteral("Server_Puerto_text"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Server_Puerto_text);

        Send_bnt = new QPushButton(centralWidget);
        Send_bnt->setObjectName(QStringLiteral("Send_bnt"));
        Send_bnt->setGeometry(QRect(20, 230, 91, 25));
        Open = new QPushButton(centralWidget);
        Open->setObjectName(QStringLiteral("Open"));
        Open->setGeometry(QRect(20, 110, 89, 25));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 20, 67, 17));
        QFont font;
        font.setPointSize(18);
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 270, 131, 31));
        label_5->setFont(font);
        formLayoutWidget_3 = new QWidget(centralWidget);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(20, 310, 471, 61));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(formLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        Carpeta_text_2 = new QLineEdit(formLayoutWidget_3);
        Carpeta_text_2->setObjectName(QStringLiteral("Carpeta_text_2"));

        formLayout_3->setWidget(2, QFormLayout::SpanningRole, Carpeta_text_2);

        Open_2 = new QPushButton(centralWidget);
        Open_2->setObjectName(QStringLiteral("Open_2"));
        Open_2->setGeometry(QRect(20, 370, 89, 25));
        Send_bnt_2 = new QPushButton(centralWidget);
        Send_bnt_2->setObjectName(QStringLiteral("Send_bnt_2"));
        Send_bnt_2->setGeometry(QRect(20, 480, 91, 25));
        formLayoutWidget_4 = new QWidget(centralWidget);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(20, 410, 221, 61));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_7);

        Server_IP_text_2 = new QLineEdit(formLayoutWidget_4);
        Server_IP_text_2->setObjectName(QStringLiteral("Server_IP_text_2"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, Server_IP_text_2);

        label_8 = new QLabel(formLayoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_8);

        Server_Puerto_text_2 = new QLineEdit(formLayoutWidget_4);
        Server_Puerto_text_2->setObjectName(QStringLiteral("Server_Puerto_text_2"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, Server_Puerto_text_2);

        formLayoutWidget_5 = new QWidget(centralWidget);
        formLayoutWidget_5->setObjectName(QStringLiteral("formLayoutWidget_5"));
        formLayoutWidget_5->setGeometry(QRect(280, 150, 251, 158));
        formLayout_5 = new QFormLayout(formLayoutWidget_5);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        user = new QLineEdit(formLayoutWidget_5);
        user->setObjectName(QStringLiteral("user"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, user);

        password = new QLineEdit(formLayoutWidget_5);
        password->setObjectName(QStringLiteral("password"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, password);

        authenticationButton = new QPushButton(formLayoutWidget_5);
        authenticationButton->setObjectName(QStringLiteral("authenticationButton"));

        formLayout_5->setWidget(4, QFormLayout::FieldRole, authenticationButton);

        RegisterButton = new QPushButton(formLayoutWidget_5);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));

        formLayout_5->setWidget(5, QFormLayout::FieldRole, RegisterButton);

        Usuario = new QLabel(formLayoutWidget_5);
        Usuario->setObjectName(QStringLiteral("Usuario"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, Usuario);

        Contrasenia = new QLabel(formLayoutWidget_5);
        Contrasenia->setObjectName(QStringLiteral("Contrasenia"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, Contrasenia);

        Cliente->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Cliente);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 576, 22));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        Cliente->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Cliente);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Cliente->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Cliente);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Cliente->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionConexion_Segura);
        menuArchivo->addAction(actionSalir);

        retranslateUi(Cliente);

        QMetaObject::connectSlotsByName(Cliente);
    } // setupUi

    void retranslateUi(QMainWindow *Cliente)
    {
        Cliente->setWindowTitle(QApplication::translate("Cliente", "Cliente", Q_NULLPTR));
        actionSalir->setText(QApplication::translate("Cliente", "Salir", Q_NULLPTR));
        actionConexion_Segura->setText(QApplication::translate("Cliente", "Conexion Segura", Q_NULLPTR));
        label->setText(QApplication::translate("Cliente", "Carpeta:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Cliente", "Servidor:", Q_NULLPTR));
        Server_IP_text->setText(QApplication::translate("Cliente", "127.0.0.1", Q_NULLPTR));
        label_3->setText(QApplication::translate("Cliente", "Puerto:", Q_NULLPTR));
        Server_Puerto_text->setText(QApplication::translate("Cliente", "30000", Q_NULLPTR));
        Send_bnt->setText(QApplication::translate("Cliente", "Enviar", Q_NULLPTR));
        Open->setText(QApplication::translate("Cliente", "Abrir", Q_NULLPTR));
        label_4->setText(QApplication::translate("Cliente", "Envio:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Cliente", "Recepci\303\263n:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Cliente", "Carpeta:", Q_NULLPTR));
        Carpeta_text_2->setText(QApplication::translate("Cliente", "/tmp", Q_NULLPTR));
        Open_2->setText(QApplication::translate("Cliente", "Abrir", Q_NULLPTR));
        Send_bnt_2->setText(QApplication::translate("Cliente", "Conectar", Q_NULLPTR));
        label_7->setText(QApplication::translate("Cliente", "Servidor:", Q_NULLPTR));
        Server_IP_text_2->setText(QApplication::translate("Cliente", "127.0.0.1", Q_NULLPTR));
        label_8->setText(QApplication::translate("Cliente", "Puerto:", Q_NULLPTR));
        Server_Puerto_text_2->setText(QApplication::translate("Cliente", "30000", Q_NULLPTR));
        authenticationButton->setText(QApplication::translate("Cliente", "Autenticar", Q_NULLPTR));
        RegisterButton->setText(QApplication::translate("Cliente", "Registrar", Q_NULLPTR));
        Usuario->setText(QApplication::translate("Cliente", "Usuario:", Q_NULLPTR));
        Contrasenia->setText(QApplication::translate("Cliente", "Contrase\303\261a:", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("Cliente", "Archivo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Cliente: public Ui_Cliente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTE_H
