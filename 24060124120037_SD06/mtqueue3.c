/* Program   : mtqueue.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model 3: head bisa lebih besar dari tail */
/* NIM/Nama  : 24060124120037/Muhammad Fahri*/
/* Tanggal   : 9 Oktober 2025*/
/***********************************/
#include<stdio.h>
#include "tqueue3.h"
#include "boolean.h"

int main() {
    tqueue3 Q1;
    char e;

    createQueue3(&Q1);
    printf("== Kondisi awal ==\n");
    printQueue3(Q1);
    printf("\napakah kosong %d", isEmptyQueue3(Q1));


    enqueue3(&Q1, 'C');
    enqueue3(&Q1, 'I');
    enqueue3(&Q1, 'L');
    enqueue3(&Q1, 'O');
    enqueue3(&Q1, 'K');
    enqueue3(&Q1, 'F');
    printf("\n== Setelah enqueue3 ==\n");
    printQueue3(Q1);
    viewQueue3(Q1);
    printf("\ntampilkan head %d", head3(Q1));
    printf("\ntampilkan tail %d", tail3(Q1));
    printf("\ntampilkan infohead : %c", infoHead3(Q1));
    printf("\ntampilkan infotail : %c", infoTail3(Q1));
    printf("\napakah full :  %d", isFullQueue3(Q1));
    printf("\napakah 1 elemen : %d", isOneElement3(Q1));
    printf("\nsize Q1 : %d", sizeQueue3(Q1));

    dequeue3(&Q1, &e);
    printf("\nsetelah deque 2 kali");
    printf("\nElemen keluar: %c \n", e);

    dequeue3(&Q1, &e);
    printf("Elemen keluar: %c\n", e);

    printf("\n== Setelah dequeue3 2 kali==\n");
    printQueue3(Q1);
    viewQueue3(Q1);
    
    enqueue3(&Q1, 'A');
    printf("\n== Setelah enqueue3 ==\n");
    printQueue3(Q1);
    viewQueue3(Q1);
    printf("\n == cek apakah tail berada di depan head ==");
    printf("\napakah isTailOverHead : %d", isTailOverHead(Q1));



}
