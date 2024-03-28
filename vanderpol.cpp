#include "vanderpol.h"

VanDerPol::VanDerPol()
{

}

double VanDerPol::f(double x, double y, double z)
{
    return y;
}

double VanDerPol::g(double x, double y, double z)
{
    return m*(1-x*x)*y - x;
}

double VanDerPol::w(double x, double y, double z)
{
    return 0;
}

QVector<QLineEdit *> VanDerPol::UI(QWidget *widget)
{
    QVBoxLayout *tlayout = new QVBoxLayout(widget);
    QHBoxLayout *mHorizontalLayout = new QHBoxLayout();
    QLabel *mLabel = new QLabel("m");
    QLineEdit *mLineEdit = new QLineEdit(widget);
    mHorizontalLayout->addWidget(mLabel);
    mHorizontalLayout->addWidget(mLineEdit);
    tlayout->addLayout(mHorizontalLayout);

    QVector<QLineEdit*> input;
    input.push_back(mLineEdit);
    return input;
}

void VanDerPol::setData(QVector<double>& data)
{
    this->m = data[0];
}

double VanDerPol::fM(double x, double y, double z, double h, QVector3D q)
{
    return x + h/2*f(x,y,z) + h/2*q.x();
}

double VanDerPol::gM(double x, double y, double z, double h, QVector3D q)
{
    return (2*y - x*h + h*q.y())/(2 - m*h*(1-x*x));
}

double VanDerPol::wM(double x, double y, double z, double h, QVector3D q)
{
    return 0;
}
