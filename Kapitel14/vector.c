#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{ 
    int *varray,tmp,a;    
    
    varray = (int*) malloc(5 * sizeof(int));
    printf("Gebe Zahlen ein: ");
    while(1) {
        if (tmp = 5) {
            break;
        }
        scanf("%d", varray);
        tmp++;
    }
	printf("1. Array: %d", varray);
    int *v2array = realloc(varray,100 * sizeof(int));
    if (v2array) {
        while (1) {
            if (scanf("%d", &v2array) == 'Q') {
                break;
            }
        }
        free(v2array);
    } else {
        free(varray);
    }
    




    return 0;
}
