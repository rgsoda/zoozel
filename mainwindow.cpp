
#include "mainwindow.h"



mainwindow::mainwindow()
    : keyUp(false), keyDown(false), keyLeft(false), keyRight(false)
{
    s = new scene;
    s->setParent(this);
    setCentralWidget ( s );
    setAttribute(Qt::WA_KeyCompression);



}



void mainwindow::keyPressEvent ( QKeyEvent *event )
{

    switch ( event->key() )
    {
    case Qt::Key_J:
        keyLeft = true;
        break;
    case Qt::Key_L:
        keyRight = true;
        break;
    case Qt::Key_I:
        keyUp = true;
        break;
    case Qt::Key_K:
        keyDown = true;
        break;
    case Qt::Key_Escape:
        exit(0);
    default:
        return;
    }
}

void mainwindow::keyReleaseEvent ( QKeyEvent *event )
{

    if ( !event->isAutoRepeat() )
    {
        switch ( event->key() )
        {
        case Qt::Key_J:
            keyLeft = false;
            break;
        case Qt::Key_L:
            keyRight = false;
            break;
        case Qt::Key_I:
            keyUp = false;
            break;
        case Qt::Key_K:
            keyDown = false;
            break;
        default:
            return;
        }
    }
}

void mainwindow::advance()
{
    movePlayer();
    s->getScene()->advance();
}

void mainwindow::movePlayer()
{
    if ( keyLeft ) { s->rotatePlayerLeft(); }
    else if ( keyRight ) s->rotatePlayerRight();
    if ( keyDown ) s->brakePlayer();
    else if ( keyUp ) s->acceleratePlayer();
}


void mainwindow::setTrackInfo(QString image, QString data) {
    this->trackImageFileName = image;
    s->setTrackImage(image);
    this->trackDataFileName = data;
    s->setTrackData(data);
}


void mainwindow::putPlayerOnScene(player *p, bool local) {
    s->putPlayer(p,local);
}
