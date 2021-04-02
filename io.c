// Solution for IJC-DU2, task 1), 28.3.2021
// File:        tail.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Works like posix tail if does not get file read from stdin.

//ARGUMENTY SE MOHOU ZADAT V LIBOVOLNÉM POŘADÍ.

#include "wordcount.h"
/**
 * Read one wordfrom file to char s*
 * returns word size 
 */
int read_word(char *s, int max, FILE *f)
{
    int c = 0;
    int i = 0;
    for(; (c = fgetc(f));i++)
    {
        if (c == ' ' || c == '\n' || c ==  '\f' ||\
            c == '\r' || c == '\t' || c == '\v')
            break;
        else if(c == EOF)
            return EOF;

        if(i == MAX_WORD_SIZE-1)
            break;
        
        s[i++] = c;

    }
    s[i] = '\0';
    return i;
    
    
}