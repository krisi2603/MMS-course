#include <stdio.h>
#include <math.h>

//Homework 5 Task2.1

int checkTriagle(unsigned a, unsigned b, unsigned c) {
    if ((a < b + c) && (b < a + c) && (c < a + b)) {
        return 1;
    }
    else {
        return 0;
    }
}

int triangleCalc(unsigned a, unsigned b, unsigned c,
                 double* area, double* perimeter) {

    if(!checkTriagle(a,b,c)) {
        *area = 0;
        *perimeter = 0;

        return -1;
    }
    else {
        *perimeter = a + b + c;
        double p = *perimeter / 2;
        

        *area = sqrt(p * (p - a) * 
                (p - b) * (p - c));

        return 0;
    }

}

int main(){
    unsigned a, b, c;
    double perimeter = 0;
    double area = 0;

    printf("Enter 3 numbers: ");
    scanf("%u %u %u", &a, &b, &c);

    //printf("%d\n",triangleCalc(a,b,c, &area, &perimeter));
    triangleCalc(a,b,c, &area, &perimeter);
    printf("%.2lf\n", perimeter);
    printf("%.2lf\n", area);

    return 0;
}