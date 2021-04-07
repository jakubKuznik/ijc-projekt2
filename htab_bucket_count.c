// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_bucket_count.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Return array size of hash table  


#include "htab_struct.h"
#include "htab.h"


/**
 * Return array size of hash table  
 */
size_t htab_bucket_count(const htab_t * t) // velikost pole
{
    return t->arr_size;
}   