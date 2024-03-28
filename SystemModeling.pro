QT       += core gui printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets datavisualization printsupport charts
CONFIG += c++17
QMAKE_CXXFLAGS += -Wa,-mbig-obj
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lorenz.cpp \
    main.cpp \
    mainwindow.cpp \
    nozeguver.cpp \
    nozeguvermoded.cpp \
    qcustomplot.cpp \
    rosslerattractor.cpp \
    vanderpol.cpp

HEADERS += \
    lorenz.h \
    mainwindow.h \
    nozeguver.h \
    nozeguvermoded.h \
    qcustomplot.h \
    rosslerattractor.h \
    system.h \
    vanderpol.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
