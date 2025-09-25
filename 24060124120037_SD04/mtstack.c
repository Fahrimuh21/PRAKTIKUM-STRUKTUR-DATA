/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	char X;
	boolean Palindrom;

	/* algoritma */
	createStack(&A);
	printStack(A);
	printf(" apakah stack kosong : %d \n", isEmptyStack(A));
	printf( "apakah stack full : %d \n",isFullStack(A));
	X='A';
	push(&A, X);
	X='B';
	push(&A, X);
	printf("KONDISI STACK A SETELAH DI PUSH A DAN B \n");
	printStack(A);
	pop(&A, &X);
	printf("KONDISI STACK A SETELAH DI POP A \n");
	printStack(A);

	printf("VIEW STACK A SAAT INI \n");
	viewStack(A);
	X='B';
	push(&A,X );
	X='A';
	push(&A, X);
	printStack(A);
	printf("apakah stack A palindrom : %d \n",isPalindrom(A));
	pushN(&A, 3);
	viewStack(A);

	
	
	
	return 0;
}
