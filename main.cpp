#include "mainwindow.h"
#include <QApplication>
#include <time.h>
#include "scene.h"

sem_t s[N]={0,0,0,0,0};

pthread_mutex_t mutex;

philosophe p[N]={pense,pense,pense,pense,pense};

pthread_t tid[N];

int gauche(int i){
    return ((i+N-1)%N);
}
int droite(int i){
    return	((i+1)%N);
}

void test(int i){
    if((p[i]==a_faim)&&(p[gauche(i)]!=mange)&&(p[droite(i)]!=mange)){
        p[i]=mange;
        sem_post(&s[i]);
    }
}

void prendre_fourchettes(tabin* T){
    pthread_mutex_lock(&mutex);
    p[T->indice]=a_faim;
    printf("philosophe %d : j'ai faim\n",T->indice+1);
    test(T->indice);
    pthread_mutex_unlock(&mutex);
    sem_wait(&s[T->indice]);
    pthread_mutex_lock(&mutex);
    int i=T->indice;
    switch (i) {
        case 0:T->T->f1->hide();T->T->f5->hide();T->T->p1->showFourchette(); break;
        case 1:T->T->f2->hide();T->T->f1->hide();T->T->p2->showFourchette();break;
        case 2:T->T->f3->hide();T->T->f2->hide();T->T->p3->showFourchette();break;
        case 3:T->T->f4->hide();T->T->f3->hide();T->T->p4->showFourchette();break;
        case 4:T->T->f5->hide();T->T->f4->hide();T->T->p5->showFourchette();break;
        default: break;
    }
    printf("philosophe %d : j'ai pris mes fourchette:\n",T->indice+1);
    pthread_mutex_unlock(&mutex);
}

void poser_fourchettes(tabin* T){
    pthread_mutex_lock(&mutex);
    p[T->indice]=pense;
    printf("philosophe %d : j'ai plus faim\n",T->indice+1);
    test(gauche(T->indice));
    test(droite(T->indice));
    int i=T->indice;
    switch (i) {
        case 0:T->T->f1->show();T->T->f5->show();T->T->p1->hideFourchette(); break;
        case 1:T->T->f2->show();T->T->f1->show();T->T->p2->hideFourchette();break;
        case 2:T->T->f3->show();T->T->f2->show();T->T->p3->hideFourchette();break;
        case 3:T->T->f4->show();T->T->f3->show();T->T->p4->hideFourchette();break;
        case 4:T->T->f5->show();T->T->f4->show();T->T->p5->hideFourchette();break;
        default: break;
    }
    printf("philosophe %d : j'ai poser mes fourchette:\n",T->indice+1);
    pthread_mutex_unlock(&mutex);
}

void penser(int i){
    int n=rand()%20;
    sleep(n);
}

void avoir_faim(tabin* T){

    printf("philosophe %d : je mange\n",T->indice+1);
    int i=T->indice;
    switch (i) {
        case 0:T->T->p1->hungry();break;
        case 1:T->T->p2->hungry(); break;
        case 2:T->T->p3->hungry();break;
        case 3:T->T->p4->hungry();break;
        case 4:T->T->p5->hungry();break;
        default: break;
    }
    printf("philosophe %d : je ne mange plus\n",T->indice+1);

}

void manger(int i){
    int n=rand()%20;
    sleep(n);
}

void* philosopher(void* t){
    tabin *philo=(tabin *) t;
    while(1){
        printf("philosophe %d\n",philo->indice +1);
        penser(philo->indice);
        avoir_faim(philo);
        prendre_fourchettes(philo);
        manger(philo->indice);
        poser_fourchettes(philo);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    Table* t=new Table();
    tabin *philo1=new tabin;
    tabin *philo2=new tabin;
    tabin *philo3=new tabin;
    tabin *philo4=new tabin;
    tabin *philo0=new tabin;
    philo0->T=t;
    philo1->T=t;
    philo2->T=t;
    philo3->T=t;
    philo4->T=t;
    philo0->indice=0;
    philo1->indice=1;
    philo2->indice=2;
    philo3->indice=3;
    philo4->indice=4;

    int i=0;
    for(i=0;i<N;i++){
        if(sem_init(&s[i],0,0)!=0){
            perror("ERREUR");
            exit(-1);
        }
    }
    i=0;
    if(pthread_mutex_init(&mutex,NULL)!=0){
        perror("ERREUR");
        exit(-1);
    }
     pthread_create(tid,NULL,philosopher,(tabin*) philo0);
     pthread_create(tid+1,NULL,philosopher,(tabin*) philo1);
     pthread_create(tid+2,NULL,philosopher,(tabin*) philo2);
     pthread_create(tid+3,NULL,philosopher,(tabin*) philo3);
     pthread_create(tid+4,NULL,philosopher,(tabin*) philo4);

    for(i=0;i<N;i++){
        //pthread_join(tid[i],NULL);
    }
    return a.exec();
}
