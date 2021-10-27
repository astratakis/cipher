#define ASCII_READABLE_CHARS 95

typedef struct permutation {
    int nums[ASCII_READABLE_CHARS];
} permutation;

permutation generate_permutation();

void print_permutation(permutation p);