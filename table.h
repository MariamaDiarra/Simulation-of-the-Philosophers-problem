#include "philosophe.h"
#ifndef TABLE_H
#define TABLE_H

class Table:public QGraphicsEllipseItem
{
public:
    Philosophe *p1=new Philosophe(1, 0);
    Philosophe *p2=new Philosophe(2, 1.2566370);
    Philosophe *p3=new Philosophe(3, 2*1.2566370);
    Philosophe *p4=new Philosophe(4, 3*1.2566370);
    Philosophe *p5=new Philosophe(5, 4*1.2566370);

    Fourchette *f1=new Fourchette();
    Fourchette *f2=new Fourchette();
    Fourchette *f3=new Fourchette();
    Fourchette *f4=new Fourchette();
    Fourchette *f5=new Fourchette();

    Table();
    void start();

};

#endif // TABLE_H
