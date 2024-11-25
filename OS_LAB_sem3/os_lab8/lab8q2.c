// Dining philosopher's problem

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define NUM_PHIL 5
sem_t chopsticks[NUM_PHIL];

void* philosopher (void* num){
    int id=*(int*)num;
    int left=id;
    int right=(id+1)%NUM_PHIL;

    for (int i=0;i<3;i++){
        printf("Philosopher %d is thinking...\n",id);
        sleep(rand()%2);
        printf("Philosopher %d is hungry and trying to pick up chopsticks...\n",id);
        sem_wait(&chopsticks[left]);
        sem_wait(&chopsticks[right]);
        printf("Philosopher %d is eating...\n",id);
        sleep(rand()%2);
        sem_post(&chopsticks[left]);
        sem_post(&chopsticks[right]);
        printf("Philosopher %d has finished and kep chopsticks down.\n",id);
    }
    return NULL;
}

int main(){
    pthread_t philosophers[NUM_PHIL];
    int ids[NUM_PHIL];

    for (int i=0;i<NUM_PHIL;i++){
        sem_init(&chopsticks[i],0,1);
    }
    for (int i=0;i<NUM_PHIL;i++){
        ids[i]=i;
        pthread_create(&philosophers[i],NULL,philosopher,&ids[i]);
    }
    for (int i=0;i<NUM_PHIL;i++){
        pthread_join(philosophers[i],NULL);
    }
    for (int i=0;i<NUM_PHIL;i++){
        sem_destroy(&chopsticks[i]);
    }
    return 0;
}