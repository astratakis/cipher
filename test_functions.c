#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>

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

int caesars_sample_encrypt_test(void) {
    string encrypted = encrypt_caesars("hello", 1);

    if (strcmp("ifmmp", encrypted) != 0) {
        free(encrypted);
        return FAILURE;
    }

    free(encrypted);
    return SUCCESS;
}

int caesars_sample_decrypt_test(void) {
    string dedcrypted = decrypt_caesars(encrypt_caesars("hello", 1), 1);

    if (strcmp(dedcrypted, "hello") != 0) {
        free(dedcrypted);
        return FAILURE;
    }

    free(dedcrypted);
    return SUCCESS;
}

int caesars_test_1(void) {
    const string text = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int key = 4;

    string enc = encrypt_caesars(text, key);

    const string expected = "456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123";

    if (strcmp(enc, expected) != 0) {
        return FAILURE;
    }

    return SUCCESS;
}

int caesars_test_2(void) {
    const string enc = "456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123";
    int key = 4;

    string dec = decrypt_caesars(enc, key);

    const string expected = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    if (strcmp(dec, expected) != 0) {
        return FAILURE;
    }

    return SUCCESS;
}

int otp_sample_encrypt_test(void) {
    string enc = encrypt_otp("hello", "XMCKL", 5);

    if (strcmp(enc, "0(/'#") != 0) {
        return FAILURE;
    }

    return SUCCESS;
}

int otp_sample_decrypt_test(void) {
    string dec = decrypt_otp("0(/'#", "XMCKL", 5);

    if (strcmp(dec, "hello") != 0) {
        return FAILURE;
    }
    return SUCCESS;
}

int otp_test_1(void) {

    const unsigned int _max_length = 1e6;

    string initial = malloc(_max_length);
    int file_desc = open("/dev/urandom", O_RDONLY);
    size_t size = read(file_desc, initial, _max_length);

    assert(size > 0);

    string key = malloc(_max_length);
    size = read(file_desc, key, _max_length);

    string encrypted = encrypt_otp(initial, key, _max_length);

    for (int i=0; i<_max_length; i++) {
        if (encrypted[i] != (initial[i] ^ key[i])) {
            printf("%d\n", i);
            return FAILURE;
        }
    }

    string decrypted = decrypt_otp(encrypted, key, _max_length);

    for (int i=0; i<_max_length; i++) {
        if (initial[i] != decrypted[i]) {
            return FAILURE;
        }
    }

    return SUCCESS;
}