#ifndef ROSSLERATTRACTOR_H
#define ROSSLERATTRACTOR_H

#include "system.h"

class RosslerAttractor : public System
{
public:

    RosslerAttractor();

private:
    double a,b,c;
    QWidget* widget;


    // System interface
public:
    double f(double x, double y, double z);
    double g(double x, double y, double z);
    double w(double x, double y, double z);
    void setData(QVector<double>& data);
    QVector<QLineEdit*> UI(QWidget* widget);

    double fM(double x, double y, double z, double h, QVector3D q);
    double gM(double x, double y, double z, double h, QVector3D q);
    double wM(double x, double y, double z, double h, QVector3D q);
};

#endif // ROSSLERATTRACTOR_H
