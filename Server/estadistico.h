#ifndef ESTADISTICO_H
#define ESTADISTICO_H

#include <QMainWindow>
#include <QVector>
#include <QString>

namespace Ui {
class Estadistico;
}

class Estadistico : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistico(QWidget *parent = 0);
    ~Estadistico();
    void get_data(QVector<int> tmp);

private:
    Ui::Estadistico *ui;
};

#endif // ESTADISTICO_H
