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
    int x = 100;    
    int rc = fork();    
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        x += 55;
        printf("Value of x:%d\n", x);  
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        
    } else {
        // parent goes down this path (original process)
        x += 45;
        int wc = wait(NULL);
        printf("Value of x:%d\n", x);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
           
           
    }
    return 0;
}