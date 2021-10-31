#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "simple_crypto.h"

tabula_recta *create_tabula_recta() {
    tabula_recta *ans = malloc(sizeof(tabula_recta));

    ans->size = 26;
    ans->matrix = malloc(ans->size * sizeof(char *));
    for (int i=0; i<ans->size; i++) {
        ans->matrix[i] = malloc(ans->size);
    }

    for (int i=0; i<ans->size; i++) {
        for (int j=0; j<ans->size; j++) {
            ans->matrix[i][j] = ((i+j) % ans->size) + 0x41;
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

char *encrypt_vigeneres(const char *__plain_text, const char *__key) {
    tabula_recta *tr = create_tabula_recta();

    char *encrypted = malloc(strlen(__plain_text) + 1);

    for (int i=0; i<strlen(__plain_text); i++) {
        encrypted[i] = tr->matrix[__key[i % strlen(__key)] - 0x41][__plain_text[i] - 0x41];
    }
    encrypted[strlen(__plain_text)] = '\0';

    free(tr->matrix);
    free(tr);

    return encrypted;
}

char *decrypt_vigeneres(const char *__encrypted, const char *__key) {
    tabula_recta *tr = create_tabula_recta();

    char *decrypted = malloc(strlen(__encrypted) + 1);

    for (int i=0; i<strlen(__encrypted); i++) {
        char starting = tr->matrix[__key[i % strlen(__key)] - 0x41][0];
        int diff = __encrypted[i] - starting;
        if (diff < 0) {
            diff += 26;
        }
        decrypted[i] = (diff + 0x41);
    }
    decrypted[strlen(__encrypted)] = '\0';

    free(tr->matrix);
    free(tr);

    return decrypted;
}