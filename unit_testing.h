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
    NULL
};