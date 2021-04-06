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
        return temp;
    
    unsigned long index = (htab_hash_function(key) % t->arr_size);

    htab_item *item_temp = t->arr[index];
    //Get to the end where new node will be added
    if(item_temp != NULL)
    {
        printf("tru");
        while (item_temp->next != NULL)
        {
            printf("X.");
            item_temp = item_temp->next;
        }
    }  

    //item_temp->next->pair.key = malloc(sizeof htab_key_t)
    //alloc space for new item
    if(item_temp == NULL) //FOR FIRST NODE 
    {
        printf("!_");
        item_temp = malloc(sizeof(htab_item));
        if(item_temp == NULL)
        {
            fprintf(stderr, "Erorr Malloc.");
            return NULL;   
        }
        item_temp->pair.key = malloc(strlen(key) + 1);
        item_temp->pair.value = 0;
        strcpy((char*)item_temp->pair.key, key);
        item_temp->next = NULL;
        t->arr[index] = item_temp;
        return &item_temp->pair;
    }
    else
    {
        printf("@_");
        item_temp->next = malloc(sizeof(htab_item));
        item_temp = item_temp->next;
        if(item_temp == NULL)
        {
            fprintf(stderr, "Erorr Malloc.");
            return NULL;   
        }
        item_temp->pair.key = malloc(strlen(key) + 1);
        item_temp->pair.value = 0;
        strcpy((char*)item_temp->pair.key, key);
        
        item_temp->next = NULL;
        return &item_temp->pair;
    }

    //This is a new key so i set value to 1

}