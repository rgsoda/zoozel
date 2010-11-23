
#include "obstacle.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QKeyEvent>
#include <QImage>
#include <QEvent>
#include <math.h>


obstacle::obstacle(QPolygon *p) {
    poly = p;
}
QRectF obstacle::boundingRect() const
{

    return poly->boundingRect();

}
QPainterPath obstacle::shape() const
{
    QPainterPath path;
    //path.addRect(x, y, width, height);
    path.addPolygon(*poly);
    return path;
}


void obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
     // not drawing this shit, it consumes CPU
    
}
