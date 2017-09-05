#include "server.h"
#include <QApplication>
#include "mydaemon.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include "server_connection.h"

static int setup_unix_signal_handlers()
{
    struct sigaction hup, term;

    hup.sa_handler = MyDaemon::hupSignalHandler;
    sigemptyset(&hup.sa_mask);
    hup.sa_flags = 0;
    hup.sa_flags |= SA_RESTART;

    if (sigaction(SIGHUP, &hup, 0) > 0)
    return 1;

    term.sa_handler = MyDaemon::termSignalHandler;
    sigemptyset(&term.sa_mask);
    term.sa_flags |= SA_RESTART;

    if (sigaction(SIGTERM, &term, 0) > 0)
        return 2;

    return 0;
}

void init_daemon(QStringList *l){
    pid_t hijo;

    // Comprobamos si no es un demonio ya.
    if(getppid() == 1){
        return ;
    }

    hijo = fork();
    printf("%u\n", hijo);

    if(hijo < 0){
        //printf("El proceso ha fallado\n");
        // El proceso hijo ha fallado al crearse, así que no es posible seguir.
        exit(1);
    }

    if( hijo > 0){
        //printf("Cerrando el proceso padre\n");
        // Si el pid es el del padre, se cierra el programa.
        exit(0);
    }

    //printf("estamos en el proceso hijo") ;

    umask(0);

    pid_t sid;

    // Intentamos crear una sesión.
    sid = setsid();

    if(sid < 0){
        // Si no podemos cambiar la sesión, terminamos el programa.
        // Introducir información en el .log
        exit(11);
    }

    // Ahora vamos a cambiar el directorio de trabajo.
    if(chdir("/") < 0){
        // Salimos, introducir mensaje en el .log
        exit(12);
    }

    // Cerramos los descriptores estándar del demonio.
//    close(STDIN_FILENO);
//    close(STDOUT_FILENO);
//    close(STDERR_FILENO);

//    // Ahora establecemos su valor a /dev/null.
//    int fd0 = open("/dev/null", O_RDONLY);
//    int fd1 = open("/dev/null", O_WRONLY);
//    int fd2 = open("/dev/null", O_WRONLY);

    // Ahora cambiaremos el grupo y el usuario a otro.
    passwd* user = getpwnam("manu");
    group* group = getgrnam("manu");

    if(user == nullptr or group == nullptr)
        exit(13);

    seteuid(user->pw_uid);
    setgid(group->gr_gid);

    // Manejar las señales.
    //setup_unix_signal_handlers();
    //MyDaemon daemon;

}

int main(int argc, char *argv[])
{
    QStringList list;
    if (argc > 1)
    for (int q = 1 ; q < argc ; q++)
         list.push_back(argv[q]);

    //Server w(0, &list)

    if(list.contains("-d") or list.contains("--daemon")){
        init_daemon(&list);

        QCoreApplication a(argc, argv);
        bool ssl = false;
        Server_Connection w(QHostAddress("127.0.0.1"), 30000, "/home/manu/Música", ssl);
        w.start();

        return a.exec();
    }else{
        QApplication a(argc, argv);
        Server w(0, &list);
        w.show();

        return a.exec();
    }
}
