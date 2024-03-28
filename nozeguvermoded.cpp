#include "nozeguvermoded.h"

NozeGuverModed::NozeGuverModed()
{

}





double NozeGuverModed::f(double x, double y, double z)
{
    return -c*x+this->getA()*y;
}

void NozeGuverModed::setData(QVector<double> &data)
{
    this->setA(data[0]);
    c = data[1];
}

QVector<QLineEdit *> NozeGuverModed::UI(QWidget *widget)
{
    QVBoxLayout *tlayout = new QVBoxLayout(widget);
    QHBoxLayout *aHorizontalLayout = new QHBoxLayout();
    QHBoxLayout *cHorizontalLayout = new QHBoxLayout();
    QLabel *aLabel = new QLabel("a");
    QLineEdit *aLineEdit = new QLineEdit(widget);
    QLabel *cLabel = new QLabel("c");
    QLineEdit *cLineEdit = new QLineEdit(widget);

    aHorizontalLayout->addWidget(aLabel);
    aHorizontalLayout->addWidget(aLineEdit);
    cHorizontalLayout->addWidget(cLabel);
    cHorizontalLayout->addWidget(cLineEdit);

    tlayout->addLayout(aHorizontalLayout);
    tlayout->addLayout(cHorizontalLayout);

    QVector<QLineEdit*> input;
    input.push_back(aLineEdit);
    input.push_back(cLineEdit);
    return input;
}

double NozeGuverModed::fM(double x, double y, double z, double h, QVector3D q)
{
    double a = this->getA();
    return (2*x + h*a*y + h*q.x())/(z+h*c);
}
