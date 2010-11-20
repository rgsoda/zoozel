
#include "player.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QKeyEvent>
#include <QImage>
#include <math.h>
#include <qevent.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}


player::player()
    : angle(0), speed(0), mouseEyeDirection(0),
      color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    setRotation(qrand() % (360 * 16));
    image = QImage("images/f1.jpg");
}
QRectF player::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
QPainterPath player::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawImage(QPoint(-10,-20),image);
    
}
void player::advance(int step)
{

    if (!step)
        return;

    setPos(mapToParent(0, -(3 + sin(speed) * 3)));
}


void player::accelerate()
{
  speed += 0.1;
}

void player::brake()
{
  speed -= 0.1;
}

void player::rotateLeft()
{
  qreal dx = ::sin(-0.6) * 10;
  setRotation(rotation() + dx);
}

void player::rotateRight()
{
  qreal dx = ::sin(-0.6) * 10;
  setRotation(rotation() - dx);

}
