#include <QGraphicsItem>
#include "track.h"
#include "mainwindow.h"

track::track()
{
  
  obstacle *top = new obstacle(0,0,mainwindow::window_width,50);
  obstacle *bottom = new obstacle(0,mainwindow::window_height-50,mainwindow::window_width,50);
  obstacle *left = new obstacle(0,0,50,mainwindow::window_height);
  obstacle *right = new obstacle(mainwindow::window_width-50,0,50,mainwindow::window_height);
  obstacle *center = new obstacle(120,130,mainwindow::window_width-280, mainwindow::window_height-240);
  obstacleList.append(top);
  obstacleList.append(bottom);
  obstacleList.append(left);
  obstacleList.append(right);
  obstacleList.append(center);
/*  for(int x = 0; x <= mainwindow::window_width; x+=100) {
      obstacleList.append(new obstacle(x,x,x+100,x+100));
  }*/
  startPoint = QPoint(60,60);
  
}

QList< obstacle* > track::getObstacleList()
{
  return obstacleList;
}
