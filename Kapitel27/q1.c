#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "mythreads.h"

    typedef struct __counter_t
    {
        int value;
        pthread_mutex_t lock;

    } counter_t;

    void init(counter_t * c)
    {
        c->value = 0;
        Pthread_mutex_init(&c->lock, NULL);
    }

    void increment(counter_t * c)
    {
        Pthread_mutex_lock(&c->lock);
        c->value++;
        Pthread_mutex_unlock(&c->lock);
    }

    void decrement(counter_t * c)
    {
        Pthread_mutex_lock(&c->lock);
        c->value--;
        Pthread_mutex_unlock(&c->lock);
    }

    int get(counter_t * c)
    {
        Pthread_mutex_lock(&c->lock);
        int rc = c->value;
        Pthread_mutex_unlock(&c->lock);
        return rc;
    }

    void* worker(void* arg)
    {
        if (get(arg) < 10000){
            increment(arg);
        }
        return NULL;
    }

int main(int argc, char const *argv[])
{

   printf("Programm Start\n");

    double startS, startUS, stopS, stopUS, end, endS, endUS;
    struct timeval time;
    struct __counter_t *counter;

    if (gettimeofday(&time, NULL) < 0)
        return 1;

//START TIME


    pthread_t p1;
    init(counter);

    startS = time.tv_sec;
    startUS = time.tv_usec;

    Pthread_create(&p1, NULL, worker, (void *) counter);
    Pthread_join(p1, NULL);

    if (gettimeofday(&time, NULL) < 0)
        return 1;

// END
    stopS = time.tv_sec;
    stopUS = time.tv_usec;

    //printf("startS: %f\tstartUS: %f\n",startS,startUS);
    //printf("stopS: %f\tstopUS: %f\n",stopS,stopUS);

    endS = stopS - startS;
    endUS = stopUS - startUS;

    if (endUS < 0)
    {
        endUS += 1000000;
        endS--;
    }

    endUS = endUS / 1000000;

    end = endS + endUS;

    printf("Time: %f\n", end);

    printf("Programm Finished\n");
    return 0;
}
