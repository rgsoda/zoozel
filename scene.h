
#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"

class scene : public QWidget
{
  
public:
    scene();
    void rotatePlayerLeft();
    void rotatePlayerRigh();
    void acceleratePlayer();
    void brakePlayer();
    QGraphicsScene * getScene();
    
private:
    QGraphicsScene field;
    QGraphicsView view;
    player *p;
};

#endif // SCENE_H
