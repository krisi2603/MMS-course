#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

//Homework 5 Task2.2
//not working 

int countOnesInMask(size_t size, size_t mask) {
    int cnt = 0;

    for(int i = 0; i < size * 8; i++) {
        if(mask & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}

unsigned onesCount(unsigned count, size_t size, ...) {
    unsigned counter = 0;
    va_list args;
    va_start(args, size);

    /*for(int i = 0; i < count; i++) {
        for(int j = 0; j < size * 8; i++) {
            if(va_arg(args,size_t) & (1 << j)) {
                counter ++;
            }
        }
    } */
    for(int i = 0; i < count; i++) {
        counter += countOnesInMask(size, va_arg(args,size_t));
    }

    va_end(args);
    return counter;
}

int main() {

    /*unsigned numMasks;
    printf("Enter number of masks:");
    scanf("%u", &numMasks);
    size_t size;
    printf("Enter size of mask in bytes: ");
    do {
        scanf("%lu", &size);
    }
    while(size < 1 || size > sizeof(int));
    */
    printf("%d\n", countOnesInMask(1,10010010));
    printf("%u\n", onesCount(3, 1, 10010010, 11110000,00010001));

    return 0;
}
