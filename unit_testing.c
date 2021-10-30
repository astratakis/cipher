#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "unit_testing.h"
#include "test_functions.h"

#define SUCCESS 151
#define FAILURE 150
#define TIME_LIMIT 149

test unit_tests[] = {
    
    NULL
};

int main(int argc, const char **argv) {


    int total_tests = sizeof(unit_tests) / sizeof(unit_tests[0]);

    for (int i=0; i<total_tests; i++) {
        execute_test(& unit_tests[i]);
        print_test(& unit_tests[i], i+1);
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
    (t->verdict == 0 ? KGRN : (t->verdict == 1 ? KMAG : KRED)), verdict_to_string(t->verdict), RST);
}