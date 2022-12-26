#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

typedef struct {
    char nama[MAX_LENGTH];
    char nomer_hp[MAX_LENGTH];
} Data;

void tampilkan_isi_file(const char *dataMasyarakat) {
    FILE *file = fopen("dataMasyarakat.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    Data data;
    while (fread(&data, sizeof(Data), 1, file) == 1) {
        printf("Nama: %s\n", data.nama);
        printf("Nomer HP: %s\n", data.nomer_hp);
    }

    fclose(file);
}

void ubah_isi_file(const char *dataMasyarakat) {
    FILE *file = fopen("dataMasyarakat.txt", "r+b");
    if (file == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    printf("Masukkan indeks data yang ingin diubah: ");
    int indeks;
    scanf("%d", &indeks);

    fseek(file, indeks * sizeof(Data), SEEK_SET);

    Data data;
    if (fread(&data, sizeof(Data), 1, file) == 1) {
        printf("Masukkan nama baru: ");
        scanf("%s", data.nama);
        printf("Masukkan nomer HP baru: ");
        scanf("%s", data.nomer_hp);

        fseek(file, -sizeof(Data), SEEK_CUR);
        fwrite(&data, sizeof(Data), 1, file);
    } else {
        printf("Indeks tidak valid\n");
    }

    fclose(file);
}

void hapus_isi_file(const char *dataMasyarakat) {
    FILE *file = fopen("dataMasyarakat.txt", "r+b");
    if (file == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    printf("Masukkan indeks data yang ingin dihapus: ");
    int indeks;
    scanf("%d", &indeks);

    fseek(file, indeks * sizeof(Data), SEEK_SET);

    Data data;
    if (fread(&data, sizeof(Data), 1, file) == 1) {
        memset(&data, 0, sizeof(Data));

        fseek(file, -sizeof(Data), SEEK_CUR);
        fwrite(&data, sizeof(Data), 1, file);
    } else {
        printf("Indeks tidak valid\n");
    }

}