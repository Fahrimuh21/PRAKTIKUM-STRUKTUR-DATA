/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait SIRKULAR, representasi fisik pointer */
/* NIM & Nama : 24060124120037/Muhammad Fahri */
/* Tanggal : 13 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

int main() {
    //kamus
    List2 L, L2, L3, L1, L2_split;
    infotype X, Y, V;
    address P;
    int jumlah;
    float frekuensi;
    
    //algoritma
    printf("====== APLIKASI ADT LIST BERKAIT SIRKULAR (List2) ======\n");
    
    // Inisialisasi list
    CreateList(&L);
    CreateList(&L2);
    CreateList(&L3);
    
    // 1. Buat List Kosong
    printf("=== 1. MEMBUAT LIST KOSONG ===\n");
    CreateList(&L);
    printf("List kosong telah dibuat.\n\n");
    
    // 2. Sisip Elemen di Awal
    printf("=== 2. MENAMBAH ELEMEN DI AWAL ===\n");
    printf("Menambahkan: A, B, C\n");
    InsertVFirst(&L, 'C');
    InsertVFirst(&L, 'B');
    InsertVFirst(&L, 'A');
    PrintList(L);
    
    // 3. Sisip Elemen di Akhir
    printf("\n=== 3. MENAMBAH ELEMEN DI AKHIR ===\n");
    printf("Menambahkan: D, E\n");
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'E');
    PrintList(L);
    
    // 4. Hitung Jumlah Elemen
    printf("\n=== 4. HITUNG JUMLAH ELEMEN ===\n");
    if (!IsEmptyList(L)) {
        jumlah = NbElm(L);
        printf("Jumlah elemen dalam list: %d\n", jumlah);
    }
    
    // 5. Sisip Elemen Setelah X
    printf("\n=== 5. SISIP ELEMEN SETELAH 'B' ===\n");
    printf("Menambahkan 'Z' setelah 'B'\n");
    InsertVAfterX(&L, 'B', 'Z');
    PrintList(L);
    
    // 6. Sisip Elemen Sebelum X
    printf("\n=== 6. SISIP ELEMEN SEBELUM 'D' ===\n");
    printf("Menambahkan 'W' sebelum 'D'\n");
    InsertVBeforeX(&L, 'D', 'W');
    PrintList(L);
    
    // 7. Cari Elemen
    printf("\n=== 7. MENCARI ELEMEN 'Z' ===\n");
    SearchX(L, 'Z', &P);
    if (P != NULL) {
        printf("Elemen 'Z' ditemukan di list.\n");
    } else {
        printf("Elemen 'Z' tidak ditemukan.\n");
    }
    
    // 8. Cari Semua Elemen
    printf("\n=== 8. MENCARI SEMUA KEMUNCULAN 'A' (POSISI) ===\n");
    SearchAllX(L, 'A');
    printf("\n");
    
    // 9. Update Elemen
    printf("\n=== 9. UPDATE ELEMEN 'Z' MENJADI 'K' ===\n");
    UpdateX(&L, 'Z', 'K');
    PrintList(L);
    
    // 10. Hitung Elemen Bernilai Tertentu
    printf("\n=== 10. HITUNG JUMLAH 'A' DALAM LIST ===\n");
    jumlah = CountX(L, 'A');
    printf("Jumlah kemunculan 'A': %d\n", jumlah);
    
    // 11. Hitung Frekuensi
    printf("\n=== 11. HITUNG FREKUENSI 'A' ===\n");
    frekuensi = FrekuensiX(L, 'A');
    printf("Frekuensi 'A': %.4f\n", frekuensi);
    
    // 12. Hitung Vokal
    printf("\n=== 12. HITUNG JUMLAH VOKAL ===\n");
    jumlah = CountVocal(L);
    printf("Jumlah huruf vokal dalam list: %d\n", jumlah);
    
    // 13. Hitung Pasangan NG
    printf("\n=== 13. HITUNG PASANGAN 'NG' ===\n");
    jumlah = CountNG(L);
    printf("Jumlah pasangan 'NG' (n diikuti g): %d\n", jumlah);
    
    // 14. Cari Modus
    printf("\n=== 14. MENCARI MODUS (HURUF PALING SERING) ===\n");
    if (!IsEmptyList(L)) {
        Y = Modus(L);
        printf("Huruf yang paling sering muncul (modus): '%c'\n", Y);
    }
    
    // 15. Cek List Kosong
    printf("\n=== 15. CEK LIST KOSONG ===\n");
    if (IsEmptyList(L)) {
        printf("List kosong.\n");
    } else {
        printf("List tidak kosong.\n");
    }
    
    // 16. Cek List Satu Elemen
    printf("\n=== 16. CEK LIST SATU ELEMEN ===\n");
    if (IsOneElm(L)) {
        printf("List memiliki tepat satu elemen.\n");
    } else if (IsEmptyList(L)) {
        printf("List kosong.\n");
    } else {
        printf("List memiliki lebih dari satu elemen.\n");
    }
    
    // 17. Salin List
    printf("\n=== 17. SALIN LIST KE L2 ===\n");
    CopyList(L, &L2);
    printf("List telah disalin ke L2.\n");
    printf("L2: ");
    PrintList(L2);
    
    // 18. Gabungkan Dua List
    printf("\n=== 18. GABUNGKAN L DAN L2 MENJADI L3 ===\n");
    ConcatList(L, L2, &L3);
    printf("L3 (hasil gabungan L + L2): ");
    PrintList(L3);
    
    // 19. Pisahkan List
    printf("\n=== 19. PISAHKAN L3 MENJADI L1 DAN L2_SPLIT ===\n");
    SplitList(L3, &L1, &L2_split);
    printf("L1: ");
    PrintList(L1);
    printf("L2_split: ");
    PrintList(L2_split);
    
    // 20. Balik Urutan List (Invers)
    printf("\n=== 20. BALIK URUTAN LIST (INVERS) ===\n");
    printf("List sebelum dibalik: ");
    PrintList(L);
    if (!IsEmptyList(L)) {
        Invers(&L);
        printf("List setelah dibalik: ");
        PrintList(L);
    }
    
    // 21. Hapus Elemen Pertama
    printf("\n=== 21. HAPUS ELEMEN PERTAMA ===\n");
    if (!IsEmptyList(L)) {
        DeleteVFirst(&L, &V);
        printf("Elemen pertama '%c' telah dihapus.\n", V);
        PrintList(L);
    }
    
    // 22. Hapus Elemen Terakhir
    printf("\n=== 22. HAPUS ELEMEN TERAKHIR ===\n");
    if (!IsEmptyList(L)) {
        DeleteVLast(&L, &V);
        printf("Elemen terakhir '%c' telah dihapus.\n", V);
        PrintList(L);
    }
    
    // 23. Hapus Elemen Tertentu
    printf("\n=== 23. HAPUS ELEMEN 'B' ===\n");
    DeleteX(&L, 'B');
    printf("Elemen 'B' telah dihapus (jika ada).\n");
    PrintList(L);
    
    // 24. Hapus Elemen Setelah X
    printf("\n=== 24. HAPUS ELEMEN SETELAH 'A' ===\n");
    if (!IsEmptyList(L)) {
        DeleteVAfterX(&L, 'A', &V);
        printf("Elemen '%c' dihapus setelah 'A'.\n", V);
        PrintList(L);
    } else {
        printf("List kosong.\n");
    }
    
    // 25. Hapus Elemen Sebelum X
    printf("\n=== 25. HAPUS ELEMEN SEBELUM 'E' ===\n");
    if (!IsEmptyList(L)) {
        DeleteVBeforeX(&L, 'E', &V);
        printf("Elemen '%c' dihapus sebelum 'E'.\n", V);
        PrintList(L);
    } else {
        printf("List kosong.\n");
    }
    
    // 26. Hapus Semua Elemen Bernilai X
    printf("\n=== 26. HAPUS SEMUA ELEMEN BERNILAI 'A' ===\n");
    DeleteAllX(&L, 'A');
    printf("Semua elemen 'A' telah dihapus.\n");
    PrintList(L);
    
    // 27. Tampilkan List Final
    printf("\n=== 27. TAMPILKAN LIST FINAL ===\n");
    printf("Isi list setelah semua operasi: ");
    PrintList(L);
    
    printf("\n====== PROGRAM SELESAI ======\n");
    
    return 0;
}
