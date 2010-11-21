
#include "mainwindow.h"


mainwindow::mainwindow()
    : keyUp(false), keyDown(false), keyLeft(false), keyRight(false)
{

    s = new scene;
    setCentralWidget ( s );
    resize ( 870,600 );
    setAttribute(Qt::WA_KeyCompression);


 
}



void mainwindow::keyPressEvent ( QKeyEvent *event )
{

    switch ( event->key() )
    {
    case Qt::Key_O:
        keyLeft = true;
        break;
    case Qt::Key_P:
        keyRight = true;
        break;
    case Qt::Key_Q:
        keyUp = true;
        break;
    case Qt::Key_A:
        keyDown = true;
        break;
    default:
        return;
    }
    movePlayer();
}

void mainwindow::keyReleaseEvent ( QKeyEvent *event )
{

    if ( !event->isAutoRepeat() )
    {
        switch ( event->key() )
        {
        case Qt::Key_O:
	    keyLeft = false;
            break;
        case Qt::Key_P:
            keyRight = false;
            break;
        case Qt::Key_Q:
            keyUp = false;
            break;
        case Qt::Key_A:
            keyDown = false;
            break;
        default:
            return;
        }
    }
    movePlayer();
}


void mainwindow::movePlayer()
{
    if ( keyLeft ) { s->rotatePlayerLeft(); }
    else if ( keyRight ) s->rotatePlayerRigh();
    if ( keyDown ) s->brakePlayer();
    else if ( keyUp ) s->acceleratePlayer();
}
