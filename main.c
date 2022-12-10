#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct harga_bensin{
	int pertalite;
	int solar;
	int pertamax_turbo;	
	int pertamina_dex;
	int dexlite;
	int pertamax;

} BBM = {10000,6800,15200,18000,18300,13900};


void keluar(){
	system("cls");
	system("exit");
}

int validasi(int *var){
	char buff[1024];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%d %c", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

void revalidint(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validasi(var))
			break;
		printf("\t\tInput salah! Silahkan coba lagi! \n");
	}
}

int cekmengulang(char y, char n, char *prompt){
    char cek;
	while(1){
		printf(prompt);
		fflush(stdin);
		scanf("%c", &cek);
		if((cek=='y' || cek=='Y') || (cek=='n' || cek=='N')){
			if (cek == 'y' || cek == 'Y'){
				system("cls");
			}
			break;
		}else{
		printf("\t\tInput salah! Silahkan coba lagi! \n");
		}
	}
	if(cek=='n' || cek=='N') return 0;
	return 1;
}

void cover(){
    system("cls");
    printf("\t\t\t======================================================\n");
    printf("\t\t\t||           Program Tagihan Rekening Air           ||\n");
    printf("\t\t\t||        Algoritma dan Pemrograman kelas B         ||\n");
    printf("\t\t\t||__________________________________________________||\n");
    printf("\t\t\t||                                                  ||\n");
    printf("\t\t\t|| I Gede Satya Ariya Putra Sangjaya   2205551040   ||\n");
    printf("\t\t\t|| I Dewa Gd Dharma Pawitra            2205551041   ||\n");
    printf("\t\t\t||                                                  ||\n");
    printf("\t\t\t======================================================\n");
}

void jenis_bensin(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t|| Jenis Bahan Bakar Yang Tersedia :                ||\n");
        printf("\t\t\t||    1. Pertalite                                  ||\n");
        printf("\t\t\t||    2. Solar                                      ||\n");
        printf("\t\t\t||    3. Pertamax Turbo                             ||\n");
        printf("\t\t\t||    4. Pertamina Dex                              ||\n");
        printf("\t\t\t||    5. Dexlite                                    ||\n");
        printf("\t\t\t||    6. Pertamax                                   ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
        printf("\t\t\t>> "); scanf("%d", &inputan);
		validasi_jenis_bensin() = inputan;

			if(inputan == 1){
				pilihan_kendaraan_pertalite();
			}
			else if(inputan == 2){
				pilihan_kendaraan_solar();
			}
			else if(inputan == 3){
				nonsubsidi_pertamax_turbo();
			}
			else if(inputan == 4){
				nonsubsidi_pertamina_dex();
			}
			else if(inputan == 5){
				nonsubsidi_dexlite();
			}
			else if(inputan == 6){
				nonsubsidi_pertamax();
			}
			else if(inputan == 0){
				keluar();
            }
            else{
				printf("\n\t\t\t==============================");
				printf("\n\t\t\t|     Silahkan menginput     |");
				printf("\n\t\t\t|      data yang benar       |");
				printf("\n\t\t\t==============================");
			}
}

void pilihan_kendaraan_pertalite(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t|| Pilih Jenis Kendaraan Yang Tersedia :            ||\n");
        printf("\t\t\t||    1. Motor       (Roda Dua)                     ||\n");
        printf("\t\t\t||    2. Mobil       (Roda Empat)                   ||\n");
        printf("\t\t\t||    3. Truck       (Diesel)                       ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
        printf("\t\t\t>> "); scanf("%d", &inputan);
		if(inputan == 1){
			pilihan_cc_motor_pertalite();
		}
		else if(inputan == 2){
			pilihan_cc_mobil_pertalite();
		}
		else if(inputan == 3){
			pilihan_cc_truck_pertalite();
		}
		else if(inputan == 0){
			keluar();
		}
		else(inputan >3 || <0 || \n){
			printf("\n\t\t\t==============================");
			printf("\n\t\t\t|     Silahkan menginput     |");
			printf("\n\t\t\t|      data yang benar       |");
			printf("\n\t\t\t==============================");
		}
}

void pilihan_cc_motor_pertalite(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t|| Pilih Kapasitas CC Pada Kendaraan :              ||\n");
        printf("\t\t\t||    1. <250 CC  (Dibawah 250 CC)                  ||\n");
        printf("\t\t\t||    2. >250 CC  (250 CC atau diatasnya)           ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
        printf("\t\t\t>> "); scanf("%d", &inputan);
		if(inputan == 1){
			subsidi_pertalite();
		}
		else if(inputan == 2){
			nonsubsidi_pertalite();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n\t\t\t==============================");
			printf("\n\t\t\t|     Silahkan menginput     |");
			printf("\n\t\t\t|      data yang benar       |");
			printf("\n\t\t\t==============================");
		}	
}

void pilihan_cc_mobil_pertalite(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t|| Pilih Kapasitas CC Pada Kendaraan :              ||\n");
        printf("\t\t\t||    1. <1400 CC  (Dibawah 1400 CC)                ||\n");
        printf("\t\t\t||    2. >1400 CC  (1400 CC atau diatasnya)         ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
        printf("\t\t\t>> "); scanf("%d", &inputan);
		if(inputan == 1){
			subsidi_pertalite();
		}
		else if(inputan == 2){
			nonsubsidi_pertalite();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n\t\t\t==============================");
			printf("\n\t\t\t|     Silahkan menginput     |");
			printf("\n\t\t\t|      data yang benar       |");
			printf("\n\t\t\t==============================");
		}
}

void pilihan_cc_truck_pertalite(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t||       Truck tidak dapat membeli bahan bakar      ||\n");
        printf("\t\t\t||         pertalite, karena rasio kompresi         ||\n");
        printf("\t\t\t||  truck tidak cocok dengan octan dari pertalite   ||\n");
        printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t======================================================\n");
		pilihan_kendaraan_pertalite();	
}

void pilihan_kendaraan_solar(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t|| Pilih Jenis Kendaraan Yang Tersedia :            ||\n");
        printf("\t\t\t||    1. Motor       (Roda Dua)                     ||\n");
        printf("\t\t\t||    2. Mobil       (Roda Empat)                   ||\n");
        printf("\t\t\t||    3. Truck       (Diesel)                       ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
        printf("\t\t\t>> "); scanf("%d", &inputan);
		if(inputan == 1){
			pilihan_cc_motor_solar();
		}
		else if(inputan == 2){
			pilihan_cc_mobil_solar();
		}
		else if(inputan == 3){
			nonsubsidi_solar();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n\t\t\t==============================");
			printf("\n\t\t\t|     Silahkan menginput     |");
			printf("\n\t\t\t|      data yang benar       |");
			printf("\n\t\t\t==============================");
		}
}

void pilihan_cc_motor_solar(){
	int inputan;
		system("cls");
		printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t||       Truck tidak dapat membeli bahan bakar      ||\n");
        printf("\t\t\t||         pertalite, karena rasio kompresi         ||\n");
        printf("\t\t\t||  truck tidak cocok dengan octan dari pertalite   ||\n");
        printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t======================================================\n");
		pilihan_kendaraan_pertalite();		
}

void pilihan_cc_mobil_solar(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t|| Pilih Kapasitas CC Pada Kendaraan :              ||\n");
        printf("\t\t\t||    1. <1400 CC  (Dibawah 1400 CC)                ||\n");
        printf("\t\t\t||    2. >1400 CC  (1400 CC atau diatasnya)         ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
        printf("\t\t\t>> "); scanf("%d", &inputan);
		if(inputan == 1){
			subsidi_solar();
		}
		else if(inputan == 2){
			nonsubsidi_solar();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n\t\t\t==============================");
			printf("\n\t\t\t|     Silahkan menginput     |");
			printf("\n\t\t\t|      data yang benar       |");
			printf("\n\t\t\t==============================");
		}
}


void subsidi_pertalite(){
	int inputan;
	printf("Masukan Jumlah Bensin : ", &inputan);
	scanf("")
}
void subsidi_solar(){
}
void nonsubsidi_pertalite(){
}
void nonsubsidi_solar(){
}
void nonsubsidi_pertamax(){
}
void nonsubsidi_pertamax_turbo(){
}
void nonsubsidi_dexlite(){
}
void nonsubsidi_pertamina_dex(){
	int inputan;
		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t||                                                  ||\n");
        printf("\t\t\t|| Pilih Takaran Berdasarkan :                      ||\n");
        printf("\t\t\t||    1. Uang   (Rp)                                ||\n");
        printf("\t\t\t||    2. Bensin (L)                                 ||\n");
        printf("\t\t\t||                                         0. keluar||\n");
        printf("\t\t\t======================================================\n");
        printf("\t\t\t>> "); scanf("%d", &inputan);
		if(inputan == 1){
			uang_nonsubsidi_pertamina_dex();
		}
		else if(inputan == 2){
			bensin_nonsubsidi_pertamina_dex();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n\t\t\t==============================");
			printf("\n\t\t\t|     Silahkan menginput     |");
			printf("\n\t\t\t|      data yang benar       |");
			printf("\n\t\t\t==============================");
		}		
}

void uang_nonsubsidi_pertamina_dex(){
		int inputan;
		float bensin;
		float total;

		system("cls");
	    printf("\t\t\t======================================================\n");
        printf("\t\t\t||              Program kalkulator pada             ||\n");
        printf("\t\t\t||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("\t\t\t||__________________________________________________||\n");
		printf("\t\t\t|| Masukan Jumlah Uang : ");scanf("%d", &inputan);
		bensin = inputan / bbm.pertamina_dex;
		total = 0;
		while(total == liter || !(total>=liter)){
			system("cls");
			total = total + 0.0100;
			printf("Bensin = ", total);
		}
		printf("Total Bensin : ", total, "Liter : \n");
}
void bensin_nonsubsidi_pertamina_dex(){
}

int main(){
    
    cover();
    system("pause");
    system("cls");

    jenis_fasilitas();
    system("pause");
    system("cls");

}
