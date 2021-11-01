typedef struct ceasars_shift_vector {
    char *table;
    int size;
} ceasars_shift_vector;

typedef char* string;

ceasars_shift_vector create_ceasars_shift_vector();

string encrypt_vigeneres(const string __plain_text, const string __key);
string decrypt_vigeneres(const string __encrypted, const string __key);

char *encrypt_otp();