#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "test_functions.h"
#include "simple_crypto.h"

#define SUCCESS 151
#define FAILURE 150

int vigeneres_sample_encrypt_test(void) {
    const string text = "ATTACKATDAWN";
    const string key = "LEMON";

    string result = encrypt_vigeneres(text, key);

    if (strcmp(result, "LXFOPVEFRNHR") != 0) {
        free(result);
        return FAILURE;
    }

    free(result);
    return SUCCESS;
}

int vigeneres_sample_decrypt_test(void) {
    const string encrypted = "LXFOPVEFRNHR";
    const string key = "LEMON";

    string result = decrypt_vigeneres(encrypted, key);
    
    if (strcmp(result, "ATTACKATDAWN") != 0) {
        free(result);
        return FAILURE;
    }

    free(result);
    return SUCCESS;
}

int vigeneres_sample_both_test(void) {
    const string initial = "HELLOMYFRIENDS";
    const string key = "WHATAMIDOING";

    string encrypted = encrypt_vigeneres(initial, key);

    if (strcmp(encrypted, "DLLEOYGIFQRTZZ") != 0) {
        free(encrypted);
        return FAILURE;
    }

    string decrypted = decrypt_vigeneres(encrypted, key);

    free(encrypted);

    if (strcmp(decrypted, "HELLOMYFRIENDS") != 0) {
        free(decrypted);
        return FAILURE;
    }

    free(decrypted);
    return SUCCESS;
}

int vigeneres_test_1(void) {
    FILE *in = fopen("vigeneres_tests/testset_1.txt", "r");
    FILE *out = fopen("vigeneres_tests/testset_1_output.txt", "r");

    int test_cases;
    fscanf(in, "%d", &test_cases);

    for (int tt=1; tt<=test_cases; tt++) {
        int input_size;
        fscanf(in, "%d", &input_size);

        string input = malloc(input_size + 1);
        fscanf(in, "%s", input);

        int key_size;
        fscanf(in, "%d", &key_size);

        string key = malloc(key_size + 1);
        fscanf(in, "%s", key);

        string encrypted = encrypt_vigeneres(input, key);

        string output = malloc(input_size + 1);
        fscanf(out, "%s", output);

        if (strcmp(encrypted, output) != 0) {
            free(input);
            free(output);
            free(key);
            free(encrypted);
            fclose(in);
            fclose(out);
            return FAILURE;
        }

        string decrypted = decrypt_vigeneres(encrypted, key);

        if (strcmp(decrypted, input) != 0) {
            free(input);
            free(output);
            free(key);
            free(encrypted);
            free(decrypted);
            fclose(in);
            fclose(out);
            return FAILURE;
        }

        free(input);
        free(output);
        free(key);
        free(encrypted);
        free(decrypted);
    }
    return SUCCESS;
}

int vigeneres_test_2(void) {
    FILE *in = fopen("vigeneres_tests/testset_2.txt", "r");
    FILE *out = fopen("vigeneres_tests/testset_2_output.txt", "r");

    int test_cases;
    fscanf(in, "%d", &test_cases);

    for (int tt=1; tt<=test_cases; tt++) {
        int input_size;
        fscanf(in, "%d", &input_size);

        string input = malloc(input_size + 1);
        fscanf(in, "%s", input);

        int key_size;
        fscanf(in, "%d", &key_size);

        string key = malloc(key_size + 1);
        fscanf(in, "%s", key);

        string encrypted = encrypt_vigeneres(input, key);

        string output = malloc(input_size + 1);
        fscanf(out, "%s", output);

        if (strcmp(encrypted, output) != 0) {
            free(input);
            free(output);
            free(key);
            free(encrypted);
            fclose(in);
            fclose(out);
            return FAILURE;
        }

        string decrypted = decrypt_vigeneres(encrypted, key);

        if (strcmp(decrypted, input) != 0) {
            free(input);
            free(output);
            free(key);
            free(encrypted);
            free(decrypted);
            fclose(in);
            fclose(out);
            return FAILURE;
        }

        free(input);
        free(output);
        free(key);
        free(encrypted);
        free(decrypted);
    }
    return SUCCESS;
}

int vigeneres_test_3(void) {
    FILE *in = fopen("vigeneres_tests/testset_3.txt", "r");
    FILE *out = fopen("vigeneres_tests/testset_3_output.txt", "r");

    int test_cases;
    fscanf(in, "%d", &test_cases);

    for (int tt=1; tt<=test_cases; tt++) {
        int input_size;
        fscanf(in, "%d", &input_size);

        string input = malloc(input_size + 1);
        fscanf(in, "%s", input);

        int key_size;
        fscanf(in, "%d", &key_size);

        string key = malloc(key_size + 1);
        fscanf(in, "%s", key);

        string encrypted = encrypt_vigeneres(input, key);

        string output = malloc(input_size + 1);
        fscanf(out, "%s", output);

        if (strcmp(encrypted, output) != 0) {
            free(input);
            free(output);
            free(key);
            free(encrypted);
            fclose(in);
            fclose(out);
            return FAILURE;
        }

        string decrypted = decrypt_vigeneres(encrypted, key);

        if (strcmp(decrypted, input) != 0) {
            free(input);
            free(output);
            free(key);
            free(encrypted);
            free(decrypted);
            fclose(in);
            fclose(out);
            return FAILURE;
        }

        free(input);
        free(output);
        free(key);
        free(encrypted);
        free(decrypted);
    }
    return SUCCESS;
}

int vigeneres_test_4(void) {
    FILE *in = fopen("vigeneres_tests/testset_4.txt", "r");
    FILE *out = fopen("vigeneres_tests/testset_4_output.txt", "r");

    int test_cases;
    fscanf(in, "%d", &test_cases);

    for (int tt=1; tt<=test_cases; tt++) {
        int input_size;
        fscanf(in, "%d", &input_size);

        string input = malloc(input_size + 1);
        fscanf(in, "%s", input);

        int key_size;
        fscanf(in, "%d", &key_size);

        string key = malloc(key_size + 1);
        fscanf(in, "%s", key);

        string encrypted = encrypt_vigeneres(input, key);

        string output = malloc(input_size + 1);
        fscanf(out, "%s", output);

        if (strcmp(encrypted, output) != 0) {
            free(input);
            free(output);
            free(key);
            free(encrypted);
            fclose(in);
            fclose(out);
            return FAILURE;
        }

        string decrypted = decrypt_vigeneres(encrypted, key);

        if (strcmp(decrypted, input) != 0) {
            free(input);
            free(output);
            free(key);
            free(encrypted);
            free(decrypted);
            fclose(in);
            fclose(out);
            return FAILURE;
        }

        free(input);
        free(output);
        free(key);
        free(encrypted);
        free(decrypted);
    }
    return SUCCESS;
}