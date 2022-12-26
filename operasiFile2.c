#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct contact {
  int plat[MAX_LENGTH];
  char jumlah_pembelian[MAX_LENGTH];
};

void print_contacts(struct contact *contacts, int num_contacts) {
  printf("--- Daftar Kontak ---\n");
  for (int i = 0; i < num_contacts; i++) {
    printf("Nama: %s\n", contacts[i].plat);
    printf("Nomor HP: %s\n", contacts[i].jumlah_pembelian);
  }
}

void add_contact(struct contact *contacts, int *num_contacts) {
  printf("--- Tambah Kontak ---\n");
  printf("Masukkan nama kontak: ");
  scanf("%s", contacts[*num_contacts].plat);
  printf("Masukkan nomor HP kontak: ");
  scanf("%s", contacts[*num_contacts].jumlah_pembelian);
  (*num_contacts)++;
}

void edit_contact(struct contact *contacts, int num_contacts) {
  int plat[MAX_LENGTH];
  printf("--- Edit Kontak ---\n");
  printf("Masukkan nama kontak yang akan diedit: ");
  scanf("%s", plat);
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i].plat, plat) == 0) {
      printf("Masukkan nama baru: ");
      scanf("%s", contacts[i].plat);
      printf("Masukkan nomor HP baru: ");
      scanf("%s", contacts[i].jumlah_pembelian);
      return;
    }
  }
  printf("Kontak tidak ditemukan!\n");
}

void delete_contact(struct contact *contacts, int *num_contacts) {
  int plat[MAX_LENGTH];
  printf("--- Hapus Kontak ---\n");
  printf("Masukkan nama kontak yang akan dihapus: ");
  scanf("%s", plat);
  for (int i = 0; i < *num_contacts; i++) {
    if (strcmp(contacts[i].plat, plat) == 0) {
      for (int j = i; j < (*num_contacts - 1); j++) {
        contacts[j] = contacts[j + 1];
      }
      (*num_contacts)--;
      return;
    }
  }
  printf("Kontak tidak ditemukan!\n");
}

int main() {
  struct contact contacts[MAX_LENGTH];
  int num_contacts = 0;

  // Membuka file kontak.txt untuk dib
}