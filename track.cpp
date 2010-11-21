
#include "track.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QKeyEvent>
#include <QImage>
#include <QEvent>
#include <math.h>


track::track()
    : color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    image = QImage("images/f1.jpg");
    
}
QRectF track::boundingRect() const
{
    qreal adjust = 0.0;
    return QRectF(10 - adjust, 10 - adjust,
                  200 + adjust, 200 + adjust);
}
QPainterPath track::shape() const
{
    QPainterPath path;
    path.addRect(10, 10, 200, 200);
    return path;
}

void track::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawRect( 10 , 10 , 200 ,200);
    
}
