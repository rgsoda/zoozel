#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>
#include <QGraphicsItem>

class obstacle : public QObject, public QGraphicsItem
{
  
public:

    obstacle(qreal x, qreal y, qreal width, qreal height);

  QRectF boundingRect() const;
  QPainterPath shape() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	      QWidget *widget);
  

private:
    QColor color;
    QImage image;
    qreal x;
    qreal y;
    qreal width;
    qreal height;
    
};

#endif
