#include "assiette.h"
#ifndef PHILOSOPHE_H
#define PHILOSOPHE_H


class Philosophe:public QGraphicsEllipseItem
{
private:
    Assiette *assiette;
    QGraphicsTextItem *numero;
    Fourchette *fourchette1;
    Fourchette *fourchette2;
public:
    Philosophe(int, float);
    void hungry();
    void showFourchette();
    void hideFourchette();
};

#endif // PHILOSOPHE_H
