/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer*/
/* NIM & Nama : 24060124120037 / Muhammad Fahri*/
/* Tanggal : 4 Desember 2025*/

#include "pohon2.h"

int main() {
    // kamus
    bintree B, B2;

    // algoritma
    printf("========== MEMBUAT POHON BINER AWAL ==========\n");
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

    printf("\n========== PENELUSURAN ==========\n");

    printf("\n=== 1. PrintTreeInden (Indentasi) ===\n");
    PrintTreeInden(B, 1);

    printf("\n=== 2. PrintLevel2 - Level 2 ===\n");
    PrintLevel2(B, 2);
    printf("\n");

    printf("\n=== 3. PrintLevel2 - Level 3 ===\n");
    PrintLevel2(B, 3);
    printf("\n");

    printf("\n========== MANIPULASI ELEMEN ==========\n");

    printf("\n=== 4. UpdateAllX - Ubah I menjadi C ===\n");
    UpdateAllX(&B, 'I', 'C' );
    PrintTreeInden(B, 1);

    printf("\n========== PENAMBAHAN ELEMEN ==========\n");

    printf("\n=== 5. AddDaunTerkiri - Tambah M ===\n");
    AddDaunTerkiri(&B, 'M');
    PrintTreeInden(B, 1);

    printf("\n=== 6. AddDaun - Tambah Z setelah A (anak kanan) ===\n");
    AddDaun(&B, 'A', 'Z', false);
    PrintTreeInden(B, 1);

    printf("\n=== 7. AddDaun - Tambah W setelah T (anak kiri) ===\n");
    AddDaun(&B, 'T', 'W', true);
    PrintTreeInden(B, 1);

    printf("\n=== 8. InsertX - Tambah B ===\n");
    InsertX(&B, 'B');
    PrintTreeInden(B, 1);

    printf("\n========== PENGHAPUSAN ELEMEN ==========\n");

    printf("\n=== 9. DelDaunTerkiri ===\n");
    infotype XDel = '#';
    DelDaunTerkiri(&B, XDel);
    PrintTreeInden(B, 1);

    printf("\n=== 10. DelDaun - Hapus Z ===\n");
    DelDaun(&B, 'Z');
    PrintTreeInden(B, 1);

    printf("\n=== 11. DeleteX - Hapus K ===\n");
    DeleteX(&B, 'C');
    PrintTreeInden(B, 1);

    printf("\n========== KONSTRUKTOR ==========\n");

    printf("\n=== 12. BuildBalanceTree (input 3 node) ===\n");
    printf("Masukkan 3 nilai untuk pohon seimbang: ");
    B2 = BuildBalanceTree(3);
    printf("Pohon yang dibangun:\n");
    PrintTreeInden(B2, 1);

    printf("\n========== PREDIKAT ==========\n");

    printf("\n=== 13. IsBalanceTree (Pohon B) ===\n");
    if (IsBalanceTree(B)) {
        printf("Pohon B adalah balanced tree\n");
    } else {
        printf("Pohon B BUKAN balanced tree\n");
    }

    printf("\n=== 14. IsBalanceTree (Pohon B2) ===\n");
    if (IsBalanceTree(B2)) {
        printf("Pohon B2 adalah balanced tree\n");
    } else {
        printf("Pohon B2 BUKAN balanced tree\n");
    }

    printf("\n=== 15. maxTree ===\n");
    printf("Elemen maksimal pohon B: %c\n", (char)maxTree(B));

    printf("\n=== 16. minTree ===\n");
    printf("Elemen minimal pohon B: %c\n", (char)minTree(B));

    printf("\n========== BINARY SEARCH TREE ==========\n");

    printf("\n=== 17. BSearch - Cari T ===\n");
    if (BSearch(B, 'T')) {
        printf("T ditemukan dalam pohon\n");
    } else {
        printf("T tidak ditemukan dalam pohon\n");
    }

    printf("\n=== 18. BSearch - Cari X ===\n");
    if (BSearch(B, 'X')) {
        printf("X ditemukan dalam pohon\n");
    } else {
        printf("X tidak ditemukan dalam pohon\n");
    }

    printf("\n=== 19. InsSearch - Masukkan P ke pohon ===\n");
    B = InsSearch(B, 'P');
    PrintTreeInden(B, 1);

    printf("\n=== 20. InsSearch - Masukkan Q ke pohon ===\n");
    B = InsSearch(B, 'Q');
    PrintTreeInden(B, 1);

    printf("\n=== 21. DelBtree - Hapus P ===\n");
    DelBtree(&B, 'P');
    PrintTreeInden(B, 1);

    printf("\n=== 22. DelBtree - Hapus Q ===\n");
    DelBtree(&B, 'Q');
    PrintTreeInden(B, 1);

    return 0;
}
