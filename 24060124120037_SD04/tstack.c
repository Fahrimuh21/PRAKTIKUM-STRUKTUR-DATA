/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    //kamus lokal
    int i;

    //algoritma 
    T->top = 0;
    for(i=1; i<=10; i++){
        T->wadah[i] = '#';
    }

}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    return T.top == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    if(!isFullStack(*T)){
        T->top++;
        T->wadah[T->top] = E;
    }   
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    if(!isEmptyStack(*T)){
        *X = T->wadah[T->top];
        T->wadah[T->top] = '#';
        T->top--;
    } else {
        *X = '#';
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    //kamus lokal
    int i;
    for(i=1; i<=10; i++){
        printf("%c ", T.wadah[i]);
        if(i<10){
            printf(";");
        }
    }
    printf("\n");   
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    //kamus lokal
    int i;

    //algoritma
    if(isEmptyStack(T)){    
        printf("Stack kosong\n");
        return;
    }
    for(i=1; i<=T.top; i++){
        printf("%c", T.wadah[i]);
        if(i<T.top){
            printf(";");
        }
    }
    printf("\n");
}

/*function  isPalindrom (input T:Stack)
    {mengembalikan true jika T palindrom atau dibaca sama dari depan dan belakang}*/

boolean isPalindrom (Tstack T){
    //KAMUS LOKAL
    int i;

    //ALGORITMA
    for(i=1; i<=(T.top/2); i++){
        if(T.wadah[i] != T.wadah[T.top-i+1]){
            return false;
        }
    }
    return true;
}

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    //kamus lokal
    char masukan;
    printf("masukan character nilai sebanyak ");
    printf("%d tanpa spasi : ", N);

    //algoritma
    while(!isFullStack(*T) && N>0){
        scanf("%c",&masukan);
        push(&(*T), masukan);
        N--;
    }

}

/*procedure PushBabel(input/output T:TStack)
    {I.S.: T terdefinisi, masukan terdefinisi }
    {F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
    {Proses: menumpuk top atau menghapus semua elemen }*/
void PushBabel(Tstack *T){
    //KAMUS LOKAL
    char masukan;
    //ALGORITMA
    printf("masukan nilai yang akan dimasukan : ");
    scanf(" %c", &masukan);
    push(&(*T), masukan);
}

/*Procedure Backward(Input/Output T1, T2:TStack, Input/Output X:char) 
     {I.S.: T1 terdefinisi, T2 terdefinisi }
    {F.S.: T berkurang 1 elemen  bila T1 tidak kosong}
    {Proses: menghapus 1 elemen di T1 dan menyimpan di T2}*/

void Backward(Tstack *T1, Tstack *T2){
    //kamus lokal
    char X;
    //ALGORITMA
    pop(&(*T1), &X);
    push(&(*T2), X);
}

/*Procedure Forward(Input/Output T1, T2:TStack, Input/Output X:char) 
     {I.S.: T1 terdefinisi, T2 terdefinisi }
    {F.S.: T2 berkurang 1 elemen  bila T2 tidak kosong}
    {Proses: menghapus 1 elemen di T2 dan menyimpan di T1}*/

void Forward(Tstack *T1, Tstack *T2){
    //kamus lokal
    char X;
    //ALGORITMA
    pop(&(*T2), &X);
    push(&(*T1), X);
}