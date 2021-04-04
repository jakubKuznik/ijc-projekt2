// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_find.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Find given key and return pointer to that place.  

#include "htab_struct.h"
#include "htab.h"


/**
 * Find given key and return pointer to that place.  
 */
htab_pair_t * htab_find(htab_t * t, htab_key_t key)  // hledání
{
    //standart index calculation iusing hash function 
    unsigned long index = (htab_hash_function(key) % t->arr_size);
    htab_item *item_temp = t->arr[index];
    while (item_temp != NULL)
    {
        if(strcmp(key, item_temp->pair.key) == 0)
        {
            return item_temp; 
        }
        item_temp = item_temp->next;
    }
    return NULL;
}
