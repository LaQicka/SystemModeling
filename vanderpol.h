#ifndef VANDERPOL_H
#define VANDERPOL_H

#include "system.h"
#include <QDebug>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>

class VanDerPol : public System
{
public:
    VanDerPol();

    // System interface
    double f(double x, double y, double z);
    double g(double x, double y, double z);
    double w(double x, double y, double z);
    QVector<QLineEdit *> UI(QWidget *widget);
    void setData(QVector<double>& data);


    double fM(double x, double y, double z, double h, QVector3D q);
    double gM(double x, double y, double z, double h, QVector3D q);
    double wM(double x, double y, double z, double h, QVector3D q);

private:
    double m;

};

#endif // VANDERPOL_H
