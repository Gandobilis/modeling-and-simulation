#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

// (2^p1*a + c)%2^p2 + b / 2^p3 (ზოგადი სახე)
void exercise1_2(ull p1, ull a, ull c, ull p2, ull b, ull p3) {
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

ull *exercise6_8_9(ull a, ull b, ull q, ull z0, ull n) {
    ull *result = (ull *) malloc(sizeof(ull) * n);

    ull z = z0;

    for (int i = 0; i < n; i++) {
        result[i] = z;
        z = exercise3(a * z, (1u << b) - q); // სიმულაციური გაყოფა
    }

    return result;
}

int main() {
    // 1
//    exercise1_2(7,(int) 1542.567,3,11,(int) 209129.238754,8);

    //2
//    exercise1_2(8,(int) 98710293.53201,7,10,(int) 189029.238,8);


    // 3
//    printf("%llu", exercise3(630360016, (1u << 31) - 1));

    // ელემენტთა რაოდენობა გენერირებულ მიმდევრობაში
    ull n = 1000;

    // 4
    ull *result = exercise4_5_7(1031, 113, 10, 1103, n);

    // 5
//    ull *result = exercise4_5_7(3074, 51, 11, 1203, n);

    //7
//    ull *result = exercise4_5_7(201, 13, 9, 2103, n);


    // 6
//    ull *result = exercise6_8_9(1604, 11, 3, 2103, n);

    // 8
//    ull *result = exercise6_8_9(856, 9, 3, 385, n);

    // 9
//    ull *result = exercise6_8_9(187, 8, 5, 119, n);

    // განაკომენტარეთ შედეგების სანახავად
    for (int i = 0; i < n; i++) {
        printf("%llu\n", result[i]);
    }

    free(result);
}
