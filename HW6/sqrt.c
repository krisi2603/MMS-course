#include <stdio.h>

int main(void) {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    double temp = 0, sq = number / 2;
    while (sq != temp) {
        temp = sq;
        sq = (number / temp + temp) / 2;
    }
    
    printf("The square of the number %d is: %lf\n", number,sq);   

    return 0;
}