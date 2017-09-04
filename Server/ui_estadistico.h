/********************************************************************************
** Form generated from reading UI file 'estadistico.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTADISTICO_H
#define UI_ESTADISTICO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Estadistico
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *Archivos;
    QLineEdit *paquetes;
    QLineEdit *bytes;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Estadistico)
    {
        if (Estadistico->objectName().isEmpty())
            Estadistico->setObjectName(QStringLiteral("Estadistico"));
        Estadistico->resize(395, 230);
        centralwidget = new QWidget(Estadistico);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 141, 41));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 60, 321, 95));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        Archivos = new QLineEdit(formLayoutWidget);
        Archivos->setObjectName(QStringLiteral("Archivos"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Archivos);

        paquetes = new QLineEdit(formLayoutWidget);
        paquetes->setObjectName(QStringLiteral("paquetes"));

        formLayout->setWidget(2, QFormLayout::FieldRole, paquetes);

        bytes = new QLineEdit(formLayoutWidget);
        bytes->setObjectName(QStringLiteral("bytes"));

        formLayout->setWidget(3, QFormLayout::FieldRole, bytes);

        Estadistico->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Estadistico);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Estadistico->setStatusBar(statusbar);

        retranslateUi(Estadistico);

        QMetaObject::connectSlotsByName(Estadistico);
    } // setupUi

    void retranslateUi(QMainWindow *Estadistico)
    {
        Estadistico->setWindowTitle(QApplication::translate("Estadistico", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("Estadistico", "Estadisticas:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Estadistico", "Numero paquetes/min:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Estadistico", "Numero bytes/min:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Estadistico", "Numero archivos/min:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Estadistico: public Ui_Estadistico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTADISTICO_H
