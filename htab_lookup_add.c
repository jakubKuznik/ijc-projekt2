// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_lookup_adc.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
//

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"
#include <stdbool.h>

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
        return temp;
    
    unsigned long index = (htab_hash_function(key) % t->arr_size);

    htab_item *item_temp = t->arr[index];
    //Get to the end where new node will be added
    if(item_temp != NULL)
        while (item_temp->next != NULL)
            item_temp = item_temp->next;

    //item_temp->next->pair.key = malloc(sizeof htab_key_t)
    //alloc space for new item
    bool firts_item = false;
    if(item_temp == NULL) //FOR FIRST NODE 
    {
        firts_item = true;
        item_temp = malloc(sizeof(htab_item));
        if(item_temp == NULL)
            goto error_malloc;
    }
    else
    {
        item_temp->next = malloc(sizeof(htab_item));
        item_temp = item_temp->next;
        if(item_temp == NULL)
            goto error_malloc;
    }

    // Allocate space for key 
    item_temp->pair.key = malloc(strlen(key) + 1);
    if(item_temp->pair.key == NULL)
        goto error_malloc;

    // set asocial value to 0 and copy given string to key
    item_temp->pair.value = 0;
    strcpy((char*)item_temp->pair.key, key);
    if(firts_item)
        t->arr[index] = item_temp;
    
    return &item_temp->pair;


error_malloc:
    fprintf(stderr, "Erorr Malloc.");
    return NULL;

}