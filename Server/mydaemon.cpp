#include "mydaemon.h"
#include <unistd.h>


int MyDaemon::sighupFd[2];
int MyDaemon::sigtermFd[2];

MyDaemon::MyDaemon(QObject *parent) : QObject(parent)
{

    if(socketpair(AF_UNIX, SOCK_STREAM, 0,sighupFd)){
        qFatal("Couldn't create HUP socketpair");
    }
    if(socketpair(AF_UNIX, SOCK_STREAM, 0, sigtermFd)){
        qFatal("Couldn't create TERM socketpair");
    }

    snHup = new QSocketNotifier(sighupFd[1], QSocketNotifier::Read, this);
    connect(snHup, SIGNAL(activated(int)), this, SLOT(handleSigHup()) );
    snTerm = new QSocketNotifier(sigtermFd[1], QSocketNotifier::Read, this);
    connect(snTerm, SIGNAL(activated(int)), this, SLOT(handleSigTerm()) );

}

MyDaemon::~MyDaemon()
{

}

void MyDaemon::hupSignalHandler(int unused)
{
    char a = 1;
    ::write(sighupFd[0], &a, sizeof(a));

}

void MyDaemon::termSignalHandler(int unused)
{
    char a = 1;
    ::write(sigtermFd[0], &a, sizeof(a));

}

void MyDaemon::handleSigHup()
{
    snHup->setEnabled(false);
    char tmp;
    ::read(sighupFd[1], &tmp, sizeof(tmp));

    // Aquí se hacen cosas.
    qDebug() << "Sighup bye";
    exit(0);

    snHup->setEnabled(true);


}

void MyDaemon::handleSigTerm()
{
    snTerm->setEnabled(false);

    char tmp;
    ::read(sigtermFd[1], &tmp, sizeof(tmp));

    // Hacemos cosas.
    qDebug() << "Bye";
    exit(0);

    snTerm->setEnabled(true);
}

