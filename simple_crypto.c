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
    p.size = ASCII_READABLE_CHARS;

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

char * one_time_pad(char *__input, int input_size, char *__key, int key_size) {
    return "?";
}

tabula_recta create_tabula_recta() {
    tabula_recta ans;

    ans.size = 26;
    ans.matrix = malloc(ans.size * sizeof(char *));
    for (int i=0; i<ans.size; i++) {
        ans.matrix[i] = malloc(ans.size);
    }

    for (int i=0; i<ans.size; i++) {
        for (int j=0; j<ans.size; j++) {
            ans.matrix[i][j] = ((i+j) % ans.size) + 0x41;
        }
    }

    return ans;
}

ceasars_shift_vector create_ceasars_shift_vector() {
    ceasars_shift_vector ans;
    ans.size = 2*26 + 10;
    ans.table = malloc(ans.size);

    char current = 'A';
    for (int i=0; i<26; i++) {
        ans.table[i] = current;
        current++;
    }

    current = 'a';

    for (int i=26; i<2*26; i++) {
        ans.table[i] = current;
        current++;
    }

    current = '0';

    for (int i=2*26; i<(2*26 + 10); i++) {
        ans.table[i] = current;
        current++;
    }

    return ans;
}