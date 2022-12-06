#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct BBM{
	int pertalite;
	int pertamax;
	int pertamax_turbo;
	int dexlite;
	int pertamina_dex;
	int solar
} bensin_default = {10000,14500,15900,17100,17400,6800};


void keluar(){
	system("cls");
	system("exit");
}

void cover(){
    system("cls");
    printf("\t\t\t======================================================\n");
    printf("\t\t\t||                                                  ||\n");
    printf("\t\t\t||           Program Tagihan Rekening Air           ||\n");
    printf("\t\t\t||        Algoritma dan Pemrograman kelas B         ||\n");
    printf("\t\t\t||                                                  ||\n");
    printf("\t\t\t||__________________________________________________||\n");
    printf("\t\t\t||                                                  ||\n");
    printf("\t\t\t|| I Gede Satya Ariya Putra Sangjaya   2205551040   ||\n");
    printf("\t\t\t|| I Dewa Gd Dharma Pawitra            2205551041   ||\n");
    printf("\t\t\t||                                                  ||\n");
    printf("\t\t\t======================================================\n");
}

void pilihan_subsidi(){
	int pilihan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
        printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t|| 1. SUBSIDI     < 1.500cc                         ||\n");
        printf("\t\t\t|| 2. NON-SUBSIDI > 1.500cc                         ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
		printf("\t\t\t >> "); scanf("%d", &pilihan);
		if(pilihan == 1){
			subsidi();
		}
		else if(pilihan == 2){
			nonsubsidi();
		}
		else if(pilihan == 0){
			keluar();
		}
		else{
			printf("\n\t\t\t==============================");
			printf("\n\t\t\t|     Silahkan menginput     |");
			printf("\n\t\t\t|      data yang benar       |");
			printf("\n\t\t\t==============================");
		}
}

void jenis_bensin(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                      SUBSIDI                     ||\n");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t|| Jenis Bahan Bakar Yang Tersedia :                ||\n");
        printf("\t\t\t||    1. Pertalite                                  ||\n");
        printf("\t\t\t||    2. Pertamax                                   ||\n");
        printf("\t\t\t||    3. Premium                                    ||\n");
        printf("\t\t\t||    4. Pertamax Turbo                             ||\n");
        printf("\t\t\t||    5. Dexlite                                    ||\n");
        printf("\t\t\t||    6. Pertamina Dex                              ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
        printf("\t\t\t>> "); scanf("%d", &inputan);

			if(inputan == 1){
				kpa();
			}
			else if(inputan == 2){
				kpb();
			}
			else if(inputan == 3){
				kpc();
			}
			else if(inputan == 4){
				kpd();
			}
			else if(inputan == 5){
				kpe();
			}
			else if(inputan == 6){
				kpe();
			}
			else if(inputan == 0){
				exit(0);
            }
            else{
					printf("\n\t\t\t==============================");
					printf("\n\t\t\t|     Silahkan menginput     |");
					printf("\n\t\t\t|      data yang benar       |");
					printf("\n\t\t\t==============================");
			}
}

void nonsubsidi(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                    NON-SUBSIDI                   ||\n");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t|| Jenis Bahan Bakar Yang Tersedia :                ||\n");
        printf("\t\t\t||    1. Pertalite                                  ||\n");
        printf("\t\t\t||    2. Pertamax                                   ||\n");
        printf("\t\t\t||    3. Premium                                    ||\n");
        printf("\t\t\t||    4. Pertamax Turbo                             ||\n");
        printf("\t\t\t||    5. Dexlite                                    ||\n");
        printf("\t\t\t||    6. Pertamina Dex                              ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");

}

void subsidi_pertalite(){
}
void subsidi_pertamax(){
}
void subsidi_pertamax_turbo(){
}
void subsidi_dexlite(){
}
void subsidi_pertamina_dex(){
}
void subsidi_solar(){
}

void nonsubsidi_pertalite(){
}
void nonsubsidi_pertamax(){
}
void nonsubsidi_pertamax_turbo(){
}
void nonsubsidi_dexlite(){
}
void nonsubsidi_pertamina_dex(){
}
void nonsubsidi_solar(){
}


int main(){
    
    cover();
    system("pause");
    system("cls");

    jenis_fasilitas();
    system("pause");
    system("cls");

}
