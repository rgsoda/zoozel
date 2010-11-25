
#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "track.h"
#include "obstacle.h"

class scene : public QWidget
{
  
public:
    scene();
    void rotatePlayerLeft();
    void rotatePlayerRight();
    void acceleratePlayer();
    void brakePlayer();
    QGraphicsScene * getScene();
    player * getPlayer();
    
    void setTrackImage(QString &fileName);
    void setTrackData(QString &fileName);
private:
    QGraphicsScene field;
    QGraphicsView view;
    player *p;
    track *t;
    
};

#endif // SCENE_H
