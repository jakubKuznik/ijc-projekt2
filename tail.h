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
int arg_parser(int argc, char *argv[], char arguments[]);