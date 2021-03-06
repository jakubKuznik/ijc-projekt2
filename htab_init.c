// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_init.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Table constructor 

#include "htab_struct.h"
#include "htab.h"
#include <stdlib.h>


/**
 * Table constructor.
*/
htab_t *htab_init(size_t n)      // konstruktor tabulky
{
    htab_t *table = NULL;
    table = (htab_t*)malloc(sizeof(htab_t) + n * sizeof(htab_pair_t));
    if(table == NULL)
    {
        fprintf(stderr, "Error: Alocation malloc problem.");
        return NULL;
    }
    
    table->arr_size = n;
    table->size = 0;
    
    for(unsigned i = 0; i < n; i++)
    {
        table->arr[i] = NULL;
        //table->arr[i] = malloc(sizeof(htab_pair_t));
    }

    
    return table;
}