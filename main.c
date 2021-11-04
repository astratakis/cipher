#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_crypto.h"

#define MAX_STRING_LENGTH 1e6

int main(int argc, char **argv) {

    string input = malloc(MAX_STRING_LENGTH);

    int shift;
    memset(input, 0x0, MAX_STRING_LENGTH);

    printf("[Caesars] input: ");
    scanf("%s", input);
    printf("[Caesars] key: ");
    scanf("%d", &shift);
    string caesars_encrypted = encrypt_caesars(input, shift);
    string caesars_decrypted = decrypt_caesars(caesars_decrypted, shift);
    printf("[Caesars] encrypted: %s\n[Caesars] decrypted: %s\n", caesars_encrypted, caesars_decrypted);

    char key[1000];
    memset(input, 0x0, 1000);

    printf("[Vigenere] input: ");
    scanf("%s", input);
    printf("[Vigenere] key: ");
    scanf("%s", key);

    char *encrypted = encrypt_vigeneres(input, key);
    printf("[Vigenere] encrypted: %s\n", encrypted);
    char *decrypted = decrypt_vigeneres(encrypted, key);
    printf("[Vigenere] decrypted: %s\n", decrypted);
    return 0;
}