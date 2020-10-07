/*  Compile: gcc prodcon.c -lpthread
    run: ./a.out 10 10 10 */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef int buffer_item;
#define BUFFER_SIZE 5

#define RAND_DIVISOR 100000000
#define TRUE 1

pthread_mutex_t mutex; // the mutex lock
sem_t full, empty; // the semaphores

buffer_item buffer[BUFFER_SIZE]; // the buffer

int counter;

pthread_t tid; // thread id
pthread_attr_t attr; // set of thread attributes

void *producer(void *param); // producer thread
void *consumer(void *param); // consumer thread

void initializeData(){
  pthread_mutex_init(&mutex, NULL); // create mutex lock

  sem_init(&full,0,0); // Create the full semaphore and initialize to 0

  sem_init(&empty,0,BUFFER_SIZE); // Create the empty semaphore and initialize to BUFFER_SIZE

  pthread_attr_init(&attr); // get the default attributes

  counter=0; // init buffer
}

// add an item to the buffer
int insert_item(buffer_item item){
  /* when the buffer is not full add the item
     and increment the counter*/
  if(counter < BUFFER_SIZE){
    buffer[counter] = item;
    counter++;
    return 0;
  }
  else{
    return -1; // error the buffer is full
  }
}


// remove an item from the buffer
int remove_item(buffer_item *item){
  /* when the buffer is not empty remove the item
     and decrement the counter*/
  if(counter > 0){
    *item = buffer[(counter-1)];
    counter--;
    return 0;
  }
  else{
    return -1; // error buffer empty
  }
}


// producer thread
void *producer(void *param){
  buffer_item item;
  while(TRUE){
    int rNum= rand()/ RAND_DIVISOR;
    sleep(rNum); // sleep for random period of time

    item=rand(); //generate a random number

    sem_wait(&empty); // acquire an empty lock

    pthread_mutex_lock(&mutex); // acquire the mutex lock

    if(insert_item(item)){
      fprintf(stderr, "Producer report error condition");
    }
    else{
      printf("producer produced %d\n",item);
    }

    pthread_mutex_unlock(&mutex); //release the mutex lock

    sem_post(&full); // signal full
  }
}


// consumer thread
void *consumer(void *param){
  buffer_item item;
  while(TRUE){
    int rNum= rand()/ RAND_DIVISOR;
    sleep(rNum); // sleep for random period of time

    sem_wait(&full); // acquire an full lock

    pthread_mutex_lock(&mutex); // acquire the mutex lock

    if(remove_item(&item)){
      fprintf(stderr, "Consumer report error condition");
    }
    else{
      printf("Consumer consumed %d\n",item);
    }

    pthread_mutex_unlock(&mutex); //release the mutex lock

    sem_post(&empty); // signal empty
  }
}

int main(int argc, char *argv[]){
  int i; // loop counter
  if(argc !=4){
    fprintf(stderr,"USAGE:./main.out <INT> <INT> <INT>\n");
  }

  int mainSleepTime = atoi(argv[1]);
  int numProd = atoi(argv[2]); // number of producer threads
  int numCons = atoi(argv[3]); // number of consumer threads

  initializeData(); // initialize data

  // create the producer threads
  for(i=0;i<numProd;i++){
    pthread_create(&tid, &attr, producer, NULL);
  }

  // create the consumer threads
  for(i=0;i<numCons;i++){
    pthread_create(&tid, &attr, consumer, NULL);
  }

  sleep(mainSleepTime); // sleep for specified time
  exit(0);
}
