#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(const char* p1, const char* p2, char* result) {
    int sum = 0;
    int num1 = atoi(p1);
    int num2 = atoi(p2);

    sum = num1 + num2;
    //char buffer[10000];
    sprintf(result,"%d", sum);
    
    /*int i = 0;
    while(buffer[i] != '\0') {
        result[i] = buffer[i];
        i++;
    }
    result[i] = '\0'; */
}

int main(void) {

    char num1[100];
    char num2[100];
    scanf("%s", num1);
    scanf("%s", num2);

    char result[10000];
    add(num1, num2, result);
    printf("The sum of the numbers is: %s\n", result);

    return 0;
}