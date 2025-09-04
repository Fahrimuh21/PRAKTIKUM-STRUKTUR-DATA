/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : Muhammad Fahri*/
/* Tanggal   : 4 September 2025*/
/***********************************/
#include <stdio.h>
#include "titik.c"

int main() {
	//kamus main
	Titik T1, T2;
	
	//algoritma
	printf("Halo, ini driver modul Titik /n");
	makeTitik(&T1,4,5);
	makeTitik(&T2,3,5);

	printf("\n Nilai absis T1 = %d",getAbsis(T1));
	printf("\n Nilai ordinat T1 = %d",getOrdinat(T1));

	printf("\n Nilai absis T2 = %d",getAbsis(T2));
	printf("\n Nilai ordinat T2 = %d",getOrdinat(T2));

	//untuk cek setAbsis dan setOrdinat
	setAbsis(&T1, 5);
	printf("\n Nilai absis T1 setelah setAbsis = %d",getAbsis(T1));
	setOrdinat(&T1, 3);
	printf("\n Nilai ordinat T1 setelah setOrdinat = %d",getOrdinat(T1));

	//cek origin, poisisi equal
	printf("\n Apakah origin T1 = %d",isOrigin(T1));
	printf("\n Apakah T1 berada di sumbu y = %d",isOnSumbuX(T1));
	printf("\n Apakah T1 berada di sumbu x = %d",isOnSumbuY(T1));
	printf("\n Apakah equal untuk T1 dan T2 = %d",isEqual(T1, T2));

	//cek geser, refleksi, dilatasi, dan posisi
	geser(&T1, 2, 1);
	printf("\n Posisi setelah T1 digeser 2 di X dan 1 di Y= %d,%d",getAbsis(T1), getOrdinat(T1));


	refleksiX(&T1);
	printf("\n Posisi setelah T1 direfleksikan dengan X = %d,%d",getAbsis(T1), getOrdinat(T1));

	refleksiY(&T1);
	printf("\n Posisi setelah T1 direfleksikan dengan Y = %d,%d",getAbsis(T1), getOrdinat(T1));

	dilatasi(&T1, 4);
	printf("\n Posisi setelah T1 didilatasi = %d,%d",getAbsis(T1), getOrdinat(T1));

	dilatasiX(&T1, T2, 3);
	printf("\n Posisi setelah T1 didilatasi dengan X T2 dan DILATASI 3 = %d,%d",getAbsis(T1), getOrdinat(T1));
	
	printf("\n Posisi kuadran T1 =  %d", kuadran(T1));

	return 0;
}
