// Solution for IJC-DU2, task 2), 28.3.2021
// File:        wordcount.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// header file for wordcount.c and io.c

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "htab.h"

#define MAX_WORD_SIZE 128

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


typedef struct htab_item htab_item_t;
//zaznam [(key,value), next]
struct htab_item
{
    htab_pair_t pair;
    htab_item_t *next;

};


/**
 * Store input file or stdin to file 
*/
FILE *parser(int argc, char *argv[]);

/*******************io.c******************/
/**
 * Read one wordfrom file to char s*
 * returns word size 
 */
int read_word(char *s, int max, FILE *f);


/*****************************************/
