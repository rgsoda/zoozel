#include <QtGui>
#include <QTimer>
#include <QDebug>
#include "player.h"
#include "scene.h"
#include "mainwindow.h"
#include "connection.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QString nickname;
    QString serverHost;
    QString serverPort;
    QString trackImageFileName;
    QString trackDataFileName;


    QStringList cmdline_args = QCoreApplication::arguments();

    if(cmdline_args.length() != 6) {
        qDebug("Usage :");
        qDebug("program path/to/track_bitmap.file path/to/track_dat.file nick serverHost serverPort");
        exit(-1);
    } else {
        trackImageFileName = cmdline_args[1];
        trackDataFileName = cmdline_args[2];
        nickname = cmdline_args[3];
        serverHost = cmdline_args[4];
        serverPort = cmdline_args[5];

    }
    connection *conn = new connection(serverHost, serverPort.toInt());
    if(!conn->bind()) {
        qDebug("Cannot connect to server");
        exit(-1);
    }

    player *localPlayer = new player(nickname);

    conn->loginPlayer(localPlayer);

    mainwindow *main = new mainwindow();
    main->setTrackInfo(trackImageFileName,trackDataFileName);



    main->show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), main, SLOT(advance()));
    QObject::connect(&timer, SIGNAL(timeout()), conn, SLOT(sendDatagram()));
    //QObject::connect(&timer, SIGNAL(timeout()), main, SLOT(movePlayer()));
    timer.start(1000 / 33);
    
    return app.exec();
  
}
