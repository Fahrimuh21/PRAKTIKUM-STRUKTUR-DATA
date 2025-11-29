/* File : List3. c*/
/* Deskripsi : realisasi body ADT list3 berkait representasi fisik pointer */
/* NIM & Nama : 24060124120037 /Muhammad Fahri */
/* Tanggal : 20 November 2025*/

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) //representasi fisik fungsi
{	//kamus lokal
	address P;
	//algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL) {
		next(P) = NIL;
		prev(P) = NIL;
		info(P) = E;
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
	if ( *P == NIL ){
		next(*P) = NIL;
		prev(*P) = NIL;
		free(*P);
		*P = NIL;	
	}
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
	//kamus lokal

	//algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
	//kamus lokal

	//algoritma
	return (First(L) == NIL);
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L){
	//kamus lokal
    address P;
    //algoritma
	
    if (IsEmptyList(L)) {
        printf("List kosong\n");
    } else {
		P=First(L);
        printf("Isi list: ");
        while(P!=NIL){
			printf("%c ", info(P));
			P=next(P);
		}
    }
}


/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
	//kamus lokal
	address P;
	int count;
	//algoritma
	if (First(L) == NIL) {
		return 0;
	}
	P = First(L);
	count = 1; 
	while(next(P) != NIL){
		count++;
		P = next(P);
	}
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ){
	//kamus lokal
	address P, Last;
	//algoritma
	P = Alokasi(V);
	if (P != NIL) {
		if (IsEmptyList(*L)) {
			First(*L) = P;
			next(P) = NIL;
			prev(P) = NIL;
		} else {
			next(P) = First(*L);
			prev(First(*L)) = P;
			First(*L) = P;
			prev(P)=NIL;
		}
	}
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
	//kamus lokal
	address P, Last;
	//algoritma 
	P = Alokasi(V);
	if (P != NIL){
		if (IsEmptyList(*L)){
			First(*L)=P;
			next(P)=NIL;
			prev(P)=NIL;
		}else{
			Last=First(*L);
			while(next(Last) != NIL){
				Last = next(Last);
			}
			next(Last)=P;
			prev(P)=Last;
			next(P)=NIL;
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
	//kamus lokal
	address P;
	//algoritma 
	if (!IsEmptyList(*L)) {
		P = First(*L);
		*V = info(P);
		if (next(P) == NIL) {
			First(*L) = NIL;
		} else {
			First(*L) = next(P);
			prev(First(*L)) = NIL;
		}
		Dealokasi(&P);
	} else {
		*V = '#';
	}
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
	//KAMUS LOKAL
	address P;
	//ALGORITMA
	if (!IsEmptyList(*L)){
		P = First(*L);
		if (next(P) == NIL){
			*V = info(P);
			First(*L) = NIL;
			Dealokasi(&P);
		}else{
			while (next(P) != NIL){
				P = next(P);
			}
			*V = info(P);
			next(prev(P)) = NIL;
			Dealokasi(&P);
		}
	}
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X){
	//kamus lokal
	address P, Prev, Del;
	//algoritma
	if (IsEmptyList(*L)) return;
	P = First(*L);
	Prev = NIL;
	while (P != NIL) {
		if (info(P) == X) {
			Del = P;
			if (P == First(*L)) {
				First(*L) = next(P);
				if (First(*L) != NIL) {
					prev(First(*L)) = NIL;
				}
				P = First(*L);
			} else {
				next(Prev) = next(P);
				if (next(P) != NIL) {
					prev(next(P)) = Prev;
				}
				P = next(P);
			}
			Dealokasi(&Del);
		} else {
			Prev = P;
			P = next(P);
		}
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A){
	//kamus lokal
	address P;
	//algoritma
	*A=NIL;
	P=First(L);
	while(P != NIL && info(P)!=X){
		P=next(P);
	}
	if(P != NIL && info(P)==X){
		*A = P;
	}
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
	//KAMUS LOKAL
	address P;
	//ALGORITMA
	P = First(*L);
	while (P != NIL && info(P) != X) {
		P = next(P);
	}
	if (P != NIL && info(P) == X) {
		info(P) = Y;
	}
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L){
	//kamus lokal
	address P, Q;
	List3 Ltemp;
	//algoritma
	if (IsEmptyList(*L)) return;
	CreateList(&Ltemp);
	P = First(*L);
	while (P != NIL) {
		Q = Alokasi(info(P));
		if (Q != NIL) {
			if (IsEmptyList(Ltemp)) {
				First(Ltemp) = Q;
				next(Q) = NIL;
				prev(Q) = NIL;
			} else {
				next(Q) = First(Ltemp);
				prev(First(Ltemp)) = Q;
				First(Ltemp) = Q;
			}
		}
		P = next(P);
	}
	*L = Ltemp;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
	//kamus lokal
	address P, Prec;
	//algoritma
	if (IsEmptyList(*L)) return;
	P = First(*L);
	while (P != NIL && info(P) != X) {
		P = next(P);
	}
	if (P != NIL) {
		Prec = Alokasi(V);
		if (Prec != NIL) {
			next(Prec) = next(P);
			prev(Prec) = P;
			if (next(P) != NIL) {
				prev(next(P)) = Prec;
			}
			next(P) = Prec;
		}
	}
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V){
	//kamus lokal
	address P, Prev, NewElm;
	//algoritma
	if (IsEmptyList(*L)) return;
	P = First(*L);
	Prev = NIL;
	while (P != NIL && info(P) != X) {
		Prev = P;
		P = next(P);
	}
	if (P != NIL) {
		NewElm = Alokasi(V);
		if (NewElm != NIL) {
			if (Prev == NIL) {
				next(NewElm) = First(*L);
				prev(First(*L)) = NewElm;
				First(*L) = NewElm;
				prev(NewElm) = NIL;
			} else {
				next(NewElm) = P;
				prev(NewElm) = Prev;
				next(Prev) = NewElm;
				prev(P) = NewElm;
			}
		}
	}
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V){
	//kamus lokal
	address P, Del;
	//algoritma
	if (IsEmptyList(*L)) return;
	P = First(*L);
	while (P != NIL && info(P) != X) {
		P = next(P);
	}
	if (P != NIL && next(P) != NIL) {
		Del = next(P);
		*V = info(Del);
		next(P) = next(Del);
		if (next(Del) != NIL) {
			prev(next(Del)) = P;
		}
		Dealokasi(&Del);
	}
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
	//kamus lokal
	address P, Prev, Del;
	//algoritma
	if (IsEmptyList(*L)) return;
	P = First(*L);
	Prev = NIL;
	while (P != NIL && info(P) != X) {
		Prev = P;
		P = next(P);
	}
	if (P != NIL && Prev != NIL) {
		Del = Prev;
		address Temp = First(*L);
		while (next(Temp) != Prev) {
			Temp = next(Temp);
		}
		next(Temp) = next(Prev);
		if (next(Prev) != NIL) {
			prev(next(Prev)) = Temp;
		}
		*V = info(Prev);
		Dealokasi(&Del);
	}
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X){
	//kamus lokal
	address P;
	int hitung;
	//ALGORITMA
	if (IsEmptyList(L)) return 0;
	P = First(L);
	hitung = 0;
	while (P!= NIL) {
		if (info(P) == X){
			hitung++;
		}
		P = next(P);
	}
	return hitung;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X){
	return CountX(L, X)*1.0/ (NbElm(L)*1.0);
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L){
	//KAMUS LOKAL
	address P;
	int max;

	//algoritma
	P=First(L);
	max=0;
	while(next(P)!=NIL){
		if(CountX(L, info(P))>max){
			max=CountX(L, info(P));
		}
	}
	return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L){
	//KAMUS LOKAL
	address P, simpan;
	int max;

	//algoritma
	P=First(L);
	max=0;
	while(P!=NIL){
		if(CountX(L, info(P))>max){
			max=CountX(L, info(P));
			simpan=P;
		}
		P=next(P);
	}
	return info(simpan);
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L){
	//kamus lokal
	address P;
	int hitung;
	//ALGORITMA
	if (IsEmptyList(L)) return 0;
	P = First(L);
	hitung = 0;
	while (P != NIL) {
		if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || 
			info(P) == 'O' || info(P) == 'a' || info(P) == 'i' || info(P) == 'u' ||
			info(P) == 'e' || info(P) == 'o' ){
				hitung++;
			}
		P = next(P);
	}
	return hitung;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L){
	//kamus lokal
	address P;
	int hitung;
	//ALGORITMA
	if (IsEmptyList(L)) return 0;
	P = First(L);
	hitung = 0;
	while (next(P) != NIL) {
		if ((info(P)=='N' || info(P)=='n') && (info(next(P))=='G'||info(next(P))=='g')){
				hitung++;
			}
		P = next(P);
	}
	return hitung;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X){
	//kamus lokal
	address P;
	int index, terdeteksi;
	//algoritma
	P=First(L);
	index=1;
	terdeteksi=0;
	while(next(P) != NIL){
		if(info(P)==X){
			if(terdeteksi==1){
				printf(", %d", index);
			}else{
				printf("%d ", index);
				terdeteksi=1;
			}
		}
		index++;
		P=next(P);
	}
	if(!terdeteksi){
		printf(0);
	}

}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X){
	//KAMUS LOKAL
	address P;
	//ALGORITMA
	if (!IsEmptyList(*L)){
		P = First(*L);
		while (next(P) != NIL){
			if (info(P) == X){
				next(prev(P)) = next(P);
				prev(next(P)) = prev(P);
				Dealokasi(&P);	
			}
			P = next(P);
		}
	}
}


/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L){
	//kamus lokal
	address P;
	//algoritma
	CreateList(L);
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L, info(P));
		P = next(P);
	}
	P = First(L2);
	while (P != NIL) {
		InsertVLast(L, info(P));
		P = next(P);
	}
} 

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2){
	//kamus lokal
	address P;
	int mid, count;
	//algoritma
	CreateList(L1);
	CreateList(L2);
	mid = NbElm(L) / 2;
	P = First(L);
	count = 0;
	while (P != NIL) {
		if (count < mid) {
			InsertVLast(L1, info(P));
		} else {
			InsertVLast(L2, info(P));
		}
		count++;
		P = next(P);
	}
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2){
	//kamus lokal
	address P;
	//algoritma
	CreateList(L2);
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L2, info(P));
		P = next(P);
	}
}

