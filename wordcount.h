// Solution for IJC-DU2, task 2), 28.3.2021
// File:        wordcount.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// header file for wordcount.c and io.c

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_WORD_SIZE 128

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
