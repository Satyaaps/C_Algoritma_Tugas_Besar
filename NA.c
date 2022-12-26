#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define batas_pembelian 120
//#define jumlah_pembelian 115
#define MAX_LENGTH 10

float validasi();
void jenis_fasilitas(), menu_pembeli(), lihat_data_pembeli(), tambah_data_pembeli(), perbaharui_data_pembeli(), menghapus_data_pembeli();
void validasi_jenis_bensin(), jenis_bensin(), keluar();
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
int proses_read_data_tmp(), cek_jumlah_pembelian(), cek_jumlah_pembelian_edit(), validasiplat();
void setDefaultDataTmp(), lihat_data_pembeli(), tambah_data_pembeli(), perbaharui_data_pembeli(), menghapus_data_pembeli();
void proses_tambah_data(), proses_lihat_data(), proses_perbaharui_data(), proses_hapus_data();


struct harga_bensin{
	int pertalite;
	int solar;
	int pertamax_turbo;	
	int pertamina_dex;
	int dexlite;
	int pertamax;

} BBM = {10000,6800,15200,18000,18300,13900};

struct contact {
  int jumlah_pembelian;
  char plat[MAX_LENGTH];
};


float input(int desimal, int min, int batas_akhir){
    char masukan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int minus = 0;
    int salah = 0;
    float hasil;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    while(masukan[i] != '\0'){
        if(masukan[0] == '.'){
            salah = 1;
            masukan[0] = '\0';
        }else if(masukan[i]>='0' && masukan[i]<='9' || masukan[i] == '.' || (masukan[0] == '-' && min == 1)){
            if((masukan[i] == '.') && (desimal == 1)){
                titik = titik + 1;
                if(titik > 1 || masukan[i+1] == '\0'){
                    salah = 1;
                    masukan[i] = '\0';
                }
                status = 1;
            }else if((masukan[i] == '.') && (desimal == 0)){
                salah = 1;
                masukan[i] = '\0';
            }

            if(masukan[0] == '-' && min == 1){
                minus = 1;
            }else if(masukan[0] == '-' && min == 0){
                salah = 1;
                masukan[i] = '\0';
            }

            if(masukan[i]>='0' && masukan[i]<='9'){
                if(status == 1){
                    isi_belakang = (isi_belakang * 10) + (masukan[i] - 48);
                    belakang = belakang + 1;
                }else{
                    isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                }
            }
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }
    if(titik == 1){
        hasil = (float)isi_depan + (isi_belakang / (pow(10, belakang)));
    }else{
        hasil = isi_depan;
    }


    if(minus == 1 && min == 1){
        hasil = hasil - (hasil * 2);
    }else if(minus == 1 && min == 0){
        salah = 1;
        masukan[i] = '\0';
    }

    if(salah == 1){
        printf("    Masukkan salah! Masukkan angka yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(min == 0 && hasil == 0){
        printf("    Masukkan tidak boleh 0 ! Masukkan nilai yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(batas_akhir != 0 && hasil > batas_akhir){
        printf("    Masukkan tidak boleh lebih dari %d ! Masukkan nilai yang benar : ", batas_akhir);
        return input(desimal, min, batas_akhir);
    }else{
        return hasil;
    }
}

void pilihan_ulang(int ulang){
    char huruf_ulang[1];

    printf("\n    Lakukan lagi? ya/kembali/keluar(Y/N/E) : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "Y") != 0) && (strcmp(huruf_ulang, "N") != 0) && (strcmp(huruf_ulang, "E") != 0 ) &&
       (strcmp(huruf_ulang, "y") != 0) && (strcmp(huruf_ulang, "n") != 0) && (strcmp(huruf_ulang, "e") != 0)){
        printf("    Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang(ulang);
    }else if((strcmp(huruf_ulang, "Y") == 0)){
        system("cls");
        if(ulang == 1){
			tambah_data_pembeli();
        }else if(ulang == 2){
            lihat_data_pembeli();
        }else if(ulang == 3){
            perbaharui_data_pembeli();
        }else if(ulang == 4){
            menghapus_data_pembeli();
        }
    }else if((strcmp(huruf_ulang, "y") == 0)){
        system("cls");
        if(ulang == 1){
			tambah_data_pembeli();
        }else if(ulang == 2){
            lihat_data_pembeli();
        }else if(ulang == 3){
            perbaharui_data_pembeli();
        }else if(ulang == 4){
            menghapus_data_pembeli();
        }
    }else if((strcmp(huruf_ulang, "N") == 0)){
        system("cls");
        menu_pembeli();
    }else if((strcmp(huruf_ulang, "n") == 0)){
        system("cls");
        menu_pembeli();
    }else{
        keluar();
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

int pertanyaanHapus(){
    char huruf_hapus[1];
    int hasil = 0;

    printf("    Apakah anda yakin ingin menghapus data ini ? (Y/N) : ");
    scanf("%s", &huruf_hapus);
    fflush(stdin);

    if((strcmp(huruf_hapus, "Y") != 0) && (strcmp(huruf_hapus, "N") != 0) &&
       (strcmp(huruf_hapus, "y") != 0) && (strcmp(huruf_hapus, "n") != 0)){
        printf("    Masukan anda salah! Masukan dengan benar\n\n");
        pertanyaanHapus();
    }else if((strcmp(huruf_hapus, "Y") == 0)){
		hasil = 1;
    }else if((strcmp(huruf_hapus, "y") == 0)){
		hasil = 1;
    }else{
		hasil = 0;
    }

    return hasil;
}

void setDefaultDataTmp(struct contact data_tmp[]){
    int i;
    for(i = 0; i < batas_pembelian; i++){
        data_tmp[i].jumlah_pembelian = 0;
    }
}

int proses_read_data_tmp(struct contact data_tmp[]){
    int jumlah = 0;

    FILE *read_tmp = fopen("datapembeli.txt","r");
    	if(!read_tmp){
        	jumlah = 1;
	    }else{
		    while(!feof(read_tmp)){
		   	    fscanf(read_tmp,"%d#%[^\n]\n", &data_tmp[jumlah].jumlah_pembelian, &data_tmp[jumlah].plat);
	            jumlah++;
		    }
    	}
		fclose(read_tmp);
    	return jumlah;
}

void proses_tambah_data(struct contact data){
    FILE *tambah = fopen("datapembeli.txt", "a");
	fprintf(tambah,"%d#%s\n", data.jumlah_pembelian, data.plat);
	fclose(tambah);
}

void proses_lihat_data(struct contact data_tmp[], int jumlah){
    int i;
    if(jumlah == 1 && data_tmp[0].jumlah_pembelian == 0){
        printf("    * Tidak ada data pembeli\n");
    }else{
        for(i = 0; i < jumlah; i++){
            printf("    %d. %d - %s\n", i+1, data_tmp[i].jumlah_pembelian, data_tmp[i].plat);
        }
    }
}

void proses_perbaharui_data(struct contact data_edit, struct contact data_tmp[], int jumlah, int nomorEdit){
    int i, j;
    data_tmp[nomorEdit].jumlah_pembelian = data_edit.jumlah_pembelian;
    for(i = 0; i < 50; i++){
        data_tmp[nomorEdit].plat[i] = data_edit.plat[i];
    }

    FILE *perbaharui = fopen("datapembeli.txt","w");
    for(i = 0; i < jumlah; i++){
        fprintf(perbaharui, "%d#%s\n", data_tmp[i].jumlah_pembelian, data_tmp[i].plat);
    }
    fclose(perbaharui);
}

void proses_hapus_data(struct contact data_tmp[], int jumlah, int nomorHapus){
    int i;
    FILE *hapus = fopen("datapembeli.txt","w");
    for(i = 0; i < jumlah; i++){
        if(i == nomorHapus){
            continue;
        }else{
            fprintf(hapus, "%d#%s\n", data_tmp[i].jumlah_pembelian, data_tmp[i].plat);
        }
    }
    fclose(hapus);
}

int cek_jumlah_pembelian(struct contact data, struct contact data_tmp[], int jumlah){
    int i;
    int ditemukan = 0;

    for(i = 0; i < jumlah; i++){
        if(data.jumlah_pembelian == data_tmp[i].jumlah_pembelian){
            ditemukan = 1;
            break;
        }else{
            ditemukan = 0;
        }
    }

    return ditemukan;
}


int cek_jumlah_pembelian_edit(struct contact data, struct contact data_tmp[], int jumlah, int nomorEdit){
    int i;
    int ditemukan = 0;

    for(i = 0; i < jumlah; i++){
        if((data.jumlah_pembelian == data_tmp[i].jumlah_pembelian) && (data_tmp[i].jumlah_pembelian != data_tmp[nomorEdit].jumlah_pembelian)){
            ditemukan = 1;
            break;
        }else{
            ditemukan = 0;
        }
    }

    return ditemukan;
}

int validasiplat(char masukan[]){
    int i = 0;
    int salah = 0;

    while(masukan[i] != '\0'){
        if((masukan[i] >= 65 && masukan[i] <= 90) || (masukan[i] >= 97 && masukan[i] <= 122) || masukan[i] == ' ' || masukan[i] == '.' || masukan[i] == ','){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        return 0;
    }else{
        return 1;
    }
}

void tambah_data_pembeli(){
    int statusPembelian;
    int statusPlat;
    struct contact data;
    struct contact data_tmp[100];
    setDefaultDataTmp(data_tmp);

    int jumlah = proses_read_data_tmp(data_tmp);

	printf(" ================================================== \n");
	printf("|============  TAMBAH DATA MAHASISWA  =============|\n");
	printf("|==================================================|\n");
	printf("    Tambah Data \n");
	printf("    * Masukan jumlah pembelian  : "); scanf("%d", statusPembelian);

    statusPembelian = cek_jumlah_pembelian(data, data_tmp, jumlah);
    while(statusPembelian == 1){
        printf("      jumlah_pembelian sudah ada ! Masukan jumlah_pembelian yang berbeda : ");
        scanf("%d", &data.jumlah_pembelian);
        statusPembelian = cek_jumlah_pembelian(data, data_tmp, jumlah);
    }

	printf("    * Masukan plat : ");
    scanf("%[^\n]", &data.plat);
    fflush(stdin);

	    statusPlat = validasiplat(data.plat);
    while(statusPlat == 0){
        printf("      Format Nama salah ! Masukan Nama dengan benar : ");
        scanf("%[^\n]", &data.plat);
        fflush(stdin);
        statusPlat = validasiplat(data.plat);
    }

    proses_tambah_data(data);

    printf("\n");
    printf("    Hasil\n");
    printf("    * jumlah_pembelian  : %d\n", data.jumlah_pembelian);
    printf("    * plat : %s\n", data.plat);
    printf("      Data tersebut berhasil ditambahkan\n");
	printf(" ==================================================\n");
    pilihan_ulang(1);
}

void lihat_data_pembeli(){
    struct contact data_tmp[100];
    setDefaultDataTmp(data_tmp);

    int jumlah = proses_read_data_tmp(data_tmp);
	printf(" ================================================== \n");
	printf("|===============  DATA Pembelian  =================|\n");
	printf("|==================================================|\n");
    printf("    Daftar Data Pembeli :\n");
    printf("\n");

    proses_lihat_data(data_tmp, jumlah);

    if(jumlah != 1 || data_tmp[0].jumlah_pembelian != 0){
        printf("\n");
        printf("    Jumlah Pembelian : %d\n", jumlah);
    }
	printf(" ==================================================\n");
    pilihan_ulang(2);
}

void perbaharui_data_pembeli(){
    int statusjumlah_pembelian, statusplat;
    struct contact data_edit;
    struct contact data_tmp[100];
    setDefaultDataTmp(data_tmp);
    int jumlah = proses_read_data_tmp(data_tmp);
    int nomorEdit = 0;
		printf(" ================================================== \n");
		printf("|==========  PERBAHARUI DATA MAHASISWA  ===========|\n");
		printf("|==================================================|\n");
		printf("    Daftar Data Mahasiswa :\n");
		printf("\n");

    	proses_lihat_data(data_tmp, jumlah);

		printf("\n");
		if(jumlah != 1 || data_tmp[0].jumlah_pembelian != 0){
			printf("    Data nomor brapa yang ingin anda perbaharui ? (1 - %d) : ", jumlah);
			nomorEdit = input(0, 0, jumlah);
			nomorEdit = nomorEdit - 1;

			printf("\n");
			printf("    Input Pembaharuan Data\n");
			printf("    * Masukan jumlah_pembelian  : ");
			scanf("%d", data_edit.jumlah_pembelian);

			printf("    * Masukan plat : ");
			scanf("%[^\n]", &data_edit.plat);
			fflush(stdin);

			printf("\n");

			proses_perbaharui_data(data_edit, data_tmp, jumlah, nomorEdit);

			printf("    Data berhasil diperbaharui\n");
		}else if(jumlah == 1 && data_tmp[0].jumlah_pembelian == 0){
			printf("   Masukan data terlebih dahulu\n");
		}
		printf(" ==================================================\n");
		pilihan_ulang(3);
}

void menghapus_data_pembeli(){
    struct contact data_tmp[100];
    setDefaultDataTmp(data_tmp);
    int jumlah = proses_read_data_tmp(data_tmp);
    int nomorHapus = 0;
    int yakinHapus = 0;
		printf(" ================================================== \n");
		printf("|=============  HAPUS DATA MAHASISWA  =============|\n");
		printf("|==================================================|\n");
		printf("    Daftar Data Pembeli :\n");
		printf("\n");

    	proses_lihat_data(data_tmp, jumlah);

		printf("\n");
		if(jumlah != 1 || data_tmp[0].jumlah_pembelian != 0){
			printf("    Pilih data yang ingin anda hapus!! (1 - %d) : ", jumlah);
			nomorHapus = input(0, 0, jumlah);
			nomorHapus = nomorHapus - 1;
			yakinHapus = pertanyaanHapus();
			printf("\n");
			if(yakinHapus == 1){
				proses_hapus_data(data_tmp, jumlah, nomorHapus);
				printf("    Data telah di hapus\n");
			}else{
				printf("    Data tidak di hapus\n");
			}
		}else if(jumlah == 1 && data_tmp[0].jumlah_pembelian == 0){
			printf("   Masukan data terlebih dahulu\n");
		}
		printf(" ==================================================\n");
		pilihan_ulang(4);
}

void keluar(){
	system("cls");
	system("exit");
}

float validasi(){
	float inputan;
	float jumlah;
	float hasil;
	float sisa;
	struct contact data_tmp[100];
	struct contact data;
		scanf("%f", &inputan);
		jumlah = inputan + data.jumlah_pembelian;	
		sisa = batas_pembelian - data.jumlah_pembelian;
printf("%d", data.jumlah_pembelian);
	if( jumlah > batas_pembelian){
		printf("Anda Hanya Dapat Membeli Sebanyak : %.5f\n", sisa);
		printf("|| Masukan Jumlah Liter : ");
		getchar();
		validasi();
	}
	return inputan;	
}
int validasi_arr(int *var){
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
		if(validasi_arr(var))
			break;
		printf("\t\tInput salah! Silahkan coba lagi! \n");
	}
}
void cekmengulang(char y, char n, char *prompt){
    char cek;
	while(1){
		printf(prompt);
		fflush(stdin);
		scanf("%c", &cek);
		if((cek=='y' || cek=='Y') || (cek=='T' || cek=='t')){
			if (cek == 'y' || cek == 'Y'){
				system("cls");
				jenis_fasilitas();
			}
			break;
		}else{
		printf("\t\tInput salah! Silahkan coba lagi! \n");
		}
	}
	if(cek=='t' || cek=='T'){
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



void cover(){
    system("cls");
    printf("======================================================\n");
    printf("||              Program kalkulator pada             ||\n");
    printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
    printf("||__________________________________________________||\n");
    printf("||                                                  ||\n");
    printf("|| I Gede Satya Ariya Putra Sangjaya   2205551040   ||\n");
    printf("|| I Dewa Gd Dharma Pawitra            2205551041   ||\n");
    printf("||                                                  ||\n");
    printf("======================================================\n");
}
void menu_pilihan(){
	int inputan;
		printf("======================================================\n");
        printf("||              Program kalkulator pada             ||\n");
        printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("||__________________________________________________||\n");
		printf("||                                                  ||\n");
        printf("|| Pilih Kapasitas CC Pada Kendaraan :              ||\n");
        printf("||    1. Kalkulator Bensin                          ||\n");
        printf("||    2. Menampilkan Data Pembeli                   ||\n");
        printf("||                                         0. keluar||\n");
        printf("======================================================\n");
		printf(">> ");scanf("%d", &inputan);

		if(inputan == 1){
			jenis_fasilitas();
		}
		else if(inputan == 2){
			menu_pembeli();
		}
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}
}
void menu_pembeli(){
	int inputan;
		system("cls");
		printf("======================================================\n");
        printf("||              Program kalkulator pada             ||\n");
        printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("||__________________________________________________||\n");
		printf("||                                                  ||\n");
        printf("|| Pilih Kapasitas CC Pada Kendaraan :              ||\n");
        printf("||    1. Lihat Data Pembeli                         ||\n");
        printf("||    2. Tambah Data Pembeli                        ||\n");
        printf("||    3. Perbaharui Data Pembeli                    ||\n");
        printf("||    4. Menghapus Data Pembeli                     ||\n");
        printf("||                                         0. keluar||\n");
        printf("======================================================\n");
        printf(">> "); scanf("%d", &inputan);

			if(inputan == 1){
				lihat_data_pembeli();
			}
			else if(inputan == 2){
				tambah_data_pembeli();
			}
			else if(inputan == 3){
				perbaharui_data_pembeli();
			}
			else if(inputan == 4){
				menghapus_data_pembeli();
			}
}


void jenis_fasilitas(){
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
        printf(">> "); scanf("%d", &inputan);

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
				printf("\n==============================");
				printf("\n|     Silahkan menginput     |");
				printf("\n|      data yang benar       |");
				printf("\n==============================");
			}
}

void pilihan_kendaraan_pertalite(){
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
        printf(">> "); scanf("%d", &inputan);
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
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}
}

void pilihan_cc_motor_pertalite(){
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
        printf(">> "); scanf("%d", &inputan);
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
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}	
}

void pilihan_cc_mobil_pertalite(){
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
        printf(">> "); scanf("%d", &inputan);
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
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}
}

void pilihan_cc_truck_pertalite(){
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

void pilihan_kendaraan_solar(){
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
        printf(">> "); scanf("%d", &inputan);
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
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}
}

void pilihan_cc_motor_solar(){
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

void pilihan_cc_mobil_solar(){
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
        printf(">> "); scanf("%d", &inputan);
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
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}
}


void subsidi_pertalite(){
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
        printf(">> "); scanf("%d", &inputan);
		if(inputan == 1){
			uang_nonsubsidi_pertalite();
		}
		else if(inputan == 2){
			bensin_nonsubsidi_pertalite();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}		
}
void uang_subsidi_pertalite(){
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
		while((total<=liter)){
			system("cls");
			total = total + 0.0100;
			printf("liter = %f\n", total);
		}
		printf("Total liter : %f", total);
        printf("Liter");
}
void bensin_subsidi_pertalite(){
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
		while((total<=uang)){
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


void subsidi_solar(){
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
        printf(">> "); scanf("%d", &inputan);
		if(inputan == 1){
			uang_subsidi_solar();
		}
		else if(inputan == 2){
			bensin_subsidi_solar();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}		
}
void uang_subsidi_solar(){
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
		while((total<=liter)){
			//system("cls");
			total = total + 0.0100;
			printf("liter = %f\n", total);
		}
		printf("Total liter : %f", total);
        printf("Liter");
}
void bensin_subsidi_solar(){
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
		while((total<=uang)){
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


void nonsubsidi_pertalite(){
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
        printf(">> "); scanf("%d", &inputan);
		if(inputan == 1){
			uang_nonsubsidi_pertalite();
		}
		else if(inputan == 2){
			bensin_nonsubsidi_pertalite();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}		
}
void uang_nonsubsidi_pertalite(){
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
		while((total<=liter)){
			system("cls");
			total = total + 0.0100;
			printf("liter = %f\n", total);
		}
		printf("Total liter : %f", total);
        printf("Liter");
}
void bensin_nonsubsidi_pertalite(){
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
		while((total<=uang)){
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


void nonsubsidi_solar(){
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
        printf(">> "); scanf("%d", &inputan);
		if(inputan == 1){
			uang_subsidi_solar();
		}
		else if(inputan == 2){
			bensin_subsidi_solar();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}		
}
void uang_nonsubsidi_solar(){
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
		while((total<=liter)){
			system("cls");
			total = total + 0.0100;
			printf("liter = %f\n", total);
		}
		printf("Total liter : %f", total);
        printf("Liter");
}
void bensin_nonsubsidi_solar(){
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
		while((total<=uang)){
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


void nonsubsidi_pertamax(){
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
        printf(">> "); scanf("%d", &inputan);
		if(inputan == 1){
			uang_nonsubsidi_pertamax();
		}
		else if(inputan == 2){
			bensin_nonsubsidi_pertamax();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}		
}
void uang_nonsubsidi_pertamax(){
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
		while((total<=liter)){
			system("cls");
			total = total + 0.0100;
			printf("liter = %f\n", total);
		}
		printf("Total liter : %f", total);
        printf("Liter");
}
void bensin_nonsubsidi_pertamax(){
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
		while((total<=uang)){
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


void nonsubsidi_pertamax_turbo(){
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
        printf(">> "); scanf("%d", &inputan);
		if(inputan == 1){
			uang_nonsubsidi_pertamax_turbo();
		}
		else if(inputan == 2){
			bensin_nonsubsidi_pertamax_turbo();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}		
}
void uang_nonsubsidi_pertamax_turbo(){
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
		while((total<=liter)){
			system("cls");
			total = total + 0.0100;
			printf("liter = %f\n", total);
		}
		printf("Total liter : %f", total);
        printf("Liter");
}
void bensin_nonsubsidi_pertamax_turbo(){
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
		while((total<=uang)){
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


void nonsubsidi_dexlite(){
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
        printf(">> "); scanf("%d", &inputan);
		if(inputan == 1){
			uang_nonsubsidi_dexlite();
		}
		else if(inputan == 2){
			bensin_nonsubsidi_dexlite();
		}
		else if(inputan == 0){
			keluar();
		}
		else{
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}		
}
void uang_nonsubsidi_dexlite(){
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
		while((total<=liter)){
			system("cls");
			total = total + 0.0100;
			printf("liter = %f\n", total);
		}
		printf("Total liter : %f", total);
        printf("Liter");
}
void bensin_nonsubsidi_dexlite(){
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
		while((total<=uang)){
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


void nonsubsidi_pertamina_dex(){
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
        printf(">> "); scanf("%d", &inputan);
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
			printf("\n==============================");
			printf("\n|     Silahkan menginput     |");
			printf("\n|      data yang benar       |");
			printf("\n==============================");
		}		
}
void uang_nonsubsidi_pertamina_dex(){
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
		liter = inputan / BBM.pertamina_dex;
        hasil = liter * BBM.pertamina_dex;
        printf(" : %f\n\n", hasil);
		total = 0;
		while((total<=liter)){
			system("cls");
			total = total + 0.0100;
			printf("liter = %f\n", total);
		}
		printf("Total liter : %f", total);
        printf("Liter");
}
void bensin_nonsubsidi_pertamina_dex(){
		time_t t;
        t = time(NULL);
        struct tm tm = *localtime(&t);
		int pilihan;
        float kembalian;
        float finaltotal;
		float inputan;
		int pilih;
		float uang;
		float total;
		float hasil;
		float total_final;
		float jumlah_uang_diterima;
		char nama[100];
		char plat[100];
		char jenis[] = "Pertamina Dex";
		char batas[] = "Belum ditetapkan";
		char harga[] = "18.000";
		system("cls");
	    printf("======================================================\n");
        printf("||              Program kalkulator pada             ||\n");
        printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
        printf("||__________________________________________________||\n");
		printf("|| Plat Nomor 			: ");fflush(stdin); scanf("%[^\n]", plat); getchar();
		printf("|| Masukan Jumlah Liter : ");
		inputan = validasi();
        fflush(stdin);
        printf(" : %f\n\n", inputan);
		uang = inputan * BBM.pertamina_dex;
        hasil = uang * BBM.pertamina_dex;
        printf(" : %f\n\n", hasil);
		total = 0;
		while((total<=uang)){
			system("cls");
			total = total + 500;
			printf("======================================================\n");
        	printf("||              Program kalkulator pada             ||\n");
        	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
        	printf("||__________________________________________________||\n");
			printf("|| Uang = %.2f\n", total);
		}
		total_final = (total - 500);
			do{
			system("cls");
			printf("======================================================\n");
        	printf("||              Program kalkulator pada             ||\n");
        	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
        	printf("||__________________________________________________||\n");
			printf("|| Uang = %.2f\n", total_final);
			printf("|| Yang Perlu dibayar : %.2f\n\n", total_final);
			printf("|| Jumlah Pembayaran  : ");scanf("%f", &jumlah_uang_diterima);
			system("pause");
			system("cls");
			printf("======================================================\n");
        	printf("||              Program kalkulator pada             ||\n");
        	printf("||           Stasiun Pengisian Bahan Bakar          ||\n");
        	printf("||__________________________________________________||\n");
    		printf("||       1. Cetak Struk                             ||\n");
    		printf("||       2. Mengulang Program                       ||\n");
    		printf("======================================================\n");
			printf("\t\t\t\nMasukkan Pilihan : ");
			pilih = validasistruck();
			system ("cls");
			
			switch(pilih){
				case 1: {
			kembalian = jumlah_uang_diterima - total_final;
			system("cls");
			printf("===========================================================\n");
			printf("||                 Program kalkulator pada               ||\n");
			printf("||              Stasiun Pengisian Bahan Bakar            ||\n");
			printf("||_______________________________________________________||\n");
			printf("||                      NOTA TAGIHAN                     ||\n");
			printf("||=======================================================||\n");
			printf("||                       PERTAMINA                       ||\n");
			printf("|| SPBU 54.803.02                                        ||\n");
			printf("|| JL, I Gusti Ngurah Rai                                ||\n");
			printf("|| Jimbaran - Bali                                       ||\n");
			printf("|| Telp. (0361) 705034                                   ||\n");
			printf("||=======================================================||\n");
			printf("|| Nama             : %s\n", nama);
			printf("|| Plat Kendaraan   : %s\n", plat);
			printf("|| Jenis Bensin     : %s\n", jenis);
			printf("|| Batas Pembelian  : %s\n", batas);
			printf("|| Tanggal          : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
			printf("===========================================================\n");
			printf("|| Harga per Liter  : Rp. %s\n", harga);
			printf("|| Jumlah pembelian : %.2f Liter\n", inputan);
			printf("|| Jumlah           : Rp. %.2f\n", jumlah_uang_diterima);
			printf("===========================================================\n");		
			printf("|| Total            : Rp. %.2f\n", finaltotal);
			printf("|| Kembalian        : Rp. %.2f\n", kembalian);
			printf("===========================================================\n");
			printf("Apakah Anda Ingin Melakukan Penghitungan Kembali? (Y/N) : "); scanf("%d", &pilihan);
			pilihan = cekmengulang();
			
			struct tm tm = *localtime(&t);
			FILE * out;
			out = fopen("strukpembelian.txt","w");//cetak file nota
			fprintf(out, "===========================================================\n");
			fprintf(out, "||                 Program kalkulator pada               ||\n");
			fprintf(out, "||              Stasiun Pengisian Bahan Bakar            ||\n");
			fprintf(out, "||_______________________________________________________||\n");
			fprintf(out, "||                      NOTA TAGIHAN                     ||\n");
			fprintf(out, "||=======================================================||\n");
			fprintf(out, "||                       PERTAMINA                       ||\n");
			fprintf(out, "|| SPBU 54.803.02                                        ||\n");
			fprintf(out, "|| JL, I Gusti Ngurah Rai                                ||\n");
			fprintf(out, "|| Jimbaran - Bali                                       ||\n");
			fprintf(out, "|| Telp. (0361) 705034                                   ||\n");
			fprintf(out, "||=======================================================||\n");
			fprintf(out, "|| Nama             : %s\n", nama);
			fprintf(out, "|| Plat Kendaraan   : %s\n", plat);
			fprintf(out, "|| Jenis Bensin     : %s\n", jenis);
			fprintf(out, "|| Batas Pembelian  : %s\n", batas);
			fprintf(out, "|| Tanggal          : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
			fprintf(out, "===========================================================\n");
			fprintf(out, "|| Harga per Liter  : Rp. %s\n", harga);
			fprintf(out, "|| Jumlah pembelian : %.2f Liter\n", inputan);
			fprintf(out, "|| Jumlah           : Rp. %.2f\n", jumlah_uang_diterima);
			fprintf(out, "===========================================================\n");		
			fprintf(out, "|| Total            : Rp. %.2f\n", finaltotal);
			fprintf(out, "|| Kembalian        : Rp. %.2f\n", kembalian);
			fprintf(out, "===========================================================\n");
			fclose (out);
			printf("\n");
			printf("\t\t\t==============================================\n");
			printf("\t\t\t|        -NOTA ANDA BERHASIL DICETAK-        |\n");
			printf("\t\t\t==============================================\n"); 
			break;
		}
				case 2:
				system("cls");
				menu_pilihan();
			}
	}while(cekmengulang('y','n', "|| Apakah Anda Ingin Melakukan Penghitungan Kembali? (Y/N) : "));
}

int main(){
    
    cover();
    system("pause");
    system("cls");

    menu_pilihan();
    system("pause");
    system("cls");
}