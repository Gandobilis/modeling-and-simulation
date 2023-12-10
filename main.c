#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

double generateRandomNumber() {
    return (double) rand() / RAND_MAX;
}

double inverseTransform() {
    return 1.0 / (1.0 - generateRandomNumber());
}

double *exercise15(ull n) {
    srand(time(NULL));
    double *result = (double *) malloc(sizeof(double) * n);

    for (int i = 0; i < n; ++i) {
        result[i] = inverseTransform();
    }

    return result;
}

int exercise17() {
    srand(time(NULL));

    double randomValue = (double)rand() / RAND_MAX;

    double probabilities[] = {0.4, 0.2, 0.4};
    int values[] = {-5, 0, 5};

    double cumulativeProbability = 0;
    for (int i = 0; i < sizeof(probabilities) / sizeof(probabilities[0]); i++) {
        cumulativeProbability += probabilities[i];
        if (randomValue <= cumulativeProbability) {
            return values[i];
        }
    }

    return 0;
}

double *exercise23(ull a, ull b, ull b1, ull z0, ull z1, ull n) {
    double *result = (double *) malloc(sizeof(double) * n);

    ull z;
    ull x = 64 - b1;

    for (int i = 0; i < n; i++) {
        z = (a * z0 + b * z1) << x >> x;
        result[i] = (double) z / (1u << b);
        z0 = z1;
        z1 = z;
    }

    return result;
}

int main() {
    // 1
//    exercise1_2(7,(int) 1542.567,3,11,(int) 209129.238754,8);


    // 3
//    printf("%llu", exercise3(630360016, (1u << 31) - 1));

    ull n = 1000;

    // 4
//    double *result = exercise4(1031, 113, 10, 1103, n);

    // 6
//    double *result = exercise6(1604, 11, 3, 2103, n);

    // 15
//    double *result = exercise15(1000);

    // 17
//    printf("%d\n", exercise17());

    // 23
    double *result = exercise23(11, 7, 4, 11, 14, n);

    for (int i = 0; i < n; i++) {
        printf("%f\n", result[i]);
    }

    free(result);

    return 0;
}


