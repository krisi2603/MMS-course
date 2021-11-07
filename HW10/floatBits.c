#include <stdio.h>
#include <stdint.h>

#define CHECKBIT(mask,bit) (((mask) & (1 << (bit))) ? 1 : 0)

union {
    float f;
    uint32_t uf;
} u;

int main(void) {

    //u.f = 5.28;
    u.f;
    printf("Enter float number: ");
    scanf("%f", &u.f);

    for(int i = 31; i >= 0; i--){
        printf("%d", CHECKBIT(u.uf, i));
    }
    printf("\n");

    return 0;
}