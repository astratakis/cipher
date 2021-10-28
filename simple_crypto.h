#define ASCII_READABLE_CHARS 95

typedef struct permutation {
    int nums[ASCII_READABLE_CHARS];
    int size;
} permutation;

permutation generate_permutation();

void print_permutation(permutation p);

char * one_time_pad(char *__input, int input_size, char *__key, int key_size);