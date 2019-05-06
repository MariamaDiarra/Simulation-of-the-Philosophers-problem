#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "table.h"

Table::Table():QGraphicsEllipseItem(0,0,rad,rad)
{
    p1->setParentItem(this);
    p2->setParentItem(this);
    p3->setParentItem(this);
    p4->setParentItem(this);
    p5->setParentItem(this);
    int xref=0;
    float yref=rad/2;
    float angle=1.2566370;
    p1->setPos(xref,yref);
    p2->setPos(rad*(1-cos(angle))/2,yref+rad*sin(angle)/2- rad/8);
    p3->setPos(rad*(1-cos(2*angle))/2- rad/8,yref+rad*sin(2*angle)/2- rad/10);
    p4->setPos(rad*(1-cos(3*angle))/2- rad/10,yref+rad*sin(3*angle)/2);
    p5->setPos(rad*(1-cos(4*angle))/2,yref+rad*sin(4*angle)/2);

    float rayonf2=rad*2/3;
    float rayonf1=rad/3;
    float anglef=angle/2;
    float yfref2=yref+rayonf2*sin(anglef);
    float yfref1=yref+rayonf1*sin(anglef);
    float xfref2=rad/2-rayonf2*cos(anglef);
    float xfref1=rad/2-rayonf1*cos(anglef);
    f1->setLine(xfref1,yfref1,xfref2,yfref2);
    f1->setPen( QPen(Qt::black, 1.5) );

    yfref2=yref+rayonf2*sin(3*anglef);
    yfref1=yref+rayonf1*sin(3*anglef);
    xfref2=rad/2-rayonf2*cos(3*anglef);
    xfref1=rad/2-rayonf1*cos(3*anglef);
    f2->setLine(xfref1,yfref1,xfref2,yfref2);
    f2->setPen( QPen(Qt::black, 1.5) );

    yfref2=yref+rayonf2*sin(5*anglef);
    yfref1=yref+rayonf1*sin(5*anglef);
    xfref2=rad/2-rayonf2*cos(5*anglef);
    xfref1=rad/2-rayonf1*cos(5*anglef);
    f3->setLine(xfref1,yfref1,xfref2,yfref2);
    f3->setPen( QPen(Qt::black, 1.5) );

    yfref2=yref+rayonf2*sin(7*anglef);
    yfref1=yref+rayonf1*sin(7*anglef);
    xfref2=rad/2-rayonf2*cos(7*anglef);
    xfref1=rad/2-rayonf1*cos(7*anglef);
    f4->setLine(xfref1,yfref1,xfref2,yfref2);
    f4->setPen( QPen(Qt::black, 1.5) );

    yfref2=yref+rayonf2*sin(9*anglef);
    yfref1=yref+rayonf1*sin(9*anglef);
    xfref2=rad/2-rayonf2*cos(9*anglef);
    xfref1=rad/2-rayonf1*cos(9*anglef);
    f5->setLine(xfref1,yfref1,xfref2,yfref2);
    f5->setPen( QPen(Qt::black, 1.5) );

    f1->setParentItem(this);
    f2->setParentItem(this);
    f3->setParentItem(this);
    f4->setParentItem(this);
    f5->setParentItem(this);

    QGraphicsScene *scene=new QGraphicsScene;
    scene->addItem(this);
    QGraphicsView *view=new QGraphicsView(scene);
    view->show();
}
