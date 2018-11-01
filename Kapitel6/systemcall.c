#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int counter = 100000;
    int time1,time2,time3;
    
    time1 = gettimeofday();

    for (int i = 0; i < counter; i++) {
        (int) getpid();
    }
    
    time2 = gettimeofday();

    time3 = (time2 - time1) / counter;
    printf("\nSystemcalltime: " + time3);
    

    return 0;
}
