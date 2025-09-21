/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "matriks.h"

int main() {
    /*kamus*/
    Matriks M, M2, M3, MHasil;
	int row, col;

    /*algoritma*/
    printf("===== UJI KONSTRUKTOR =====\n");
    initMatriks(&M);
	initMatriks(&M2);
	initMatriks(&M3);
	initMatriks(&MHasil);

	printf("===== MATRIKS M SETELAH DI INIT =====\n");
    printMatriks(M);

    printf("===== UJI SELEKTOR M =====\n");
    printf("Jumlah baris = %d\n", getNBaris(M));
    printf("Jumlah kolom = %d\n", getNKolom(M));

    printf("===== UJI PREDIKAT M =====\n");
    printf("Apakah kosong? %d\n", isEmptyMatriks(M));
    printf("Apakah full? %d\n", isFullMatriks(M));

    printf("===== UJI ADD & DELETE X MATRIKS M =====\n");
    addX(&M, 10, 1, 1);
    addX(&M, 20, 2, 2);
	printf("Setelah addX(10,1,1) dan addX(20,2,2) pada matriks M:\n");
    viewMatriks(M);
    delX(&M, 10);
    printf("Setelah delX(10) pada matriks M:\n");
    viewMatriks(M);

    printf("===== UJI MATRIKS RANDOM MATRIKS M=====\n");
    isiMatriksRandom(&M, 6, 6);
    viewMatriks(M);

    printf("===== UJI ISI MATRIKS IDENTITAS PADA MATRIKS M2 =====\n");
    isiMatriksIdentitas(&M2, 4);
    viewMatriks(M2);

    printf("===== UJI OPERASI POPULATE PADA MATRIKS M3 =====\n");
    printf("Isi matriks M3 2x2 manual:\n");
    populateMatriks(&M3, 2, 2);
    viewMatriks(M3);

    printf("===== UJI PENJUMLAHAN M3 dengan M3 =====\n");
    viewMatriks(addMatriks(M3, M3));

    printf("===== UJI PENGURANGAN M3 dengan M3 =====\n");
    viewMatriks(subMatriks(M3, M3));

    printf("===== UJI PERKALIAN SKALAR M3 dengan 5 =====\n");
    viewMatriks(kaliSkalarMatriks(M3, 5));

    printf("===== UJI TRANSPOSE M3 =====\n");
    transposeMatriks(&M3);
    viewMatriks(M3);

    printf("===== UJI GET TRANSPOSE M3 =====\n");
    viewMatriks(getTransposeMatriks(M3));

    printf("===== UJI SEARCH X PADA MATRIKS M3 =====\n");
    searchX(M3, 1, &row, &col);
    printf("Ketemu 1 di baris %d kolom %d\n", row, col);

    printf("===== UJI COUNT X PADA MATRIKS M3 =====\n");
    printf("Jumlah angka 1 di matriks = %d\n", countX(M3, 1));

    printf("===== UJI MAX POOLING PADA MATRIKS M =====\n");
    viewMatriks(maxPooling(M, 2));

    printf("===== UJI AVG POOLING PADA MATRIKS M =====\n");
    viewMatriks(avgPooling(M, 2));

    printf("===== SELESAI =====\n");
}
