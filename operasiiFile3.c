struct Pembeli{
	char plate[MAX_LENGTH];                              // nomor plat
	int purchase;                                           // jumlah pembelian
	int max_purchase;
} Customer;

int openFile(struct Pembeli Customer[]){
	FILE *fp = fopen("customers.txt", "r"); 	                                                    // buka file teks

	if (fp == NULL) {                                                                               // cek apakah file dapat dibuka atau tidak
		printf("File Tidak Ada\n");
		return 1;
	}Customer c;                                                                                    // deklarasi variabel c sebagai tipe data Customer

	while (fscanf(fp, "%s %d %d", &c.plate, &c.purchase, &c.max_purchase) != EOF) {                 // baca data dari file teks sampai akhir file
		if (c.purchase > c.max_purchase) {                                                          // cek apakah pembelian melebihi batas maksimum
		printf("Pembelian melebihi batas maksimum!\n");
		} else {
		printf("Nomor plat: %s\n", c.plate);
		printf("Anda sudah membeli sebanyak : %d liter\n", c.purchase);
		printf("Batas pembelian anda untuk bulan ini : %d liter \n", c.max_purchase);
		}
	}
	fclose(fp);
	return 0;
}

void readPlate(char *plate) {
	int c;                                                                                          // variabel untuk menyimpan karakter input
	int i = 0;                                                                                      // indeks untuk menyimpan karakter ke dalam string

	                                                                                                // baca input sampai enter atau sampai maksimum panjang string
	while ((c = getchar()) != '\n' && c != EOF && i < MAX_LENGTH - 1) {
		plate[i++] = c;                                                                              // simpan karakter ke dalam string
	}
	plate[i] = '\0';                                                                                   // tambahkan null character di akhir string
}

                                                                                                        // fungsi untuk membaca input jumlah pembelian
int readPurchase() {
	int purchase;                                                                                               // variabel untuk menyimpan jumlah pembelian

	                                                                                                    // baca input sampai mendapatkan angka yang valid
	while (scanf("%d", &purchase) != 1) {
		printf("Input tidak valid, masukkan angka: ");
	while (getchar() != '\n');                                                                                    // baca sampai newline
}

return purchase;
}