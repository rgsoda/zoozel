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
    
    
    p = new player();
    
    
    field.addItem(p);
    
    t = new track();
    foreach(obstacle *o, t->getObstacleList()) {
      field.addItem(dynamic_cast<QGraphicsItem*>(o));
    }
    p->setPos(t->startPoint);
    
    view.setBackgroundBrush(QPixmap("images/asphalt.jpg"));



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


void scene::rotatePlayerRigh()
{
  p->rotateRight();
}

QGraphicsScene *scene::getScene()
{
  return &field;
}
