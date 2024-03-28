#include "nozeguver.h"

NozeGuver::NozeGuver()
{

}

double NozeGuver::f(double x, double y, double z)
{
    return this->a*y;
}

double NozeGuver::g(double x, double y, double z)
{
    return -x + y*z;
}

double NozeGuver::w(double x, double y, double z)
{
    return 1 - y*y;
}

void NozeGuver::setData(QVector<double> &data)
{
    this->a = data[0];
}

QVector<QLineEdit *> NozeGuver::UI(QWidget *widget)
{   
    QVBoxLayout *tlayout = new QVBoxLayout(widget);
    QHBoxLayout *aHorizontalLayout = new QHBoxLayout();
    QLabel *aLabel = new QLabel("a");
    QLineEdit *aLineEdit = new QLineEdit(widget);
    aHorizontalLayout->addWidget(aLabel);
    aHorizontalLayout->addWidget(aLineEdit);
    tlayout->addLayout(aHorizontalLayout);

    QVector<QLineEdit*> input;
    input.push_back(aLineEdit);
    return input;
}

double NozeGuver::fM(double x, double y, double z, double h, QVector3D q)
{
    return x + (h*a*y + h*q.x())/2;
}

double NozeGuver::gM(double x, double y, double z, double h, QVector3D q)
{
    return (2*y - h*x +h*q.y())/(2-h*z);
}

double NozeGuver::wM(double x, double y, double z, double h, QVector3D q)
{
    return z + h*(1-y*y)/2 + h*q.z()/2;
}

double NozeGuver::getA()
{
    return this->a;
}

double NozeGuver::setA(double a)
{
    this->a = a;
}
