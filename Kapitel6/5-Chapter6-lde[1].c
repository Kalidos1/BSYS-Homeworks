//GruppenNR 5 - Goehring Andre,Marvin Klett
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>




int main(int argc, char const *argv[])
{
    int counter = 1000000;
    double start,stop,testtime;
    struct timeval time;
    int p;  
    

    gettimeofday(&time,NULL);
    start = time.tv_sec + time.tv_usec;

    for (int i = 0; i <= counter; i++) {    
        p = (int) getpid();
    }
    
    gettimeofday(&time,NULL);
    stop = time.tv_sec + time.tv_usec;
    testtime = ((stop - start) / counter);
    printf("\nSystemcalltime: %.5f\n", testtime);      

    return 0;
}



