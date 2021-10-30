#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test_functions.h"
#include "simple_crypto.h"

#define SUCCESS 151
#define FAILURE 150

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

    tabula_recta tr = create_tabula_recta();

    FILE *in = fopen("vigeneres_tests/testset_1.txt", "r");
    FILE *out = fopen("vigeneres_tests/testset_1_output.txt", "r");

    if (in == NULL || out == NULL) {
        return FAILURE;
    }

    int test_cases;
    fscanf(in, "%d", &test_cases);

    for (int tt=1; tt<=test_cases; tt++) {
        int string_length;

        fscanf(in, "%d", &string_length);
        string_length++;

        char *input_string = malloc(string_length);
        char *key = malloc(string_length);
        char *output = malloc(string_length);

        fscanf(in, "%s", input_string);
        fscanf(in, "%s", key);

        char *cipher_text = malloc(string_length);

        for (int i=0; i<string_length-1; i++) {
            cipher_text[i] = tr.matrix[input_string[i] - 0x41][key[i] - 0x41];
        }

        cipher_text[string_length-1] = '\0';

        fscanf(out, "%s", output);

        if (strcmp(output, cipher_text) != 0) {
            return FAILURE;
        }

        free(output);
        free(cipher_text);
        free(input_string);
        free(key);
    }

    fclose(in);
    fclose(out);

    return SUCCESS;
}

int vigeneres_cipher_test_set_2(void) {

    tabula_recta tr = create_tabula_recta();

    FILE *in = fopen("vigeneres_tests/testset_2.txt", "r");
    FILE *out = fopen("vigeneres_tests/testset_2_output.txt", "r");

    if (in == NULL || out == NULL) {
        return FAILURE;
    }

    int test_cases;
    fscanf(in, "%d", &test_cases);

    for (int tt=1; tt<=test_cases; tt++) {
        int string_length;

        fscanf(in, "%d", &string_length);
        string_length++;

        char *input_string = malloc(string_length);
        char *key = malloc(string_length);
        char *output = malloc(string_length);

        fscanf(in, "%s", input_string);
        fscanf(in, "%s", key);

        char *cipher_text = malloc(string_length);

        for (int i=0; i<string_length-1; i++) {
            cipher_text[i] = tr.matrix[input_string[i] - 0x41][key[i] - 0x41];
        }

        cipher_text[string_length-1] = '\0';

        fscanf(out, "%s", output);

        if (strcmp(output, cipher_text) != 0) {
            return FAILURE;
        }

        free(output);
        free(cipher_text);
        free(input_string);
        free(key);
    }

    fclose(in);
    fclose(out);

    return SUCCESS;
}