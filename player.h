#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>

class player : public QObject, public QGraphicsItem
{
  
public:
    player();
    player(QString nickname);

  QRectF boundingRect() const;
  QPainterPath shape() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	      QWidget *widget);
  void rotateLeft();
  void rotateRight();
  void accelerate();
  void brake();
  QString nick;

protected:
    void advance(int step);

private:
    qreal angle;
    qreal speed;
    qreal mouseEyeDirection;
    QColor color;
    QImage image;

};

#endif
