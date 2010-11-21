
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QKeyEvent>
#include <QShowEvent>
#include <QHideEvent>
#include <QTimer>
#include "scene.h"
#include <QObject>

class mainwindow : public QMainWindow
{

public:
    mainwindow();
    scene *s;
    const static int window_width = 800;
    const static int window_height = 600;

protected:
    virtual void keyPressEvent( QKeyEvent *event );
    virtual void keyReleaseEvent( QKeyEvent *event );

private:
    int keys;
    bool keyUp;
    bool keyDown;
    bool keyLeft;
    bool keyRight;

public slots:
  void movePlayer();
};

#endif // MAINWINDOW_H
