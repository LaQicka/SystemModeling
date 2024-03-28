#ifndef NOZEGUVER_H
#define NOZEGUVER_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>

#include "system.h"


class NozeGuver : public System
{
public:
    NozeGuver();

    // System interface
public:
    virtual double f(double x, double y, double z);
    double g(double x, double y, double z);
    double w(double x, double y, double z);

    virtual void setData(QVector<double> &data);
    virtual QVector<QLineEdit *> UI(QWidget *widget);

    virtual double fM(double x, double y, double z, double h, QVector3D q);
    virtual double gM(double x, double y, double z, double h, QVector3D q);
    virtual double wM(double x, double y, double z, double h, QVector3D q);

    double getA();
    double setA(double a);

private:
    double a;

};

#endif // NOZEGUVER_H
