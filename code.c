#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data karyawan
typedef struct {
    int employeeID;
    char namaLengkap[31];
    char tempatLahir[31];
    char tanggalLahir[11];
    char jabatan[51];
} Karyawan;

// Struktur node singly linked list
typedef struct Node {
    Karyawan data;
    struct Node* next;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(Karyawan data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk push data karyawan
void pushData(Node** head, Karyawan data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Fungsi untuk menampilkan semua daftar karyawan
void displayData(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("Tidak ada data yang tersedia.\n");
        return;
    }
    while (current!= NULL) {
        printf("Employee ID: %d\n", current->data.employeeID);
        printf("Nama Lengkap: %s\n", current->data.namaLengkap);
        printf("Tempat Lahir: %s\n", current->data.tempatLahir);
        printf("Tanggal Lahir: %s\n", current->data.tanggalLahir);
        printf("Jabatan: %s\n\n", current->data.jabatan);
        current = current->next;
    }
}

// Fungsi untuk menghapus data karyawan berdasarkan Employee ID
void deleteData(Node** head, int employeeID) {
    Node* current = *head;
    Node* previous = NULL;
    while (current!= NULL) {
        if (current->data.employeeID == employeeID) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            printf("Data yang dihapus:\n");
            printf("Employee ID: %d\n", current->data.employeeID);
            printf("Nama Lengkap: %s\n", current->data.namaLengkap);
            printf("Tempat Lahir: %s\n", current->data.tempatLahir);
            printf("Tanggal Lahir: %s\n", current->data.tanggalLahir);
            printf("Jabatan: %s\n\n", current->data.jabatan);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Data tidak ditemukan!\n");
}

// Fungsi untuk menghapus semua data karyawan
void deleteAllData(Node** head) {
    Node* current = *head;
    while (current!= NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("Semua data telah dihapus!\n");
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice;
    Karyawan data;
    int count = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Input Data\n");
        printf("2. Menampilkan semua daftar karyawan\n");
        printf("3. Hapus data karyawan berdasarkan Employee ID\n");
        printf("4. Hapus semua data karyawan\n");
        printf("5. Keluar dari program\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (count < 5) {
                    printf("Input Employee ID (maksimal 5 angka): ");
                    scanf("%d", &data.employeeID);
                    printf("Input Nama Lengkap (maksimal 30 karakter): ");
                    scanf("%30s", data.namaLengkap);
                    printf("Input Tempat Lahir (maksimal 30 karakter): ");
                    scanf("%30s", data.tempatLahir);
                    printf("Input Tanggal Lahir (format: dd/mm/yyyy): ");
                    scanf("%10s", data.tanggalLahir);
                    printf("Input Jabatan (maksimal 50 karakter): ");
                    scanf("%50s", data.jabatan);
                    printf("\n");
                    pushData(&head, data);
                    count++;
                } else {
                    printf("Maksimal 5 data telah tercapai!\n");
                }
                break;
            case 2:
                displayData(head);
                break;
            case 3:
                printf("Input Employee ID yang ingin dihapus: ");
                scanf("%d", &data.employeeID);
                printf("\n");
                deleteData(&head, data.employeeID);
                printf("Data berhasil dihapus!\n");
                printf("\n");
                break;
            case 4:
                deleteAllData(&head);
                break;
            case 5:
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}
