#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomReal(void);
double randomRealRange(double, double);

int main(void) {
    srand(time(NULL));
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    double* numArr = (double*)malloc(n * sizeof(double));
    if(numArr == NULL) {
        printf("Can't allocate memory!\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        numArr[i] = randomReal();
    }
    for(int i = 0; i < n; i++) {
        printf("%.3lf ", numArr[i]);
    }
    putchar('\n');

    int m;
    printf("Enter a number for extended size: ");
    scanf("%d", &m);

    numArr = realloc(numArr, (m + n) * sizeof(double));
    if(numArr == NULL) {
        printf("Can't reallocate memory!\n");
        return 1;
    }

    for(int i = n; i < m + n; i++) {
        numArr[i] = randomRealRange(1.0, 2.0);
    }

    for(int i = 0; i < m + n; i++) {
        printf("%.3lf ", numArr[i]);
    }
    putchar('\n');

    int p;
    printf("Enter a number for extended size again: ");
    scanf("%d", &p);

    numArr = realloc(numArr, (m + n + p) * sizeof(double));
    if(numArr == NULL) {
        printf("Can't reallocate memory!\n");
        return 1;
    }
    
    for(int i = m + n; i < p + m + n; i++) {
        numArr[i] = randomRealRange(2.0, 3.0);
    }

    for(int i = 0; i < m + p + n; i++) {
        printf("%.3lf ", numArr[i]);
    }
    putchar('\n');

    free(numArr);
    return 0;
}

double randomReal(void){
    return (double)rand() / RAND_MAX;
}

double randomRealRange(double min, double max){
    return min + randomReal() * (max - min);
}
