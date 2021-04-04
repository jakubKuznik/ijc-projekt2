// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_lookup_adc.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
//

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

/**
 * Add given key to hash table. 
 * If the key was alredy here just increment value
 * Return ponter to that table record.
 * RETURN NULL IF ERROR 
*/
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key)
{
    htab_pair_t *temp = NULL;
    //If 
    temp = htab_find(t, key);
    if(temp != NULL)
    {
        temp->value = temp->value + 1;
        return temp;
    }
    unsigned long index = (htab_hash_function(key) % t->arr_size);


    htab_item *item_temp = t->arr[index];
    //Get to the end where new node will be added 
    while (item_temp->next != NULL)
    {
        item_temp = item_temp->next;
    }
    
    //alloc space for new item
    item_temp->next = malloc(sizeof(htab_item));
    if(item_temp->next == NULL)
    {
        fprintf(stderr, "Erorr Malloc.");
        return NULL;   
    }
    //TODO MALLOC KEY
    //item_temp->next->pair.key = malloc(sizeof htab_key_t)

    //This is a new key so i set value to 1
    item_temp->next->pair.value = 1;
    strncmp(item_temp->next->pair.key, key, strlen(key));

    return item_temp->next;

}