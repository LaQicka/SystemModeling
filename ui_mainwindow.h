/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *graphWidget;
    QWidget *editorWidget;
    QCustomPlot *timeView;
    QCustomPlot *volView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *drawBiff;
    QComboBox *BifParamBox;
    QComboBox *CoordParamBox;
    QLabel *label_2;
    QLineEdit *startParamLine;
    QLabel *label_3;
    QLineEdit *endParamLine;
    QLabel *label_4;
    QLineEdit *stepParamLine;
    QLabel *label_8;
    QLineEdit *transientTimeLine;
    QCustomPlot *biffGraphView;
    QCustomPlot *lpGraphView;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *drawButton;
    QComboBox *methodBox;
    QComboBox *systemBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *nLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *stepLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *volLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLineEdit *xLine;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QLineEdit *yLine;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLineEdit *zLine;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *volumeStepLine;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *lpDrawButton;
    QComboBox *lpCoordParamBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QLineEdit *deltaLine;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_17;
    QLineEdit *xLPLine;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QLineEdit *yLPLine;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QLineEdit *zLPLine;
    QWidget *syncGraphWidget;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *syncButton;
    QComboBox *syncCoordParamBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_13;
    QComboBox *masterMethodBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_21;
    QComboBox *slaveMethodBox;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_19;
    QLineEdit *syncKLine;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QLineEdit *syncXLine;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_20;
    QLineEdit *syncYLine;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_18;
    QLineEdit *syncZLine;
    QPushButton *yScaleButton;
    QPushButton *xScaleButton;
    QCustomPlot *syncTimeGraphView;
    QCustomPlot *syncPhaseGraphView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1698, 743);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphWidget = new QWidget(centralwidget);
        graphWidget->setObjectName("graphWidget");
        graphWidget->setGeometry(QRect(209, 9, 351, 361));
        editorWidget = new QWidget(centralwidget);
        editorWidget->setObjectName("editorWidget");
        editorWidget->setGeometry(QRect(10, 380, 181, 171));
        timeView = new QCustomPlot(centralwidget);
        timeView->setObjectName("timeView");
        timeView->setGeometry(QRect(210, 380, 281, 311));
        volView = new QCustomPlot(centralwidget);
        volView->setObjectName("volView");
        volView->setGeometry(QRect(500, 380, 271, 311));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(570, 10, 116, 356));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        drawBiff = new QPushButton(verticalLayoutWidget);
        drawBiff->setObjectName("drawBiff");

        verticalLayout->addWidget(drawBiff);

        BifParamBox = new QComboBox(verticalLayoutWidget);
        BifParamBox->setObjectName("BifParamBox");

        verticalLayout->addWidget(BifParamBox);

        CoordParamBox = new QComboBox(verticalLayoutWidget);
        CoordParamBox->addItem(QString());
        CoordParamBox->addItem(QString());
        CoordParamBox->addItem(QString());
        CoordParamBox->setObjectName("CoordParamBox");

        verticalLayout->addWidget(CoordParamBox);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        startParamLine = new QLineEdit(verticalLayoutWidget);
        startParamLine->setObjectName("startParamLine");

        verticalLayout->addWidget(startParamLine);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        endParamLine = new QLineEdit(verticalLayoutWidget);
        endParamLine->setObjectName("endParamLine");

        verticalLayout->addWidget(endParamLine);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        stepParamLine = new QLineEdit(verticalLayoutWidget);
        stepParamLine->setObjectName("stepParamLine");

        verticalLayout->addWidget(stepParamLine);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);

        transientTimeLine = new QLineEdit(verticalLayoutWidget);
        transientTimeLine->setObjectName("transientTimeLine");

        verticalLayout->addWidget(transientTimeLine);

        biffGraphView = new QCustomPlot(centralwidget);
        biffGraphView->setObjectName("biffGraphView");
        biffGraphView->setGeometry(QRect(700, 10, 351, 361));
        lpGraphView = new QCustomPlot(centralwidget);
        lpGraphView->setObjectName("lpGraphView");
        lpGraphView->setGeometry(QRect(780, 380, 271, 311));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 191, 361));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        drawButton = new QPushButton(verticalLayoutWidget_2);
        drawButton->setObjectName("drawButton");

        verticalLayout_2->addWidget(drawButton);

        methodBox = new QComboBox(verticalLayoutWidget_2);
        methodBox->addItem(QString());
        methodBox->addItem(QString());
        methodBox->addItem(QString());
        methodBox->addItem(QString());
        methodBox->addItem(QString());
        methodBox->setObjectName("methodBox");

        verticalLayout_2->addWidget(methodBox);

        systemBox = new QComboBox(verticalLayoutWidget_2);
        systemBox->addItem(QString());
        systemBox->addItem(QString());
        systemBox->addItem(QString());
        systemBox->addItem(QString());
        systemBox->addItem(QString());
        systemBox->setObjectName("systemBox");

        verticalLayout_2->addWidget(systemBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        nLine = new QLineEdit(verticalLayoutWidget_2);
        nLine->setObjectName("nLine");

        horizontalLayout_4->addWidget(nLine);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        stepLine = new QLineEdit(verticalLayoutWidget_2);
        stepLine->setObjectName("stepLine");

        horizontalLayout_3->addWidget(stepLine);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        volLabel = new QLabel(verticalLayoutWidget_2);
        volLabel->setObjectName("volLabel");

        horizontalLayout_2->addWidget(volLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName("label_9");

        horizontalLayout_5->addWidget(label_9);

        xLine = new QLineEdit(verticalLayoutWidget_2);
        xLine->setObjectName("xLine");

        horizontalLayout_5->addWidget(xLine);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName("label_10");

        horizontalLayout_6->addWidget(label_10);

        yLine = new QLineEdit(verticalLayoutWidget_2);
        yLine->setObjectName("yLine");

        horizontalLayout_6->addWidget(yLine);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName("label_11");

        horizontalLayout_7->addWidget(label_11);

        zLine = new QLineEdit(verticalLayoutWidget_2);
        zLine->setObjectName("zLine");

        horizontalLayout_7->addWidget(zLine);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName("label_7");

        horizontalLayout->addWidget(label_7);

        volumeStepLine = new QLineEdit(verticalLayoutWidget_2);
        volumeStepLine->setObjectName("volumeStepLine");

        horizontalLayout->addWidget(volumeStepLine);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(1060, 380, 121, 311));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lpDrawButton = new QPushButton(verticalLayoutWidget_3);
        lpDrawButton->setObjectName("lpDrawButton");

        verticalLayout_3->addWidget(lpDrawButton);

        lpCoordParamBox = new QComboBox(verticalLayoutWidget_3);
        lpCoordParamBox->addItem(QString());
        lpCoordParamBox->addItem(QString());
        lpCoordParamBox->addItem(QString());
        lpCoordParamBox->setObjectName("lpCoordParamBox");

        verticalLayout_3->addWidget(lpCoordParamBox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName("label_12");

        horizontalLayout_8->addWidget(label_12);

        deltaLine = new QLineEdit(verticalLayoutWidget_3);
        deltaLine->setObjectName("deltaLine");

        horizontalLayout_8->addWidget(deltaLine);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_17 = new QLabel(verticalLayoutWidget_3);
        label_17->setObjectName("label_17");

        horizontalLayout_13->addWidget(label_17);

        xLPLine = new QLineEdit(verticalLayoutWidget_3);
        xLPLine->setObjectName("xLPLine");

        horizontalLayout_13->addWidget(xLPLine);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_16 = new QLabel(verticalLayoutWidget_3);
        label_16->setObjectName("label_16");

        horizontalLayout_12->addWidget(label_16);

        yLPLine = new QLineEdit(verticalLayoutWidget_3);
        yLPLine->setObjectName("yLPLine");

        horizontalLayout_12->addWidget(yLPLine);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_15 = new QLabel(verticalLayoutWidget_3);
        label_15->setObjectName("label_15");

        horizontalLayout_11->addWidget(label_15);

        zLPLine = new QLineEdit(verticalLayoutWidget_3);
        zLPLine->setObjectName("zLPLine");

        horizontalLayout_11->addWidget(zLPLine);


        verticalLayout_3->addLayout(horizontalLayout_11);

        syncGraphWidget = new QWidget(centralwidget);
        syncGraphWidget->setObjectName("syncGraphWidget");
        syncGraphWidget->setGeometry(QRect(1060, 10, 351, 361));
        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(1190, 380, 225, 311));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        syncButton = new QPushButton(verticalLayoutWidget_4);
        syncButton->setObjectName("syncButton");

        verticalLayout_4->addWidget(syncButton);

        syncCoordParamBox = new QComboBox(verticalLayoutWidget_4);
        syncCoordParamBox->addItem(QString());
        syncCoordParamBox->addItem(QString());
        syncCoordParamBox->addItem(QString());
        syncCoordParamBox->setObjectName("syncCoordParamBox");

        verticalLayout_4->addWidget(syncCoordParamBox);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_13 = new QLabel(verticalLayoutWidget_4);
        label_13->setObjectName("label_13");

        horizontalLayout_9->addWidget(label_13);

        masterMethodBox = new QComboBox(verticalLayoutWidget_4);
        masterMethodBox->addItem(QString());
        masterMethodBox->addItem(QString());
        masterMethodBox->addItem(QString());
        masterMethodBox->addItem(QString());
        masterMethodBox->addItem(QString());
        masterMethodBox->setObjectName("masterMethodBox");

        horizontalLayout_9->addWidget(masterMethodBox);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_21 = new QLabel(verticalLayoutWidget_4);
        label_21->setObjectName("label_21");

        horizontalLayout_10->addWidget(label_21);

        slaveMethodBox = new QComboBox(verticalLayoutWidget_4);
        slaveMethodBox->addItem(QString());
        slaveMethodBox->addItem(QString());
        slaveMethodBox->addItem(QString());
        slaveMethodBox->addItem(QString());
        slaveMethodBox->addItem(QString());
        slaveMethodBox->setObjectName("slaveMethodBox");

        horizontalLayout_10->addWidget(slaveMethodBox);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_19 = new QLabel(verticalLayoutWidget_4);
        label_19->setObjectName("label_19");

        horizontalLayout_16->addWidget(label_19);

        syncKLine = new QLineEdit(verticalLayoutWidget_4);
        syncKLine->setObjectName("syncKLine");

        horizontalLayout_16->addWidget(syncKLine);


        verticalLayout_4->addLayout(horizontalLayout_16);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_14 = new QLabel(verticalLayoutWidget_4);
        label_14->setObjectName("label_14");

        horizontalLayout_15->addWidget(label_14);

        syncXLine = new QLineEdit(verticalLayoutWidget_4);
        syncXLine->setObjectName("syncXLine");

        horizontalLayout_15->addWidget(syncXLine);


        verticalLayout_4->addLayout(horizontalLayout_15);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_20 = new QLabel(verticalLayoutWidget_4);
        label_20->setObjectName("label_20");

        horizontalLayout_18->addWidget(label_20);

        syncYLine = new QLineEdit(verticalLayoutWidget_4);
        syncYLine->setObjectName("syncYLine");

        horizontalLayout_18->addWidget(syncYLine);


        verticalLayout_4->addLayout(horizontalLayout_18);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_18 = new QLabel(verticalLayoutWidget_4);
        label_18->setObjectName("label_18");

        horizontalLayout_17->addWidget(label_18);

        syncZLine = new QLineEdit(verticalLayoutWidget_4);
        syncZLine->setObjectName("syncZLine");

        horizontalLayout_17->addWidget(syncZLine);


        verticalLayout_4->addLayout(horizontalLayout_17);

        yScaleButton = new QPushButton(centralwidget);
        yScaleButton->setObjectName("yScaleButton");
        yScaleButton->setGeometry(QRect(10, 560, 181, 24));
        xScaleButton = new QPushButton(centralwidget);
        xScaleButton->setObjectName("xScaleButton");
        xScaleButton->setGeometry(QRect(10, 590, 181, 24));
        syncTimeGraphView = new QCustomPlot(centralwidget);
        syncTimeGraphView->setObjectName("syncTimeGraphView");
        syncTimeGraphView->setGeometry(QRect(1420, 10, 271, 311));
        syncPhaseGraphView = new QCustomPlot(centralwidget);
        syncPhaseGraphView->setObjectName("syncPhaseGraphView");
        syncPhaseGraphView->setGeometry(QRect(1420, 380, 271, 311));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1698, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        drawBiff->setText(QCoreApplication::translate("MainWindow", "Draw Biff", nullptr));
        CoordParamBox->setItemText(0, QCoreApplication::translate("MainWindow", "x", nullptr));
        CoordParamBox->setItemText(1, QCoreApplication::translate("MainWindow", "y", nullptr));
        CoordParamBox->setItemText(2, QCoreApplication::translate("MainWindow", "z", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "    Start Param", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "    End Param", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "    Param Step", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "    Transient Time", nullptr));
        drawButton->setText(QCoreApplication::translate("MainWindow", "Draw Graph", nullptr));
        methodBox->setItemText(0, QCoreApplication::translate("MainWindow", "Standart Euler", nullptr));
        methodBox->setItemText(1, QCoreApplication::translate("MainWindow", "Moded Euler", nullptr));
        methodBox->setItemText(2, QCoreApplication::translate("MainWindow", "Euler-Cromer", nullptr));
        methodBox->setItemText(3, QCoreApplication::translate("MainWindow", "CD", nullptr));
        methodBox->setItemText(4, QCoreApplication::translate("MainWindow", "RungeKutta", nullptr));

        systemBox->setItemText(0, QCoreApplication::translate("MainWindow", "Rossler Attractor", nullptr));
        systemBox->setItemText(1, QCoreApplication::translate("MainWindow", "VanDerPol", nullptr));
        systemBox->setItemText(2, QCoreApplication::translate("MainWindow", "NozeGuver", nullptr));
        systemBox->setItemText(3, QCoreApplication::translate("MainWindow", "NozeGuverModed", nullptr));
        systemBox->setItemText(4, QCoreApplication::translate("MainWindow", "Lorenz", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "        N", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "     Step", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Volume", nullptr));
        volLabel->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "    x   ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "    y    ", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "    z   ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Volume Step", nullptr));
        lpDrawButton->setText(QCoreApplication::translate("MainWindow", "LPDraw", nullptr));
        lpCoordParamBox->setItemText(0, QCoreApplication::translate("MainWindow", "x", nullptr));
        lpCoordParamBox->setItemText(1, QCoreApplication::translate("MainWindow", "y", nullptr));
        lpCoordParamBox->setItemText(2, QCoreApplication::translate("MainWindow", "z", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "  delta ", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "  x ", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "  y ", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "  z ", nullptr));
        syncButton->setText(QCoreApplication::translate("MainWindow", "Syncronize", nullptr));
        syncCoordParamBox->setItemText(0, QCoreApplication::translate("MainWindow", "x", nullptr));
        syncCoordParamBox->setItemText(1, QCoreApplication::translate("MainWindow", "y", nullptr));
        syncCoordParamBox->setItemText(2, QCoreApplication::translate("MainWindow", "z", nullptr));

        label_13->setText(QCoreApplication::translate("MainWindow", "Master Method", nullptr));
        masterMethodBox->setItemText(0, QCoreApplication::translate("MainWindow", "Standart Euler", nullptr));
        masterMethodBox->setItemText(1, QCoreApplication::translate("MainWindow", "Moded Euler", nullptr));
        masterMethodBox->setItemText(2, QCoreApplication::translate("MainWindow", "Euler-Cromer", nullptr));
        masterMethodBox->setItemText(3, QCoreApplication::translate("MainWindow", "CD", nullptr));
        masterMethodBox->setItemText(4, QCoreApplication::translate("MainWindow", "RungeKutta", nullptr));

        label_21->setText(QCoreApplication::translate("MainWindow", "Slave Method", nullptr));
        slaveMethodBox->setItemText(0, QCoreApplication::translate("MainWindow", "Standart Euler", nullptr));
        slaveMethodBox->setItemText(1, QCoreApplication::translate("MainWindow", "Moded Euler", nullptr));
        slaveMethodBox->setItemText(2, QCoreApplication::translate("MainWindow", "Euler-Cromer", nullptr));
        slaveMethodBox->setItemText(3, QCoreApplication::translate("MainWindow", "CD", nullptr));
        slaveMethodBox->setItemText(4, QCoreApplication::translate("MainWindow", "RungeKutta", nullptr));

        label_19->setText(QCoreApplication::translate("MainWindow", "   k  ", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "    x   ", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "    y   ", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "    z   ", nullptr));
        yScaleButton->setText(QCoreApplication::translate("MainWindow", "Lock y scale", nullptr));
        xScaleButton->setText(QCoreApplication::translate("MainWindow", "Lock x scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
