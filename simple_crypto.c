#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
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

string encrypt_vigeneres(const string __plain_text, const string __key) {
    string encrypted = malloc(strlen(__plain_text) + 1);

    for (int i=0; i<strlen(__plain_text); i++) {
        encrypted[i] = (__plain_text[i] - 0x41 + __key[i % strlen(__key)] - 0x41) % 26 + 0x41;
    }
    encrypted[strlen(__plain_text)] = '\0';

    return encrypted;
}

string decrypt_vigeneres(const string __encrypted, const string __key) {
    string decrypted = malloc(strlen(__encrypted) + 1);

    for (int i=0; i<strlen(__encrypted); i++) {
        decrypted[i] = (__encrypted[i] - __key[i % strlen(__key)] + 26) % 26 + 0x41;
    }
    decrypted[strlen(__encrypted)] = '\0';

    return decrypted;
}

bool isletter(const char c) {
    return (c >= 0x41 && c <= 0x5A) || (c >= 0x61 && c <= 0x7A);
}

string encrypt_caesars(const string __plain_text, const int shift) {
    string encrypted = malloc(strlen(__plain_text) + 1);

    for (int i=0; i<strlen(__plain_text); i++) {
        int enc_char = __plain_text[i];
        if (isletter(__plain_text[i])) {
            if (isupper(__plain_text[i])) {
                enc_char -= 0x41;
                enc_char = (enc_char + shift) % 26;
                enc_char += 0x41;
            }
            else {
                enc_char -= 0x61;
                enc_char = (enc_char + shift) % 26;
                enc_char += 0x61;
            }
        }
        else if (isdigit(__plain_text[i])) {
            enc_char -= 0x30;
            enc_char = (enc_char + shift) % 10;
            enc_char += 0x30;
        }
        encrypted[i] = enc_char;
    }
    encrypted[strlen(__plain_text)] = '\0';

    return encrypted;
}

string decrypt_caesars(const string __encrypted, const int shift) {
    string decrypted = malloc((strlen(__encrypted) + 1));

    for (int i=0; i<strlen(__encrypted); i++) {
        decrypted[i] = __encrypted[i] - shift;
    }
    decrypted[strlen(__encrypted)] = '\0';

    return decrypted;
}