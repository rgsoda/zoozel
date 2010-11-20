
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QKeyEvent>
#include <QShowEvent>
#include <QHideEvent>

#include "scene.h"

class mainwindow : public QMainWindow
{

public:
    mainwindow();
    scene *s;
protected:
    virtual void keyPressEvent( QKeyEvent *event );
    virtual void keyReleaseEvent( QKeyEvent *event );

private:
    enum Action { Accelerate, Brake, RotateLeft, RotateRight };
    QMap<int,Action> actions;
};

#endif // MAINWINDOW_H
