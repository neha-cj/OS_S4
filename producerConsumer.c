#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define MAX_ITEM 5

int buffer[BUFFER_SIZE];
int in=0,out =0;

sem_t mutex,empty,full;
void*producer(void*arg){
    int item;
    for(int i=0;i<MAX_ITEM;i++){
        item=rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in]=item;
        printf("Producer:%d\n",item);
        in = (in+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    pthread_exit(NULL);
}

void*consumer(void*arg){
    int item;
    for(int i=0;i<MAX_ITEM;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        item=buffer[out];
        out=(out+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    pthread_exit(NULL) ;
}

void main(){
    int NUM_PRODUCERS,NUM_CONSUMERS;
    printf("Enter the number of producers \n");
    scanf("%d",&NUM_PRODUCERS);
    printf("Enter the number of consumers \n");
    scanf("%d",&NUM_CONSUMERS);
    
    pthread_t producer_threads[NUM_PRODUCERS],consumer_threads[NUM_CONSUMERS];
    
    sem_init(&mutex,0,1);
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    
    for(int i=0;i<NUM_PRODUCERS;i++){
        pthread_create(&producer_threads[i],NULL,producer,NULL);
    }
    
    for(int i=0;i<NUM_CONSUMERS;i++){
        pthread_create(&consumer_threads[i],NULL,consumer,NULL);
    }
    for(int i=0;i<NUM_PRODUCERS;i++){
        pthread_join(producer_threads[i],NULL);
    }
    for(int i=0;i<NUM_CONSUMERS;i++){
        pthread_join(consumer_threads[i],NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);    
}


/*
OUTPUT

Enter the number of producers 
3
Enter the number of consumers 
2
Producer:83
Producer:86
Producer:77
Producer:15
Producer:35
Producer:93
Producer:86
Producer:92
Producer:49
Producer:21
Producer:62
Producer:27
Producer:90
Producer:63
Producer:59
*/
