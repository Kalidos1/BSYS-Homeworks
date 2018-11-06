#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = NULL;
    int *pointint = &i;

    printf("%d", *pointint);
    return 0;
}
