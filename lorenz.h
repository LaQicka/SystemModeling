#ifndef LORENZ_H
#define LORENZ_H

#include "system.h"

class Lorenz : public System
{
public:
    Lorenz();

    // System interface
public:
    double f(double x, double y, double z);
    double g(double x, double y, double z);
    double w(double x, double y, double z);
    void setData(QVector<double> &data);
    QVector<QLineEdit *> UI(QWidget *widget);
    double fM(double x, double y, double z, double h, QVector3D q);
    double gM(double x, double y, double z, double h, QVector3D q);
    double wM(double x, double y, double z, double h, QVector3D q);

private:
    double p,o,b;
};

#endif // LORENZ_H
