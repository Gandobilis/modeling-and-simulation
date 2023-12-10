#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

void exercise1(ull p1, ull a, ull c, ull p2, ull b, ull p3) {
    ull x = 64 - p2;
    ull result = (((a << p1) + c) << x >> x) + (b >> p3);
    printf("%llu\n\n", result);
}

ull exercise3(ull dividend, ull divisor) {
    while (dividend >= divisor) {
        dividend -= divisor;
    }
    return dividend;
}

double *exercise4(ull a, ull c, ull b, ull z0, ull n) {
    double *result = (double *) malloc(sizeof(double) * n);

    ull z = z0;
    ull x = 64 - b;

    for (int i = 0; i < n; i++) {
        z = (a * z + c) << x >> x;
        result[i] = (double) z / (1u << b);
    }

    return result;
}

double *exercise6(ull a, ull b, ull q, ull z0, ull n) {
    double *result = (double *) malloc(sizeof(double) * n);

    ull z = z0;

    for (int i = 0; i < n; i++) {
        z = exercise3(a * z, (1u << b) - q);
        result[i] = (double) z / (double) ((1u << b) - q);
    }

    return result;
}

int main() {
    // 1
//    exercise1_2(7,(int) 1542.567,3,11,(int) 209129.238754,8);


    // 3
//    printf("%llu", exercise3(630360016, (1u << 31) - 1));

    // ელემენტთა რაოდენობა გენერირებულ მიმდევრობაში
    ull n = 1000;

    // 4
//    double *result = exercise4(1031, 113, 10, 1103, n);

    // 6
//    double *result = exercise6(1604, 11, 3, 2103, n);

//     განაკომენტარეთ შედეგის სანახავად
//    for (int i = 0; i < n; i++) {
//        printf("%f\n", result[i]);
//    }
//
//    free(result);

    return 0;
}


