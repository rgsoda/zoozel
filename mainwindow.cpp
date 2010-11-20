
#include "mainwindow.h"


mainwindow::mainwindow()
{

    s = new scene;
    setCentralWidget ( s );
    resize ( 870,600 );
    //this->setAttribute(Qt::WA_KeyCompression);
    actions.insert ( Qt::Key_W, Accelerate );
    actions.insert ( Qt::Key_A, RotateLeft );
    actions.insert ( Qt::Key_D, RotateRight );
    actions.insert ( Qt::Key_S, Brake );


    QTimer timer;
    QObject::connect ( &timer, SIGNAL ( timeout() ), this, SLOT ( movePlayer() ) );
    timer.start ( 1000 / 33 );

}



void mainwindow::keyPressEvent ( QKeyEvent *event )
{

    switch ( event->key() )
    {
    case Qt::Key_Left:
        keyLeft = true;
        break;
    case Qt::Key_Right:
        keyRight = true;
        break;
    case Qt::Key_Up:
        keyUp = true;
        break;
    case Qt::Key_Down:
        keyDown = true;
        break;
    }
}

void mainwindow::keyReleaseEvent ( QKeyEvent *event )
{

    if ( !event->isAutoRepeat() )
    {
        switch ( event->key() )
        {
        case Qt::Key_Left:
            keyLeft = false;
            break;
        case Qt::Key_Right:
            keyRight = false;
            break;
        case Qt::Key_Up:
            keyUp = false;
            break;
        case Qt::Key_Down:
            keyDown = false;
            break;
        }
    }
}


void mainwindow::movePlayer()
{
    if ( keyLeft ) { s->rotatePlayerLeft(); }
    else if ( keyRight ) s->rotatePlayerRigh();
    if ( keyDown ) s->brakePlayer();
    else if ( keyUp ) s->acceleratePlayer();
}
