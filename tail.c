// Solution for IJC-DU2, task 1), 28.3.2021
// File:        tail.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
//   

#include <stdio.h>
#include "tail.h"

int main(int argc, char *argv[])
{
    if (arg_parser(argc, argv))
        return 0;
    
    printf("success");
    return 0;
}

/**
 * Parse arguments. 
 * return 1 if there are no parameters 
 */
int arg_parser(int argc, char *argv[])
{
    if(argc == 1)
        return 1;

    printf("%d", argc);
    return 0;
}