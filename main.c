#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_crypto.h"

#define MAX_STRING_LENGTH 1e6

#define reset_string(s) memset(s, 0x0, MAX_STRING_LENGTH)

int main(int argc, char **argv) {

    string input = malloc(MAX_STRING_LENGTH);
    string key = malloc(MAX_STRING_LENGTH);
    int shift;
    reset_string(input);
    reset_string(key);

    // ------------------ < One time padding > ------------------
    // ----------------------------------------------------------

    reset_string(input);
    reset_string(key);

    // ---------------------- < Caesar's > ----------------------
    printf("[Caesars] input: ");
    scanf("%s", input);
    printf("[Caesars] key: ");
    scanf("%d", &shift);
    string enc_ceasar = encrypt_caesars(input, shift);
    string dec_ceasar = decrypt_caesars(enc_ceasar, shift);
    printf("[Caesars] encrypted: %s\n[Caesars] decrypted: %s\n", enc_ceasar, dec_ceasar);
    // ----------------------------------------------------------

    reset_string(input);
    reset_string(key);

    // --------------------- < Vigenere's > ---------------------
    printf("[Vigenere] input: ");
    scanf("%s", input);
    printf("[Vigenere] key: ");
    scanf("%s", key);
    string enc_vigenere = encrypt_vigeneres(input, key);
    string dec_vigenere = decrypt_vigeneres(enc_vigenere, key);
    printf("[Vigenere] encrypted: %s\n[Vigenere] decrypted: %s\n", enc_vigenere, dec_vigenere);
    // ----------------------------------------------------------

    return 0;
}