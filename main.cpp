#include <QtGui>
#include <QTimer>
#include "player.h"
#include "scene.h"
#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    
    QStringList cmdline_args = QCoreApplication::arguments();

    if(cmdline_args.length() != 3) {
        qDebug("Usage :");
        qDebug("program path/to/track_bitmap.file path/to/track_dat.file");
        return 0;
    }

    mainwindow *main = new mainwindow();
    main->setTrackInfo(cmdline_args[1],cmdline_args[2]);
    main->show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), main, SLOT(advance()));
    //QObject::connect(&timer, SIGNAL(timeout()), main, SLOT(movePlayer()));
    timer.start(1000 / 33);
    
    return app.exec();
  
}
