#ifndef SYSTEM_H
#define SYSTEM_H

#include <QVector>
#include <QVector3D>
#include <QLineEdit>
#include <QDebug>
#include <QWidget>
#include <QLayout>
#include <QLabel>

class System
{
public:
    ~System() = default;

    virtual double f(double x, double y, double z) = 0;
    virtual double g(double x, double y, double z) = 0;
    virtual double w(double x, double y, double z) = 0;
    virtual void setData(QVector<double>& data) = 0;
    virtual QVector<QLineEdit*> UI(QWidget* widget) = 0;

    virtual double fM(double x, double y, double z, double h, QVector3D q) = 0;
    virtual double gM(double x, double y, double z, double h, QVector3D q) = 0;
    virtual double wM(double x, double y, double z, double h, QVector3D q) = 0;

};

#endif // SYSTEM_H
