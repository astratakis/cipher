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
    {"Vigenere's sample encrypt", "Test ATTACKATDAWN with key LEMON", 1, vigeneres_sample_encrypt_test},
    {"Vigenere's sample decrypt", "Test LXFOPVEFRNHR with key LEMON", 1, vigeneres_sample_decrypt_test},
    {"Vigenere's sample test", "Test encrypt and decrypt", 1, vigeneres_sample_both_test},
    {"Vigenere's T=10, N=100", "A small scale test for Vigenere's implementation", 1, vigeneres_test_1},
    {"Vigenere's T=10, N=1000", "A medium scale test for Vigenere's implementation", 1, vigeneres_test_2},
    {"Vigenere's T=100, N=10000", "A large scale test for Vigenere's implementation", 1, vigeneres_test_3},
    {"Vigenere's T=1000, N=10000", "A very large scale test for Vigenere's implementation", 2, vigeneres_test_4},
    NULL
};