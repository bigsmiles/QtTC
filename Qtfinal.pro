#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T19:08:36
#
#-------------------------------------------------

QT       += core gui

TARGET = Qtfinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    resultdialog.cpp

HEADERS  += mainwindow.h \
    ICTCLAS50.h \
    COMMON.h \
    resultdialog.h

FORMS    += mainwindow.ui \
    resultdialog.ui

#LIBS += E:\final\Qtfinal\ICTCLAS50.lib
#LIBS += -LE:\final\Qtfinal\ -lICTCLAS50
LIBS += $$_PRO_FILE_PWD_\ICTCLAS50.lib
