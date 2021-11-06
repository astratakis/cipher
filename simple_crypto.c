#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "simple_crypto.h"

#define CAESARS_TABLE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

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
    
    /*  Information about the character must not be lost.
    *   This means that this algorithm will work on a specific character set
    *   which is [0-9A-Za-z].
    */

    const int max_shifts = (26 + 26 + 10);
    int rotation = shift % max_shifts;
    string encrypted = malloc(strlen(__plain_text) + 1);

    for (int i=0; i<strlen(__plain_text); i++) {
        if (isdigit(__plain_text[i])) {
            int pos = __plain_text[i] - 0x30;

            pos = (pos + rotation) % max_shifts;
            encrypted[i] = CAESARS_TABLE[pos];
        }
        else if (isletter(__plain_text[i])) {
            int pos;
            if (isupper(__plain_text[i])) {
                pos = __plain_text[i] - 0x41 + 10;
            }
            else {
                pos = __plain_text[i] - 0x61 + 36;
            }

            pos = (pos + rotation) % max_shifts;
            encrypted[i] = CAESARS_TABLE[pos];
        }
        else {
            encrypted[i] = __plain_text[i];
        }
    }
    encrypted[strlen(__plain_text)] = '\0';

    return encrypted;
}

string decrypt_caesars(const string __encrypted, const int shift) {

    const int max_shifts = (26 + 26 + 10);
    int rotation = shift % max_shifts;
    string decrypted = malloc((strlen(__encrypted) + 1));

    for (int i=0; i<strlen(__encrypted); i++) {
        if (isdigit(__encrypted[i])) {
            int pos = __encrypted[i] - 0x30;

            pos -= rotation;
            pos += (pos < 0 ? max_shifts : 0);

            decrypted[i] = CAESARS_TABLE[pos];
        }
        else if (isletter(__encrypted[i])) {
            int pos;
            if (isupper(__encrypted[i])) {
                pos = __encrypted[i] - 0x41 + 10;
            }
            else {
                pos = __encrypted[i] - 0x61 + 36;
            }

            pos -= rotation;
            pos += (pos < 0 ? max_shifts : 0);

            decrypted[i] = CAESARS_TABLE[pos];
        }
        else {
            decrypted[i] = __encrypted[i];
        }
    }
    decrypted[strlen(__encrypted)] = '\0';

    return decrypted;
}

string encrypt_otp(const string __plain_text, const string __key) {
    string encrypted = malloc(strlen(__plain_text) + 1);

    for (int i=0; i<strlen(__plain_text); i++) {
        if (isdigit(__plain_text[i]) || isletter(__plain_text[i])) {
            encrypted[i] = __plain_text[i] ^ __key[i];
        }
        else {
            encrypted[i] = __plain_text[i];
        }
    }

    encrypted[strlen(__plain_text)] = '\0';

    return encrypted;
}

string decrypt_otp(const string __encrypted, const string __key, const int __text_size) {
    string decrypted = malloc(__text_size + 1);

    for (int i=0; i<__text_size; i++) {
        decrypted[i] = __key[i] ^ __encrypted[i];
    }

    decrypted[__text_size] = '\0';

    return decrypted;
}