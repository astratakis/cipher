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