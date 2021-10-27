#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "simple_crypto.h"

void print_array(int array[], int size) {
    printf("[ ");
    for (int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int get_num(int array[], int size) {
    srand(time(NULL));

    int index = rand() % size;
    int num = array[index];
    array[index] = array[size-1];
    return num;
}

permutation generate_permutation() {
    permutation p;

    int initial[ASCII_READABLE_CHARS];
    for (int i=0; i<ASCII_READABLE_CHARS; i++) {
        initial[i] = i + 0x20;
    }

    int size = ASCII_READABLE_CHARS;
    int index = 0;

    while (size) {
        p.nums[index++] = get_num(initial, size--);
    }

    return p;
}

void print_permutation(permutation p) {
    printf("[ ");
    for (int i=0; i<ASCII_READABLE_CHARS; i++) {
        printf("%d ", p.nums[i]);
    }
    printf("]\n");
}