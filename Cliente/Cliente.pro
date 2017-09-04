#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T12:30:58
#
#-------------------------------------------------

QT       += core gui
QT       += network sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cliente
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        cliente.cpp \
    send_files.cpp \
    server_connection.cpp \
    socketthread.cpp \
    registerthread.cpp \
    authenticationthread.cpp

HEADERS  += cliente.h \
    send_files.h \
    server_connection.h \
    socketthread.h \
    autheticationthread.h \
    registerthread.h \
    authenticationthread.h

FORMS    += cliente.ui

unix {          # Esta configuración es específica de Linux y UNIX
    # Variables
    #
    isEmpty(PREFIX) {
        PREFIX = /usr/local
    }
    BINDIR  = $$PREFIX/bin
    DATADIR = $$PREFIX/share
    CONFDIR = /etc
    isEmpty(VARDIR) {
        VARDIR  = /var/lib/$${TARGET}
    }

    # Install
    #
    INSTALLS += target config desktop icon32 vardir

    ## Instalar ejecutable
    target.path = $$BINDIR

    ## Instalar archivo de configuración
    config.path = $$CONFDIR
    config.files += $${TARGET}.conf

    ## Instalar acceso directo en el menú del escritorio
    desktop.path = $$DATADIR/applications
    desktop.files += $${TARGET}.desktop

    ## Instalar icono de aplicación
    icon32.path = $$DATADIR/icons/hicolor/32x32/apps
    icon32.files += ./data/32x32/$${TARGET}.png

    ## Crear directorio de archivos variables
    vardir.path = $$VARDIR
    vardir.commands = true
}

RESOURCES += \
    ssl.qrc
