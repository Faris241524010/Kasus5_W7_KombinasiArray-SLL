/* File        : menu.c */
/* Deskripsi   : body file menu interaktif  */
/* Dibuat oleh : Faris */

#include "menu.h"

void menu() {
    Array daftarKota = NULL; // Inisialisasi daftar kota
    
    int pilihan;
    char kota[50], nama[50];

    do {
        printf("\n===== MENU =====\n");
        printf("1. Tambah Nama ke Kota\n");
        printf("2. Tampilkan Semua Kota\n");
        printf("3. Hapus Semua Kota\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // Menghapus karakter newline setelah input angka

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(kota, sizeof(kota), stdin);
                kota[strcspn(kota, "\n")] = 0; // Hapus newline di akhir

                printf("Masukkan nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; // Hapus newline di akhir

                tambahNama(daftarKota, kota, nama);
                printf("Nama berhasil ditambahkan!\n");
                break;

            case 2:
                printf("\n=== Daftar Kota dan Nama ===\n");
                tampilKota(daftarKota);
                break;

            case 3:
                deleteKota(daftarKota);
                daftarKota = NULL; // Pastikan daftar kosong setelah dihapus
                printf("Semua kota dan nama telah dihapus.\n");
                break;

            case 4:
                deleteKota(daftarKota);
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);

    return;
}