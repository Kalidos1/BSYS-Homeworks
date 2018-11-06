//GruppenNR 5 - Goehring Andre,Marvin Klett
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

    double startpipe,stoppipe;
    struct timeval time;
    int nbytes;
    int pipem[2];
    char* string = "Hallo, Test";
    char readbuffer[100];
    pid_t childpid;

    cpu_set_t  process;
    CPU_ZERO(&process);
    unsigned int lenght = sizeof(process);
    CPU_SET(0, &process);

  
    pipe(pipem);
    
    if ((childpid = fork()) == -1) {    
        perror("fork");
        exit(1);
    }
    gettimeofday(&time,NULL);
    startpipe = time.tv_sec + time.tv_usec;
    if ((sched_setaffinity(0,lenght,&process)) < 1) {
        if (childpid == 0) {
            close(pipem[1]);
            nbytes = read(pipem[0],readbuffer,sizeof(readbuffer));
            printf("Received String: %s ", nbytes);
            exit(0);
        } else {
            close(pipem[0]);
            write(pipem[1], string, strlen(string) + 1);
            gettimeofday(&time,NULL);
            stoppipe = time.tv_sec + time.tv_usec;        
            printf("ContextSwitch Time: %.5f \n", (stoppipe - startpipe));
            close(pipem[1]);
            wait(0);
        }
    }

    return 0;
}
