#include "cliente.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QStringList list;
    if (argc > 1)
    for (int q = 1 ; q < argc ; q++)
         list.push_back(argv[q]);
    QApplication a(argc, argv);

    Cliente w(0, & list);
    w.show();

    return a.exec();
}
