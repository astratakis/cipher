#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test_functions.h"
#include "simple_crypto.h"

#define SUCCESS 151
#define FAILURE 150
#define TIME_LIMIT 149

int segmentation_fault_example(void) {
    char *str = "You make my software turn into hardware ;)";
 
    /* Problem:  trying to modify read only memory */
    *(str+1) = 'n';
    return SUCCESS;
}

int example_test(void) {
    return SUCCESS;
}

int wrong_answer_example(void) {
    return FAILURE;
}

int time_limit_example(void) {
    while (1) {

    }
    return SUCCESS;
}

int vigeneres_cipher_test_set_1(void) {
    
}