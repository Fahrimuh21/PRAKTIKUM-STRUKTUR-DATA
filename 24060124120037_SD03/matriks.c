/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124120037/Muhammad Fahri*/
/* Tanggal   : 21 September 2025*/
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"
/* include matriks.h & boolean.h */

/* KONSTRUKTOR */
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    //KAMUS 
    int i, j;

    //algoritma
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            M->cell[i][j] = (-999);
        }
    }
    (*M).nbaris=0;
    (*M).nkolom=0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    return M.nkolom ==0 && M.nbaris==0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    return M.nkolom == 10 && M.nbaris==0;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){

    //kamus 
    int i, j, sudahterisi;
    M->cell[row][col]=X;
    if(row>M->nbaris){
        M->nbaris=row;
    }
    if(col>M->nkolom){
        M->nkolom=col;
    }
}



/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    //kamus 
    int i, j,  row, col, barisTerluar, kolomTerluar;

    //algoritma
    searchX(*M, X, &row, &col);
    M->cell[row][col]=-999;
    barisTerluar=0;
    kolomTerluar=0;
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            if(M->cell[i][j]!=-999){
                if(barisTerluar<i){
                    barisTerluar=i;
                }
                if(kolomTerluar<i){
                    kolomTerluar=i;
                }
            }
        }
    }
    M->nbaris=barisTerluar;
    M->nkolom=kolomTerluar;
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    //KAMUS
    int i, j, masukan;

    //algoritma
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            masukan = rand() %50;
            M->cell[i][j]=masukan;
        }
    }
    if(M->nbaris<x){
        M->nbaris=x;
    }
    if(M->nkolom<y){
        M->nkolom=y;
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    //KAMUS
    int i, j;

    //algoritma
    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            if(i==j){
                M->cell[i][j]=1;
            }else{
                M->cell[i][j]=0;
            }
        }
    }
    for(i=n+1; i<=10; i++){
        for(j=n+1; j<=10; j++){
            M->cell[i][j]=-999;
        }
    }
    if(M->nbaris<n){
        M->nbaris=n-1;
    }
    if(M->nkolom<n){
        M->nkolom=n-1;
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
    //KAMUS
    int i, j, masukan;

    //algoritma
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            scanf("%d", &masukan);
            M->cell[i][j]=masukan;
        }
    }
     if(M->nbaris<x){
        M->nbaris=x;
    }
    if(M->nkolom<y){
        M->nkolom=y;
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    //KAMUS 
    int i, j;

    //algoritma
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            printf("%d   ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M){
    //KAMUS 
    int i, j;

    //algoritma
    for(i=1; i<=getNBaris(M); i++){
        for(j=1; j<=getNKolom(M); j++){
            printf("%d   ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    //KAMUS 
    int i, j;
    Matriks M;
    initMatriks(&M);
    //algoritman
    if(getNBaris(M1)==getNBaris(M2) && getNKolom(M1)==getNKolom(M2)){
        M.nbaris=M1.nbaris;
        M.nkolom=M1.nkolom;
        for(i=1; i<=getNBaris(M1); i++){
            for(j=1; j<=getNKolom(M1); j++){
                M.cell[i][j]=M1.cell[i][j]+M2.cell[i][j];
            }
        }
        return M;
    }
    
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
    //KAMUS 
    int i, j;
    Matriks M;
    initMatriks(&M);

    //algoritman
    if(getNBaris(M1)==getNBaris(M2) && getNKolom(M1)==getNKolom(M2)){
        M.nbaris=M1.nbaris;
        M.nkolom=M1.nkolom;
        for(i=1; i<=getNBaris(M1); i++){
            for(j=1; j<=getNKolom(M1); j++){
                M.cell[i][j]=M1.cell[i][j]-M2.cell[i][j];
            }
        }
        return M;
    }
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    //KAMUS
    int i, j, k;
    Matriks M;

    //ALGORITMA
    if(getNBaris(M1)==getNKolom(M2)){
        M.nbaris=M1.nbaris;
        M.nkolom=M2.nkolom;
        initMatriks(&M);
        for (i = 1; i <=getNBaris(M1); i++) { 
            for (j = 1; j <=getNKolom(M2); j++) { 
                M.cell[i][j] = 0;
                for (k = 1; k <=getNBaris(M1); k++) { 
                    M.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
                }
            }
        }
        return M;
    }
    
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x){
    //KAMUS 
    int i, j;
    Matriks M;
    initMatriks(&M);
    M.nbaris=M1.nbaris;
    M.nkolom=M1.nkolom;
    //algoritma
    for(i=1; i<=getNBaris(M1); i++){
        for(j=1; j<=getNKolom(M1); j++){
            M.cell[i][j]=M1.cell[i][j]*x;
        }
    }
    return M;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M){
    //KAMUS LOKAL
    int i, j, temp;
    Matriks Mtemp;
    initMatriks(&Mtemp);

    //algoritma
    Mtemp =*M;
    for(i=1; i<=getNBaris(*M); i++){
        for(j=1; j<=getNKolom(*M); j++){
            M->cell[i][j]=Mtemp.cell[j][i];
        }
    }
    temp =M->nbaris;
    M->nbaris=M->nkolom;
    M->nkolom=temp;
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
    //KAMUS LOKAL
    int i, j, temp;
    Matriks Mtemp;
    initMatriks(&Mtemp);
    //algoritma
    for(i=1; i<=getNBaris(M); i++){
        for(j=1; j<=getNKolom(M); j++){
            Mtemp.cell[i][j]=M.cell[j][i];
        }
    }
    Mtemp.nbaris=M.nkolom;
    Mtemp.nkolom=M.nbaris;
    return Mtemp;
}

/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n){
    //kamus 
    int i, j;
    Matriks Mpadding;
    initMatriks(&Mpadding);
    //ALGORITMA
    for(i=1; i<=getNBaris(M)+(2*n); i++){
        for(j=1; j<=getNKolom(M)+(2*n); j++){
            Mpadding.cell[i][j]=0;
        }
    }
    for(i=n+1; i<=getNBaris(M)-n; i++){
        for(j=n+1; j<=getNKolom(M)-n; j++){
            Mpadding.cell[i][j]=M.cell[i-n][j-n];
        }
    }
    return Mpadding;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size){
    //KAMUS 
    int i, j, k, l, max;
    Matriks Mmax;
    initMatriks(&Mmax);
    //ALGORITMA
    for(i=1; i<=getNBaris(M)/size; i++){
        for(j=1; j<=getNKolom(M)/size; j++){
            max=M.cell[(i-1)*size+1][(j-1)*size+1];
            for(k=1; k<=size; k++){
                for(l=1; l<=size; l++){
                    if(M.cell[(i-1)*size+k][(j-1)*size+l]>max){
                        max=M.cell[(i-1)*size+k][(j-1)*size+l];
                    }
                }
            }
            Mmax.cell[i][j]=max;
        }
    }
    Mmax.nbaris=M.nbaris/size;
    Mmax.nkolom=M.nkolom/size;
    return Mmax;

}

/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size){
    //KAMUS 
    int i, j, k, l, sum;
    Matriks rataratapoling;
    initMatriks(&rataratapoling);

    //ALGORITMA
    for(i=1; i<=getNBaris(M)/size; i++){
        for(j=1; j<=getNKolom(M)/size; j++){
            sum=0;
            for(k=1; k<=size; k++){
                for(l=1; l<=size; l++){
                    sum=sum+M.cell[(i-1)*size+k][(j-1)*size+l];
                }
            }
            rataratapoling.cell[i][j]=sum/(size*size);
        }
    }
    rataratapoling.nbaris=M.nbaris/size;
    rataratapoling.nkolom=M.nkolom/size;
    return rataratapoling;
}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K){
    //KAMUS 
    int i, j, k, l, sum;
    Matriks conv;
    initMatriks(&conv);
    conv.nbaris=M.nbaris-K.nbaris+1;
    conv.nkolom=M.nkolom-K.nkolom+1;

    //ALGORITMA
    for(i=1; i<=getNBaris(M)-getNBaris(K)+1; i++){
        for(j=1; j<=getNKolom(M)-getNKolom(K)+1; j++){
            sum=0;
            for(k=1; k<=getNBaris(K); k++){
                for(l=1; l<=getNKolom(K); k++){
                    sum=sum+(M.cell[i+k-1][j+l-1]*K.cell[k][l]);
                }
            }
            conv.cell[i][j]=sum;
        }
    }
    return conv;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    //kamus 
    int i, j;

    //algoritma
    i=1; j=1;
    while(M.cell[i][j]!=X || (j==getNKolom(M) && i==getNBaris(M))){
        if(j==getNKolom(M))i++;
        j++;
    }
    if(M.cell[i][j]==X){
        *row=i;
        *col=j;
    }else {
        *row =-999;
        *col = -999;
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
    //kamus 
    int i, j, count;

    //algoritma
    count=0;
    for(i=1; i<=getNBaris(M); i++){
        for(j=1; j<=getNKolom(M); j++){
            if(M.cell[i][j]==X){
                count++;
            }
        }
    }
    return count;
}