#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5

typedef enum{pense,a_faim,mange} philosophe;

struct tabin
{
    Table *T;
    int indice;
};

int gauche(int);
int droite(int);
void penser(int);
void avoir_faim(tabin*);
void manger(int);
void test(int);
void prendre_fourchettes(tabin*);
void poser_fourchettes(tabin*);

