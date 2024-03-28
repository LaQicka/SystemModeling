#include "lorenz.h"

Lorenz::Lorenz()
{

}


double Lorenz::f(double x, double y, double z)
{
    return o*(y-x);
}

double Lorenz::g(double x, double y, double z)
{
    return x*(p-z)-y;
}

double Lorenz::w(double x, double y, double z)
{
    return x*y - b*z;
}

void Lorenz::setData(QVector<double> &data)
{
    this->p = data[0];
    this->o = data[1];
    this->b = data[2];
}

QVector<QLineEdit *> Lorenz::UI(QWidget *widget)
{
    QVBoxLayout *tlayout = new QVBoxLayout(widget);
    QHBoxLayout *pHorizontalLayout = new QHBoxLayout();
    QHBoxLayout *oHorizontalLayout = new QHBoxLayout();
    QHBoxLayout *bHorizontalLayout = new QHBoxLayout();
    QLabel *pLabel = new QLabel("p");
    QLabel *oLabel = new QLabel("o");
    QLabel *bLabel = new QLabel("b");
    QLineEdit *pLineEdit = new QLineEdit(widget);
    QLineEdit *oLineEdit = new QLineEdit(widget);
    QLineEdit *bLineEdit = new QLineEdit(widget);
    pHorizontalLayout->addWidget(pLabel);
    pHorizontalLayout->addWidget(pLineEdit);
    oHorizontalLayout->addWidget(oLabel);
    oHorizontalLayout->addWidget(oLineEdit);
    bHorizontalLayout->addWidget(bLabel);
    bHorizontalLayout->addWidget(bLineEdit);
    tlayout->addLayout(pHorizontalLayout);
    tlayout->addLayout(oHorizontalLayout);
    tlayout->addLayout(bHorizontalLayout);
    widget->setLayout(tlayout);
    QVector<QLineEdit*> input;
    input.push_back(pLineEdit);
    input.push_back(oLineEdit);
    input.push_back(bLineEdit);
    return input;
}

double Lorenz::fM(double x, double y, double z, double h, QVector3D q)
{
    return (2*x + h*o*y + h*q.x())/(2 + h*o);
}

double Lorenz::gM(double x, double y, double z, double h, QVector3D q)
{
    return (2*y + h*x*(p-z) +h*q.y())/(2+h);
}

double Lorenz::wM(double x, double y, double z, double h, QVector3D q)
{
    return (2*z + h*x*y + h*q.z())/(2 + h*b);
}
