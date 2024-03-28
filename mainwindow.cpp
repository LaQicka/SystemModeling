#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    {
        modelGraph.scatter = new Q3DScatter();
        modelGraph.scatter->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
        modelGraph.container = QWidget::createWindowContainer(modelGraph.scatter);
        modelGraph.dataProxy = new QScatterDataProxy();
        modelGraph.series = new QScatter3DSeries(modelGraph.dataProxy);
        modelGraph.scatter->addSeries(modelGraph.series);
        modelGraph.layout = new QVBoxLayout(ui->graphWidget);
        ui->graphWidget->setLayout(modelGraph.layout);
        modelGraph.layout->addWidget(modelGraph.container);
    }

    {
        syncGraph.scatter = new Q3DScatter();
        syncGraph.scatter->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
        syncGraph.container = QWidget::createWindowContainer(syncGraph.scatter);
        syncGraph.dataProxy1 = new QScatterDataProxy();
        syncGraph.series1 = new QScatter3DSeries(syncGraph.dataProxy1);
        syncGraph.dataProxy2 = new QScatterDataProxy();
        syncGraph.series2 = new QScatter3DSeries(syncGraph.dataProxy2);
        syncGraph.scatter->addSeries(syncGraph.series1);
        syncGraph.scatter->addSeries(syncGraph.series2);
        syncGraph.layout = new QVBoxLayout(ui->syncGraphWidget);
        ui->syncGraphWidget->setLayout(syncGraph.layout);
        syncGraph.layout->addWidget(syncGraph.container);
    }

    {
        this->timeGraph = ui->timeView;
        timeGraph->xAxis->setRange(0,10);
        timeGraph->yAxis->setRange(0,10);
        timeGraph->setInteraction(QCP::iRangeZoom, true);
        timeGraph->setInteraction(QCP::iRangeDrag, true);
    }

    {
        this->bGraph = ui->biffGraphView;
        bGraph->xAxis->setRange(0,10);
        bGraph->yAxis->setRange(0,10);
        bGraph->setInteraction(QCP::iRangeZoom, true);
        bGraph->setInteraction(QCP::iRangeDrag, true);
    }

    {
        this->lpGraph = ui->lpGraphView;
        lpGraph->xAxis->setRange(0,10);
        lpGraph->yAxis->setRange(0,10);
        lpGraph->setInteraction(QCP::iRangeZoom, true);
        lpGraph->setInteraction(QCP::iRangeDrag, true);
    }

    {
        this->volumeGraph = ui->volView;
        volumeGraph->xAxis->setRange(0,10);
        volumeGraph->yAxis->setRange(0,10);
        volumeGraph->setInteraction(QCP::iRangeZoom, true);
        volumeGraph->setInteraction(QCP::iRangeDrag, true);
    }

    {
        this->syncTimeGraph = ui->syncTimeGraphView;
        syncTimeGraph->xAxis->setRange(0,10);
        syncTimeGraph->yAxis->setRange(0,10);
        syncTimeGraph->setInteraction(QCP::iRangeZoom, true);
        syncTimeGraph->setInteraction(QCP::iRangeDrag, true);
    }

    {
        this->syncPhaseGraph = ui->syncPhaseGraphView;
        syncPhaseGraph->xAxis->setRange(0,10);
        syncPhaseGraph->yAxis->setRange(0,10);
        syncPhaseGraph->setInteraction(QCP::iRangeZoom, true);
        syncPhaseGraph->setInteraction(QCP::iRangeDrag, true);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


//Methods
QVector3D MainWindow::standartEulerStep(QVector3D data_cur, double h, QVector3D q)
{
    double x = data_cur.x() + h*this->modelingSystem->f(data_cur.x(), data_cur.y(), data_cur.z()) + h*q.x();
    double y = data_cur.y() + h*this->modelingSystem->g(data_cur.x(), data_cur.y(), data_cur.z()) + h*q.y();
    double z = data_cur.z() + h*this->modelingSystem->w(data_cur.x(), data_cur.y(), data_cur.z()) + h*q.z();

    if(this->curSystem == "VanDerPol")return QVector3D(x,y,data_cur.z());
    else return QVector3D(x,y,z);
}

QVector3D MainWindow::modedEulerStep(QVector3D data_cur, double h, QVector3D q)
{
    double x_temp = data_cur.x() + (h/2)*this->modelingSystem->f(data_cur.x(),data_cur.y(),data_cur.z()) + (h/2)*q.x();
    double y_temp = data_cur.y() + (h/2)*this->modelingSystem->g(data_cur.x(),data_cur.y(),data_cur.z()) + (h/2)*q.y();
    double z_temp = data_cur.z() + (h/2)*this->modelingSystem->w(data_cur.x(),data_cur.y(),data_cur.z()) + (h/2)*q.z();

    double x = data_cur.x() + h*this->modelingSystem->f(x_temp, y_temp, z_temp) + h*q.x();
    double y = data_cur.y() + h*this->modelingSystem->g(x_temp, y_temp, z_temp) + h*q.y();
    double z = data_cur.z() + h*this->modelingSystem->w(x_temp, y_temp, z_temp) + h*q.z();

    if(this->curSystem == "VanDerPol")return QVector3D(x,y,data_cur.z());
    else return QVector3D(x,y,z);

}

QVector3D MainWindow::EulerCromer(QVector3D data_cur, double h, QVector3D q)
{
    double x = data_cur.x() + h*this->modelingSystem->f(data_cur.x(),data_cur.y(),data_cur.z()) + h*q.x();
    double y = data_cur.y() + h*this->modelingSystem->g(x,data_cur.y(),data_cur.z()) + h*q.y();
    double z = data_cur.z() + h*this->modelingSystem->w(x,y,data_cur.z()) + h*q.z();

    if(this->curSystem == "VanDerPol")return QVector3D(x,y,data_cur.z());
    else return QVector3D(x,y,z);
}

QVector3D MainWindow::CDmethod(QVector3D data_cur, double h, QVector3D q)
{
    double x_temp = data_cur.x() + (h/2)*this->modelingSystem->f(data_cur.x(),data_cur.y(),data_cur.z());
    double y_temp = data_cur.y() + (h/2)*this->modelingSystem->g(x_temp,data_cur.y(),data_cur.z());

    double y = this->modelingSystem->gM(x_temp,y_temp,data_cur.z(), h, q);
    double x = this->modelingSystem->fM(x_temp,y,data_cur.z(), h, q);

    double z = data_cur.z() + h*this->modelingSystem->w(x_temp,y_temp,data_cur.z());

    if(this->curSystem == "VanDerPol")return QVector3D(x,y,data_cur.z());
    else return QVector3D(x,y,z);
}

QVector3D MainWindow::RungeKutta(QVector3D data_cur, double h, QVector3D q)
{
    QVector3D k1 = h * derivatives(data_cur);
    QVector3D k2 = h * derivatives(data_cur + 1.0/4.0 * k1);
    QVector3D k3 = h * derivatives(data_cur + 3.0/32.0 * k1 + 9.0/32.0 * k2);
    QVector3D k4 = h * derivatives(data_cur + 1932.0/2197.0 * k1 - 7200.0/2197.0 * k2 + 7296.0/2197.0 * k3);
    QVector3D k5 = h * derivatives(data_cur + 439.0/216.0 * k1 - 8.0 * k2 + 3680.0/513.0 * k3 - 845.0/4104.0 * k4);
//    QVector3D k6 = h * derivatives(data_cur - 8.0/27.0 * k1 + 2.0 * k2 - 3544.0/2565.0 * k3 + 1859.0/4104.0 * k4 - 11.0/40.0 * k5);

    // Вычисление следующего значения data_cur с использованием коэффициентов 4-го порядка
    QVector3D next_data = data_cur + (25.0/216.0 * k1 + 1408.0/2565.0 * k3 + 2197.0/4104.0 * k4 - 1.0/5.0 * k5) + h*q;

    return next_data;
}




QVector<QVector3D> MainWindow::modeling(QVector<double>& x, QVector<double>& y, QVector<double>& z, int n, double h, bool coordsFill)
{
    QVector<QVector3D> ans;
    QVector3D cur(this->x,this->y,this->z);

    QVector3D q(0,0,0);

    for(int i=0;i<n;i++){
        ans.push_back(cur);
        QVector3D next(0,0,0);
        if(coordsFill)x.push_back(cur.x()), y.push_back(cur.y()), z.push_back(cur.z());

        switch (methods[method]) {
        case 0:
            next = this->standartEulerStep(cur, h, q);
            break;
        case 1:
            next = this->modedEulerStep(cur, h, q);
            break;
        case 2:
            next = this->EulerCromer(cur, h, q);
            break;
        case 3:
            next = this->CDmethod(cur, h, q);
            break;
        case 4:
            next = this->RungeKutta(cur, h, q);
            break;
        default:
            break;
        }
        cur = next;
    }
    return ans;
}


QVector<QVector3D> MainWindow::synchronization(const QVector<QVector3D>& mSystem, QString modMethod, QVector3D slave, double k, int coordN, double h)
{
    this->x = slave.x();
    this->y = slave.y();
    this->z = slave.z();
    QVector<QVector3D> sSystem(mSystem.size());

    QVector3D cur = slave;
    QVector3D next, q(0,0,0);
    for(int i=0; i<mSystem.size(); i++)
    {

        switch (methods[modMethod]) {
        case 0:
            next = this->standartEulerStep(cur, h, q);
            break;
        case 1:
            next = this->modedEulerStep(cur, h, q);
            break;
        case 2:
            next = this->EulerCromer(cur, h, q);
            break;
        case 3:
            next = this->CDmethod(cur, h, q);
            break;
        case 4:
            next = this->RungeKutta(cur, h, q);
            break;
        default:
            break;
        }

        q.setX(0);
        q.setY(0);
        q.setZ(0);

        if(i){
            switch (coordN) {
            case 0:
                q.setX(k*(mSystem[i - 1].x() - sSystem[i - 1].x()));
                break;
            case 1:
                q.setY(k*(mSystem[i - 1].y() - sSystem[i - 1].y()));
                break;
            case 2:
                q.setZ(k*(mSystem[i - 1].z() - sSystem[i - 1].z()));
                break;
            default:
                break;
            }
        }
        sSystem[i] = next;
        cur = next;

    }

    return sSystem;
}


double MainWindow::min(const QVector<double> data, int start, int end){
    if (start >= end || data.isEmpty()) {
        throw std::invalid_argument("Invalid range or empty vector.");
    }

    double minimum = data[start];
    for (int i = start + 1; i <= end; ++i) {
        if (data[i] < minimum) {
            minimum = data[i];
        }
    }
    return minimum;
}

double MainWindow::max(const QVector<double> data, int start, int end)
{
    if (start >= end || data.isEmpty()) {
        throw std::invalid_argument("Invalid range or empty vector.");
    }

    double maximum = data[start];
    for (int i = start + 1; i <= end; ++i) {
        if (data[i] > maximum) {
            maximum = data[i];
        }
    }
    return maximum;
}

QVector<double> MainWindow::findLocalExtrema(const QVector<double> &data, int start, int end)
{   
    QVector<double> extrema;

    for (int cur = start+1; cur < end - 1 && cur < data.size()-1; ++cur) {
        if (data[cur] > data[cur - 1] && data[cur] > data[cur + 1]) {
            // Локальный максимум

            if(data[cur]<0)extrema.push_back(abs(data[cur]));
            else extrema.push_back(data[cur]);

        } else if (data[cur] < data[cur - 1] && data[cur] < data[cur + 1]) {
            // Локальный минимум
            if(data[cur]<0)extrema.push_back(abs(data[cur]));
            else extrema.push_back(data[cur]);
        }
    }

    return extrema;
}

double MainWindow::countLocalVolume(int start, int end)
{

    if(end >= hCoords.size()) end = hCoords.size()-1;

    double x_max = max(xCoords, start, end);
    double x_min = min(xCoords, start, end);
    double y_max = max(yCoords, start, end);
    double y_min = min(yCoords, start, end);
    double z_max = max(xCoords, start, end);
    double z_min = min(xCoords, start, end);

    double dx = abs(x_max-x_min), dy = abs(y_max-y_min), dz = abs(z_max-z_min);

    if(this->systems[this->curSystem] == 1) dz = 1;

    return dx*dy*dz;
}

QVector3D MainWindow::derivatives(const QVector3D &point)
{
    double x = this->modelingSystem->f(point.x(),point.y(),point.z());
    double y = this->modelingSystem->g(point.x(),point.y(),point.z());
    double z = this->modelingSystem->w(point.x(),point.y(),point.z());

    return QVector3D(x,y,z);
}

void MainWindow::initSystem(QString system)
{
    switch(systems[system]){
    case 0:
    {
        double a = this->input[0]->text().toDouble();
        double b = this->input[1]->text().toDouble();
        double c = this->input[2]->text().toDouble();
        this->initValues.clear();
        this->initValues.push_back(a);
        this->initValues.push_back(b);
        this->initValues.push_back(c);
        this->rosslerAttractor->setData(initValues);
    }
    break;
    case 1:
    {
        this->initValues.clear();
        double m = this->input[0]->text().toDouble();
        this->initValues.push_back(m);
        this->vanDerPol->setData(initValues);
        break;
    }
    case 2:
    {
        this->initValues.clear();
        double a = this->input[0]->text().toDouble();
        this->initValues.push_back(a);
        this->nozeGuver->setData(initValues);
        break;
    }
    case 3:
    {
        this->initValues.clear();
        double a = this->input[0]->text().toDouble();
        double c = this->input[1]->text().toDouble();
        this->initValues.push_back(a);
        this->initValues.push_back(c);
        this->nozeGuverModed->setData(initValues);
        break;
    }
    case 4:
    {
        this->initValues.clear();
        double p = this->input[0]->text().toDouble();
        double o = this->input[1]->text().toDouble();
        double b = this->input[2]->text().toDouble();
        this->initValues.push_back(p);
        this->initValues.push_back(o);
        this->initValues.push_back(b);
        this->lorenz->setData(initValues);
        break;
    }
    default:
        break;
    }
}



void MainWindow::drawTimeGraph()
{
    QPen pen;
    pen.setColor(Qt::blue);
    timeGraph->addGraph();
    timeGraph->graph(0)->setPen(pen);
    timeGraph->graph(0)->setData(hCoords,xCoords);
    pen.setColor(Qt::red);
    timeGraph->addGraph();
    timeGraph->graph(1)->setPen(pen);
    timeGraph->graph(1)->setData(hCoords,yCoords);
    pen.setColor(Qt::green);
    timeGraph->addGraph();
    timeGraph->graph(2)->setPen(pen);
    timeGraph->graph(2)->setData(hCoords,zCoords);
    timeGraph->replot();
}

void MainWindow::drawVolumeGraph(int t)
{
    QVector<double> x;
    QVector<double> vol;
    x.push_back(0);
    vol.push_back(0);

    for(int i = 0; i < hCoords.size() - t; i += t){

        double v = this->countLocalVolume(i, i+t);
        vol.push_back(v/100);
        x.push_back(hCoords[i]);

    }

    QPen pen;
    pen.setColor(Qt::blue);
    volumeGraph->addGraph();
    volumeGraph->graph(0)->setPen(pen);
    volumeGraph->graph(0)->setData(x, vol);
}

void MainWindow::drawBiffrucGraph(int n, double h, double h2, double start, double end, int index, int extrema, int transientTime)
{
    QVector<double> xCoords2,yCoords2,zCoords2;

    QVector<double> params, value;
    int l = bGraph->graphCount();
    bGraph->addGraph();
    bGraph->graph(l)->setLineStyle(QCPGraph::lsNone);
    bGraph->graph(l)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    for(double param = start; param <= end; param += h2){
        xCoords2.clear();
        yCoords2.clear();
        zCoords2.clear();
        QVector3D cur(this->x, this->y, this->z);

        initValues[index] = param;

        this->modelingSystem->setData(initValues);

        QVector<QVector3D> points = this->modeling(xCoords2,yCoords2,zCoords2,n,h,true);

        QVector<double> e;

        switch (extrema) {
        case 0:
            e = this->findLocalExtrema(xCoords2,transientTime,n);
            break;
        case 1:
            e = this->findLocalExtrema(yCoords2,transientTime,n);
            break;
        case 2:
            e = this->findLocalExtrema(zCoords2,transientTime,n);
            break;
        default:
            break;
        }

        for(int j = 0; j < e.size(); j++){
            params.push_back(param);
            value.push_back(e[j]);
        }

    }

    bGraph->graph(l)->setData(params,value);
    bGraph->replot();
}

void MainWindow::drawLPGraph(QVector3D delta, int step, int n, double h, int coord)
{
    QVector<double> lp;
    QVector<double> hlp;

    QVector<QVector3D> points = modeling(xCoords,yCoords,zCoords,n,h, false);
    this->x += delta.x();
    this->y += delta.y();
    this->z += delta.z();
    QVector<QVector3D> points2 = modeling(xCoords,yCoords,zCoords,n,h, false);

    for(int i=0; i<points.size() - step && i<points2.size() - step; i += step){
        double r0 = 0.0, rt = 0.0;

        switch (coord) {
        case 0:
            r0 = points[i].x() - points2[i].x();
            rt = points[i+step].x() - points2[i+step].x();
            break;
        case 1:
            r0 = points[i].y() - points2[i].y();
            rt = points[i+step].y() - points2[i+step].y();
            break;
        case 2:
            r0 = points[i].z() - points2[i].z();
            rt = points[i+step].z() - points2[i+step].z();
            break;
        default:
            break;
        }
        double l = log10(rt/r0)/step;
        lp.push_back(l);
        hlp.push_back(i*step);
    }

    this->lpGraph->clearGraphs();
    this->lpGraph->addGraph();
    this->lpGraph->graph(0)->setData(hlp,lp);
}



void MainWindow::on_drawButton_clicked()
{
    this->clearTimeZone();

    int n = ui->nLine->text().toInt();
    double h = ui->stepLine->text().toDouble();

    this->x = ui->xLine->text().toDouble();
    this->y = ui->yLine->text().toDouble();
    this->z = ui->zLine->text().toDouble();


    this->method = ui->methodBox->currentText();
    this->curSystem = ui->systemBox->currentText();


    this->initSystem(curSystem);

    this->ui->BifParamBox->clear();
    for(int i = 0; i < initValues.size(); i++) this->ui->BifParamBox->addItem(QString::number(i));

    for(int i=0;i<n;i++)hCoords.push_back(h*i);

    QVector3D cur(this->x, this->y, this->z);
    QVector<QVector3D> points = this->modeling(xCoords,yCoords,zCoords,n,h, true);

    QScatterDataArray data;

    for(int i=0;i<points.size();i++){
        QScatterDataItem point;
        point.setPosition(points[i]);
        data << point;
    }

    double t = ui->volumeStepLine->text().toDouble();
    // Считаем максимальный объем на отрезках времени
    this->drawVolumeGraph(t);

    // Считаем максимальный объем на всем моделировании
    double vol = this->countLocalVolume(0, this->hCoords.size()-1);
    this->ui->volLabel->setText(QString::number(vol));

    this->drawTimeGraph();
    this->modelGraph.series->dataProxy()->addItems(data);
    this->modelGraph.series->setItemSize(0.05f);
}

void MainWindow::clearWidget(QWidget* widget) {
    QLayout* layout = widget->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (QWidget* widgetItem = item->widget()) {
                delete widgetItem;
            }
            delete item;
        }
        delete layout;
    }

    // Опционально, если у виджета есть дополнительные дочерние элементы без макета
    foreach(QObject* obj, widget->children()) {
        if (QWidget* childWidget = qobject_cast<QWidget*>(obj)) {
            delete childWidget;
        }
    }
}

void MainWindow::clearTimeZone()
{
    this->modelGraph.dataProxy->removeItems(0,this->modelGraph.dataProxy->array()->size());
    this->modelGraph.scatter->clearSelection();
    this->xCoords.clear();
    this->yCoords.clear();
    this->zCoords.clear();
    this->hCoords.clear();
    this->timeGraph->clearGraphs();
    this->timeGraph->replot();
    this->volumeGraph->clearGraphs();
    this->volumeGraph->replot();
}

void MainWindow::scaleLock()
{
    if(yLock && xLock){
        bGraph->axisRect()->setRangeZoomAxes(nullptr, nullptr);
        timeGraph->axisRect()->setRangeZoomAxes(nullptr, nullptr);
        volumeGraph->axisRect()->setRangeZoomAxes(nullptr, nullptr);
        lpGraph->axisRect()->setRangeZoomAxes(nullptr, nullptr);
        syncTimeGraph->axisRect()->setRangeZoomAxes(nullptr, nullptr);
        syncPhaseGraph->axisRect()->setRangeZoomAxes(nullptr, nullptr);
    }
    else if(yLock && !xLock){
        bGraph->axisRect()->setRangeZoomAxes(bGraph->xAxis, nullptr);
        timeGraph->axisRect()->setRangeZoomAxes(timeGraph->xAxis, nullptr);
        volumeGraph->axisRect()->setRangeZoomAxes(volumeGraph->xAxis, nullptr);
        lpGraph->axisRect()->setRangeZoomAxes(lpGraph->xAxis, nullptr);
        syncTimeGraph->axisRect()->setRangeZoomAxes(syncTimeGraph->xAxis, nullptr);
        syncPhaseGraph->axisRect()->setRangeZoomAxes(syncPhaseGraph->xAxis, nullptr);
    }
    else if(!yLock && xLock){
        bGraph->axisRect()->setRangeZoomAxes(nullptr, bGraph->yAxis);
        timeGraph->axisRect()->setRangeZoomAxes(nullptr, timeGraph->yAxis);
        volumeGraph->axisRect()->setRangeZoomAxes(nullptr, volumeGraph->yAxis);
        lpGraph->axisRect()->setRangeZoomAxes(nullptr, lpGraph->yAxis);
        syncTimeGraph->axisRect()->setRangeZoomAxes(nullptr, syncTimeGraph->yAxis);
        syncPhaseGraph->axisRect()->setRangeZoomAxes(nullptr, syncPhaseGraph->yAxis);
    }
    else{
        bGraph->axisRect()->setRangeZoomAxes(bGraph->xAxis, bGraph->yAxis);
        timeGraph->axisRect()->setRangeZoomAxes(timeGraph->xAxis, timeGraph->yAxis);
        volumeGraph->axisRect()->setRangeZoomAxes(volumeGraph->xAxis, volumeGraph->yAxis);
        lpGraph->axisRect()->setRangeZoomAxes(lpGraph->xAxis, lpGraph->yAxis);
        syncTimeGraph->axisRect()->setRangeZoomAxes(syncTimeGraph->xAxis, syncTimeGraph->yAxis);
        syncPhaseGraph->axisRect()->setRangeZoomAxes(syncPhaseGraph->xAxis, syncPhaseGraph->yAxis);
    }
    bGraph->replot();
    timeGraph->replot();
    volumeGraph->replot();
    lpGraph->replot();
}




void MainWindow::on_systemBox_currentTextChanged(const QString &arg1)
{
    this->clearWidget(this->ui->editorWidget);
    this->input.clear();

    switch (systems[arg1]) {
    case 0:
        this->modelingSystem = this->rosslerAttractor;
        break;
    case 1:
        this->modelingSystem = this->vanDerPol;
        break;
    case 2:
        this->modelingSystem = this->nozeGuver;
        break;
    case 3:
        this->modelingSystem = this->nozeGuverModed;
        break;
    case 4:
        this->modelingSystem = this->lorenz;
        break;
    default:
        break;
    }
    this->input = this->modelingSystem->UI(this->ui->editorWidget);
}

void MainWindow::on_drawBiff_clicked()
{
    this->bGraph->clearGraphs();
    this->bGraph->replot();

    double start = ui->startParamLine->text().toDouble();
    double end = ui->endParamLine->text().toDouble();
    double h = ui->stepLine->text().toDouble();
    double h2 = ui->stepParamLine->text().toDouble();
    double n = ui->nLine->text().toDouble();
    int transientTime = ui->transientTimeLine->text().toInt();

    int param = ui->BifParamBox->currentText().toInt();

    QString coord = ui->CoordParamBox->currentText();
    double coordN = -1;
    if(coord == "x") coordN = 0;
    else if(coord == "y") coordN = 1;
    else coordN = 2;

    this->drawBiffrucGraph(n, h, h2, start, end, param, coordN, transientTime);
}

void MainWindow::on_lpDrawButton_clicked()
{
    int n = ui->nLine->text().toInt();
    double h = ui->stepLine->text().toDouble();
    double step = ui->deltaLine->text().toDouble();

    this->x = ui->xLine->text().toDouble();
    this->y = ui->yLine->text().toDouble();
    this->z = ui->zLine->text().toDouble();

    QString coord = ui->lpCoordParamBox->currentText();
    double coordN = -1;
    if(coord == "x") coordN = 0;
    else if(coord == "y") coordN = 1;
    else coordN = 2;

    double xLp = ui->xLPLine->text().toDouble();
    double yLp = ui->yLPLine->text().toDouble();
    double zLp = ui->zLPLine->text().toDouble();

    QVector3D delta(xLp,yLp,zLp);

    this->drawLPGraph(delta,step,n,h,coordN);
}

void MainWindow::on_syncButton_clicked()
{
    this->syncTimeGraph->clearGraphs();
    this->syncTimeGraph->replot();
    this->syncPhaseGraph->clearGraphs();
    this->syncPhaseGraph->replot();
    this->syncGraph.dataProxy1->removeItems(0,this->syncGraph.dataProxy1->array()->size());
    this->syncGraph.dataProxy2->removeItems(0,this->syncGraph.dataProxy2->array()->size());
    this->syncGraph.scatter->clearSelection();

    this->x = ui->xLine->text().toDouble();
    this->y = ui->yLine->text().toDouble();
    this->z = ui->zLine->text().toDouble();

    double h = ui->stepLine->text().toDouble();
    int n = ui->nLine->text().toInt();
    double k = ui->syncKLine->text().toDouble();

    QString coord = ui->syncCoordParamBox->currentText();
    int coordN = -1;
    if(coord == "x") coordN = 0;
    else if(coord == "y") coordN = 1;
    else coordN = 2;

    double x = ui->syncXLine->text().toDouble();
    double y = ui->syncYLine->text().toDouble();
    double z = ui->syncZLine->text().toDouble();
    QVector3D slave(x,y,z);

    curSystem = ui->systemBox->currentText();
    this->initSystem(curSystem);

    QVector<double> localXCoords, localYCoords, localZCoords, localHCoords;

    for(int i=0;i<n;i++)localHCoords.push_back(h*i);

    this->method = ui->masterMethodBox->currentText();
    QVector<QVector3D> mSystem = this->modeling(localXCoords,localYCoords,localZCoords, n, h, true);


    QString sMethod = ui->slaveMethodBox->currentText();
    QVector<QVector3D> sSystem = this->synchronization(mSystem,sMethod,slave,k,coordN,h);

    QScatterDataArray mdata,sdata;

    QPen pen;
    {
        this->syncTimeGraph->addGraph();
        this->syncTimeGraph->addGraph();
        this->syncTimeGraph->addGraph();
        this->syncTimeGraph->graph(0)->setData(localHCoords,localXCoords);
        this->syncTimeGraph->graph(1)->setData(localHCoords,localYCoords);
        this->syncTimeGraph->graph(2)->setData(localHCoords,localZCoords);
        pen.setColor(Qt::blue);
        this->syncTimeGraph->graph(0)->setPen(pen);
        pen.setColor(Qt::red);
        this->syncTimeGraph->graph(1)->setPen(pen);
        pen.setColor(Qt::green);
        this->syncTimeGraph->graph(2)->setPen(pen);
    }

    localXCoords.clear(), localYCoords.clear(), localZCoords.clear();

    QVector<double> dx,dy,dz;

    for(int i=0;i<mSystem.size();i++){
        QScatterDataItem point;
        point.setPosition(mSystem[i]);
        mdata << point;
        point.setPosition(sSystem[i]);
        localXCoords.push_back(sSystem[i].x());
        localYCoords.push_back(sSystem[i].y());
        localZCoords.push_back(sSystem[i].z());
        dx.push_back(abs(mSystem[i].x()-sSystem[i].x()));
        dy.push_back(abs(mSystem[i].y()-sSystem[i].y()));
        dz.push_back(abs(mSystem[i].z()-sSystem[i].z()));
        sdata << point;
    }

    {
        this->syncTimeGraph->addGraph();
        this->syncTimeGraph->addGraph();
        this->syncTimeGraph->addGraph();
        this->syncTimeGraph->graph(3)->setData(localHCoords,localXCoords);
        this->syncTimeGraph->graph(4)->setData(localHCoords,localYCoords);
        this->syncTimeGraph->graph(5)->setData(localHCoords,localZCoords);
        pen.setColor(Qt::darkBlue);
        this->syncTimeGraph->graph(3)->setPen(pen);
        pen.setColor(Qt::darkRed);
        this->syncTimeGraph->graph(4)->setPen(pen);
        pen.setColor(Qt::darkGreen);
        this->syncTimeGraph->graph(5)->setPen(pen);
    }

    {
        this->syncPhaseGraph->addGraph();
        this->syncPhaseGraph->addGraph();
        this->syncPhaseGraph->addGraph();
        this->syncPhaseGraph->graph(0)->setData(localHCoords,dx);
        this->syncPhaseGraph->graph(1)->setData(localHCoords,dy);
        this->syncPhaseGraph->graph(2)->setData(localHCoords,dz);
        pen.setColor(Qt::blue);
        this->syncPhaseGraph->graph(0)->setPen(pen);
        pen.setColor(Qt::red);
        this->syncPhaseGraph->graph(1)->setPen(pen);
        pen.setColor(Qt::green);
        this->syncPhaseGraph->graph(2)->setPen(pen);
    }

    {
        this->syncPhaseGraph->replot();
        this->syncTimeGraph->replot();
        syncGraph.series1->dataProxy()->addItems(mdata);
        syncGraph.series1->setBaseColor(Qt::green);
        syncGraph.series1->setItemSize(0.05f);
        syncGraph.series2->dataProxy()->addItems(sdata);
        syncGraph.series2->setBaseColor(Qt::blue);
        syncGraph.series2->setItemSize(0.05f);
    }


}


void MainWindow::on_yScaleButton_clicked()
{
    yLock = !yLock;
    this->scaleLock();
    if(yLock) ui->yScaleButton->setText("Unlock y scale");
    else ui->yScaleButton->setText("Lock y scale");
}

void MainWindow::on_xScaleButton_clicked()
{
    xLock = !xLock;
    this->scaleLock();
    if(xLock) ui->xScaleButton->setText("Unlock x scale");
    else ui->xScaleButton->setText("Lock x scale");
}

