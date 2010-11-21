#include <QtGui>
#include "scene.h"
#include "player.h"
#include "track.h"

scene::scene() : QWidget() , field(0,0,870,600), view(&field, this)
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
    
    t = new track();
    p = new player();
    p->setPos(300,300);
    t->setPos(300,300);
    field.addItem(p);
    field.addItem(t);
    
    //view.setBackgroundBrush(QPixmap("images/track.jpg"));



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
