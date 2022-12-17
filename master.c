#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

#define batas_pembelian 120
#define data_pembelian 115

float validasi();
void jenis_fasilitas();
void validasi_jenis_bensin(), jenis_bensin();
void pilihan_kendaraan_pertalite(), pilihan_cc_mobil_pertalite(), pilihan_cc_motor_pertalite(), pilihan_cc_truck_pertalite();
void pilihan_kendaraan_solar(), pilihan_cc_mobil_solar(), pilihan_cc_motor_solar(), pilihan_cc_motor_solar();
void subsidi_pertalite(), uang_subsidi_pertalite(), bensin_subsidi_pertalite();
void nonsubsidi_pertalite(), uang_nonsubsidi_pertalite(), bensin_nonsubsidi_pertalite();
void subsidi_solar(), uang_subsidi_solar(), bensin_subsidi_solar();
void nonsubsidi_solar(), uang_nonsubsidi_solar(), bensin_nonsubsidi_solar();
void nonsubsidi_pertamax_turbo(), uang_nonsubsidi_pertamax_turbo(), bensin_nonsubsidi_pertamax_turbo();
void nonsubsidi_pertamina_dex(), uang_nonsubsidi_pertamina_dex(), bensin_nonsubsidi_pertamina_dex();
void nonsubsidi_dexlite(), uang_nonsubsidi_dexlite(), bensin_nonsubsidi_dexlite();
void nonsubsidi_pertamax(), uang_nonsubsidi_pertamax(), bensin_nonsubsidi_pertamax();

struct harga_bensin {
	int pertalite;
	int solar;
	int pertamax_turbo;
	int pertamina_dex;
	int dexlite;
	int pertamax;

} BBM = {10000,6800,15200,18000,18300,13900};


void keluar() {
	system("cls");
	system("exit");
}

/*void pilihan_keluar(){

	printf("Ingin Mengulang Program? (Y/T)");

}
*/



float validasi() {
	float inputan;
	float jumlah;
	float hasil;
	float sisa;
	scanf("%f", &inputan);
	jumlah = inputan + data_pembelian;
	sisa = batas_pembelian - data_pembelian;

	if( jumlah > batas_pembelian) {
		printf("Anda Hanya Dapat Membeli Sebanyak : %.5f\n", sisa);
		printf("|| Masukan Jumlah Liter : ");
		getchar();
		validasi();
	}
	return inputan;
}


int validasi_arr(int *var) {
	char buff[1024];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL) {
		if(sscanf(buff, "%d %c", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

void revalidint(int *var, char *prompt) {
	while(1) {
		printf(prompt);
		if(validasi_arr(var))
			break;
		printf("\t\tInput salah! Silahkan coba lagi! \n");
	}
}

int cekmengulang(char y, char n, char *prompt) {
	char cek;
	while(1) {
		printf(prompt);
		fflush(stdin);
		scanf("%c", &cek);
		if((cek=='y' || cek=='Y') || (cek=='T' || cek=='t')) {
			if (cek == 'y' || cek == 'Y') {
				system("cls");
				jenis_fasilitas();
			}
			break;
		} else {
			printf("\t\tInput salah! Silahkan coba lagi! \n");
		}
	}
	if(cek=='t' || cek=='T') {
		system("cls");
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("||                                                  ||\n");
		printf("||                 TERIMA KASIH :)                  ||\n");
		printf("||                                                  ||\n");
		printf("======================================================\n");
		system("exit");
	}
}



void cover() {
	system("cls");
	printf("======================================================\n");
	printf("||           Program Tagihan Rekening Air           ||\n");
	printf("||        Algoritma dan Pemrograman kelas B         ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| I Gede Satya Ariya Putra Sangjaya   2205551040   ||\n");
	printf("|| I Dewa Gd Dharma Pawitra            2205551041   ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n");
}

void methode() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Methode Pembayaran                         ||\n");
	printf("||    1. Debit Card                                 ||\n");
	printf("||    2. Cash                                       ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		nonsubsidi_pertamina_dex();
	} else if(inputan == 2) {
		bensin_nonsubsidi_pertamina_dex();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}

void jenis_fasilitas() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Jenis Bahan Bakar Yang Tersedia :                ||\n");
	printf("||    1. Pertalite                                  ||\n");
	printf("||    2. Solar                                      ||\n");
	printf("||    3. Pertamax Turbo                             ||\n");
	printf("||    4. Pertamina Dex                              ||\n");
	printf("||    5. Dexlite                                    ||\n");
	printf("||    6. Pertamax                                   ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);

	if(inputan == 1) {
		pilihan_kendaraan_pertalite();
	} else if(inputan == 2) {
		pilihan_kendaraan_solar();
	} else if(inputan == 3) {
		nonsubsidi_pertamax_turbo();
	} else if(inputan == 4) {
	   methode();
	} else if(inputan == 5) {
		nonsubsidi_dexlite();
	} else if(inputan == 6) {
		nonsubsidi_pertamax();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}


void pilihan_kendaraan_pertalite() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Jenis Kendaraan Yang Tersedia :            ||\n");
	printf("||    1. Motor       (Roda Dua)                     ||\n");
	printf("||    2. Mobil       (Roda Empat)                   ||\n");
	printf("||    3. Truck       (Diesel)                       ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		pilihan_cc_motor_pertalite();
	} else if(inputan == 2) {
		pilihan_cc_mobil_pertalite();
	} else if(inputan == 3) {
		pilihan_cc_truck_pertalite();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}

void pilihan_cc_motor_pertalite() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Kapasitas CC Pada Kendaraan :              ||\n");
	printf("||    1. <250 CC  (Dibawah 250 CC)                  ||\n");
	printf("||    2. >250 CC  (250 CC atau diatasnya)           ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		subsidi_pertalite();
	} else if(inputan == 2) {
		nonsubsidi_pertalite();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}

void pilihan_cc_mobil_pertalite() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Kapasitas CC Pada Kendaraan :              ||\n");
	printf("||    1. <1400 CC  (Dibawah 1400 CC)                ||\n");
	printf("||    2. >1400 CC  (1400 CC atau diatasnya)         ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		subsidi_pertalite();
	} else if(inputan == 2) {
		nonsubsidi_pertalite();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}

void pilihan_cc_truck_pertalite() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("||       Truck tidak dapat membeli bahan bakar      ||\n");
	printf("||         pertalite, karena rasio kompresi         ||\n");
	printf("||  truck tidak cocok dengan octan dari pertalite   ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n");
	pilihan_kendaraan_pertalite();
}

void pilihan_kendaraan_solar() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Jenis Kendaraan Yang Tersedia :            ||\n");
	printf("||    1. Motor       (Roda Dua)                     ||\n");
	printf("||    2. Mobil       (Roda Empat)                   ||\n");
	printf("||    3. Truck       (Diesel)                       ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		pilihan_cc_motor_solar();
	} else if(inputan == 2) {
		pilihan_cc_mobil_solar();
	} else if(inputan == 3) {
		nonsubsidi_solar();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}

void pilihan_cc_motor_solar() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("||       Truck tidak dapat membeli bahan bakar      ||\n");
	printf("||         pertalite, karena rasio kompresi         ||\n");
	printf("||  truck tidak cocok dengan octan dari pertalite   ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n");
	pilihan_kendaraan_pertalite();
}

void pilihan_cc_mobil_solar() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Kapasitas CC Pada Kendaraan :              ||\n");
	printf("||    1. <1400 CC  (Dibawah 1400 CC)                ||\n");
	printf("||    2. >1400 CC  (1400 CC atau diatasnya)         ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		subsidi_solar();
	} else if(inputan == 2) {
		nonsubsidi_solar();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}


void subsidi_pertalite() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Takaran Berdasarkan :                      ||\n");
	printf("||    1. Uang   (Rp)                                ||\n");
	printf("||    2. Bensin (L)                                 ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		uang_nonsubsidi_pertalite();
	} else if(inputan == 2) {
		bensin_nonsubsidi_pertalite();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}

int validasistruck(){
	char ch;
    char * data;
    int vlds = 0;
    data = (char *) malloc(sizeof(char));
  while ((ch = getch()) != 13){
        if ((ch >= '1' && ch <= '2')|| (ch == '.')){
            printf("%c", ch);
            data[vlds] = ch;
            vlds++;
        }
    }
    data[vlds] = '\0';
    return atof(data);
}

void uang_subsidi_pertalite() {
	float inputan;
	float liter;
	float total;
	float hasil;

	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Uang : ");
	scanf("%f", &inputan);
	liter = inputan / BBM.pertalite;
	hasil = liter * BBM.pertalite;
	total = 0;
	while((total<=liter)) {
		system("cls");
		total = total + 0.0100;
		printf("liter = %f\n", total);
	}
	printf("Total liter : %f", total);
	printf("Liter");
	time_t t;
	t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE * out;
	out = fopen("uang_subsidi_pertalite.txt","w");//cetak file nota
	fprintf (out, "==========================================\n\n");
	fprintf (out, "          SPBU Universitas Udayana          \n");
	fprintf (out, "            JL, Raya Kampus Unud            \n");
	fprintf (out, "              BUKIT JIMBARAN                \n");
	fprintf (out, "==========================================\n\n");
	fprintf (out, "Tanggal      : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fprintf (out, "Harga/Liter  : %2.1f \n",total);
	fprintf (out, "Jumlah Liter : %2.1f \n",total);
	fprintf (out, "Harga  : %2.1f \n",total);
	fprintf (out, "---------------------------------------------\n");
	fprintf (out, "              TOTAL PEMBAYARAN               \n");
	fprintf (out, "                 %2.1f \n",total);
	fprintf (out, "---------------------------------------------\n");
	fclose  (out);
	printf("\n");
	printf("\t\t\t==============================================\n");
	printf("\t\t\t|        -NOTA ANDA BERHASIL DICETAK-        |\n");
	printf("\t\t\t==============================================\n");


}
void bensin_subsidi_pertalite() {
	float inputan;
	float uang;
	float total;
	float hasil;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Liter : ");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.pertalite;
	hasil = uang * BBM.pertalite;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		system("cls");
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("|| Uang = %.2f\n", total);
	}
	printf("|| Yang Perlu dibayar : %.2f\n\n", total);
	printf("|| Ingin Membuat Struck Dari Pembelian Tadi? (Y/T)");
		time_t t;
	t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE * out;
	out = fopen("bensin_subsidi_pertalite.txt","w");//cetak file nota
	fprintf (out, "==========================================\n\n");
	fprintf (out, "          SPBU Universitas Udayana          \n");
	fprintf (out, "            JL, Raya Kampus Unud            \n");
	fprintf (out, "              BUKIT JIMBARAN                \n");
	fprintf (out, "==========================================\n\n");
	fprintf (out, "Tanggal      : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fprintf (out, "Jumlah Liter : %2.1f Liter\n",total);
	fprintf (out, "Harga  : %2.1f \n",inputan);
	fprintf (out, "------------------------------------------\n");
	fprintf (out, "              TOTAL PEMBAYARAN               \n");
	fprintf (out, "                 %2.1f \n",inputan);
	fprintf (out, "------------------------------------------\n");
	fclose  (out);
}


void subsidi_solar() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Takaran Berdasarkan :                      ||\n");
	printf("||    1. Uang   (Rp)                                ||\n");
	printf("||    2. Bensin (L)                                 ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		uang_subsidi_solar();
	} else if(inputan == 2) {
		bensin_subsidi_solar();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}
void uang_subsidi_solar() {
	float inputan;
	float liter;
	float total;
	float hasil;

	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Uang : ");
	scanf("%f", &inputan);
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	liter = inputan / BBM.solar;
	hasil = liter * BBM.solar;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=liter)) {
		//system("cls");
		total = total + 0.0100;
		printf("liter = %f\n", total);
	}
	printf("Total liter : %f", total);
	printf("Liter");
		time_t t;
	t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE * out;
	out = fopen("uang_subsidi_solar.txt","w");//cetak file nota
	fprintf (out, "==========================================\n\n");
	fprintf (out, "          SPBU Universitas Udayana          \n");
	fprintf (out, "            JL, Raya Kampus Unud            \n");
	fprintf (out, "              BUKIT JIMBARAN                \n");
	fprintf (out, "==========================================\n\n");
	fprintf (out, "Tanggal      : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fprintf (out, "Jumlah Liter : %2.1f Liter\n",total);
	fprintf (out, "Harga  : %2.1f \n",inputan);
	fprintf (out, "------------------------------------------\n");
	fprintf (out, "              TOTAL PEMBAYARAN               \n");
	fprintf (out, "                 %2.1f \n",inputan);
	fprintf (out, "------------------------------------------\n");
	fclose  (out);
}
void bensin_subsidi_solar() {
	float inputan;
	float uang;
	float total;
	float hasil;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Liter : ");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.solar;
	hasil = uang * BBM.solar;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		system("cls");
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("|| Uang = %.2f\n", total);
	}
	printf("|| Yang Perlu dibayar : %.2f\n\n", total);
	printf("|| Ingin Membuat Struck Dari Pembelian Tadi? (Y/T)");
	time_t t;
	t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE * out;
	out = fopen("bensin_subsidi_solar.txt","w");//cetak file nota
	fprintf (out, "==========================================\n\n");
	fprintf (out, "          SPBU Universitas Udayana          \n");
	fprintf (out, "            JL, Raya Kampus Unud            \n");
	fprintf (out, "              BUKIT JIMBARAN                \n");
	fprintf (out, "==========================================\n\n");
	fprintf (out, "Tanggal      : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fprintf (out, "Jumlah Liter : %2.1f Liter\n",total);
	fprintf (out, "Harga  : %2.1f \n",inputan);
	fprintf (out, "------------------------------------------\n");
	fprintf (out, "              TOTAL PEMBAYARAN               \n");
	fprintf (out, "                 %2.1f \n",inputan);
	fprintf (out, "------------------------------------------\n");
	fclose  (out);
}


void nonsubsidi_pertalite() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Takaran Berdasarkan :                      ||\n");
	printf("||    1. Uang   (Rp)                                ||\n");
	printf("||    2. Bensin (L)                                 ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		uang_nonsubsidi_pertalite();
	} else if(inputan == 2) {
		bensin_nonsubsidi_pertalite();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}

void uang_nonsubsidi_pertalite() {
	float inputan;
	float liter;
	float total;
	float hasil;

	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Uang : ");
	scanf("%f", &inputan);
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	liter = inputan / BBM.pertalite;
	hasil = liter * BBM.pertalite;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=liter)) {
		system("cls");
		total = total + 0.0100;
		printf("liter = %f\n", total);
	}
	printf("Total liter : %f", total);
	printf("Liter");
time_t t;
	t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE * out;
	out = fopen("uang_nonsubsidi_pertalite.txt","w");//cetak file nota
	fprintf (out, "==========================================\n\n");
	fprintf (out, "          SPBU Universitas Udayana          \n");
	fprintf (out, "            JL, Raya Kampus Unud            \n");
	fprintf (out, "              BUKIT JIMBARAN                \n");
	fprintf (out, "==========================================\n\n");
	fprintf (out, "Tanggal      : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fprintf (out, "Jumlah Liter : %2.1f Liter\n",total);
	fprintf (out, "Harga  : %2.1f \n",inputan);
	fprintf (out, "------------------------------------------\n");
	fprintf (out, "              TOTAL PEMBAYARAN               \n");
	fprintf (out, "                 %2.1f \n",inputan);
	fprintf (out, "------------------------------------------\n");
	fclose  (out);



}
void bensin_nonsubsidi_pertalite() {
	float inputan;
	float uang;
	float total;
	float hasil;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Liter : ");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.pertalite;
	hasil = uang * BBM.pertalite;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		system("cls");
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("|| Uang = %.2f\n", total);
	}
	printf("|| Yang Perlu dibayar : %.2f\n\n", total);
	printf("|| Ingin Membuat Struck Dari Pembelian Tadi? (Y/T)");
	time_t t;
	t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE * out;
	out = fopen("bensin_nonsubsidi_pertalite.txt","w");//cetak file nota non subsidi
	fprintf (out, "==========================================\n\n");
	fprintf (out, "          SPBU Universitas Udayana          \n");
	fprintf (out, "            JL, Raya Kampus Unud            \n");
	fprintf (out, "              BUKIT JIMBARAN                \n");
	fprintf (out, "==========================================\n\n");
	fprintf (out, "Tanggal      : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fprintf (out, "Jumlah Liter : %2.1f Liter\n",inputan); //jika ingin subsidi ganti dengan total.
	fprintf (out, "Harga  : %2.1f \n",total);//ini diganti dengan inputan.
	fprintf (out, "------------------------------------------\n");
	fprintf (out, "              TOTAL PEMBAYARAN               \n");
	fprintf (out, "                 %2.1f \n",total);// ini diganti dengan inputan.
	fprintf (out, "------------------------------------------\n");
	fclose  (out);
}


void nonsubsidi_solar() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Takaran Berdasarkan :                      ||\n");
	printf("||    1. Uang   (Rp)                                ||\n");
	printf("||    2. Bensin (L)                                 ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		uang_subsidi_solar();
	} else if(inputan == 2) {
		bensin_subsidi_solar();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}
void uang_nonsubsidi_solar() {
	float inputan;
	float liter;
	float total;
	float hasil;

	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Uang : ");
	scanf("%f", &inputan);
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	liter = inputan / BBM.solar;
	hasil = liter * BBM.solar;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=liter)) {
		system("cls");
		total = total + 0.0100;
		printf("liter = %f\n", total);
	}
	printf("Total liter : %f", total);
	printf("Liter");
}
void bensin_nonsubsidi_solar() {
	float inputan;
	float uang;
	float total;
	float hasil;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Liter : ");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.solar;
	hasil = uang * BBM.solar;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		system("cls");
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("|| Uang = %.2f\n", total);
	}
	printf("|| Yang Perlu dibayar : %.2f\n\n", total);
	printf("|| Ingin Membuat Struck Dari Pembelian Tadi? (Y/T)");
}


void nonsubsidi_pertamax() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Takaran Berdasarkan :                      ||\n");
	printf("||    1. Uang   (Rp)                                ||\n");
	printf("||    2. Bensin (L)                                 ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		uang_nonsubsidi_pertamax();
	} else if(inputan == 2) {
		bensin_nonsubsidi_pertamax();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}
void uang_nonsubsidi_pertamax() {
	float inputan;
	float liter;
	float total;
	float hasil;

	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Uang : ");
	scanf("%f", &inputan);
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	liter = inputan / BBM.pertamax;
	hasil = liter * BBM.pertamax;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=liter)) {
		system("cls");
		total = total + 0.0100;
		printf("liter = %f\n", total);
	}
	printf("Total liter : %f", total);
	printf("Liter");
}
void bensin_nonsubsidi_pertamax() {
	float inputan;
	float uang;
	float total;
	float hasil;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Liter : ");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.pertamax;
	hasil = uang * BBM.pertamax;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		system("cls");
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("|| Uang = %.2f\n", total);
	}
	printf("|| Yang Perlu dibayar : %.2f\n\n", total);
	printf("|| Ingin Membuat Struck Dari Pembelian Tadi? (Y/T)");
}


void nonsubsidi_pertamax_turbo() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Takaran Berdasarkan :                      ||\n");
	printf("||    1. Uang   (Rp)                                ||\n");
	printf("||    2. Bensin (L)                                 ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		uang_nonsubsidi_pertamax_turbo();
	} else if(inputan == 2) {
		bensin_nonsubsidi_pertamax_turbo();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}
void uang_nonsubsidi_pertamax_turbo() {
	float inputan;
	float liter;
	float total;
	float hasil;

	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Uang : ");
	scanf("%f", &inputan);
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	liter = inputan / BBM.pertamax_turbo;
	hasil = liter * BBM.pertamax_turbo;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=liter)) {
		system("cls");
		total = total + 0.0100;
		printf("liter = %f\n", total);
	}
	printf("Total liter : %f", total);
	printf("Liter");
}
void bensin_nonsubsidi_pertamax_turbo() {
	float inputan;
	float uang;
	float total;
	float hasil;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Liter : ");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.pertamax_turbo;
	hasil = uang * BBM.pertamax_turbo;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		system("cls");
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("|| Uang = %.2f\n", total);
	}
	printf("|| Yang Perlu dibayar : %.2f\n\n", total);
	printf("|| Ingin Membuat Struck Dari Pembelian Tadi? (Y/T)");
}


void nonsubsidi_dexlite() {
	int inputan;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Takaran Berdasarkan :                      ||\n");
	printf("||    1. Uang   (Rp)                                ||\n");
	printf("||    2. Bensin (L)                                 ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		uang_nonsubsidi_dexlite();
	} else if(inputan == 2) {
		bensin_nonsubsidi_dexlite();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}
void uang_nonsubsidi_dexlite() {
	float inputan;
	float liter;
	float total;
	float hasil;

	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Uang : ");
	scanf("%f", &inputan);
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	liter = inputan / BBM.dexlite;
	hasil = liter * BBM.dexlite;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=liter)) {
		system("cls");
		total = total + 0.0100;
		printf("liter = %f\n", total);
	}
	printf("Total liter : %f", total);
	printf("Liter");
}
void bensin_nonsubsidi_dexlite() {
	float inputan;
	float uang;
	float total;
	float hasil;
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Masukan Jumlah Liter : ");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.dexlite;
	hasil = uang * BBM.dexlite;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		system("cls");
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("|| Uang = %.2f\n", total);
	}
	printf("|| Yang Perlu dibayar : %.2f\n\n", total);
	printf("|| Ingin Membuat Struck Dari Pembelian Tadi? (Y/T)");
}

void debit() { //untuk debit
	float inputan;
	float uang;
	float total;
	float hasil;
	int pilih;
	char nama[50];
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("|| Nama				    :");
	scanf("%s",&nama);
	printf("|| Masukan Jumlah Liter :");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.pertamina_dex;
	hasil = uang * BBM.pertamina_dex;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		
		system("cls");

		
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("||==================================================||\n");
		printf("||                PERTAMINA                         ||\n");
		printf("|| SPBU 54.803.02                                   ||\n");
		printf("|| JL, I Gusti Ngurah Rai                           ||\n");
		printf("|| Jimbaran - Bali                                  ||\n");
		printf("|| Telp. (0361) 705034                              ||\n");
		printf("||==================================================||\n");
		printf("||No. Nota     : 1230123                            ||\n");
		printf("||Nama	       : %s\n",nama);
		printf("||Jenis BBM    : Pertamina Dex                      ||\n");
		printf("||Harga/liter  : 19.000                             ||\n");
		printf("||Jumlah Liter : %2.1f Liter\n",inputan);  
		printf("||Total        : %.2f\n\n", total);
		printf("||--------------------------------------------------\n");
		printf("||              TOTAL PEMBAYARAN              \n");
		printf("||Tunai        :    %2.1f \n",total            );
		printf("||--------------------------------------------\n");
	}
	printf("|============================|\n");
    printf("|       1. Cetak Struk       |\n");
    printf("|       2. Keluar            |\n");
    printf("|============================|\n");
    printf("\t\t\t\nMasukkan Pilihan : ");
    pilih = validasistruck();
    system ("cls");

    switch(pilih){
	    case 1: {
		
			
    time_t t;							                              
	t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE * out;
	out = fopen("bensin_subsidi_pertalite.txt","w");//cetak file nota
	fprintf (out, "==========================================\n\n");
	fprintf (out, "                PERTAMINA                   \n");
	fprintf (out, " SPBU 54.803.02                             \n");
	fprintf (out, " JL, I Gusti Ngurah Rai                     \n");
	fprintf (out, " Jimbaran - Bali                            \n");
	fprintf (out, " Telp. (0361) 705034                        \n");
	fprintf (out, "Tanggal      : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fprintf (out, "==========================================\n\n");
	fprintf (out, "No. Nota     : 1230123 \n");
	fprintf (out, "Nama	     : %s \n",nama);
	fprintf	(out, "Jenis BBM    : Pertamina Dex                \n");
	fprintf	(out, "Harga/liter  : 19.000                       \n");
	fprintf (out, "Jumlah Liter : %2.1f Liter\n",inputan            );
	fprintf (out, "Total        : %2.1f \n",total               );
	fprintf (out, "--------------------------------------------\n");
	fprintf (out, "              TOTAL PEMBAYARAN              \n");
	fprintf (out, "Tunai        :    %2.1f \n",total            );
	fprintf (out, "--------------------------------------------\n");
	fclose  (out);
	printf("\n");
	printf("\t\t\t==============================================\n");
	printf("\t\t\t|        -NOTA ANDA BERHASIL DICETAK-        |\n");
	printf("\t\t\t==============================================\n"); 
	break;
}
	    case 2:
	    exit(1);
	    break;
    }
   
}



void nonsubsidi_pertamina_dex() {
	int inputan;
	char nama[50];
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("||                                                  ||\n");
	printf("|| Pilih Takaran Berdasarkan :                      ||\n");
	printf("||    1. Uang   (Rp)                                ||\n");
	printf("||    2. Bensin (L)                                 ||\n");
	printf("||                                         0. keluar||\n");
	printf("======================================================\n");
	printf(">> ");
	scanf("%d", &inputan);
	if(inputan == 1) {
		uang_nonsubsidi_pertamina_dex();
	} else if(inputan == 2) {
		bensin_nonsubsidi_pertamina_dex();
	} else if(inputan == 0) {
		keluar();
	} else {
		printf("\n==============================");
		printf("\n|     Silahkan menginput     |");
		printf("\n|      data yang benar       |");
		printf("\n==============================");
	}
}


void uang_nonsubsidi_pertamina_dex() {
	float inputan;
	float liter;
	float total;
	float hasil;
	char nama[50];
    time_t waktu;
    srand(time(&waktu));
    for(int i=0;i<5;i++);

	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("Masukan Nama: ");
	scanf("%s",&nama);
	printf("|| Masukan Jumlah Uang : ");
	scanf("%f", &inputan);
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	liter = inputan / BBM.pertamina_dex;
	hasil = liter * BBM.pertamina_dex;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=liter)) {
		system("cls");
		total = total + 0.0100;
		printf("liter = %f\n", total);
	}
	printf("Total liter : %f", total);
	printf("Liter");
	
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("||==================================================||\n");
		printf("||                PERTAMINA                         ||\n");
		printf("|| SPBU 54.803.02                                   ||\n");
		printf("|| JL, I Gusti Ngurah Rai                           ||\n");
		printf("|| Jimbaran - Bali                                  ||\n");
		printf("|| Telp. (0361) 705034                              ||\n");
		printf("||==================================================||\n");
		printf("||No. Nota     : %d\n", rand());
		printf("||Nama         : %s\n",nama);
		printf("||Jenis BBM    : Pertamina Dex                      ||\n");
		printf("||Harga/liter  : 19.000                             ||\n");
		printf("||Jumlah Liter : %2.1f Liter\n",inputan);  
		printf("||Total        : %.2f\n\n", total);
		printf("||--------------------------------------------------\n");
		printf("||              TOTAL PEMBAYARAN              \n");
		printf("||Tunai        :    %2.1f \n",total            );
		printf("||--------------------------------------------\n");
}



// struct awal
void bensin_nonsubsidi_pertamina_dex() {
	float inputan;
	float uang;
	float total;
	float hasil;
	int pilih;
	char nama[50];
	time_t waktu;
    srand(time(&waktu));
    for(int i=0;i<5;i++);
	system("cls");
	printf("======================================================\n");
	printf("||              Program kalkulator pada             ||\n");
	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
	printf("||__________________________________________________||\n");
	printf("Masukan Nama: ");
	scanf("%s",&nama);
	printf("|| Masukan Jumlah Liter :");
	inputan = validasi();
	fflush(stdin);
	printf(" : %f\n\n", inputan);
	uang = inputan * BBM.pertamina_dex;
	hasil = uang * BBM.pertamina_dex;
	printf(" : %f\n\n", hasil);
	total = 0;
	while((total<=uang)) {
		
		system("cls");

		
		total = total + 100;
		printf("======================================================\n");
		printf("||              Program kalkulator pada             ||\n");
		printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
		printf("||__________________________________________________||\n");
		printf("||==================================================||\n");
		printf("||                PERTAMINA                         ||\n");
		printf("|| SPBU 54.803.02                                   ||\n");
		printf("|| JL, I Gusti Ngurah Rai                           ||\n");
		printf("|| Jimbaran - Bali                                  ||\n");
		printf("|| Telp. (0361) 705034                              ||\n");
		printf("||==================================================||\n");
		printf("||No. Nota     : %d\n", rand());
		printf("||Jenis BBM    : Pertamina Dex                      ||\n");
		printf("||Nama         : %s\n",nama);
		printf("||Harga/liter  : 19.000                             ||\n");
		printf("||Jumlah Liter : %2.1f Liter\n",inputan);  
		printf("||Total        : %.2f\n\n", total);
		printf("||--------------------------------------------------\n");
		printf("||              TOTAL PEMBAYARAN              \n");
		printf("||Tunai        :    %2.1f \n",total            );
		printf("||--------------------------------------------\n");
	}
	printf("|============================|\n");
    printf("|       1. Cetak Struk       |\n");
    printf("|       2. Keluar            |\n");
    printf("|============================|\n");
    printf("\t\t\t\nMasukkan Pilihan : ");
    pilih = validasistruck();
    system ("cls");

    switch(pilih){
	    case 1: {
		
			
    time_t t;							                              
	t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE * out;
	out = fopen("bensin_subsidi_pertalite.txt","w");//cetak file nota
	fprintf (out, "==========================================\n\n");
	fprintf (out, "                PERTAMINA                   \n");
	fprintf (out, " SPBU 54.803.02                             \n");
	fprintf (out, " JL, I Gusti Ngurah Rai                     \n");
	fprintf (out, " Jimbaran - Bali                            \n");
	fprintf (out, " Telp. (0361) 705034                        \n");
	fprintf (out, "Tanggal      : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fprintf (out, "==========================================\n\n");
	fprintf (out, "No. Nota     : %d\n", rand());
	fprintf (out, "Jenis BBM    : Pertalite                    \n");
	fprintf	(out, "Nama         : %s\n",nama);
	fprintf (out, "Harga/liter  : 10.000                       \n");
	fprintf (out, "Jumlah Liter : %2.1f Liter\n",inputan            );
	fprintf (out, "Total        : %2.1f \n",total               );
	fprintf (out, "--------------------------------------------\n");
	fprintf (out, "              TOTAL PEMBAYARAN              \n");
	fprintf (out, "Tunai        :    %2.1f \n",total            );
	fprintf (out, "--------------------------------------------\n");
	fclose  (out);
	printf("\n");
	printf("\t\t\t==============================================\n");
	printf("\t\t\t|        -NOTA ANDA BERHASIL DICETAK-        |\n");
	printf("\t\t\t==============================================\n"); 
	break;
}
	    case 2:
	    exit(1);
	    break;
    }
   
}


int main() {

	cover();
	system("pause");
	system("cls");

	jenis_fasilitas();
	system("pause");
	system("cls");



}