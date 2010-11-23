#include <QGraphicsItem>
#include <QFile>
#include <QtDebug>
#include "track.h"
#include "mainwindow.h"
#include <qjson/parser.h>

track::track()
{

  startPoint = QPoint(65,60);
  
}

QList< obstacle *> track::getObstacleList()
{
  return obstacleList;
}


void track::readJSON(QString &filename) {
    QJson::Parser parser;
    bool ok;
    QFile read(filename);
    read.open(QIODevice::ReadOnly);
    QDataStream in(&read);    // read the data serialized from the file
    QByteArray json;
    in >> json;

    QVariantList vmap = parser.parse(json, &ok).toList();

    if (!ok) {
      qFatal("An error occurred during parsing track data");
      exit (1);
    }



   foreach (QVariant polygon, vmap) {
      QPolygon *p = new QPolygon();
      foreach(QVariant point, polygon.toList()) {
            p->append(QPoint(point.toMap()["x"].toInt(),point.toMap()["y"].toInt()));
            obstacleList.append(new obstacle(p));
      }
   }
}
