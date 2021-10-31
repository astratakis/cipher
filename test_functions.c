#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "test_functions.h"
#include "simple_crypto.h"

#define SUCCESS 151
#define FAILURE 150

int check_tabula_recta(void) {
    tabula_recta *tr = create_tabula_recta();

    assert(tr->size == 26);

    for (int i=0; i<tr->size; i++) {
        assert(strlen(tr->matrix[i]) == tr->size);
    }

    free(tr->matrix);
    free(tr);

    return SUCCESS;
}

