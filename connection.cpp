#include <QDebug>

#include "connection.h"

connection::connection(QString host, quint16 port)
{
    this->serverHostame = host;
    this->serverPort = port;
    udpSocket = new QUdpSocket();
    udpSocket->bind(QHostAddress::LocalHost,12345);

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
    //return udpSocket->bind(12345,QUdpSocket::ShareAddress);
    return true;
}

void connection::sendDatagram() {
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);

    out << QString("POS_UPDATE") << localPlayer->nick << localPlayer->x() << localPlayer->y();

    udpSocket->writeDatagram(datagram, QHostAddress(this->serverHostame), this->serverPort);


}


void connection::processPendingDatagrams() {
    QByteArray datagram;
    do {
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
    } while (udpSocket->hasPendingDatagrams());

    qDebug() << "datagram :" << datagram.data();
}
