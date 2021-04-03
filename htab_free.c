// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_free.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// 


#include "htab.h"


void htab_free(htab_t * t)     // destruktor tabulky
{

    htab_clear(t);
    free(t);
}