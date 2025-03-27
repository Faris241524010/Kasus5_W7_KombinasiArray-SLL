/* File        : ArraySLL.h */
/* Deskripsi   :  */
/*                 */
/*                 */
/* Dibuat oleh : Faris */

#ifndef ARRAY_SLL_H
#define ARRAY_SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"

// Struktur data
typedef struct Nama *nextNama;
typedef struct Nama {
    char *nm;
    nextNama q;
} ElmtNama;

typedef struct Kota *Array;
typedef struct Kota {
    char *kt;
    nextNama *p;
} ElmtKota;

// Deklarasi fungsi
void tambahNama(Array A, char* kt, char *nm);
void tampilKota(Array A);
void deleteKota(Array A);

#endif