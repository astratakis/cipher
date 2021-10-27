#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simple_crypto.h"

int main(int argc, char **argv) {

    permutation p = generate_permutation();
    print_permutation(p);

    printf("Enter key: ");
    char *key = malloc(sizeof(100));
    scanf("%s", key);

    FILE *fp = fopen("input.txt", "r");

    char *input;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s - %ld\n", buffer, strlen(buffer));
    }


    return 0;
}