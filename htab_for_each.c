// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_free.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
//


#include "htab.h"
#include "htab_struct.h"

/**
 * For every record call function 
 */
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
    for(unsigned i = 0; i < t->arr_size; i++)
    {
        while (t->arr[i]->next != NULL)
        {
            f(t->arr[i]); //call function f for every record in table 
        }
    }    
}
