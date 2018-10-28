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
    int rc2 = fork();    
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0 && rc2 != 0) {
        // child (new process)
        printf("hello, I am child1 (pid:%d)\n",  (int) getpid());
    } else if (rc2 == 0 && rc != 0) {
        printf("hello, I am child2 (pid:%d)\n",  (int) getpid());
    } else {
        // parent goes down this path (original process)
        if (rc > 0) {
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
        } else if (rc2 > 0)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc2, (int) getpid());
        
    }
    return 0;
}