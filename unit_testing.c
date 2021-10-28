#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "unit_testing.h"
#include "test_functions.h"

test unit_tests[] = {
    {"permutation test", "Check if there are no repeating numbers in the generated permutation", 1, check_permutation},
    /*{"example", "Returns success", 10, example_test},
    {"wrong answer example", "Returns failure", 10, wrong_answer_example},
    {"runtime error example", "Generates a segmentation fault", 10, segmentation_fault_example},
    {"time limit exmaple", "An aterminal loop", 1, time_limit_example}*/
    {"read input from stdin test", "Check if data from stdin is read correctly", 5, check_read_stdin},
    NULL
};

typedef struct program_arguments {
    int color;
    int instant_verdict;
    int specific_test;
} program_arguments;

program_arguments args;

const char *help_msg = 
"Usage validate_api.exe [option]\n\
\nOptions:\n\n\
--no-color    :         Disables color output\n\
--verdict     :         Gives instant verdict for each test after it is executed\n\
--list        :         Prints the list of registered tests\n\
--exec <args> :         Executes a specific given list of tests\n";

int main(int argc, const char **argv) {

    args.color = 1;
    args.instant_verdict = 0;
    args.specific_test = 0;

    int valid = 1;

    int total_tests = sizeof(unit_tests) / sizeof(unit_tests[0]);

    for (int i=1; i<argc; i++) {
        if (strcmp(argv[i], "--no-color") == 0) {
            args.color = 0;
        }
        else if (strcmp(argv[i], "--verdict") == 0) {
            args.instant_verdict = 1;
        }
        else if (strcmp(argv[i], "--exec") == 0) {
            args.specific_test = 1;
        }
        else if (strcmp(argv[i], "--help") == 0) {
            printf("%s", help_msg);
            exit(0);
        }
        else if (strcmp(argv[i], "--list") == 0) {
            for (int i=0; i<total_tests; i++) {
                printf("Test: [ %d ] - %s\nDescription: %s\n\n", (i+1), unit_tests[i].name, unit_tests[i].description);
            }
            exit(0);
        }
        else {
            printf("Invalid usage... Try --help for a list of options.\n");
            exit(0);
        }
    }

    if (args.instant_verdict) {
        for (int i=0; i<total_tests; i++) {
            execute_test(& unit_tests[i]);
            print_test(& unit_tests[i], i+1);
        }
    }
    else {
        for (int i=0; i<total_tests; i++) {
            execute_test(& unit_tests[i]);
        }

        for (int i=0; i<total_tests; i++) {
            print_test(& unit_tests[i], i+1);
        }
    }
    return 0;
}

const char *verdict_to_string(test_verdict v) {
    if (v == OK) {
        return "OK";
    }
    else if (v == TLE) {
        return "Time Limit Exceeded";
    }
    else if (v == RE) {
        return "Runtime Error";
    }
    else if (v == WA) {
        return "Wrong Answer";
    }

    return "Null";
}

void handle_alarm() {
    alarm(0);
    exit(TIME_LIMIT);
}

void execute_test(test *t) {
    t->verdict = RE;

    // The child process will execute the test function and the parent will wait for the result
    pid_t pid = fork();

    if (pid == 0) {
        signal(SIGALRM, handle_alarm);

        alarm(t->timeout);

        int ret = t->function();

        alarm(0);
        exit(ret);
    }

    int status;

    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid failed");
        return;
    }

    if (WIFEXITED(status)) {
        const int es = WEXITSTATUS(status);
        if (es == SUCCESS) {
            t->verdict = OK;
        }
        else if (es == FAILURE) {
            t->verdict = WA;
        }
        else if (es == TIME_LIMIT) {
            t->verdict = TLE;
        }
    }
}

void print_test(test *t, int index) {
    printf("Test  [ %3d ] %30s  -  Verdict: [ %s%s%s ]\n", index, t->name, 
    (args.color != 0 ? (t->verdict == 0 ? KGRN : (t->verdict == 1 ? KMAG : KRED)) : RST), verdict_to_string(t->verdict), RST);
}