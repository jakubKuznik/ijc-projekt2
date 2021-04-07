// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_move.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Move whole hash table data to new one 


#include "htab.h"
#include "htab_struct.h"

/**
 * Move whole hash table data to new one 
 * Return Null if malloc is not succesfull
 * n = new table size
 * */
htab_t *htab_move(size_t n, htab_t *from)      // přesun dat do nové tabulky
{
    htab_t *new_table = htab_init(n); //creating new table 
    if(new_table == NULL)
        goto error_malloc;


    // Copy old table to new one 
    for(unsigned long i = 0; i < from->arr_size ; i++)
    {
        htab_item *help = from->arr[i];
        while(&help != NULL)
        {
            htab_pair_t *retunt_poniter = htab_lookup_add(new_table, help->pair.key);
            retunt_poniter->key = retunt_poniter->key + 1;
            help = help->next;
        }    
    }

    new_table->arr_size = from->arr_size;
    new_table->size = from->size;

    htab_free(from);
    return new_table;

error_malloc:
    fprintf(stderr, "Error malloc \n");
    return NULL;

}