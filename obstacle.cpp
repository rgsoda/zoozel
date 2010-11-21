
#include "obstacle.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QKeyEvent>
#include <QImage>
#include <QEvent>
#include <math.h>


obstacle::obstacle ( qreal x, qreal y, qreal width, qreal height )
{
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

QRectF obstacle::boundingRect() const
{
    qreal adjust = 0.0;
    return QRectF(x - adjust, y - adjust,
                  width + adjust, height + adjust);
}
QPainterPath obstacle::shape() const
{
    QPainterPath path;
    path.addRect(x, y, width, height);
    return path;
}

void obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    
    painter->drawRect( x , y , width,height);
    painter->fillRect( x , y , width,height, Qt::green);
    
    
}
