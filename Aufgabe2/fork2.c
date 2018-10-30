#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{   
    printf("hello world (pid:%d)\n", (int) getpid());   
    int rc = fork(); 
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child1 (pid:%d)\n",  (int) getpid());
    } else {
        // parent goes down this path (original process)
        // fork here to get a 2nd child then create array[1] with input/output for both children   
        // then pipe with this array and create a connection between those 2 children       
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
     
        
    }
    return 0;
}