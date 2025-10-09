/* Program   : tqueue2.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060124120037/Muhammad Fahri*/
/* Tanggal   : */
/***********************************/

#include<stdio.h>
#include "tqueue2.h"
#include "boolean.h"

int main() {
    tqueue2 Q1, Q2;
    char E;
    
    // 1. Create Queue
    printf("=== Create Queue ===\n");
    createQueue2(&Q1);
    printQueue2(Q1);
    printf("\nHead=%d Tail=%d\n", head2(Q1), tail2(Q1));

    // 2. Enqueue beberapa elemen
    printf("\n=== Enqueue Elemen ===\n");
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');
    enqueue2(&Q1, 'D');
    enqueue2(&Q1, 'E');
    printQueue2(Q1);
    printf("\nView Queue: ");
    viewQueue2(Q1);
    printf("\n");

    // 3. Dequeue beberapa elemen
    printf("\n=== Dequeue Elemen ===\n");
    dequeue2(&Q1, &E);
    printf("Dequeue: %c\n", E);
    dequeue2(&Q1, &E);
    printf("Dequeue: %c\n", E);
    printQueue2(Q1);
    printf("\nView Queue: ");
    viewQueue2(Q1);
    printf("\n");

    // 4. ResetHead 
    printf("\n=== ResetHead Test ===\n");
    resetHead(&Q1);
    printQueue2(Q1);

    // 5. Enqueue2N
    printf("\n=== Enqueue2N (input 1 elemen) ===\n");
    enqueue2N(&Q1, 1);   // masukkan misalnya X dan Y
    printQueue2(Q1);
    printf("\nView Queue: ");
    viewQueue2(Q1);
    printf("\n");

    // 6. Test isEqualQueue2
    printf("\n=== Test isEqualQueue2 ===\n");
    createQueue2(&Q2);
    enqueue2(&Q2, 'C');
    enqueue2(&Q2, 'D');
    enqueue2(&Q2, 'X'); // samakan dengan isi Q1 untuk coba true
    printQueue2(Q2);
    printf("\nQueue Q1 vs Q2 sama? %s\n", isEqualQueue2(Q1,Q2) ? "TRUE" : "FALSE");

    // 7. Cek fungsi infoHead dan infoTail
    printf("\nInfo Head Q1: %c\n", infoHead2(Q1));
    printf("Info Tail Q1: %c\n", infoTail2(Q1));

    return 0;
}
