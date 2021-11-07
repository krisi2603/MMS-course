#include <stdio.h>
#include <stdint.h>

typedef union {
    uint16_t word;
    struct {
        uint8_t byte0;
        uint8_t byte1;
    };  
} num;

void swapBytes(num* word) {
    uint8_t b = word->byte0;
    word->byte0 = word->byte1;
    word->byte1 = b;
}

int main(void) {

    num n;
    n.word = 0x3b8a;
    num* ptr = &n;
    
    printf("Byte0: %x Byte1: %x\n", n.byte0, n.byte1);

    swapBytes(ptr);

    printf("Byte0: %x Byte1: %x\n", n.byte0, n.byte1);
    return 0;
}
