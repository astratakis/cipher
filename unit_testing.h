
#ifndef _COLORS_
#define _COLORS_

#define RST   "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#endif

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

void execute_test(test *t);
void print_test(test *t, int index);
const char *verdict_to_string(test_verdict v);