// Solution for IJC-DU2, task 1), 28.3.2021
// File:        tail.h
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Header file for tail.c 



/**
 * Parse arguments. 
 * return -1 error 
 * else return -n number positio
 * 
 * argument[]
 * 0. byte plus sign indicator 
 * 1. Is there a file indicatro 
 * 2-258 bytes file_name 
 */
int arg_parser(int argc, char *argv[], int arguments[]);

/**
 * Just copy from to 
 * from[][] is 
 * return -1 if limit was reached
 */
int copy_from_to(char *from[], char to[], int first_index, int limit, int from_start_byte, int to_start_byte);


/**
 * Check if array of given size has just number
 * return -1 if error 
 */
int check_if_array_is_digit(char array[], int size, int plus_sign);


/**
 * Print last n lines to stdout 
 * printf from n +num to end of file 
 * plus sign = 1 means there was a + sign 
 */
int tail(FILE *file, int n, int plus_sign);