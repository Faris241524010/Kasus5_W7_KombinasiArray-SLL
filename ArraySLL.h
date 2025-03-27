/* File        : ArraySLL.h */
/* Deskripsi   :  */
/*                 */
/*                 */
/* Dibuat oleh : Faris */

#include "linked.h"

typedef struct nama *nextNm;
typedef struct kota {
        infotype kt;
        nextNm  p;
 } ElmtKota;

typedef struct nama {
        infotype nm;
        nextNm  q;
 } ElmtNama;