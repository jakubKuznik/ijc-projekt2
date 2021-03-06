// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_size.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Returns hash table number of records.


#include "htab_struct.h"
#include "htab.h"

/**
 * Returns hash table number of records.
 */
size_t htab_size(const htab_t *t)             // počet záznamů v tabulce
{
    return t->size;
}