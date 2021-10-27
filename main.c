#include <stdio.h>
#include "simple_crypto.h"

int main(int argc, char **argv) {

    permutation p = generate_permutation();
    print_permutation(p);
    return 0;
}