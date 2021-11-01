#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "simple_crypto.h"

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
    char *encrypted = malloc(strlen(__plain_text) + 1);

    for (int i=0; i<strlen(__plain_text); i++) {
        encrypted[i] = (__plain_text[i] - 0x41 + __key[i % strlen(__key)] - 0x41) % 26 + 0x41;
    }
    encrypted[strlen(__plain_text)] = '\0';

    return encrypted;
}

char *decrypt_vigeneres(const char *__encrypted, const char *__key) {
    char *decrypted = malloc(strlen(__encrypted) + 1);

    for (int i=0; i<strlen(__encrypted); i++) {
        decrypted[i] = (__encrypted[i] - __key[i % strlen(__key)] + 26) % 26 + 0x41;
    }
    decrypted[strlen(__encrypted)] = '\0';

    return decrypted;
}