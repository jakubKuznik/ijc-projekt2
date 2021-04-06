// Solution for IJC-DU2, task 1), 28.3.2021
// File:        tail.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Works like posix tail if does not get file read from stdin.

//ARGUMENTY SE MOHOU ZADAT V LIBOVOLNÉM POŘADÍ.
#include "htab_struct.h"
#include "wordcount.h"
/**
 * Read one wordfrom file to char s*
 * returns word size
 * return -1 if there is file error
 * return EOF if there is end of file   
 */
int read_word(char *s, int max, FILE *f)
{
    if(s == NULL || f == NULL)
        return -1;

    int c = 0;
    int i = 0;
    while((c = fgetc(f)))
    {
        if (c == ' ' || c == '\n' || c ==  '\f' ||\
            c == '\r' || c == '\t' || c == '\v')
            break;
        else if(c == EOF)
            return EOF;

        if(i == max-1)
            break;
        
        s[i++] = c;

    }

    //IF WOROD WAS TO LONG 
    if(i == max-1)
        while ((c = fgetc(f)))
            if (c == ' ' || c == '\n' || c ==  '\f' ||\
                c == '\r' || c == '\t' || c == '\v')
                break;
    
    s[i] = '\0';
    // if there are multiple isspace symbols it ll skip them
    if (s[0] == ' ' || s[0] == '\n' || s[0] ==  '\f' || s[0] == '\r' || s[0] == '\t' || s[0] == '\v')
        return '\0';


    return i;
    
    
}