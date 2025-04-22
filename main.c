#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {
    Kota *head = NULL;
    int choice;
    char namaKota[50];
    char namaOrang[50];

    do {
        printf("\n1. Entry Kota\n");
        printf("2. Delete Kota\n");
        printf("3. Tampilkan Kota dan Orang\n");
        printf("4. Keluar\n");
        printf("5. Tambah Nama Orang ke Kota\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                entryKota(&head, namaKota);
                break;
            case 2:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                deleteKota(&head, namaKota);
                break;
            case 3:
                tampilKota(head);
                break;
            case 4:
                printf("Keluar program...\n");
                break;
            case 5:
                printf("Masukkan nama kota tujuan: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;
                tambahOrang(head, namaKota, namaOrang);
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while(choice != 4);

    deallocateMemory(head);
    return 0;
}