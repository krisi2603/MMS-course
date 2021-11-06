#include <stdio.h>
#include <math.h>

//Homework 1 Task 1

int main() {

    double weight, height, bmi, bmiNew;

    printf("Enter weigth in kgs: ");
    scanf("%lf", &weight);
    printf("Enter height in meters: ");
    scanf("%lf", &height);

    bmi = weight / (height * height);
    bmiNew = 1.3 * (weight / pow (height, 2.5));

    printf("The body mass index is: %.2lf\n", bmi);
    printf("The body mass index with new formula is: %.2lf\n", bmiNew);

    return 0;
}