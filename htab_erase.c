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
    // Try to find given key If given key is not in table return null 
    if(htab_find(t, key) == NULL)
        return false;

    unsigned long index = (htab_hash_function(key) % t->arr_size);
    
    htab_item *item_to_remove = t->arr[index];
    htab_item *help_var = t->arr[index];
    
    // Get to position
    while((strcmp(item_to_remove->pair.key, key) != 0) && (&item_to_remove->pair != NULL))
        item_to_remove = item_to_remove->next;

    //If key is on first place
    if (&help_var->pair == &item_to_remove->pair)
    {
        t->arr[index] = t->arr[index]->next;
        free((char *)help_var->pair.key);
        free(help_var);
        return true;
    }

    //Get to possiton before record that i want erase 
    while(&help_var->next->pair != &item_to_remove->pair)
        help_var = help_var->next;


    help_var->next = item_to_remove->next;
    free((char *)item_to_remove->pair.key);
    free(item_to_remove);
    return true;
}