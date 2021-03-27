// Solution for IJC-DU2, task 1), 28.3.2021
// File:        tail.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Works like posix tail if does not get file read from stdin.  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tail.h"

//Indicate if there is + in -n +10 argument
//It is on byte one if value is 1 there is plus sign 
#define PLUS 1 
#define IS_THERE_FILE 2 //if file was on intput set to 1

#define SIGN_INDICATOR_POSITION 0
#define IS_THERE_A_FILE_POSITION 1 // 1 byte is true or false and second i in argv[i]
#define POSITION_IN_ARGV 2

#define MAX_ROWS_DIGIT 12 // 1000 = 10 * 10^12
#define INT_MAX 2147483647

int main(int argc, char *argv[])
{
    FILE *file = NULL;

    // 0. byte plus sign indicator // 1. Is there a file indicatro // 2-258 bytes file_name 
    int arguments[PLUS + IS_THERE_FILE] = {0};
    arguments[SIGN_INDICATOR_POSITION] = arguments[IS_THERE_A_FILE_POSITION] = 0;
    
    char *buffer = NULL;
    int n = arg_parser(argc, argv, arguments);

    if (n == -1)    // Parsing error 
        return -1;
    else if(n == -2) //no arguments looking for stdin 
    {
        //read from stdin 
        n = 10;
    }

    //TODO check if file exist function 
    if(arguments[IS_THERE_A_FILE_POSITION] == 1)
    {
        file = fopen(argv[arguments[POSITION_IN_ARGV]], "r");
        if(file == NULL) //check if fopen was succesfull 
            goto error_1;
    
    }
    
    

    printf("%d",n);
    if(arguments[IS_THERE_A_FILE_POSITION] == 1)
        fclose(file);

    return 0;


error_1:
    fprintf(stderr, "File does not exist.\n");
    return -1;


}

/**
 * Parse arguments. 
 * return -1 error 
 * return -2 if there are no args 
 * else return -n number positio
 * 
 * argument[]
 * 0. byte plus sign indicator 
 * 1. Is there a file indicatro 
 * 2. file position in argv
 */
int arg_parser(int argc, char *argv[], int arguments[])
{
    int n = 10;
    char help[MAX_ROWS_DIGIT] = {0}; //tempo variable where number will n be stored 
    
    if(argc == 1) // No arguments
        return -2;

    // Go throw all the argv[] loking for:
    // -n [+]number file 
    for(int i=1; i < argc ;i++) //for -n [+]number
    {		
        if(strcmp(argv[i], "-n")==0)
        {
            if(i < argc - 1)
            {
                if(argv[i+1][0] == '+')
                {
                    arguments[SIGN_INDICATOR_POSITION] = 1;
                    if(copy_from_to(argv, help, i+1, MAX_ROWS_DIGIT ,1 , 0) == -1)
                        goto error_4;
                }
                else
                {
                    if(copy_from_to(argv, help, i+1, MAX_ROWS_DIGIT, 0 , 0) == -1)
                        goto error_4;
                }
            }
            else
                goto error_2;
            i++;
            continue;
        }
        else //for file 
        {
            if(arguments[IS_THERE_A_FILE_POSITION] == 1) //multiple file names 
                goto error_3;
            arguments[IS_THERE_A_FILE_POSITION] = 1;
            arguments[POSITION_IN_ARGV] = i;
        }
    }

    //check if number in (-n number) is number.
    if(check_if_array_is_digit(help, MAX_ROWS_DIGIT, arguments[SIGN_INDICATOR_POSITION]) == -1)
        goto error_1;

    if(atoi(help) > INT_MAX || atoi(help) < 0)
        goto error_4;
    
    for(int i = 0; help[i] != '\0';i++)
        printf("%c",help[i]);
    
    n = atoi(help);
    printf("%d\n",n);
    return n;


//////////////ERRORS 
error_1:
    fprintf(stderr, "Error there has to be digit after -n.\n");
    return -1;

error_2:
    fprintf(stderr, "Error missing number after -n argument.\n");
    return -1;

error_3:
    fprintf(stderr, "Error there can be only one file.\n");
    return -1;

error_4:
    fprintf(stderr, "Number has to be positive. Or number is to big.\n");
    return -1;

error_5:
    fprintf(stderr, "Error to big file name \n");
    return -1;
}

/**
 * Just copy from to 
 * from[][] is 
 * return -1 if limit was reached
 */
int copy_from_to(char *from[], char to[], int first_index, int limit, int from_start_byte, int to_start_byte)
{
    for(int j = from_start_byte; (from[first_index][j] != '\0'); j++)
    {
        if(j > limit)
            return -1;
        to[to_start_byte + (j-from_start_byte)] = from[first_index][j];
    }
    return 0;
}

/**
 * Check if array of given size has just number
 * return -1 if error 
 */
int check_if_array_is_digit(char array[], int size, int plus_sign)
{
    int j = 0;
    if(plus_sign = 1)
        j++;

    for(; (j < size) && (array[j] != '\0'); j++)
        if(!isdigit(array[j]))
            return -1;
    return 0;

}