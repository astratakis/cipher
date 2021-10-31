#include "test_functions.h"

typedef enum test_verdict {
    OK,     // Successful test
    TLE,    // Time limit exceeded
    RE,     // Runtime Error
    WA      // Wrong answer
} test_verdict;

typedef struct test {
    const char *name;
    const char *description;
    unsigned long timeout;
    int (*function)(void);
    test_verdict verdict;
} test;

test unit_tests[] = {
    {"Tabula Recta creation", "Check if the tabula recta matrix is created correctly", 1, check_tabula_recta},
    {"Vigeneres sample encrypt", "Test ATTACKATDAWN with key LEMON", 1, vigeneres_sample_encrypt_test},
    {"Vigeneres sample decrypt", "Test LXFOPVEFRNHR with key LEMON", 1, vigeneres_sample_decrypt_test},
    {"Vigeneres sample test", "Test encrypt and decrypt", 1, vigeneres_sample_both_test},
    NULL
};