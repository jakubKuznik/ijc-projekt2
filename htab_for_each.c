// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_free.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Call function f for every record in table t 


#include "htab.h"
#include "htab_struct.h"

/**
 * Call function f for every record in table t 
 */
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
    for(unsigned i = 0; i < t->arr_size; i++)
    {
        for (htab_item *item = t->arr[i]; item != NULL; item = item->next) 
        {
            f(&(item->pair));//call function f for every record in table 
        }
    }    
}
