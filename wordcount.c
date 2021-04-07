// Solution for IJC-DU2, task 2), 28.3.2021
// File:        wordcount.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Count words in some text.

#include "wordcount.h"
#include "htab.h"
#include "htab_struct.h"
#include <stdbool.h>

int main(int argc, char *argv[])
{
    htab_t *table = htab_init(ARR_SIZE); //Creating hash table 
    FILE *f = NULL;                     //Input file where we are geting words from 
    if((f = parser(argc, argv)) == NULL)
        goto error_1;


    char one_word[MAX_WORD_SIZE] = {0};  //here i store one word 
    int word_len = 0;                    
    bool word_overflow = false;          //If max word size was ever reached the word was cut and var set to true 
    htab_pair_t *return_record = NULL;   //Store output of htab_add
    
    //Read word by word and store them to hash table 
    while((word_len = read_word(one_word, MAX_WORD_SIZE, f)) != EOF)
    {
        if(word_len == MAX_WORD_SIZE - 1)
            word_overflow = true;

        //if there are multiple isspace symbols return '\0'
        if(strlen(one_word) > 0)
            if((return_record = htab_lookup_add(table, one_word)) == NULL)
                goto error_malloc;
        // Calculate number of ocurrencess 
        return_record->value = return_record->value + 1;

    }

    htab_for_each(table, print_record);

    if(word_overflow)
        fprintf(stderr,"Error word was longer then MAX_WORD_SIZE\n");
    
    fclose(f); 
    htab_free(table);
    return 0;

    
error_1:
    fprintf(stderr, "Error cant open file or file doesnt exist.\n");
    return -1;

error_malloc:
    fprintf(stderr, "Error malloc.\n");
    fclose(f); 
    htab_free(table);


}
/**
 * Print record.key (word) and its key (Number of occurrences)
 */
void print_record(htab_pair_t *record)
{
    printf("%s\t%u\n",record->key, record->value);
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