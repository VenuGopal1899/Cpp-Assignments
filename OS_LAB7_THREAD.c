#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
#include <pthread.h>

int NO_OF_THREADS=20;

int counter=1;
void *task1( void *x )
{
    printf("Thread is attached!  -  %d  \n",counter);
    counter++;
    pthread_exit(0);
}
void *task2( void *z )
{
    printf("Thread is detached ! - %d \n",counter);
    counter++;
    pthread_exit(0);
}

int main()
{
     pthread_t thid[NO_OF_THREADS];
     int  i,iret[NO_OF_THREADS],f_arg;

    /* Create independent threads each of which will execute function */

    for(i=0;i<NO_OF_THREADS;i++)
    {
        f_arg=i;
        if(i&1)
        iret[i] = pthread_create( &thid[i], NULL, task1, (void*) &f_arg);
        else
        {
            pthread_attr_t th_attr;
            pthread_attr_init(&th_attr);
            pthread_detach(&th_attr);
            iret[i] = pthread_create( &thid[i], &th_attr, task2, (void*) &f_arg);
        }
        sleep(1);
     
    }
     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

    for(i=0;i<NO_OF_THREADS;i=+2)
    {
        pthread_join( thid[i], NULL);
    }


}

