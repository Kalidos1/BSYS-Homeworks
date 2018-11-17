#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{ 
    int *data = (int*) malloc (100 * sizeof(int));
    data[100] = 0;
    int *pointer = &data[50];
    free(pointer);
    return 0;
}
