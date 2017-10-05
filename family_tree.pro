#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T11:16:31
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = family_tree
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
           mainwindow.cpp \
           simpletree.cpp \
           sql_connect.cpp \
    person.cpp \
    person_graphicitem.cpp

HEADERS  += mainwindow.h \
    simpletree.h \
    sql_connect.h \
    person.h \
    person_graphicitem.h

FORMS    += mainwindow.ui



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../drzewo/lib/ -llibmysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../drzewo/lib/ -llibmysqld

INCLUDEPATH += $$PWD/../../drzewo
DEPENDPATH += $$PWD/../../drzewo
