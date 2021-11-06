#include <stdio.h>

int main(void) {

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    double sq = number;
    double error = number * 1e-8;

    while ((sq - number / sq) > error) { 
        sq = (number / sq + sq) / 2; 
    }

    printf("The square of the number %d is: %lf\n", number,sq);   

    return 0;
}