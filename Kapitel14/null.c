
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x = 2;
	int *xpointer = NULL;
	xpointer = &x;
	*xpointer = 4;
	printf("Pointer: %p\n", xpointer);
	printf("PointerInhalt: %d\n", *xpointer);
	printf("Variable x: %d\n", x);
	return 0;
}
