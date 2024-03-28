#include "rosslerattractor.h"

RosslerAttractor::RosslerAttractor()
{

}

double RosslerAttractor::f(double x, double y, double z)
{
    return -y-z;
}

double RosslerAttractor::g(double x, double y, double z)
{
    return x+a*y;
}

double RosslerAttractor::w(double x, double y, double z)
{
    return b+z*(x-c);
}

void RosslerAttractor::setData(QVector<double>& data)
{
    this->a = data[0];
    this->b = data[1];
    this->c = data[2];
}

QVector<QLineEdit*> RosslerAttractor::UI(QWidget* widget)
{
    QVBoxLayout *tlayout = new QVBoxLayout(widget);
    QHBoxLayout *aHorizontalLayout = new QHBoxLayout();
    QHBoxLayout *bHorizontalLayout = new QHBoxLayout();
    QHBoxLayout *cHorizontalLayout = new QHBoxLayout();
    QLabel *aLabel = new QLabel("a");
    QLabel *bLabel = new QLabel("b");
    QLabel *cLabel = new QLabel("c");
    QLineEdit *aLineEdit = new QLineEdit(widget);
    QLineEdit *bLineEdit = new QLineEdit(widget);
    QLineEdit *cLineEdit = new QLineEdit(widget);
    aHorizontalLayout->addWidget(aLabel);
    aHorizontalLayout->addWidget(aLineEdit);
    bHorizontalLayout->addWidget(bLabel);
    bHorizontalLayout->addWidget(bLineEdit);
    cHorizontalLayout->addWidget(cLabel);
    cHorizontalLayout->addWidget(cLineEdit);
    tlayout->addLayout(aHorizontalLayout);
    tlayout->addLayout(bHorizontalLayout);
    tlayout->addLayout(cHorizontalLayout);
    widget->setLayout(tlayout);
    QVector<QLineEdit*> input;
    input.push_back(aLineEdit);
    input.push_back(bLineEdit);
    input.push_back(cLineEdit);
    return input;
}

double RosslerAttractor::fM(double x, double y, double z, double h, QVector3D q)
{
    return x+(h/2)*(-y-z+q.x());
}

double RosslerAttractor::gM(double x, double y, double z, double h, QVector3D q)
{
    return (2*y+x*h+h*q.y())/(2-a*h);
}

double RosslerAttractor::wM(double x, double y, double z, double h, QVector3D q)
{
    return (2*z + h*b + h*q.z())/(2 - h*(x-c));
}
