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

char *encrypt_vigeneres(const char *__plain_text, const char *__key);
char *decrypt_vigeneres(const char *__encrypted, const char *__key);

char *encrypt_otp();