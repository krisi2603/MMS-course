#include <stdio.h>

//Homework 4 Task 2a
void printSquare(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

//Task 2b
void printTriangle(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            printf("$ ");
        }
        printf("\n");
    }
}

//Task 2c
void printSquareDiff(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           if( (i==0 && j==0) || (i==n-1 && j==n-1) 
            || (i==0 && j==n-1) || (i==n-1 && j==0)) {
                printf("+ ");
            }
            else if(j==0 || j==n-1) {
                printf("| ");
            }
            else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

//Task 2d
void printPyramid(int n) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0 ; j <= 2*n; j++) {
            if( j == n) {
                printf(" | ");
            }
            else if((j - i <= n && j>=n-i) || i == n) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main () {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    //printSquare(n);
    //printTriangle(n);
    //printSquareDiff(n);
    printPyramid(n);

    return 0;
}