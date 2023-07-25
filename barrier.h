//hxh190024

#ifndef BARRIER_H
#define BARRIER_H


#include <semaphore.h>

namespace synchronization
{

   // Provides a reusable barrier
   class barrier {
   private:
      int waiting;
      int numOfProcess;
      sem_t Lock;
      sem_t Gate1;
      sem_t Gate2;

   public:

      // Constructor
      barrier( int numberOfThreads );

      // Destructor
      ~barrier( );

      // Function to wait at the barrier until all threads have reached the barrier
      void arriveAndWait( void );
   };

}

#endif
