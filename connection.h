#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtNetwork>
#include <player.h>

class connection : public QObject
{
    Q_OBJECT

public:
    connection(QString host, quint16 port,quint16 localPort);
    bool bind();
    void loginPlayer(player *p);
private:
    QUdpSocket *udpSocket;
    player *localPlayer;
    QString serverHostame;
    quint16 serverPort;
    quint16 localPort;
    QList<player*> netPlayers;
    void sendReadyDatagram();

public slots:
    void processPendingDatagrams();
    void sendDatagram();

};

#endif // CONNECTION_H
