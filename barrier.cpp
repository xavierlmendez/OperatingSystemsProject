// hxh190024

#include "barrier.h"
#include <iostream>
using namespace synchronization;



   
barrier::barrier( int numberOfThreads ) {
   waiting = 0;
   numOfProcess = numberOfThreads;
   sem_init(&Lock, 0, 1);
   sem_init(&Gate1, 0, 0);
   sem_init(&Gate2, 0, 1);
   return;
}

barrier::~barrier( ) {

   return;
}

void barrier::arriveAndWait( void ) {
   sem_wait(&Lock);
   waiting++;
   if(waiting == numOfProcess){
      sem_wait(&Gate2);
      sem_post(&Gate1);
   }
   sem_post(&Lock);
   sem_wait(&Gate1);
   sem_post(&Gate1);
   
   sem_wait(&Lock);
   waiting--;
   
   if(waiting == 0 ){
      sem_post(&Gate2);
      sem_wait(&Gate1);
   }
   sem_post(&Lock);
   sem_wait(&Gate2);
   sem_post(&Gate2);
   
   return;
}


