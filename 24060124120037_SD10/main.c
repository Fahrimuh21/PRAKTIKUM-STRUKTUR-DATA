/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Muhammad Fahri*/
/* Tanggal : 27 November 2025*/

#include "pohon1.h"
#include "pohon1.c"

int main()
{//kamus
    bintree B;
 //algirtma
    B = Tree('T',
             Tree('I',
                  Tree('N',NIL,NIL),
                  Tree('F',
                       Tree('O',NIL,NIL),
                       NIL)),
             Tree('R',
                  Tree('M',
                       Tree('A',NIL,NIL),
                       Tree('T',NIL,NIL)),
                  Tree('I',
                       NIL,
                       Tree('K',
                            NIL,
                            Tree('A',NIL,NIL))))
            );
    PrintPrefix(B);
	
    return 0;
}