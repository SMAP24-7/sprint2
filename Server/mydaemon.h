#ifndef MYDAEMON_H
#define MYDAEMON_H

#include <QObject>
#include <QSocketNotifier>
#include <QDebug>
#include <csignal>
#include <sys/socket.h>

class MyDaemon : public QObject
{
    Q_OBJECT
public:
    explicit MyDaemon(QObject *parent = 0);
    ~MyDaemon();

    // Unix signal handlers
    static void hupSignalHandler(int unused);
    static void termSignalHandler(int unused);

public slots:
    // Qt signals handlers.
    void handleSigHup();
    void handleSigTerm();

private:
    // Están declarados, no definidos.
    static int sighupFd[2];
    static int sigtermFd[2];

    QSocketNotifier *snHup;
    QSocketNotifier *snTerm;
};

#endif // MYDAEMON_H
