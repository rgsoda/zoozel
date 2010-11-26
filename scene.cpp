#include <QtGui>
#include "scene.h"
#include "player.h"
#include "track.h"
#include "obstacle.h"
#include "mainwindow.h"

scene::scene() : QWidget() , field(0,0,mainwindow::window_width,mainwindow::window_height), view(&field, this)
{
    view.setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view.setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setOptimizationFlags(QGraphicsView::DontClipPainter
                              | QGraphicsView::DontSavePainterState
                              );
    view.setRenderHint(QPainter::Antialiasing);
    view.viewport()->setFocusProxy( this );
    
    
//    p = new player();
//    field.addItem(p);
    
    t = new track();

}

void scene::acceleratePlayer()
{
  p->accelerate();
}

void scene::brakePlayer()
{
  p->brake();
}


void scene::rotatePlayerLeft()
{
  p->rotateLeft();
}


void scene::rotatePlayerRight()
{
  p->rotateRight();
}

QGraphicsScene *scene::getScene()
{
  return &field;
}
player *scene::getPlayer() {
    return p;
}

void scene::setTrackImage(QString &fileName) {
    QPixmap trackImage(fileName);
    view.setBackgroundBrush(trackImage);
    dynamic_cast<mainwindow*>(this->parent())->resize(trackImage.size());
    field.setSceneRect(trackImage.rect());
}


void scene::setTrackData(QString &fileName) {
    t->readJSON(fileName);
    foreach(obstacle *o, t->getObstacleList()) {
      field.addItem(dynamic_cast<QGraphicsItem*>(o));
    }
    p->setPos(t->startPoint);

}

void scene::putPlayer(player *p, bool local) {
    if (local) this->p = p;
    field.addItem(p);
}
