#-------------------------------------------------
#
# Project created by QtCreator 2014-04-01T08:33:08
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CasseBrique
TEMPLATE = app


SOURCES += main.cpp\
    CGLArea.cpp \
    CFenetrePrincipale.cpp \
    CSphere.cpp \
    CObject.cpp \
    CVector3.cpp

HEADERS  += \
    CGLArea.h \
    CFenetrePrincipale.h \
    CSphere.h \
    CObject.h \
    CVector3.h

FORMS    += \
    CFenetrePrincipale.ui
