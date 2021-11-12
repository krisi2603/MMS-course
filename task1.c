#include <stdio.h>
#include <stdint.h>

//Problem 1

int countOnes(unsigned int mask) { //working
    int counter = 0;

    for (int i = sizeof(mask)*8 - 1; i >= 0; i--){
        counter += ((mask & (1 << i)) ? 1 : 0);
    }
    return counter;
}

unsigned char checkBit(unsigned int uValue) {
    if(countOnes(uValue) == 1) {
        return '1';
    }
    else {
        return '0';
    }
}

int main(void) {

    uint16_t number;
    printf("Enter a number: ");
    scanf("%hd", &number);

    //printf("%d\n", countOnes(number));

    printf("%d\n",checkBit(number) - '0');

    return 0;
}