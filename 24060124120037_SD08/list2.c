/* File : List2. c*/
/* Deskripsi : realisasi body ADT list2 berkait representasi fisik pointer */
/* NIM & Nama : 24060124120037 /Muhammad Fahri */
/* Tanggal : 13 November 2025*/
#include <stdio.h>
#include <stdlib.h>
#include "list2.h" 

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E} */
address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma 
    P = (address) malloc(sizeof(Elm)); //casting
    if (P != NIL) { //ruang memori tersedia) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    //kamus lokal

    //algoritma
    if ( *P != NIL ) {
        next(*P) = NIL;
        free(*P);
        *P = NIL;
    }
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L){
    //kamus lokal

    //algoritma
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L){
    //kamus lokal

    //algoritma
    return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L){
    //kamus lokal

    //algoritma
    return ( (!IsEmptyList(L)) && (next(First(L)) == First(L)));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L){
    //kamus lokal
    address P = First(L);
    //algoritma
    if (P == NIL) {
        printf("List kosong\n");
    } else {
        printf("Isi list: ");
        do {
            printf("%c ", info(P));
            P = next(P);
        } while (P != First(L));
        printf("\n");
    }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L){
    //kamus lokal
    address P;
    int count;
    //algoritma
    if (First(L) == NIL) {
        return 0;
    }
    P = First(L);
    count = 1; 
    while(next(P) != First(L)){
        count++;
        P = next(P);
    }
    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ){
    //kamus lokal
    address P, Last;
    //algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P;
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(P) = First(*L);
            First(*L) = P;
            next(Last) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ){
    //kamus lokal
    address P, Last;
    //algoritma 
    P = Alokasi(V);
    if(P!=NIL){
        if(IsEmptyList(*L)){
            First(*L)=P;
            next(P)=P;
        }else{
            Last=First(*L);
            while(next(Last) != First(*L)){
                Last = next(Last);
            }
            next(Last)=P;
            next(P)=First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V){
    //kamus lokal
    address P, Last;
    //algoritma 
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);
        if (next(P) == P) {
            First(*L) = NIL;
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
        }
        Dealokasi(&P);
    } else {
        *V = '#';
    }

}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V){
    //kamus lokal 
    address P, Prev;
    //algoritma 
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (next(P) == P) {
            *V = info(P);
            First(*L) = NIL;
            Dealokasi(&P);
        } else {
            Prev = NIL;
            while (next(P) != First(*L)) {
                Prev = P;
                P = next(P);
            }
            *V = info(P);
            next(Prev) = First(*L);
            Dealokasi(&P);
        }
    } else {
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X){

    //kamus lokal
    address P, prev, del;

    //algoritma
    prev = First(*L);
    P = First(*L);

    if (info(P) == X) {
        if (next(P) == P) {
            First(*L) = NULL;
        } else {
            while (next(prev) != First(*L)) {
                prev = next(prev);
            }
            prev->next = next(P); 
            First(*L) = next(P);
        }
        Dealokasi(&P);
    }
}


/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A){
    //kamus lokal
    address P;
    //algoritma
    *A=NIL;
    P=First(L);
    while(next(P)!=First(L) && info(P)!=X){
        P=next(P);
    }
    if(info(P)==X){
        *A = P;
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y){
    //kamus lokal
    address P;
    //algoritma
    P = First(*L);
    while(info(P)!=X && next(P)!=First(*L)){
        P=next(P);
    }
    if(info(P)==X){
        info(P)=Y;
    }

}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L){
    //kamus lokal
	address P;
	List2 Ltemp;
	//algoritma
    if (IsEmptyList(*L)) return;
    CreateList(&Ltemp);
    P = First(*L);
	do {
		InsertVFirst(&Ltemp, info(P));
		P=next(P);
	} while(P != First(*L));
	P = First(*L);
    address temp;
    do {
        temp = P;
        P = next(P);
        Dealokasi(&temp);
    } while(P != First(*L));
    First(*L) = First(Ltemp);
}    


/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X){
    //kamus lokal
    address P;
    int hitung;
    //ALGORITMA
    if (IsEmptyList(L)) return 0;
    P = First(L);
    hitung = 0;
    do {
        if (info(P)==X) hitung++;
        P=next(P);
    } while(P!=First(L));
    return hitung;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X){
    //kamus lokal
    int countX, total;
    float frekuensi;
    //ALGORITMA
    countX = CountX(L, X);
    total = NbElm(L);
    if (total == 0) {
        frekuensi = 0.0;
    } else {
        frekuensi = (float)countX / total;
    }
    return frekuensi;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L){
    //kamus lokal
    address P;
    int hitung;
    //ALGORITMA
    if (IsEmptyList(L)) return 0;
    P = First(L);
    hitung = 0;
    do {
        if (info(P)=='a' || info(P)=='i' || info(P)=='u' || info(P)=='e' || info(P)=='o' ||
            info(P)=='A' || info(P)=='I' || info(P)=='U' || info(P)=='E' || info(P)=='O') {
            hitung++;
        }
        P=next(P);
    } while(P!=First(L));
    return hitung;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L){
    //kamus lokal
    address P;
    int hitung;
    //ALGORITMA
    if (IsEmptyList(L)) return 0;
    P = First(L);
    hitung = 0;
    do {
        if (info(P)=='N' || info(P)=='n') {
            address NextP = next(P);
            if (NextP != First(L) && (info(NextP)=='G' || info(NextP)=='g')) {
                hitung++;
            }
        }
        P=next(P);
    } while(P!=First(L));
    return hitung;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V){
    //kamus lokal
	address P, Prec;
	//algoritma
	if (IsEmptyList(*L)) return;
	P = First(*L);
	do {
		if (info(P) == X) {
			Prec = Alokasi(V);
			if (Prec != NIL) {
				next(Prec) = next(P);
				next(P) = Prec;
			}
			return;
		}
		P = next(P);
	} while(P != First(*L));
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V){
    //kamus lokal
    address P, Prev, NewElm;
    //algoritma
    if (IsEmptyList(*L)) return;
    P = First(*L);
    Prev = NIL;
    do {
        if (info(P) == X) {
            NewElm = Alokasi(V);
            if (NewElm != NIL) {
                if (Prev == NIL) {
                    address Last = First(*L);
                    while (next(Last) != First(*L)) {
                        Last = next(Last);
                    }
                    next(NewElm) = First(*L);
                    First(*L) = NewElm;
                    next(Last) = First(*L);
                } else {
                    next(NewElm) = P;
                    next(Prev) = NewElm;
                }
            }
            return;
        }
        Prev = P;
        P = next(P);
    } while(P != First(*L));
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V){
    //kamus lokal
    address P, Del;
    //algoritma
    if (IsEmptyList(*L)) return;
    P = First(*L);
    do {
        if (info(P) == X) {
            Del = next(P);
            *V = info(Del);
            if (Del == First(*L)) {
                First(*L) = next(Del);
            }
            next(P) = next(Del);
            Dealokasi(&Del);
            return;
        }
        P = next(P);
    } while(P != First(*L));
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V){
    //kamus lokal
    address P, Prev, Del;
    //algoritma
    if (IsEmptyList(*L)) return;
    P = First(*L);
    Prev = NIL;
    do {
        if (info(P) == X && Prev != NIL) {
            Del = Prev;
            // Cari elemen sebelum Prev
            address Temp = First(*L);
            while (next(Temp) != Prev) {
                Temp = next(Temp);
            }
            next(Temp) = next(Prev);
            *V = info(Prev);
            Dealokasi(&Del);
            return;
        }
        Prev = P;
        P = next(P);
    } while(P != First(*L));
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X){
    //kamus lokal
    address P, Prev, Del;
    //algoritma
    if (IsEmptyList(*L)) {
        return;
    }
    P = First(*L);
    Prev = NIL;
    while (P != First(*L) && !IsEmptyList(*L)) {
        if (info(P) == X) {
            Del = P;
            if (P == First(*L)) {
                if (next(P) == P) {
                    First(*L) = NIL;
                    Dealokasi(&Del);
                    return;
                } else {
                    address Last = First(*L);
                    while (next(Last) != First(*L)) {
                        Last = next(Last);
                    }
                    First(*L) = next(P);
                    next(Last) = First(*L);
                    P = First(*L);
                }
            } else {
                next(Prev) = next(P);
                P = next(P);
            }
            Dealokasi(&Del);
        } else {
            Prev = P;
            P = next(P);
        }
    }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X){
    //kamus lokal
    address P;
    int hitung;
    //ALGORITMA
    if (IsEmptyList(L)) {
        printf("0\n");
        return;
    }
    P = First(L);
    hitung = 1;
    int found = 0;
    do {
        if (info(P)==X) {
            printf("%d ", hitung);
            found = 1;
        }
        P=next(P);
        hitung++;
    } while(P!=First(L));
    if (!found) {
        printf("0");
    }
    printf("\n");
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L){
    //kamus lokal
    address P, Q;
    int maxCount, count;
    infotype modus;
    //ALGORITMA
    if (IsEmptyList(L)) return 0;
    maxCount = 0;
    modus = '\0';
    P = First(L);
    do {
        count = 0;
        Q = First(L);
        do {
            if (info(Q) == info(P)) {
                count++;
            }
            Q = next(Q);
        } while(Q != First(L));
        if (count > maxCount) {
            maxCount = count;
            modus = info(P);
        }
        P = next(P);
    } while(P != First(L));
    return maxCount;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L){
    //kamus lokal
    address P, Q;
    int maxCount, count;
    infotype modus;
    //ALGORITMA
    if (IsEmptyList(L)) return '\0';
    maxCount = 0;
    modus = '\0';
    P = First(L);
    do {
        count = 0;
        Q = First(L);
        do {
            if (info(Q) == info(P)) {
                count++;
            }
            Q = next(Q);
        } while(Q != First(L));
        if (count > maxCount) {
            maxCount = count;
            modus = info(P);
        }
        P = next(P);
    } while(P != First(L));
    return modus;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L){
    //kamus lokal
    address P;
    //algoritma
    CreateList(L);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while(P != First(L1));
    }
    if (!IsEmptyList(L2)) {
        P = First(L2);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while(P != First(L2));
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2){
    //kamus lokal
    address P;
    int count, mid;
    //algoritma
    CreateList(L1);
    CreateList(L2);
    if (IsEmptyList(L)) return;
    int total = NbElm(L);
    mid = total / 2;
    count = 0;
    P = First(L);
    do {
        if (count < mid) {
            InsertVLast(L1, info(P));
        } else {
            InsertVLast(L2, info(P));
        }
        P = next(P);
        count++;
    } while(P != First(L));
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2){
    //kamus lokal
    address P;
    //algoritma
    CreateList(L2);
    if (IsEmptyList(L1)) return;
    P = First(L1);
    do {
        InsertVLast(L2, info(P));
        P = next(P);
    } while(P != First(L1));
}
