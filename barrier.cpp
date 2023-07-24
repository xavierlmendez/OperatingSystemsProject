#include "barrier.h"
#include <iostream>
using namespace synchronization;



   
barrier::barrier( int numberOfThreads ) {
   std::cout << "starting barrier constructor\n";
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
   std::cout << "incrementing wait\n";
   waiting++;
   if(waiting == numOfProcess){
      sem_wait(&Gate2);
      sem_post(&Gate1);
   }
   std::cout << "1\n";
   sem_post(&Lock);
   std::cout << "2\n";
   sem_wait(&Gate1);
   std::cout << "3\n";
   sem_post(&Gate1);
   std::cout << "4\n";
   
   sem_wait(&Lock);
   std::cout<<"decrementing wait\n";
   waiting--;
   std::cout<<"waiting equals "<< waiting<< "\n";
   
   if(waiting == 0 ){
      sem_post(&Gate2);
      sem_wait(&Gate1);
   }
   sem_post(&Lock);
   sem_wait(&Gate2);
   sem_post(&Gate2);
   
   return;
}


