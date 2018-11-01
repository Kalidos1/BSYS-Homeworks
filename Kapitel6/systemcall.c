#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sched.h>



int main(int argc, char const *argv[])
{
    int counter = 1000000;
    double start,stop,startpipe,stoppipe;
    struct timeval time;
    int p, nbytes;
    int pipem[2];
    char* string = "Hello, Test";
    char readbuffer[100];
    pid_t childpid;

    cpu_set_t  mask;
    CPU_ZERO(&mask);
    unsigned int lenght = sizeof(mask);
    CPU_SET(0, &mask);

    gettimeofday(&time,NULL);
    start = time.tv_sec + time.tv_usec;

    for (int i = 0; i <= counter; i++) {    
        p = (int) getpid();
    }
    
    gettimeofday(&time,NULL);
    startpipe = time.tv_sec + time.tv_usec;

    printf("\nSystemcalltime: %.5f\n", ((stop - start) / counter));
    
    pipe(pipem);
    
    if ((childpid =fork()) == -1) {
        // fork failed; exit
        perror("fork");
        exit(1);
    }
    gettimeofday(&time,NULL);
    startpipe = time.tv_sec + time.tv_usec;
    if ((sched_setaffinity(0,lenght,&mask)) < 1) {
        if (childpid == 0) {
            close(pipem[0]);
            write(pipem[1],string, strlen(string) + 1);
            exit(0);
        } else {
            nbytes = read(pipem[0],readbuffer,sizeof(readbuffer));
            gettimeofday(&time,NULL);
            stoppipe = time.tv_sec + time.tv_usec;

            printf("Received via Pipe: %s\n", readbuffer);
            printf("ContextSwitch Time: %.5f \n", stoppipe - startpipe);
            close(pipem[1]);
        }
    }

    return 0;
}



