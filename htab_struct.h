// Solution for IJC-DU2, task 2), 28.3.2021
// File:        wordcount.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Declares structures for htab.h

#include "htab.h"

#ifndef __HTAB_STRUCT_H__
#define __HTAB_STRUCT_H__

typedef struct htab_item htab_item;

/*
+----------+
| size     | // aktuální počet záznamů [(key,data),next]
+----------+
| arr_size | // velikost následujícího pole ukazatelů
+----------+
+---+
|ptr|-->[(key,data),next]-->[(key,data),next]-->[(key,data),next]--|
+---+
|ptr|--|
+---+
|ptr|-->[(key,data),next]-->[(key,data),next]--|
+---+
|ptr|--|
+---+
*/
/**
 * Whole hash table.
*/
struct htab
{
    size_t size; // aktuální počet záznamů [(key,data),next]
    size_t arr_size; // velikost následujícího pole ukazatelů
    htab_item *arr[];
};

/**
 * One record in hash table 
*/
struct htab_item
{
    htab_pair_t pair; // There is a key and value 
    htab_item *next; // pointer to next record 

};


#endif