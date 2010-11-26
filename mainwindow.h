
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QMap>
#include <QKeyEvent>
#include <QShowEvent>
#include <QHideEvent>
#include <QTimer>
#include <QtNetwork>
#include "scene.h"
#include "player.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow();
    scene *s;
    const static int window_width = 800;
    const static int window_height = 600;
    void setTrackInfo(QString image, QString data);
    void putPlayerOnScene(player *p,bool local);

protected:
    virtual void keyPressEvent( QKeyEvent *event );
    virtual void keyReleaseEvent( QKeyEvent *event );

private:
    int keys;
    bool keyUp;
    bool keyDown;
    bool keyLeft;
    bool keyRight;
    QString trackImageFileName;
    QString trackDataFileName;


public slots:
    void advance();
    void movePlayer();

};

#endif // MAINWINDOW_H
