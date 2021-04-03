// Solution for IJC-DU2, task 2), 28.3.2021
// File:        htab_hash_function.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// 

#include "htab.h"
#include <stdint.h>

size_t htab_hash_function(const char *str)
{
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}