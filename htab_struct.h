// Solution for IJC-DU2, task 2), 28.3.2021
// File:        wordcount.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Declares structures for htab.h

#include "htab.h"
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
struct htab
{
    size_t size;
    size_t arr_size;
    htab_pair_t arr[];
};


//zaznam [(key,value), next]
typedef struct htab_item htab_item;

struct htab_item
{
    htab_pair_t pair;
    htab_item *next;

};