#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simple_crypto.h"

int main(int argc, char **argv) {

    tabula_recta tr = create_tabula_recta();

    for (int i=0; i<tr.size; i++) {
        printf("%s\n", tr.matrix[i]);
    }
    return 0;
}