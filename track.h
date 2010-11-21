#ifndef TRACK_H
#define TRACK_H

#include <QObject>
#include <QGraphicsItem>

class track : public QObject, public QGraphicsItem
{
  
public:
    track();

  QRectF boundingRect() const;
  QPainterPath shape() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	      QWidget *widget);
  

private:
    QColor color;
    QImage image;
};

#endif
