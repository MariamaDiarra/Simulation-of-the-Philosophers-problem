#include<iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QGraphicsItem>
#include <math.h>
using namespace std;
#define rad 400
#define flen rad/20
#ifndef FOURCHETTE_H
#define FOURCHETTE_H


class Fourchette:public QGraphicsLineItem
{
public:
    Fourchette();
};

#endif // FOURCHETTE_H
