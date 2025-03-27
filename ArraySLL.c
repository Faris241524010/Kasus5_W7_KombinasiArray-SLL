/* File        : ArraySLL.c */
/* Deskripsi   :  */
/*                 */
/*                 */
/* Dibuat oleh : Faris */

#include "ArraySLL.h"

// Fungsi menambahkan nama ke kota yang sesuai
void tambahNama(Array A, char* kt, char *nm) {
    // Mencari kota yang sesuai
    while (A != NULL) {
        if (strcmp(A->kt, kt) == 0) {
            // Kota ditemukan, tambahkan nama ke dalam linked list
            ElmtNama *baru = (ElmtNama*)malloc(sizeof(ElmtNama));
            baru->nm = strdup(nm);
            baru->q = *(A->p); // Menunjuk ke elemen pertama
            *(A->p) = baru; // Jadikan elemen baru sebagai head
            return;
        }
        A = (Array)(A->p); // Pindah ke elemen kota berikutnya
    }

    // Jika kota belum ada, buat kota baru
    Array kotaBaru = (Array)malloc(sizeof(ElmtKota));
    kotaBaru->kt = strdup(kt);
    kotaBaru->p = (nextNama*)malloc(sizeof(nextNama));
    *(kotaBaru->p) = NULL;

    // Tambahkan nama pertama
    ElmtNama *baru = (ElmtNama*)malloc(sizeof(ElmtNama));
    baru->nm = strdup(nm);
    baru->q = NULL;
    *(kotaBaru->p) = baru;

    // Tambahkan ke dalam array kota (sebagai linked list kota)
    kotaBaru->p = (nextNama*)A;
    A = kotaBaru;
}

// Fungsi menampilkan semua kota beserta daftar nama
void tampilKota(Array A) {
    while (A != NULL) {
        printf("Kota: %s\n", A->kt);
        nextNama namaPtr = *(A->p);
        while (namaPtr != NULL) {
            printf("  - %s\n", namaPtr->nm);
            namaPtr = namaPtr->q;
        }
        A = (Array)(A->p); // Pindah ke kota berikutnya
    }
}

// Fungsi menghapus semua kota dan nama yang terkait
void deleteKota(Array A) {
    while (A != NULL) {
        // Hapus semua nama dalam kota
        nextNama namaPtr = *(A->p);
        while (namaPtr != NULL) {
            nextNama temp = namaPtr;
            namaPtr = namaPtr->q;
            free(temp->nm);
            free(temp);
        }

        // Hapus kota
        Array tempKota = A;
        A = (Array)(A->p);
        free(tempKota->kt);
        free(tempKota->p);
        free(tempKota);
    }
}