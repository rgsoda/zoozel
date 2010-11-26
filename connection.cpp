#include <QDebug>

#include "connection.h"
#include "mainwindow.h"

connection::connection(QString host, quint16 port, quint16 localPort)
{
    this->serverHostame = host;
    this->serverPort = port;
    this->localPort = localPort;
    udpSocket = new QUdpSocket();

    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));

}

void connection::loginPlayer(player *p) {
    qDebug() << "Sending loginPlayer datagram ";
    this->localPlayer = p;

    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);
    out << QString("NEW_PLAYER") << localPlayer->nick;

    qint64 res = udpSocket->writeDatagram(datagram, QHostAddress(this->serverHostame), this->serverPort);
    if(res!=-1) {
        qDebug() << "Login info sended";
    }


}

bool connection::bind() {
    return udpSocket->bind(QHostAddress::Any,this->localPort);
}

void connection::sendDatagram() {
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);

    out << QString("POS_UPDATE") << localPlayer->nick << localPlayer->pos() << localPlayer->rotation();
    udpSocket->writeDatagram(datagram, QHostAddress(this->serverHostame), this->serverPort);
}

void connection::sendReadyDatagram() {
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);

    out << QString("PLAYER_READY") << localPlayer->nick;
    udpSocket->writeDatagram(datagram, QHostAddress(this->serverHostame), this->serverPort);
}

void connection::processPendingDatagrams() {
    QByteArray datagram;
    do {
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
    } while (udpSocket->hasPendingDatagrams());

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_1);

    QString messageType;
    in >> messageType;
    //qDebug() << "DATAGRAM ARIVED : " << messageType;
    if(messageType == "PLAYER_LIST") {
        QList<QString> playerNames;
        in >> playerNames;
        qDebug() << "PLAYER_LIST_DATAGAM" << playerNames;
        qDebug() << "adding players " << playerNames;
        foreach(QString playerName,playerNames) {
            player *p = new player(playerName);
            dynamic_cast<mainwindow*>(this->parent())->s->putPlayer(p,false);
            netPlayers.append(p);
        }
        sendReadyDatagram();
    }

    if(messageType == "PLAYER_CONNECTED") {
        QString newPlayerNick;
        in >> newPlayerNick;
        qDebug() << "player connected : " << newPlayerNick;
        player *p = new player(newPlayerNick);
        dynamic_cast<mainwindow*>(this->parent())->s->putPlayer(p,false);
        netPlayers.append(p);
    }

    if(messageType == "POS_UPDATE") {
        QString nick;
        QPointF pos;
        qreal angle;

        in >> nick >> pos >> angle;
        //qDebug() << nick << pos << angle;
        foreach(player *player,netPlayers) {
            if (player != localPlayer) {
                player->setPos(pos);
                player->setRotation(angle);
            }
        }
    }

}
