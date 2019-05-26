#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "mythreads.h"
#include <sys/syscall.h>


typedef struct __counter_t
{
    int global;                     // global count
    pthread_mutex_t glock;          // global lock
    int local[4];             // local count (per cpu)
    pthread_mutex_t llock[4]; // ... and locks
    int threshold;                  // update frequency
} counter_t;
// init: record threshold, init locks, init values
// of all local counts and global count
void init(counter_t *c, int threshold)
{
    c->threshold = threshold;
    c->global = 0;
    pthread_mutex_init(&c->glock, NULL);
    int i;
    for (i = 0; i < 4; i++)
    {
        c->local[i] = 0;
        pthread_mutex_init(&c->llock[i], NULL);
    }
}

// update: usually, just grab local lock and update local amount
// once local count has risen by â€™thresholdâ€™, grab global
// lock and transfer local values to it
void update(counter_t *c, int threadID, int amt)
{
    int cpu = threadID % 4;
    pthread_mutex_lock(&c->llock[cpu]);
    c->local[cpu] += amt; // assumes amt > 0
    if (c->local[cpu] >= c->threshold)
    { // transfer to global
        pthread_mutex_lock(&c->glock);
        c->global += c->local[cpu];
        pthread_mutex_unlock(&c->glock);
        c->local[cpu] = 0;
    }
    pthread_mutex_unlock(&c->llock[cpu]);
}

// get: just return global amount (which may not be perfect)
int get(counter_t *c)
{
    pthread_mutex_lock(&c->glock);
    int val = c->global;
    pthread_mutex_unlock(&c->glock);
    return val; // only approximate!
}

void *worker(void *arg)
{
    int tid = syscall(SYS_gettid);
    while (get(arg) < 100000000) // Abfrage falsch (Manchmal 1 Mehr als erwartet)
    { 
        update(arg,tid,1);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{

    printf("Programm Start\n");

    double startS, startUS, stopS, stopUS, end, endS, endUS;
    struct timeval time;
    struct __counter_t *counter = (counter_t *)malloc(sizeof(counter_t));

    if (gettimeofday(&time, NULL) < 0)
        return 1;

    //START TIME

    pthread_t p1, p2, p3;
    init(counter,1);

    startS = time.tv_sec;
    startUS = time.tv_usec;

    Pthread_create(&p1, NULL, worker, (void *)counter);
    Pthread_create(&p2, NULL, worker, (void *)counter);
    Pthread_create(&p3, NULL, worker, (void *)counter);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    Pthread_join(p3, NULL);

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
    printf("Counter: %d\n ", counter->global);
    printf("Programm Finished\n");
    return 0;
}
