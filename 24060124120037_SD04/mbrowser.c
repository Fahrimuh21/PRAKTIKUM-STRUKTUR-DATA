/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */


int main(){

    //kamus 
    Tstack A1, A2;
    int masukan;

    masukan=0;
    //ALGORITMA
    createStack(&A1);
    createStack(&A2);
    while(masukan!=4){
        printf("masukan sesuai kode : \n");
        printf("1. menambahkan elemen baru ke dalam stack dengan meminta input dari keyboard\n 2.Melakukan backward\n 3.Melakukan forward\n 4.Exit (keluar dari perulangan, selesai)\n");

        printf("masukan : ");
        scanf("%d", &masukan);
        if(masukan==1) PushBabel(&A1);
        else if(masukan==2) Backward(&A1, &A2);
        else if(masukan==3) Forward(&A1, &A2);
        else break;

        viewStack(A1);
    }
}