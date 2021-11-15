#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    if(argc != 4 ) {
        printf("No enough arguments\n");
        return -1;
    }
    char* mode = argv[3]; //"-BT"
    printf("%c", mode[1]);
    char* m = mode[1];
    char* m2 = mode[2];

    FILE *fr = fopen(argv[1], m);
    if(fr == NULL) {
        printf("Can't open file\n");
        return -1;
    }
    FILE* fw = fopen(argv[2], m2);
    if(fw == NULL) {
        printf("Can't open file\n");
        return -1;
    }

    uint16_t number;
    while(fread(&number, sizeof(uint16_t),1, fr)) {
        fputc(number, fw);
        fputc('\n', fw);
    }
    fclose(fw);
    fclose(fr);

    return 0;
}