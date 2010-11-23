#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>
#include <QGraphicsItem>

class obstacle : public QObject, public QGraphicsItem
{
  
public:

    //obstacle(qreal x, qreal y, qreal width, qreal height);
    obstacle(QPolygon *p);

  QRectF boundingRect() const;
  QPainterPath shape() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	      QWidget *widget);
  bool collidesWithItem ( const QGraphicsItem * other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape ) const;

private:
    QColor color;
    QImage image;
    QPolygon *poly;
};

#endif
