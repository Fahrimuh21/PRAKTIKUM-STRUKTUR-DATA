/* Program   : mtqueue.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060124120037/Muhammad Fahri*/
/* Tanggal   : 2 Oktober 2025*/
/***********************************/
#include<stdio.h>
#include "tqueue.h"
#include "boolean.h"

int main() {
    tqueue Q1, Q2;
    char e;

    createQueue(&Q1);
    createQueue(&Q2);
    printf("== Kondisi awal ==\n");
    printQueue(Q1);
    printf("\napakah kosong %d", isEmptyQueue(Q1));


    enqueue(&Q1, 'A');
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');
    enqueue(&Q1, 'D');
    enqueue(&Q1, 'E');
    enqueue(&Q1, 'F');
    printf("\n== Setelah enqueue ==\n");
    printQueue(Q1);
    viewQueue(Q1);
    printf("\napakah full %d", isFullQueue(Q1));
    printf("\napakah 1 elemen %d", isOneElement(Q1));
    printf("\nsize Q1 %d", sizeQueue(Q1));

    dequeue(&Q1, &e);
    printf("\nElemen keluar: %c \n", e);

    dequeue(&Q1, &e);
    printf("Elemen keluar: %c\n", e);

    printf("\n== Setelah dequeue ==\n");
    printQueue(Q1);
    viewQueue(Q1);

    enqueue2(&Q1, &Q2, 'A');
    enqueue2(&Q1, &Q2, 'B');
    enqueue2(&Q1, &Q2, 'C');
    enqueue2(&Q1, &Q2, 'D');

    printf("== Setelah enqueue2 4 kali A B C D==\n");
    printf("Q1: "); printQueue(Q1);
    printf("Q2: "); printQueue(Q2);

    dequeue2(&Q1, &Q2, &e);
    printf("Elemen keluar: %c\n", e);

    dequeue2(&Q1, &Q2, &e);
    printf("Elemen keluar: %c\n", e);

    printf("== Setelah dequeue2 2 kali ==\n");
    printf("Q1: "); printQueue(Q1);
    printf("Q2: "); printQueue(Q2);

    return 0;
}
