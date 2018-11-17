
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
<<<<<<< HEAD
{
	int x = 2;
	int *xpointer = NULL;
	xpointer = &x;
	*xpointer = 4;
	printf("Pointer: %p\n", xpointer);
	printf("PointerInhalt: %d\n", *xpointer);
	printf("Variable x: %d\n", x);
	return 0;
=======
{ 
    int x = 2;
    int *xpointer = NULL;
    xpointer = &x;
    *xpointer = 4;
    printf("Pointer: %p\n", xpointer);
    printf("PointerInhalt: %d\n", *xpointer);
    printf("Variable x: %d\n", x);
    return 0;
>>>>>>> e6f00654cc077a002f2b3f5cbb84ae066a25eaaf
}


/*
Question1:
an851goe@ct-bsys-ws18-5:~/BSYS/BSYS-Homeworks/Kapitel14$ ./null
Pointer: 0x7ffcf3152b94
PointerInhalt: 4
Variable x: 4

Question2:
(gdb) run
Starting program: /home/an851goe/BSYS/BSYS-Homeworks/Kapitel14/null
Pointer: 0x7fffffffe8b4
PointerInhalt: 4
Variable x: 4
[Inferior 1 (process 24438) exited normally]

Question3:
an851goe@ct-bsys-ws18-5:~/BSYS/BSYS-Homeworks/Kapitel14$ valgrind --leak-check=yes ./null
==24562== Memcheck, a memory error detector
==24562== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==24562== Using Valgrind-3.12.0.SVN and LibVEX; rerun with -h for copyright info
==24562== Command: ./null
==24562==
Pointer: 0xfff000874
PointerInhalt: 4
Variable x: 4
==24562==
==24562== HEAP SUMMARY:
==24562==     in use at exit: 0 bytes in 0 blocks
==24562==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==24562==
==24562== All heap blocks were freed -- no leaks are possible
==24562==
==24562== For counts of detected and suppressed errors, rerun with: -v
==24562== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
an851goe@ct-bsys-ws18-5:~/BSYS/BSYS-Homeworks/Kapitel14$
*/