/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer*/
/* NIM & Nama : 24060124120037 / Muhammad Fahri*/
/* Tanggal : 27 November 2025*/

#include "pohon1.h"

int main() {
    // kamus
    bintree B;

    // algoritma
    B = Tree('T',
             Tree('I',
                  Tree('N', NIL, NIL),
                  Tree('F',
                       Tree('O', NIL, NIL),
                       NIL)),
             Tree('R',
                  Tree('M',
                       Tree('A', NIL, NIL),
                       Tree('T', NIL, NIL)),
                  Tree('I',
                       NIL,
                       Tree('K',
                            NIL,
                            Tree('A', NIL, NIL))))
            );

    printf("\n=== PrintPrefix ===\n");
    PrintPrefix(B);

    printf("\n\n=== NbElm ===\n");
    printf("%d", NbElm(B));
    
    printf("\n\n=== NbDaun ===\n");
    printf("%d", NbDaun(B));
    
    printf("\n\n=== Tinggi ===\n");
    printf("%d", Tinggi(B));

    printf("\n\n=== SearchX (cari 'A') ===\n");
    printf("%d", SearchX(B, 'A'));
    
    printf("\n\n=== UpdateX (Ubah 'A' menjadi 'Z') ===\n");
    UpdateX(&B, 'A', 'Z');
    PrintPrefix(B);

    printf("\n\n=== CountX (menghitung banyak 'I') ===\n");
    printf("%d", CountX(B, 'I'));

    printf("\n\n=== isSkewLeft ===\n");
    printf("%d", IsSkewLeft(B));
    
    printf("\n\n=== isSkewRight ===\n");
    printf("%d", IsSkewRight(B));
    
    printf("\n\n=== PrintPrefixRingkas ===\n");
    PrintPrefixRingkas(B);

    printf("\n\n === LevelX('T') ===\n");
    printf("%d", LevelX(B, 'T'));

    printf("\n\n=== CountLevel(B, 2) ===\n");
    printf("%d", CountLevel(B, 2));

    printf("\n\n=== PrintLevel (level 3) ===\n");
    PrintLevel(B, 3);

    printf("\n\n=== GetDaunTerkiri ===\n");
    printf("%c", GetDaunTerkiri(B));

    printf("\n\n=== FrekuensiX (menghitung frekuensi 'T') ===\n");
    printf("%.2f", FrekuensiX(B, 'T'));

    printf("\n\n=== CountVocal ===\n");
    printf("%d", CountVocal(B));

    printf("\n\n=== PrintVocal ===\n");
    PrintVocal(B);

    printf("\n\n=== CountConsonant ===\n");
    printf("%d", CountConsonant(B));

    printf("\n\n=== PrintConsonant ===\n");
    PrintConsonant(B);

    printf("\n\n=== Modus ===\n");
    printf("%c", Modus(B));

    return 0;
}
