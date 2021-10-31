#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "test_functions.h"
#include "simple_crypto.h"

#define SUCCESS 151
#define FAILURE 150

int check_tabula_recta(void) {
    tabula_recta *tr = create_tabula_recta();

    assert(tr->size == 26);

    for (int i=0; i<tr->size; i++) {
        assert(strlen(tr->matrix[i]) == tr->size);
    }

    free(tr->matrix);
    free(tr);

    return SUCCESS;
}

int vigeneres_sample_encrypt_test(void) {
    const char *text = "ATTACKATDAWN";
    const char *key = "LEMON";

    char *result = encrypt_vigeneres(text, key);

    if (strcmp(result, "LXFOPVEFRNHR") != 0) {
        free(result);
        return FAILURE;
    }

    free(result);
    return SUCCESS;
}

int vigeneres_sample_decrypt_test(void) {
    const char *encrypted = "LXFOPVEFRNHR";
    const char *key = "LEMON";

    char *result = decrypt_vigeneres(encrypted, key);
    
    if (strcmp(result, "ATTACKATDAWN") != 0) {
        free(result);
        return FAILURE;
    }

    free(result);
    return SUCCESS;
}

int vigeneres_sample_both_test(void) {
    const char *initial = "HELLOMYFRIENDS";
    const char *key = "WHATAMIDOING";

    char *encrypted = encrypt_vigeneres(initial, key);

    if (strcmp(encrypted, "DLLEOYGIFQRTZZ") != 0) {
        free(encrypted);
        return FAILURE;
    }

    char *decrypted = decrypt_vigeneres(encrypted, key);

    free(encrypted);

    if (strcmp(decrypted, "HELLOMYFRIENDS") != 0) {
        free(decrypted);
        return FAILURE;
    }

    free(decrypted);
    return SUCCESS;
}