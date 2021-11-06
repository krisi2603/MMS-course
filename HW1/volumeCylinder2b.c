#include <stdio.h>
#include <math.h>

//Homework 1 Task 2b
int main() {
    double r, l, h, area, volume;
    printf("Enter R: ");
    scanf("%lf", &r);
    printf("Enter L: ");
    scanf("%lf", &l);
    printf("Enter H: ");
    scanf("%lf", &h);

    area = acos((r - h) / r) * r * r - (r - h) * sqrt(2*r*h - h*h);
    volume = area * l;
    printf("Volume = %.2lf m^3\n", volume);

    return 0;
}