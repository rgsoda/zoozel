
#include "mainwindow.h"


mainwindow::mainwindow()
{
  
  s = new scene;
  setCentralWidget(s);
  resize(870,600);

  actions.insert( Qt::Key_W, Accelerate );
  actions.insert( Qt::Key_A, RotateLeft );
  actions.insert( Qt::Key_D, RotateRight );
  actions.insert( Qt::Key_S, Brake );
  
}



void mainwindow::keyPressEvent( QKeyEvent *event )
{
    if (  !actions.contains( event->key() ) )
    {
        event->ignore();
        return;
    }

    Action a = actions[ event->key() ];

    switch ( a )
    {
        case RotateLeft:
            this->s->rotatePlayerLeft();
            break;

        case RotateRight:
            this->s->rotatePlayerRigh();
            break;

        case Accelerate:
            this->s->acceleratePlayer();
            break;

        case Brake:
            this->s->brakePlayer();
            break;

        default:
            event->ignore();
            return;
    }
    event->accept();
}

void mainwindow::keyReleaseEvent( QKeyEvent *event )
{
    event->accept();
}


