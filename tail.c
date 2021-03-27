// Solution for IJC-DU2, task 1), 28.3.2021
// File:        tail.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Works like posix tail if does not get file read from stdin.  

#include <stdio.h>
#include <string.h>
#include "tail.h"

//Indicate if there is + in -n +10 argument
//It is on byte one if value is 1 there is plus sign 
#define PLUS 1 
#define IS_THERE_FILE 1 //if file was on intput set to 1
#define FILE_NAME_MAX_SIZE 256

#define SIGN_INDICATOR_POSITION 0
#define IS_THERE_A_FILE_POSITION 1
#define FILE_NAME_START_BYTE 2

int main(int argc, char *argv[])
{

    // 0. byte plus sign indicator // 1. Is there a file indicatro // 2-258 bytes file_name 
    char arguments[PLUS + IS_THERE_FILE + FILE_NAME_MAX_SIZE] = {0};
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

    for(int i = 0; i < 258; i++)
        printf("%c",arguments[i]);
    

    return 0;
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
 * 2-258 bytes file_name 
 */
int arg_parser(int argc, char *argv[], char arguments[])
{
    
    if(argc == 1) // No arguments
        return -2;


    for(int i=1; i < argc ;i++)
    {		
        if(strcmp(argv[i], "-n")==0)
        {
            if(i < argc - 1)
            {
                if(argv[i+1][0] == '+')
                {
                    arguments[SIGN_INDICATOR_POSITION] = 1;
                    for(int j = 1; argv[i+1][j] != '\0'; j++)
                        arguments[FILE_NAME_START_BYTE + (j - 1)] = argv[i+1][j];
                }
                else
                {
                    for(int j = 0; argv[i+1][j] != '\0'; j++)
                        arguments[FILE_NAME_START_BYTE + j] = argv[i+1][j];
                }
            }
            else
            {
                fprintf(stderr, "Error missing number after -n argument.\n");
                return -1;
            }
        }
    }

    return 0;
}

