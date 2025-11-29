/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait SIRKULAR, representasi fisik pointer */
/* NIM & Nama : 24060124120037 / Muhammad Fahri */
/* Tanggal : 20 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"   // ganti ke list2.h jika memakai List2

int main() {
    // Kamus
    List3 L, L2, L3, L1, L2_split;
    infotype X, Y, V;
    address P;
    int jumlah;
    float frekuensi;
    
    // Algoritma
    printf("====== APLIKASI ADT LIST BERKAIT SIRKULAR (List3) ======\n\n");

    /* 1. Membuat list kosong */
    printf("1. CreateList\n");
    CreateList(&L);
    CreateList(&L2);
    CreateList(&L3);
    printf("List kosong berhasil dibuat.\n\n");

    /* 2. Insert last */
    printf("2. InsertVLast\n");
    InsertVLast(&L, 'F');
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'H');
    InsertVLast(&L, 'R');
    InsertVLast(&L, 'I');
    PrintList(L); printf("\n\n");

    /* 3. Insert di awal */
    printf("3. InsertVFirst ('X' di awal)\n");
    InsertVFirst(&L, 'X');
    PrintList(L); printf("\n\n");

    /* 4. Insert di akhir */
    printf("4. InsertVLast ('Z' di akhir)\n");
    InsertVLast(&L, 'Z');
    PrintList(L); printf("\n\n");

    /* 5. Hitung jumlah elemen */
    printf("5. NbElm\n");
    jumlah = NbElm(L);
    printf("Jumlah elemen: %d\n\n", jumlah);

    /* 6. Insert setelah huruf A */
    printf("6. InsertVAfterX tambah 'Q' setelah 'A'\n");
    InsertVAfterX(&L, 'A', 'Q');
    PrintList(L); printf("\n\n");

    /* 7. Insert sebelum H */
    printf("7. InsertVBeforeX tambah 'M' sebelum 'H'\n");
    InsertVBeforeX(&L, 'H', 'M');
    PrintList(L); printf("\n\n");

    /* 8. Search elemen */
    printf("8. SearchX mencari 'R'\n");
    SearchX(L, 'R', &P);
    if (P != NIL) printf("'R' ditemukan.\n");
    else printf("'R' tidak ditemukan.\n");
    printf("\n");

    /* 9. CountX elemen tertentu */
    printf("9. CountX jumlah huruf A\n");
    printf("Jumlah A: %d\n\n", CountX(L, 'A'));

    /* 10. Frekuensi A */
    printf("10. FrekuensiX frekuensi huruf A\n");
    printf("Frekuensi A: %.4f\n\n", FrekuensiX(L, 'A'));

    /* 11. Hitung huruf vokal */
    printf("11. CountVocal jumlah vokal\n");
    printf("Jumlah vokal: %d\n\n", CountVocal(L));

    /* 12. Hitung pasangan NG */
    printf("12. CountNG pasangan 'NG'\n");
    printf("Jumlah NG: %d\n\n", CountNG(L));

    /* 13. Modus */
    printf("13. Modus huruf paling sering muncul\n");
    printf("Modus: %c\n\n", Modus(L));

    /* 14. CopyList */
    printf("14. CopyList menyalin L ke L2\n");
    CopyList(L, &L2);
    PrintList(L2); printf("\n\n");

    /* 15. Concat list */
    printf("15. ConcatList L + L2 = L3\n");
    ConcatList(L, L2, &L3);
    PrintList(L3); printf("\n\n");

    /* 16. Split list */
    printf("16. SplitList memisah L3 menjadi L1 dan L2_split\n");
    SplitList(L3, &L1, &L2_split);
    printf("L1: "); PrintList(L1);
    printf("L2_split: "); PrintList(L2_split); printf("\n\n");

    /* 17. Invers list */
    printf("17. Invers membalik urutan L\n");
    Invers(&L);
    PrintList(L); printf("\n\n");

    /* 18. DeleteVFirst */
    printf("18. DeleteVFirst\n");
    DeleteVFirst(&L, &V);
    printf("Elemen '%c' dihapus dari awal\n", V);
    PrintList(L); printf("\n\n");

    /* 19. DeleteVLast */
    printf("19. DeleteVLast\n");
    DeleteVLast(&L, &V);
    printf("Elemen '%c' dihapus dari akhir\n", V);
    PrintList(L); printf("\n\n");

    /* 20. DeleteX huruf tertentu */
    printf("20. DeleteX hapus huruf 'A'\n");
    DeleteX(&L, 'A');
    PrintList(L); printf("\n\n");

    /* 21. DeleteVAfterX */
    printf("21. DeleteVAfterX hapus sesudah 'F'\n");
    DeleteVAfterX(&L, 'F', &V);
    printf("Dihapus: %c\n", V);
    PrintList(L); printf("\n\n");

    /* 22. DeleteVBeforeX */
    printf("22. DeleteVBeforeX hapus sebelum 'I'\n");
    DeleteVBeforeX(&L, 'I', &V);
    printf("Dihapus: %c\n", V);
    PrintList(L); printf("\n\n");

    /* 23. DeleteAllX */
    printf("23. DeleteAllX hapus semua 'R'\n");
    DeleteAllX(&L, 'R');
    PrintList(L); printf("\n\n");

    /* Final output */
    printf("24. Final list:\n");
    PrintList(L);

    printf("\n====== PROGRAM SELESAI ======\n");
    return 0;
}
