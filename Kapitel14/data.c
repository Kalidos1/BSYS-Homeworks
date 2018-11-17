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
<<<<<<< HEAD
=======

/*

Question5:
(gdb) run
Starting program: /home/an851goe/BSYS/BSYS-Homeworks/Kapitel14/data
[Inferior 1 (process 27477) exited normally]

an851goe@ct-bsys-ws18-5:~/BSYS/BSYS-Homeworks/Kapitel14$ valgrind --leak-check=yes ./data
==27561== Memcheck, a memory error detector
==27561== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==27561== Using Valgrind-3.12.0.SVN and LibVEX; rerun with -h for copyright info
==27561== Command: ./data
==27561==
==27561== Invalid write of size 4
==27561==    at 0x1086D7: main (in /home/an851goe/BSYS/BSYS-Homeworks/Kapitel14/data)
==27561==  Address 0x51d71d0 is 0 bytes after a block of size 400 alloc'd
==27561==    at 0x4C2BBAF: malloc (vg_replace_malloc.c:299)
==27561==    by 0x1086C8: main (in /home/an851goe/BSYS/BSYS-Homeworks/Kapitel14/data)
==27561==
==27561==
==27561== HEAP SUMMARY:
==27561==     in use at exit: 400 bytes in 1 blocks
==27561==   total heap usage: 1 allocs, 0 frees, 400 bytes allocated
==27561==
==27561== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==27561==    at 0x4C2BBAF: malloc (vg_replace_malloc.c:299)
==27561==    by 0x1086C8: main (in /home/an851goe/BSYS/BSYS-Homeworks/Kapitel14/data)
==27561==
==27561== LEAK SUMMARY:
==27561==    definitely lost: 400 bytes in 1 blocks
==27561==    indirectly lost: 0 bytes in 0 blocks
==27561==      possibly lost: 0 bytes in 0 blocks
==27561==    still reachable: 0 bytes in 0 blocks
==27561==         suppressed: 0 bytes in 0 blocks
==27561==
==27561== For counts of detected and suppressed errors, rerun with: -v
==27561== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)


Question7:
No need to use tools to find the Issue
*/
>>>>>>> e6f00654cc077a002f2b3f5cbb84ae066a25eaaf
