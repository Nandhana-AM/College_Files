// Producer-Consumer Problem Using Semaphores 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define BUFFER_SIZE 5
sem_t mutex,full,empty;
int buffer[BUFFER_SIZE];
int in=0,out=0;

void* producer (void* arg){
    for (int i=0;i<10;i++){
        usleep(100);
        int item=rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in]=item;
        printf("Produced: %d\n",item);
        in=(in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void* consumer(void* arg){
    for (int i=0;i<10;i++){
        sem_wait(&full);
        sem_wait(&mutex);

        int item=buffer[out];
        printf("Consumed: %d\n",item);
        out=(out+1)%BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);
        usleep(100);
    }
    return NULL;
}

int main(){
    pthread_t prod,cons;

    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);

    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);

    pthread_join(prod,NULL);
    pthread_join(cons,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}