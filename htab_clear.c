// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_clear.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
//


#include "htab_struct.h"
#include <stdlib.h>
#include "htab.h"

/**
 *  
 */
void htab_clear(htab_t * t)    // ruší všechny záznamy
{
    for(int i = 0; i < htab_bucket_count(t); i++)
    {
        htab_item *t_help = t->arr[i];
        htab_item *t_help_free = t->arr[i];
        while (t_help != NULL)
        {
            t_help_free = t_help;    
            t_help = t_help->next;
            free(t_help_free->pair.key);
            free(t_help_free);
        }
        t->arr[i] = NULL; 
    }
    t->size = 0;
    t->arr_size = 0;
}