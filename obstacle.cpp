
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

    return QRectF();

}
QPainterPath obstacle::shape() const
{
    QPainterPath path;
    //path.addRect(x, y, width, height);
    path.addPolygon(*poly);
    return path;
}

bool obstacle::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {
    if(other->shape().intersects(this->shape())) {
        return true;
    }
    return false;
}
void obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    
//    painter->drawRect( x , y , width,height);
//    painter->fillRect( x , y , width,height, Qt::green);
    painter->drawPolygon(*poly,Qt::OddEvenFill);
    
}
