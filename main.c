#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int exercise3(int dividend, int divisor) {
    while (dividend >= divisor) {
        int dividend_bits = 0;
        int divisor_bits = 0;
        int temp = divisor;

        while (temp > 0) {
            temp >>= 1;
            divisor_bits++;
        }

        temp = dividend;
        while (temp > 0) {
            temp >>= 1;
            dividend_bits++;
        }

        int shift_count = dividend_bits - divisor_bits;
        dividend -= (divisor << shift_count);
    }

    return dividend;
}

ull *exercise4_5_7(ull a, ull c, ull b, ull z0, ull n) {
    ull *result = (ull *) malloc(sizeof(ull) * n);

    ull z = z0;
    ull x = 64 - b;

    for (int i = 0; i < n; i++) {
        result[i] = z;
        z = (a * z + c) << x >> x;
    }

    return result;
}

//ull *exercise6_8_9(ull a, ull b, ull q, ull z0, ull n) {
//    ull *result = (ull *) malloc(sizeof(ull) * n);
//
//    ull z = z0;
//
//    for (int i = 0; i < n; i++) {
//        result[i] = z;
//        z = (a * z + c) << x >> x;
//    }
//
//    return result;
//}

int main() {
    //    // 1
//    ull a = (int)1542.567;
//    ull b = (int)209129.238754;
//    ull x = 64 - 11; // 2^11 = 2048
//    ull exercise1 = (((a << 7) + 3) << x >> x) + (b >> 8);
//    printf("%llu", exercise1);

//    // 2
//    ull a = (int) 98710293.53201;
//    ull b = (int) 189029.238;
//    ull x = 64 - 10; // 2^10 = 1024
//    ull exercise2 = (((a << 8) + 7) << x >> x) + (b >> 8);
//    printf("%llu", exercise2);

//    ull n = 1000;
    // 3
//    printf("%d", exercise3(630360016, (1u << 31) - 1));
    // 4
//    ull *result = exercise4_5_7(1031, 113, 10, 1103, n);

    // 5
//    ull *result = exercise4_5_7(3074, 51, 11, 1203, n);

    // 7
//    ull *result = exercise4_5_7(201, 13, 9, 2103, n);


//    for (int i = 0; i < n; i++) {
//        printf("%llu\n", result[i]);
//    }
//
//    free(result);

    return 0;
}
