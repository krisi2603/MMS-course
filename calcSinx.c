#include <stdio.h>

//sin x = x - x^3/3! + x^5/5! - x^7/7! + ... x^n/n!

int main() {

    int n, fact, sign = -1;
    double x, p, sum = 0;

    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("Enter a value for n: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i+=2) {
        p = 1;
        fact = 1;
        for(int j = 1; j <= i; j++) {
            p = p * x;
            fact = fact * j;
        }
        sign = -1 * sign;
        sum += (sign * p) / fact;
    }

    printf("sin(%.3lf) : %lf\n", x, sum);

    return 0;
}