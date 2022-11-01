#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//Halaman Utama
	int stop_p = 0;
	while(stop_p == 0){
		welcome();
		option();
		printf("\n");
		
		//Pilih Opsi Menu
		scanf("%d", &os);
		
		//Verfifikasi imputan user
		verif_opsi(os, &os, &condition);
		if(condition == 1){
			//Menuju halaman sesuai opsi yang telah dipilih
			pilih_opsi_menu(os, &stop_p);
		}else{
			printf("Err : Terjadi Kesalahan");
		} 
	}
	system("cls");
	printf("akhir dari program...");
	return 0;
}



