#include <stdio.h>
#include <math.h>

//Homework 1 Task 2a - made in class
int main() {
    double r, l, volume;
    printf("Enter R: ");
    scanf("%lf", &r);
    printf("Enter L: ");
    scanf("%lf", &l);

    volume = 2 * M_PI * r * r * l;
    printf("Volume = %.2lf m^3\n", volume);

    return 0;
}