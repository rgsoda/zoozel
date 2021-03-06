
#include "player.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QKeyEvent>
#include <QImage>
#include <QEvent>
#include <math.h>


static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
static qreal maxSpeed = 6.0;
static qreal maxReverseSpeed = -1.6;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}


player::player()
    : angle(0), speed(0),
      color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    setRotation(qrand() % (360 * 16));
    image = QImage("images/fureks_mini.png");
    setZValue(1.0);
    
}

player::player(QString nickname)
    : angle(0), speed(0),
      color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    this->nick = nickname;
    setRotation(qrand() % (360 * 16));
    image = QImage("images/fureks_mini.png");
    setZValue(1.0);
}

QRectF player::boundingRect() const
{
    qreal adjust = 0.0;
    return QRectF(-5 - adjust, -10 - adjust,
                  10 + adjust, 20 + adjust);
}
QPainterPath player::shape() const
{
    QPainterPath path;
    path.addRect(-5, -10, 10, 20);
    return path;
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setBrush(Qt::white);
    //painter->drawRect(-5,-10,10,20);
    painter->drawImage(QRect(-5,-10,10,20),image);

    if(scene()->collidingItems(this).size() > 0) {
        this->speed = 0;
//TODO implement speed down after different class of obstacles
//      static float minSpeed = 1.0;
//      if (this->speed > minSpeed)
//        this->speed = (this->speed - minSpeed) * 0.9 + minSpeed;
    }
}
void player::advance(int step)
{

    if (!step)
        return;

    setPos(mapToParent(0, -(speed)));
    
}


void player::accelerate()
{
  if(speed<maxSpeed)
    speed += 0.2;
}

void player::brake()
{
  if(speed>maxReverseSpeed)
    speed -= 0.16;
}

void player::rotateLeft()
{
  qreal dx = 7;
  if( speed > 0.07 )
    speed -= 0.07;
  //avoid rotating in place
  if(abs(speed) > 0.3)
     dx -= maxSpeed/1.8;
     setRotation(rotation() - dx);
  
}

void player::rotateRight()
{
  qreal dx = 7;
  if( speed > 0.07 )
    speed -= 0.07;
  //avoid rotating in place
  if(abs(speed) > 0.3)
     dx -= maxSpeed/1.8;
     setRotation(rotation() + dx);
  
}

qreal player::getAngle() {
    return angle;
}
