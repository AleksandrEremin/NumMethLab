QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "include"
INCLUDEPATH += "qcustomplot"
INCLUDEPATH += "app"

SOURCES += \
    app/main.cpp \
    app/mainwindow.cpp \
    qcustomplot/qcustomplot.cpp \
    src/MainWork.cpp

HEADERS += \
    app/mainwindow.h \
    include/MainWork.h \
    qcustomplot/qcustomplot.h

FORMS += \
    app/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
