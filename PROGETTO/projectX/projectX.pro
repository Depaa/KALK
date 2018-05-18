QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projectX
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    orario.cpp \
    data.cpp \
    overflow_error.cpp \
    fusoorario.cpp \
    sole.cpp \
    model.cpp \
    view.cpp \
    control.cpp

HEADERS += \
    orario.h \
    data.h \
    overflow_error.h \
    fusoorario.h \
    sole.h \
    model.h \
    view.h \
    control.h

FORMS += \
    view.ui
