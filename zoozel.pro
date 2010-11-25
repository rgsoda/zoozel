QT       += core gui network

TARGET = zoozel
TEMPLATE = app


SOURCES +=  main.cpp \
            mainwindow.cpp \
            obstacle.cpp \
            player.cpp \
            scene.cpp \
            track.cpp \
    connection.cpp



HEADERS  += mainwindow.h \
            obstacle.h \
            player.h \
            scene.h \
            track.h \
    connection.h


FORMS    +=
LIBS     += -L. -lqjson

RESOURCES +=

DEPENDPATH += .
INCLUDEPATH += .

SUBDIRS =
