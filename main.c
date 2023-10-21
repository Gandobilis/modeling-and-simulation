#include <stdio.h>
#include <stdlib.h>

unsigned long long *
lcg_rand_array(unsigned long long a, unsigned long long c, unsigned long long b, unsigned long long seed, int n) {
    unsigned long long *result = (unsigned long long *) malloc(sizeof(unsigned long long) * n);

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    unsigned long long z = 64 - b;

    for (int i = 0; i < n; i++) {
        seed = (a * seed + c) << z >> z;
        result[i] = seed;
    }

    return result;
}

int main() {
    unsigned long long *result = lcg_rand_array(1031, 113, 10, 1103, 100);

    for (int i = 0; i < 100; i++) {
        printf("%llu\n", result[i]);
    }

    free(result);

    return 0;
}
