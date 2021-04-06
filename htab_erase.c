// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_erase.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Erase one pair from hash table.



#include "htab_struct.h"
#include "htab.h"
#include <stdlib.h>

/**
 *     --> word --> something ---> cola 
 *         ERASE(something)
 *     --> word --> cola
 */


/**
 * Remote given record (pair)
 * return true if succes.
*/
bool htab_erase(htab_t * t, htab_key_t key)    // ruší zadaný záznam
{
    // Try to find given key 
    htab_pair_t *record = htab_find(t, key);
    if(record == NULL)
        return false;
    
    unsigned long index = (htab_hash_function(key) % t->arr_size);
    htab_item *help_var = t->arr[index];
    
    //If key is on first place
    if (&help_var->pair == record)
    {
        t->arr[index] = t->arr[index]->next;
        free(&help_var->pair.key);
        free(&help_var->pair);
        return true;
    }

    //Get to possiton before record that i want erase 
    while(&help_var->next->pair != record)
        help_var = help_var->next;


    help_var->next = help_var->next->next;
    help_var = help_var->next;
    
    free(&help_var->pair.key);
    free(&help_var->pair);
    return true;
}