#include <QtGui>
#include <QTimer>
#include "player.h"
#include "scene.h"
#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    mainwindow *main = new mainwindow();
    main->show();
    
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), main, SLOT(advance()));
    //QObject::connect(&timer, SIGNAL(timeout()), main, SLOT(movePlayer()));
    timer.start(1000 / 33);
    
    return app.exec();
  
}
