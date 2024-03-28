#ifndef NOZEGUVERMODED_H
#define NOZEGUVERMODED_H

#include "nozeguver.h"

class NozeGuverModed : public NozeGuver
{
public:
    NozeGuverModed();

private:

    double c;

    // System interface
public:
    double f(double x, double y, double z);
    void setData(QVector<double> &data);
    QVector<QLineEdit *> UI(QWidget *widget);
    double fM(double x, double y, double z, double h, QVector3D q);
};

#endif // NOZEGUVERMODED_H
