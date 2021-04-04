// Solution for IJC-DU2, task 2), 28.3.2021
// File:        wordcount.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Count words in some text.

#include "wordcount.h"
#include "htab.h"

/* This is how is index in hash table calculate.*/
//index = (htab_hash_function("mystring") % arr_size);

int main(int argc, char *argv[])
{
    htab_t *table = htab_init(ARR_SIZE);
    htab_free(table);


    FILE *f; //Input file where we are geting words from 
    if((f = parser(argc, argv)) == NULL)
        goto error_1;


    char one_word[MAX_WORD_SIZE] = {0};
    while(read_word(one_word, MAX_WORD_SIZE, f) != EOF)
    {
        printf("kolo rovno hovno\n");
    }



    //todo if(wordcount == MAX_WORD_SIZE fprintf error )
    
    return 0;

    
error_1:
    fprintf(stderr, "Error cant open file or file doesnt exist.");
    return -1;

}

/**
 * Store input file or stdin to file 
 * return NULL if error 
*/
FILE *parser(int argc, char *argv[])
{
    FILE *f = NULL;
    if(argc == 2)
    {
        f = fopen(argv[1], "r");
        if(f == NULL)
            return NULL;
        return f;
    }
    f = stdin;
    return f;
}