// Solution for IJC-DU2, task 2), 28.3.2021
// File:        wordcount.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Count words in some text.

#include "wordcount.h"
#include "htab.h"
#include <stdbool.h>

/*Max word lenght.*/
#define MAX_WORD_SIZE 128
//#define MOVETEST

/**
 * Number of elements in hash table.
 * Číslo jsem vybral čárka protože:
 *  - Je to prvnočíslo a ty zlepšují výpočet indexu pomocí hashovací funkce.
 *  - Mělo by být co jak možno nevzálenější od mocniny 2 )
 *  - Vybral jsem prvočíslo zruba mezi (2^14 a 2^15) 
 *  - Přiměřená velikost předpokládám že málokterý text obsahuje hodně slov. Pro představu aktivní slovní
 *  - zasoba obsahuje 6000 - 10000 slov a kniha může mít i 50000 
 *  - číslo se zdá trochu velké, ale jelikož máme v dnešní době velké pamětové prostředky neměl by to být 
 *  problém. Navíc jsem k němu dospěl pomocí měření času. Je t5eba brát v potaz vlastnosti hash tabulky
 *  kdy nevadí že je velká ptotože výpočet indexu je vždy velmi efektivní.
 * 
*/
//VYBRANA HODNOTA = 20763
#define ARR_SIZE 20763



#define ARR_SIZE_TEST 6131 //using for test purpose in htab_move()

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

    #ifdef MOVETEST
    htab_t *test_table = htab_move(ARR_SIZE_TEST, table);
    htab_for_each(test_table, print_record);

    if(word_overflow)
        fprintf(stderr,"Error word was longer then MAX_WORD_SIZE\n");
    
    fclose(f); 
    htab_free(test_table);
    return 0;
    #endif

    //print every record in table using print_record() function
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