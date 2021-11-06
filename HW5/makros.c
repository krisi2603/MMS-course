#include <stdio.h>
#include <stdint.h>

//Homework 5 Task1

#define MAX(x,y,z) (((x) > (y) && (x) > (z)) ? (x) : (((y) > (x) && (y) > (z)) ? (y) : (z)))
#define MIN(x,y,z) (((x) < (y) && (x) < (z)) ? (x) : (((y) < (x) && (y) < (z)) ? (y) : (z)))
#define SETBIT(mask,bit) ((mask) | (1 << (bit)))
#define CLEARBIT(mask,bit) ((mask) & ~(1 << (bit)))
#define INVERSEBIT(mask,bit) ((mask) ^ (1 << (bit)))
#define CHECKBIT(mask,bit) (((mask) & (1 << (bit))) ? 1 : 0)
#define SWAP(a,b) (a^=b; b^=a;a^=b;)


int main(void) {
    int x,y,z;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &x, &y, &z);

    printf("%d\n", MAX(x,y,z));
    printf("%d\n", MIN(x,y,z));

    int mask = 1001;
    printf("%d",CHECKBIT(mask, 1));
    
    return 0;
}