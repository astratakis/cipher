#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test_functions.h"
#include "simple_crypto.h"

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

int check_permutation(void) {
    permutation p = generate_permutation();

    int sum = 0;

    for (int i=0; i<p.size; i++) {
        sum += (p.nums[i] - 0x20);
        for (int j=0; j<p.size; j++) {
            if (i != j) {
                if (p.nums[i] == p.nums[j]) {
                    return FAILURE;
                }
            }
        }
    }

    return (sum == ((95 * 94) >> 1) ? SUCCESS : FAILURE);
}

int check_read_stdin(void) {
    
    char buffer[100];
    int index = 0;
    char *key;
    read(STDIN_FILENO, &buffer, 100);

    int length = strlen(buffer);
    
    key = malloc(length-1);

    for (int i=0; i<length-1; i++) {
        key[i] = buffer[i];
    }

    return SUCCESS;
}

int check_read_from_file(void) {

    char buffer[100];
    
    FILE *fp = fopen("input/small_input.txt", "r");

    if (fp == NULL) {
        return FAILURE;
    }

    fgets(buffer, 100, fp);

    int length = strlen(buffer);

    if (strcmp(buffer, "Hello") != 0) {
        return FAILURE;
    }

    return SUCCESS;
}

int key_addition_test(void) {
    permutation p = generate_permutation();

    char *initial_message = "Hello";
    char *key = "Pizza";

    if (srtlen(initial_message) != strlen(key)) {
        return FAILURE;
    }

    for (int i=0; i<strlen(initial_message); i++) {
        
    }
}