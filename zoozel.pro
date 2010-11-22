QT       += core gui

TARGET = zoozel
TEMPLATE = app


SOURCES +=  main.cpp \
            mainwindow.cpp \
            obstacle.cpp \
            player.cpp \
            scene.cpp \
            track.cpp \



HEADERS  += mainwindow.h \
            obstacle.h \
            player.h \
            scene.h \
            track.h \


FORMS    +=
LIBS     += -L.

RESOURCES +=

DEPENDPATH += .
INCLUDEPATH += .

SUBDIRS =

