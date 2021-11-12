#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_cond  = PTHREAD_COND_INITIALIZER;

void *WestGateEntry();
void *WestGateExit();
void *EastGateEntry();
void *EastGateExit();
static int  count = 0;
#define COUNT_DONE  99
#define COUNT_HALT1  3
#define COUNT_HALT2  6

int main()
{
   #pragma omp parallel num_threads(8)
   {

   pthread_t thread1, thread2,thread3,thread4;

   pthread_create( &thread1, NULL, &WestGateEntry, NULL);
   pthread_create( &thread2, NULL, &WestGateExit, NULL);
   pthread_create( &thread3, NULL, &EastGateEntry, NULL);
   pthread_create( &thread4, NULL, &EastGateExit, NULL);
   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);
   pthread_join( thread3, NULL);
   pthread_join( thread4, NULL);
   }
   exit(0);
}

void *WestGateEntry()
{
   for(;;)
   {

      pthread_mutex_lock( &count_mutex );
      count++;
      printf("Total Visitors inside the Garden[West Gate Entry]: %d\n",count);
      pthread_mutex_unlock( &count_mutex );

      if(count >= COUNT_DONE)
	  {
		  return(NULL);
	  }
   }
}

void *WestGateExit()
{
   for(;;)
   {


      pthread_mutex_lock( &count_mutex );
      count--;
      printf("Total Visitors inside the Garden[West Gate Exit]: %d\n",count);
      pthread_mutex_unlock( &count_mutex );

      if(count <= 0)
	  {
		  return(NULL);
	  }
   }
}

void *EastGateEntry()
{
    for(;;)
    {


       pthread_mutex_lock( &count_mutex );
       count++;
       printf("Total Visitors inside the Garden[East Gate Entry]: %d\n",count);
       pthread_mutex_unlock( &count_mutex );

       if(count >= COUNT_DONE) return(NULL);
    }

}

void *EastGateExit()
{
    for(;;)
    {


       pthread_mutex_lock( &count_mutex );
       count--;
       printf("Total Visitors inside the Garden[East Gate Exit]: %d\n",count);
       pthread_mutex_unlock( &count_mutex );

       if(count <= 0)
	  {
		  return(NULL);
	  }
    }

}

