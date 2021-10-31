#include "test_functions.h"

typedef enum test_verdict {
    OK,
    TLE,
    RE,
    WA
} test_verdict;

typedef struct test {
    const char *name;
    const char *description;
    unsigned long timeout;
    int (*function)(void);
    test_verdict verdict;
} test;

test unit_tests[] = {
    {"Vigenere's Implementation", "", 2, vigeneres_cipher_test_set_1},
    {"Vigenere's Cipher (large)", "", 2, vigeneres_cipher_test_set_2},
    {"Ceasars table", "", 1, check_ceasars_table},
    {"Time limit example", "", 1, time_limit_example},
    NULL
};