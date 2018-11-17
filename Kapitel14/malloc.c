#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{ 
    int *x = (int*) malloc(sizeof(int));    
    return 0;
}
<<<<<<< HEAD
=======

/*
Question4:

(gdb) run
Starting program: /home/an851goe/BSYS/BSYS-Homeworks/Kapitel14/malloc
[Inferior 1 (process 25893) exited normally]

an851goe@ct-bsys-ws18-5:~/BSYS/BSYS-Homeworks/Kapitel14$ valgrind --leak-check=yes ./malloc
==26013== Memcheck, a memory error detector
==26013== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==26013== Using Valgrind-3.12.0.SVN and LibVEX; rerun with -h for copyright info
==26013== Command: ./malloc
==26013==
==26013==
==26013== HEAP SUMMARY:
==26013==     in use at exit: 4 bytes in 1 blocks
==26013==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==26013==
==26013== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==26013==    at 0x4C2BBAF: malloc (vg_replace_malloc.c:299)
==26013==    by 0x1086C8: main (in /home/an851goe/BSYS/BSYS-Homeworks/Kapitel14/malloc)
==26013==
==26013== LEAK SUMMARY:
==26013==    definitely lost: 4 bytes in 1 blocks
==26013==    indirectly lost: 0 bytes in 0 blocks
==26013==      possibly lost: 0 bytes in 0 blocks
==26013==    still reachable: 0 bytes in 0 blocks
==26013==         suppressed: 0 bytes in 0 blocks
==26013==
==26013== For counts of detected and suppressed errors, rerun with: -v
==26013== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


*/
>>>>>>> e6f00654cc077a002f2b3f5cbb84ae066a25eaaf
