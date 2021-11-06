#include <stdio.h>
#include <string.h>
#include <math.h>

//Homework 4 Task3

int isValid(char* number) {
    while(*number) {
        if( (*number >='0' && *number <= '9') || (*number >= 'a' && *number <= 'z')) {
            number++;
        }
        else {
            return 0;
        }
    }
    return 1;
}

int toDecimal(char* number, int baseInput) {
    int dec = 0;
    int len = strlen(number);

    for(int i = 0; i < len; i++) {
        if(number[i] >= 'a') {
            dec += ((int)number[i] -'a' + 10) * pow(baseInput, len- i-1);
        }
        else {
            dec += ((int)number[i] - '0') * pow(baseInput, len - i - 1);
        }
    }
    return dec;
}

//char* fromDecimal(char* number, int baseOutput) 

int main() {
    int baseInput, baseOutput;
    char* number;

    printf("Enter a number: ");
    do {
        scanf("%s" ,number);
    }
    while(!isValid(number));

    printf("Enter base inpit: ");
    do {
        scanf("%d" , &baseInput);
    }
    while(baseInput < 2 || baseInput > 36);

    printf("Enter base output: ");
    do {
        scanf("%d" , &baseOutput);
    }
    while(baseOutput < 2 || baseOutput > 36);

    if(baseOutput == 10) {
        printf("The dec number is: %d\n", toDecimal(number, baseInput));
    }

    return 0;
}
