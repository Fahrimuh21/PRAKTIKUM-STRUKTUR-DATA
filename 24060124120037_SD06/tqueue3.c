/* Program   : tqueue3.c */
/* Deskripsi : file body modul queue3 */
/* NIM/Nama  : 24060124120037/Muhammad Fahri*/
/* Tanggal   : 9 Oktober 2025*/
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "tqueue3.h"

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
    return Q.head==0 && Q.tail==0;
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
    if(Q.head>Q.tail){
        return Q.tail +1 == Q.head;
    }else{
        return Q.head == 1 && Q.tail==5;
    }
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
    if(isEmptyQueue3(Q)){
        return false;
    }else{
        return Q.head==Q.tail;
    }
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q){
    //kamus lokal
    int i;

    //algoritma
    for(i=1; i<=5; i++){
        Q->wadah[i]='#';
    }
    Q->tail=0;
    Q->head=0;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q){
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q){
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
    return Q.wadah[Q.head];
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
    return Q.wadah[Q.tail];
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
    if(Q.head>Q.tail){
        return 5-(Q.head-Q.tail+1);
    }
    else{
        return Q.tail-Q.head+1;
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q){
    //kamus lokal
    int i;

    //algoritma
    for(i=1; i<=5; i++){
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
    //kamus lokal
    int i;

    //algoritma
    if(Q.head>Q.tail){
        for(i=Q.head-1; i<Q.tail+5; i++){
            printf("%c ", Q.wadah[(i%5)+1]);
        }
    }
    else{
        for(i=Q.head; i<=Q.tail; i++){
            printf("%c ", Q.wadah[i]);
        }
    }
    
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E){
    if(isEmptyQueue3((*Q))){
        Q->wadah[1]=E;
        Q->head=1;
        Q->tail=1;
    }else if(!isFullQueue3(*Q)){
        if(Q->tail==5){
            Q->wadah[1]=E;
            Q->tail=1; 
        }else{
            Q->wadah[Q->tail+1]=E;
            Q->tail++;
        }
    }
    else{
        return;
    }
}
  
/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
    if(!isEmptyQueue3(*Q)){
        if(isOneElement3(*Q)){
            (*E)=Q->wadah[Q->tail];
            Q->wadah[Q->tail]='#';
            Q->tail=0;
            Q->head=0;
        }
        else if(Q->head>Q->tail){
            if(Q->head==5){
                (*E)=Q->wadah[Q->head];
                Q->wadah[Q->head]='#';
                Q->head=1;
            }else{
                (*E)=Q->wadah[Q->head];
                Q->wadah[Q->head]='#';
                Q->head++;
            }
        }else{
            (*E)=Q->wadah[Q->head];
            Q->wadah[Q->head]='#';
            Q->head++;
        }
    }else{
        (*E)=' ';
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q){
    return head3(Q)>tail3(Q);
}