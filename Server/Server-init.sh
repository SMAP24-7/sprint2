#!/bin/bash

# Script para ejecutar el servicio cuando se inicie el sistema.

# Dentro del archivo del proyecto, Server.pro, se introducirán las instruccciones oportunas para que el archivo se copie
# dentro del directorio /etc/init.d/

# Salir inmediatamente si algún comando falla.
set -e

. /lib/lsb/init-functions

NAME=Server
PIDFILE=/var/run/$NAME.pid
DAEMON=/usr/local/bin/$NAME
DAEMON_OPTS="--daemon"

# Si el demonio no exite, salimos.
test -x $DAEMON || exit 5

start(){
    log_daemon_msg "Iniciando $DAEMON."
    start_daemon -p $PIDFILE -- $DAEMON $DAEMON_OPTS
    log_end_msg $?
}

stop(){
    log_daemon_msg "Parando el proceso $DAEMON"
    killproc -p $PIDFILE
    log_end_msg $?
}


case $1 in
    start)
        start
        ;;
    stop)
        stop
        ;;
    status)
        if [ -e $PIDFILE ]; then
            status_of_proc -p $PIDFILE $DAEMON "$NAME process"
        else
            log_failure_msg "$NAME process is not running"
            log_end_msg 0
        fi
        ;;
    restart)
        start
        stop
        ;;
    *)
        echo "Uso: $0 {start|stop|status|restart}"
        exit 2
        ;;
esac
