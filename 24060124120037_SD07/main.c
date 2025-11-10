/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120037/Muhammad Fahri */
/* Tanggal : 9 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  List1 Senarai, Senarai2, Gabung;
  infotype X;
  //algoritma
  
  //aplikasi tipe address
  
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List1
  Senarai.First = B; //First(Senarai) = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL) {
	  printf("\t%c",info(P));
	  P = next(P);
  }
// algoritma
  printf("=== PROGRAM UJI ADT LIST BERKAIT (List1) ===\n");

  // 1. Membuat list kosong
  CreateList(&Senarai);
  printf("\nList dibuat kosong.\n");
  PrintList(Senarai);

  // 2. Menambah elemen di awal
  printf("\nMenambah elemen di awal: A, B, C\n");
  InsertVFirst(&Senarai, 'C');
  InsertVFirst(&Senarai, 'B');
  InsertVFirst(&Senarai, 'A');
  PrintList(Senarai);

  // 3. Menambah elemen di akhir
  printf("\nMenambah elemen di akhir: D, E\n");
  InsertVLast(&Senarai, 'D');
  InsertVLast(&Senarai, 'E');
  PrintList(Senarai);

  // 4. Menghitung jumlah elemen
  printf("\nJumlah elemen list = %d\n", NbElm(Senarai));

  // 5. Menyisipkan setelah elemen tertentu
  printf("\nMenyisipkan huruf 'X' setelah huruf 'C'\n");
  InsertVAfter(&Senarai, 'C', 'X');
  PrintList(Senarai);

  // 6. Menghapus elemen pertama dan terakhir
  printf("\nMenghapus elemen pertama dan terakhir:\n");
  DeleteVFirst(&Senarai, &X);
  printf("Elemen pertama yang dihapus: %c\n", X);
  DeleteVLast(&Senarai, &X);
  printf("Elemen terakhir yang dihapus: %c\n", X);
  PrintList(Senarai);

  // 7. Update elemen
  printf("\nMengubah huruf 'X' menjadi 'Z'\n");
  UpdateX(&Senarai, 'X', 'Z');
  PrintList(Senarai);

  // 8. Menghitung jumlah vokal
  printf("\nJumlah huruf vokal dalam list = %d\n", CountVocal(Senarai));

  // 9. Mencari modus
  printf("Huruf yang paling sering muncul (modus) = %c\n", Modus(Senarai));

  // 10. Membalik urutan list
  printf("\nMembalik urutan list:\n");
  Invers(&Senarai);
  PrintList(Senarai);

  // 11. Menyalin list ke Senarai2
  printf("\nMenyalin list ke Senarai2:\n");
  CopyList(Senarai, &Senarai2);
  PrintList(Senarai2);

  // 12. Menggabungkan dua list (Concat)
  printf("\nMenggabungkan Senarai + Senarai2 menjadi Gabung:\n");
  ConcatList(Senarai, Senarai2, &Gabung);
  PrintList(Gabung);

  // 13. Memisahkan list Gabung menjadi dua
  printf("\nMemisahkan Gabung menjadi dua list (L1 dan L2):\n");
  List1 L1, L2;
  SplitList(Gabung, &L1, &L2);
  printf("L1: "); PrintList(L1);
  printf("L2: "); PrintList(L2);

  // 14. Tes frekuensi huruf tertentu
  printf("\nFrekuensi huruf 'A' dalam list Gabung = %.2f\n", FrekuensiX(Gabung, 'A'));

  return 0;
}
