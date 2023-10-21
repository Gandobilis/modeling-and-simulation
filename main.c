#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull *exercise4_5(ull a, ull c, ull b, ull z0, ull n) {
    ull *result = (ull *) malloc(sizeof(ull) * n);

    ull z = z0;
    ull x = 64 - b;

    for (int i = 0; i < n; i++) {
        result[i] = z;
        z = (a * z + c) << x >> x;
    }

    return result;
}

int main() {
    ull n = 1000;
    ull *result = exercise4_5(1031, 113, 10, 1103, n);
    for (int i = 0; i < n; i++) {
        printf("%llu\n", result[i]);
    }

    free(result);

    return 0;
}
