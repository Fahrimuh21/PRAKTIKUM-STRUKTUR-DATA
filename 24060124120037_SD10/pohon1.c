/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124120037/Muhammad Fahri */
/* Tanggal : 27 November 2025*/

#include "pohon1.h"

bintree AlokasiTree(infotype E) {
    //kamus lokal
    bintree P;
    //algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void DealokasiTree (bintree *P) {
  //kamus lokal

  //algoritma
  if(*P != NIL){ //jika ada pohon P
    left(*P) = NIL;
    right(*P) = NIL;
  }
  free(*P); //mengosongkan memori
  *P = NIL; //mengatur pointer ke NIL
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right) {
  //kamus lokal
  bintree P;

  //algoritma
  P = AlokasiTree(akar);
  if (P != NIL) {
    left(P) = left;
    right(P) = right;
  }
  return P;
}
/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
  //kamus lokal

  //algoritma
  return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
  //kamus lokal

  //algoritma
  return right(P);
}
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan Akar pohon biner P }*/
infotype GetAkar(bintree P) {
    return P->info;
}
/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P) {
  //kamus lokal

  //algoritma
  return (P == NIL);
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    return false;
  } else {
    return IsEmptyTree(GetLeft(P)) && IsEmptyTree(GetRight(P));
  }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    return false;
  } else {
    return !IsEmptyTree(GetLeft(P)) && !IsEmptyTree(GetRight(P));
  }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    return false;
  } else {
    return !IsEmptyTree(GetLeft(P)) && IsEmptyTree(GetRight(P));
  }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    return false;
  } else {
    return IsEmptyTree(GetLeft(P)) && !IsEmptyTree(GetRight(P));
  }
}


/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    printf("( )");
  } else {
    printf("%c", GetAkar(P));
    PrintPrefix(GetLeft(P)); //rekursif anak pohon P sebelah kiri
    printf(",");
    PrintPrefix(GetRight(P)); //rekursif anak pohon P sebelah kanan
    printf(")");
  }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    return 0;
  } else {
    return 1 + NbElm(GetLeft(P)) + NbElm(GetRight(P));
  }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    return 0;
  } else { 
    if (IsDaun(P)) { 
      return 1;
    } else {
      return NbDaun(GetLeft(P)) + NbDaun(GetRight(P));
    }
  }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
  //kamus lokal

  //algoritma
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
  /*kamus lokal*/

  /*algoritma*/
  if (IsEmptyTree(P)) {
      return 0;
  } else if (NbElm(P) == 1) {
      return 0;
  } else { 
      return 1 + max2(Tinggi(GetLeft(P)), Tinggi(GetRight(P)));
  }
}


/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { 
    return false;
  } else if (GetAkar(P) == X) { 
    return true;
  } else { 
    return SearchX(GetLeft(P), X) || SearchX(GetRight(P), X);
  }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
/*asumsi: procedure ini hanya akan mengubah elemen X yang paling cepat ditemukan*/
void UpdateX(bintree *P, infotype X, infotype Y) {
  //kamus lokal

  //algoritma
  if (!IsEmptyTree(*P)) { 
    if (GetAkar(*P) == X) {
      akar(*P) = Y;
    } else {
      if (SearchX(GetLeft(*P), X)){
        UpdateX(&left(*P), X, Y);
      } else {
        UpdateX(&right(*P), X, Y);
      }
    }
  }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { 
    return 0;
  } else if (GetAkar(P) == X) { 
    return 1 + CountX(GetLeft(P), X) + CountX(GetRight(P), X);
  } else { 
    return CountX(GetLeft(P), X) + CountX(GetRight(P), X);
  }
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    return true;
  } else if (IsUnerLeft(P)) { 
    return true;
  } else {
    return IsEmptyTree(GetRight(P)) && IsSkewLeft(GetLeft(P));
  }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P) {
  if (IsEmptyTree(P)) { 
    return true;
  } else if (IsUnerRight(P)) { 
    return true;
  } else { 
    return IsEmptyTree(GetLeft(P)) && IsSkewRight(GetRight(P));
  }
}

/* procedure PrintPrefixSwalow(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { 
    printf("( )");
  } else {
    printf("%c", GetAkar(P));
    if (!IsEmptyTree(GetLeft(P)) || !IsEmptyTree(GetRight(P))) { 
      printf("(");
      PrintPrefixRingkas(GetLeft(P));
      if (!IsEmptyTree(GetRight(P))) { 
        printf(",");
        PrintPrefixRingkas(GetRight(P));
      }
      printf(")");
    }
  }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { 
    return 0;
  } else {
    if (GetAkar(P) == X) { 
      return 1;
    } else {
      if (LevelX(GetLeft(P), X) != 0) { 
        return 1 + LevelX(GetLeft(P), X);
      } else if (LevelX(GetRight(P), X) != 0) { 
        return 1 + LevelX(GetRight(P), X);
      } else { 
        return 0;
      }
    }
  }
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return 0;
  } else {
    if (T == 1) { 
      return 1; 
    } else {
      return CountLevel(GetLeft(P), T - 1) + CountLevel(GetRight(P), T - 1);
    }
  }
}

/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N){
    //kamus lokal
    
    //algoritma
    if (IsEmptyTree(P)) { 
        return;
    } else {
        if (N == 1) { 
        printf("%c ", GetAkar(P)); 
        } else {
        PrintLevel(GetLeft(P), N - 1); 
        PrintLevel(GetRight(P), N - 1); 
        }
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { 
    return '#';
  } else {
    if (IsDaun(P)) { 
      return GetAkar(P);
    } else {
      if (!IsEmptyTree(GetLeft(P))) { 
        return GetDaunTerkiri(GetLeft(P));
      } else { 
        return GetDaunTerkiri(GetRight(P));
      }
    }
  }
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    return 0;
  }
  else {
    return (float) CountX(P, X) / NbElm(P);
  }
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(L)) { //kasus pohon kosong
    return 0;
  } else {
    if (GetAkar(L) == 'A' || GetAkar(L) == 'a' || GetAkar(L) == 'I' || GetAkar(L) == 'i' || GetAkar(L) == 'U' || GetAkar(L) == 'u' || GetAkar(L) == 'E' || GetAkar(L) == 'e' || GetAkar(L) == 'O' || GetAkar(L) == 'o') { //kasus akar huruf vokal
      return 1 + CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
    } else {
      return CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
    }
  }
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P){
    //kamus lokal

    //algoritma
    if (IsEmptyTree(P)) { //kasus pohon kosong
        return;
    } else { 
        if (GetAkar(P) == 'A' || GetAkar(P) == 'a' || GetAkar(P) == 'I' || GetAkar(P) == 'i' || GetAkar(P) == 'U' || GetAkar(P) == 'u' || GetAkar(P) == 'E' || GetAkar(P) == 'e' || GetAkar(P) == 'O' || GetAkar(P) == 'o') { //kasus akar huruf vokal
            printf("%c ", GetAkar(P));
        }
        PrintVocal(GetLeft(P));
        PrintVocal(GetRight(P));
    }
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P){
    //kamus lokal

    //algoritma
    if (IsEmptyTree(P)) { //kasus pohon kosong
        return 0;
    } else { 
        if (! (GetAkar(P) == 'A' || GetAkar(P) == 'a' || GetAkar(P) == 'I' || GetAkar(P) == 'i' || GetAkar(P) == 'U' || GetAkar(P) == 'u' || GetAkar(P) == 'E' || GetAkar(P) == 'e' || GetAkar(P) == 'O' || GetAkar(P) == 'o')) { //kasus akar huruf konsonan
            return 1 + CountConsonant(GetLeft(P)) + CountConsonant(GetRight(P));
        } else { 
            return CountConsonant(GetLeft(P)) + CountConsonant(GetRight(P));
        }
    }
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P){
    //kamus lokal

    //algoritma
    if (IsEmptyTree(P)) { 
        return;
    } else { 
        if (! (GetAkar(P) == 'A' || GetAkar(P) == 'a' || GetAkar(P) == 'I' || GetAkar(P) == 'i' || GetAkar(P) == 'U' || GetAkar(P) == 'u' || GetAkar(P) == 'E' || GetAkar(P) == 'e' || GetAkar(P) == 'O' || GetAkar(P) == 'o')) { //kasus akar huruf konsonan
            printf("%c ", GetAkar(P));
        }
        PrintConsonant(GetLeft(P)); 
        PrintConsonant(GetRight(P));
    }
}


/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P) {
  // kamus lokal
  infotype temp;
  int count;
  char modus;

  // algoritma
  if (!IsEmptyTree(P)) { 
    temp = GetAkar(P);
    count = CountX(P, temp);
    modus = temp;
    if (CountX(P, Modus(GetLeft(P))) > count) {
      modus = Modus(GetLeft(P));
      count = CountX(P, modus);
    } else if (CountX(P, Modus(GetRight(P))) > count) { 
      modus = Modus(GetRight(P));
      count = CountX(P, modus);
    }
  } else { 
    modus = '#'; 
  }
  return modus;
}



