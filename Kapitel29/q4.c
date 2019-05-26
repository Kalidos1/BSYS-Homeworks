#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "mythreads.h"
#include <sys/syscall.h>

// basic node structure
typedef struct __node_t
{
    int key;
    struct __node_t *next;
} node_t;

// basic list structure (one used per list)
typedef struct __list_t
{
    node_t *head;
    pthread_mutex_t lock;
} list_t;

void List_Init(list_t *L)
{
    L->head = NULL;
    pthread_mutex_init(&L->lock, NULL);
}

void List_Insert(list_t *L, int key)
{
    // synchronization not needed
    node_t *new = malloc(sizeof(node_t));
    if (new == NULL)
    {
        perror("malloc");
        return;
    }
    new->key = key;

    // just lock critical section
    pthread_mutex_lock(&L->lock);
    new->next = L->head;
    L->head = new;
    pthread_mutex_unlock(&L->lock);
}

int List_Lookup(list_t *L, int key)
{
    int rv = -1;
    pthread_mutex_lock(&L->lock);
    node_t *curr = L->head;
    while (curr)
    {
        if (curr->key == key)
        {
            rv = 0;
            break;
        }
        curr = curr->next;
    }
    pthread_mutex_unlock(&L->lock);
    return rv; // now both success and failure
}

void *worker(void *arg)
{
    int count = 0;
    while (List_Lookup(arg,30000) == -1)
    {
        if (List_Lookup(arg,count) == -1){ 
        List_Insert(arg,count);
        } 
        count++;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{

    printf("Programm Start\n");

    double startS, startUS, stopS, stopUS, end, endS, endUS;
    struct timeval time;
    struct __list_t *list = (list_t *)malloc(sizeof(list_t));

    if (gettimeofday(&time, NULL) < 0)
        return 1;

    //START TIME

    pthread_t p1, p2, p3;
    List_Init(list);

    startS = time.tv_sec;
    startUS = time.tv_usec;

    Pthread_create(&p1, NULL, worker, (void *)list);
    Pthread_create(&p2, NULL, worker, (void *)list);
    Pthread_create(&p3, NULL, worker, (void *)list);
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
    printf("Counter: %d\n ", List_Lookup(list,10000));
    printf("Programm Finished\n");
    return 0;
}
