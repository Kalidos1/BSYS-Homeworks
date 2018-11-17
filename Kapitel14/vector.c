#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{ 
    int *varray,tmp,a;    
    
    varray = (int*) malloc(5 * sizeof(int));
<<<<<<< HEAD
    printf("Gebe Zahlen ein: ");
=======
    printf("Gebe Zahlen ein: (Beende mit Q)");
>>>>>>> e6f00654cc077a002f2b3f5cbb84ae066a25eaaf
    while(1) {
        if (tmp = 5) {
            break;
        }
        scanf("%d", varray);
        tmp++;
    }
<<<<<<< HEAD
	printf("1. Array: %d", varray);
    int *v2array = realloc(varray,100 * sizeof(int));
=======
    printf("1. Array: %d", varray)
    int *v2array = realloc(varray,100 * sizeof(*int));
>>>>>>> e6f00654cc077a002f2b3f5cbb84ae066a25eaaf
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
<<<<<<< HEAD
    




=======
>>>>>>> e6f00654cc077a002f2b3f5cbb84ae066a25eaaf
    return 0;
}
