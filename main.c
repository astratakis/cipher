#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_crypto.h"

int main(int argc, char **argv) {

    char input[1000];

    printf("[OTP] input: ");
    scanf("%s", input);
    printf("[OTP] encrypted: \n");
    printf("[OTP] decrypted: \n");

    int shift;
    memset(input, 0x0, 1000);

    printf("[Caesars] input: ");
    scanf("%s", input);
    printf("[Caesars] key: ");
    scanf("%d", &shift);
    printf("[Caesars] encrypted: \n");
    printf("[Caesars] decrypted: \n");

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