typedef struct tabula_recta {
    char **matrix;
    int size;
} tabula_recta;

typedef struct ceasars_shift_vector {
    char *table;
    int size;
} ceasars_shift_vector;

tabula_recta *create_tabula_recta();
ceasars_shift_vector create_ceasars_shift_vector();