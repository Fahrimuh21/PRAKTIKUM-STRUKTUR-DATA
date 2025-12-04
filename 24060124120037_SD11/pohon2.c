/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124120037/Muhammad Fahri */
/* Tanggal : 2 Desember 2025*/

#include "pohon2.h"
#include <stdio.h>

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ){
    //kamus lokal
    int i;
    //algoritma
    if (IsEmptyTree(P)) {
        for (i = 0; i < H; i++) {
        printf(" ");
        }
        printf("(\n");
        for (i = 0; i < H; i++) {
        printf(" ");
        }
        printf(")\n");
    } else {
        PrintTreeInden(GetRight(P), H + 4);
        for (i = 0; i < H; i++) {
        printf(" ");
        }
        printf("%c\n", GetAkar(P));
        PrintTreeInden(GetLeft(P), H + 4);
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
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

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y){
    //kamus lokal

    //algoritma
    if (!IsEmptyTree(*P)) { 
        if (GetAkar(*P) == X) {
        akar(*P) = Y;
        }
        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X){
    //kamus lokal
    bintree NewNode;
    //algoritma
    if (IsEmptyTree(*P)) {
        NewNode = AlokasiTree(X);
        if (NewNode != NIL) {
            *P = NewNode;
        }
    } else {
        AddDaunTerkiri(GetLeft(P), X);
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri){
    //kamus lokal
    bintree NewNode;
    //algoritma
    if (!IsEmptyTree(P)) {
        if (IsDaun(*P) && GetAkar(*P) == X) {
        NewNode = AlokasiTree(Y);
        if (NewNode != NIL) {
            if (Kiri) {
                left(*P) = NewNode;
            } else {
                right(*P) = NewNode;
            }
        }
        } else {
        AddDaun(&left(*P), X, Y, Kiri);
        AddDaun(&right(*P), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X){
    //kamus lokal
    bintree NewNode;
    //algoritma
    if (IsEmptyTree(*P)) {
        NewNode = AlokasiTree(X);
        if (NewNode != NIL) {
        (*P) = NewNode;
        }
    } else {
        if (NbElm(GetLeft(*P)) <= NbElm(GetRight(*P))) {
        InsertX(&left(*P), X);
        } else {
        InsertX(&right(*P), X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype X){
    //kamus lokal
    bintree Temp;
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
        X = GetAkar(*P);
        DealokasiTree(*P);
        } else {
        DelDaunTerkiri(&left(*P), X);
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X){
    //kamus lokal
    bintree Temp;
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P) && GetAkar(*P) == X) {
        DealokasiTree(P);
        } else {
        DelDaun(&left(*P), X);
        DelDaun(&right(*P), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X){
    //kamus lokal

    //algoritma
    if (!IsEmptyTree(*P)) {
        if (GetAkar(*P) == X) {
        DelDaunTerkiri(P, X); //menghapus daun terkiri sebagai pengganti
        } else {
        DeleteX(&left(*P), X);
        DeleteX(&right(*P), X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n){
    //kamus lokal
    bintree P;
    infotype X;
    int nLeft, nRight;
    //algoritma
    if (n <= 0) {
        return NIL;
    } else {
        printf("Masukkan nilai node: ");
        scanf(" %c", &X);
        nLeft = n / 2;
        nRight = n - nLeft - 1;
        P = Tree(X, BuildBalanceTree(nLeft), BuildBalanceTree(nRight));
        return P;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P){
    //kamus lokal
    int leftCount, rightCount;
    //algoritma
    if (IsEmptyTree(P)) {
        return true;
    } else {
        leftCount = NbElm(GetLeft(P));
        rightCount = NbElm(GetRight(P));
        if (abs(leftCount - rightCount) <= 1) {
        return IsBalanceTree(GetLeft(P)) && IsBalanceTree(GetRight(P));
        } else {
        return false;
        }
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P){
    //kamus lokal
    int maxLeft, maxRight, currentMax;
    //algoritma
    if (IsEmptyTree(P)) {
        return '\0';
    } else {
        currentMax = GetAkar(P);
        maxLeft = maxTree(GetLeft(P));
        maxRight = maxTree(GetRight(P));
        
        if (maxLeft > currentMax) {
        currentMax = maxLeft;
        }
        if (maxRight > currentMax) {
        currentMax = maxRight;
        }
        return currentMax;
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P){
    //kamus lokal
    int minLeft, minRight, currentMin;
    //algoritma
    if (IsEmptyTree(P)) {
        return '\255';
    } else {
        currentMin = GetAkar(P);
        minLeft = minTree(GetLeft(P));
        minRight = minTree(GetRight(P));
        
        if (minLeft < currentMin) {
        currentMin = minLeft;
        }
        if (minRight < currentMin) {
        currentMin = minRight;
        }
        return currentMin;
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X){
    //kamus lokal

    //algoritma
    if (IsEmptyTree(P)) {
        return false;
    } else if (GetAkar(P) == X) {
        return true;
    } else if (X < GetAkar(P)) {
        return BSearch(GetLeft(P), X);
    } else {
        return BSearch(GetRight(P), X);
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X){
    //kamus lokal
    bintree NewNode;
    //algoritma
    if (IsEmptyTree(P)) {
        NewNode = AlokasiTree(X);
        return NewNode;
    } else {
        if (X < GetAkar(P)) {
        left(P) = InsSearch(GetLeft(P), X);
        } else {
        right(P) = InsSearch(GetRight(P), X);
        }
        return P;
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X){
    //kamus lokal
    bintree Temp;
    infotype Y;
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (X < GetAkar(*P)) {
        DelBtree(&left(*P), X);
        } else if (X > GetAkar(*P)) {
        DelBtree(&right(*P), X);
        } else {
        if (IsDaun(*P)) {
            DealokasiTree(P);
        } else if (IsUnerLeft(*P)) {
            Temp = *P;
            *P = GetLeft(*P);
            DealokasiTree(&Temp);
        } else if (IsUnerRight(*P)) {
            Temp = *P;
            *P = GetRight(*P);
            DealokasiTree(&Temp);
        } else {
            Temp = GetLeft(*P);
            while (!IsEmptyTree(GetRight(Temp))) {
            Temp = GetRight(Temp);
            }
            Y = GetAkar(Temp);
            akar(*P) = Y; 
            DelBtree(&left(*P), Y);
        }
        }
    }
}
