#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDataVisualization>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QVBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QString>
#include <QVector>
#include <QMap>
#include <cmath>

#include "qcustomplot.h"

#include "system.h"
#include "rosslerattractor.h"
#include "vanderpol.h"
#include "nozeguver.h"
#include "nozeguvermoded.h"
#include "lorenz.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    struct Graph3D
    {
        Q3DScatter *scatter;
        QWidget *container;
        QScatterDataProxy *dataProxy;
        QScatter3DSeries *series;
        QVBoxLayout *layout;
    };

    struct Graph3Dext
    {
        Q3DScatter *scatter;
        QWidget *container;
        QScatterDataProxy *dataProxy1;
        QScatterDataProxy *dataProxy2;
        QScatter3DSeries *series1;
        QScatter3DSeries *series2;
        QVBoxLayout *layout;
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    // modeling methods
    QVector3D standartEulerStep(QVector3D data_cur, double h, QVector3D q);
    QVector3D modedEulerStep(QVector3D data_cur, double h, QVector3D q);
    QVector3D EulerCromer(QVector3D data_cur, double h, QVector3D q);
    QVector3D CDmethod(QVector3D data_cur, double h, QVector3D q);
    QVector3D RungeKutta(QVector3D data_cur, double h, QVector3D q);

    QVector<QVector3D> modeling(QVector<double>& x, QVector<double>& y, QVector<double>& z, int n, double h, bool coordsFill);
    QVector<QVector3D> synchronization(const QVector<QVector3D>& mSystem, QString modMethod, QVector3D slave, double k, int coordN, double h);

    double min(const QVector<double> data, int start, int end);
    double max(const QVector<double> data, int start, int end);
    QVector<double> findLocalExtrema(const QVector<double>& data, int start, int end);

    double countLocalVolume(int start, int end);
    QVector3D derivatives(const QVector3D& point);
    void initSystem(QString system);


    void drawTimeGraph();
    void drawVolumeGraph(int t);
    void drawBiffrucGraph(int n, double h, double h2, double start, double end, int index, int extrema, int transientTime);
    void drawLPGraph(QVector3D delta, int step, int n, double h, int coord);
    void clearWidget(QWidget* widget);

    void clearTimeZone();
    void scaleLock();

private slots:
    void on_drawButton_clicked();

    void on_systemBox_currentTextChanged(const QString &arg1);

    void on_drawBiff_clicked();

    void on_lpDrawButton_clicked();

    void on_syncButton_clicked();

    void on_yScaleButton_clicked();

    void on_xScaleButton_clicked();

private:
    Ui::MainWindow *ui;

    Graph3D modelGraph;
    Graph3Dext syncGraph;

    QCustomPlot* bGraph;
    QCustomPlot* timeGraph;
    QCustomPlot* volumeGraph;
    QCustomPlot* lpGraph;
    QCustomPlot* syncTimeGraph;
    QCustomPlot* syncPhaseGraph;

    QVector<double> xCoords, yCoords, zCoords, hCoords, initValues;

    QWidget *editor;
    QVBoxLayout *editorLayout;

    double x = 1, y = 1, z = 1;
    QString curSystem;
    QString method;

    QMap<QString,int> methods{
        {"Standart Euler",0},
        {"Moded Euler", 1},
        {"Euler-Cromer", 2},
        {"CD",3},
        {"RungeKutta",4}
    };

    QMap<QString,int> systems{
        {"Rossler Attractor",0},
        {"VanDerPol", 1},
        {"NozeGuver", 2},
        {"NozeGuverModed", 3},
        {"Lorenz", 4}
    };

    QVector<QLineEdit*> input;

    System* modelingSystem;

    RosslerAttractor* rosslerAttractor = new RosslerAttractor();
    VanDerPol* vanDerPol = new VanDerPol();
    NozeGuver* nozeGuver = new NozeGuver();
    NozeGuverModed* nozeGuverModed = new NozeGuverModed();
    Lorenz* lorenz = new Lorenz();

    QVector<QVector<double>>a = {
        {1/5},
        {3/40, 9/40},
        {44/45, -56/15, 32/9},
        {19372/6561, -25360/2187, 64448/6561, -212/729},
        {9017/3168, -355/33, 46732/5247, 49/176, -5163/18656},
        {35/384, 0, 500/1113, 125/192, -2187/6784, 11/84}
    };

    bool yLock = false, xLock = false;

};
#endif // MAINWINDOW_H
