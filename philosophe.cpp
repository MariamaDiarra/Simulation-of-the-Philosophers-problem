#include "philosophe.h"
#include <unistd.h>

Philosophe::Philosophe(int num, float angle):QGraphicsEllipseItem(0,0,0,0)
{
    fourchette1=new Fourchette();
    fourchette2=new Fourchette();
    assiette=new Assiette();
    fourchette1->setLine(radAssiette/2,radAssiette/4,-radAssiette,radAssiette);
    fourchette2->setLine(radAssiette/2,radAssiette*3/4,-radAssiette,radAssiette);
    fourchette1->setParentItem(assiette);
    fourchette2->setParentItem(assiette);
    hideFourchette();
    assiette->setParentItem(this);
    assiette->setBrush( QBrush(Qt::blue) );
    numero=new QGraphicsTextItem();
    numero->setParentItem(this);
    numero->setPos(radAssiette/3,radAssiette/2);
    numero->setPlainText(QString::number(num));
}
void Philosophe::showFourchette(){
    fourchette1->show();
    assiette->setBrush( QBrush(Qt::green) );
    fourchette2->show();
    assiette->setBrush( QBrush(Qt::green) );
}
void Philosophe::hideFourchette(){
    fourchette1->hide();
    assiette->setBrush( QBrush(Qt::blue) );
    fourchette2->hide();
    assiette->setBrush( QBrush(Qt::blue) );
}

void Philosophe::hungry(){

    assiette->setBrush( QBrush(Qt::red) );
}
