#-------------------------------------------------
#
# Project created by QtCreator 2015-11-28T19:17:48
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sterna_C
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Base/baseform.cpp \
    Artikli/artikli.cpp \
    Artikli/artiklivnes.cpp \
    Artikli/artiklilista.cpp \
    Artikli/artiklikorekcija.cpp \
    Left/left.cpp \
    xx.cpp \
    Helper/qhelperc.cpp \
    Helper/qrestapiex.cpp \
    Komintenti/komintenti.cpp \
    Komintenti/komintentikorekcija.cpp \
    Komintenti/komintentilista.cpp \
    Komintenti/komintentivnes.cpp

HEADERS  += mainwindow.h \
    Base/baseform.h \
    Artikli/artikli.h \
    Artikli/artiklivnes.h \
    Artikli/artiklilista.h \
    Artikli/artiklikorekcija.h \
    Left/left.h \
    xx.h \
    Helper/qhelperc.h \
    Helper/qrestapiex.h \
    Komintenti/komintenti.h \
    Komintenti/komintentikorekcija.h \
    Komintenti/komintentilista.h \
    Komintenti/komintentivnes.h

FORMS    += mainwindow.ui \
    Base/baseform.ui \
    Artikli/artikli.ui \
    Artikli/artiklivnes.ui \
    Artikli/artiklilista.ui \
    Artikli/artiklikorekcija.ui \
    Left/left.ui \
    Komintenti/komintenti.ui \
    Komintenti/komintentikorekcija.ui \
    Komintenti/komintentilista.ui \
    Komintenti/komintentivnes.ui
