#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void entryKota(Kota **head, char *namaKota) {
    Kota *newKota = (Kota*)malloc(sizeof(Kota));
    strcpy(newKota->nama, namaKota);
    newKota->jumlahOrang = 0;
    newKota->firstOrang = NULL;
    newKota->nextKota = *head;
    *head = newKota;
}

void deleteKota(Kota **head, char *namaKota) {
    Kota *temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->nama, namaKota) != 0) {
        prev = temp;
        temp = temp->nextKota;
    }

    if (temp == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    Orang *orangTemp = temp->firstOrang;
    while (orangTemp != NULL) {
        Orang *hapus = orangTemp;
        orangTemp = orangTemp->nextOrang;
        free(hapus);
    }

    if (prev == NULL) {
        *head = temp->nextKota;
    } else {
        prev->nextKota = temp->nextKota;
    }

    free(temp);
}

void tampilKota(Kota *head) {
    if (head == NULL) {
        printf("Tidak ada kota yang terdaftar.\n");
        return;
    }

    while (head != NULL) {
        printf("Kota: %s, Jumlah Orang: %d\n", head->nama, head->jumlahOrang);
        Orang *orang = head->firstOrang;
        while (orang != NULL) {
            printf("  - %s\n", orang->nama);
            orang = orang->nextOrang;
        }
        head = head->nextKota;
    }
}

void tambahOrang(Kota *head, char *namaKota, char *namaOrang) {
    Kota *temp = head;
    while (temp != NULL && strcmp(temp->nama, namaKota) != 0) {
        temp = temp->nextKota;
    }

    if (temp == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    Orang *newOrang = (Orang*)malloc(sizeof(Orang));
    strcpy(newOrang->nama, namaOrang);
    newOrang->nextOrang = temp->firstOrang;
    temp->firstOrang = newOrang;
    temp->jumlahOrang++;
}

void deallocateMemory(Kota *head) {
    Kota *temp;
    while (head != NULL) {
        Orang *orang = head->firstOrang;
        while (orang != NULL) {
            Orang *hapus = orang;
            orang = orang->nextOrang;
            free(hapus);
        }
        temp = head;
        head = head->nextKota;
        free(temp);
    }
}