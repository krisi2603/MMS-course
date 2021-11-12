#include <stdio.h>

//Problem 2

int strLen(const char* str) {
    int len = 0;
    while (*str) {
        ++len;
        ++str;
    }
    return len;
}

void reverse(char* ptr) {
    int len = strLen(ptr);

    for(int i = 0; i < len / 2; i++) {
        char c = ptr[i];
        ptr[i] = ptr[len-i-1];
        ptr[len-i-1] = c;
    }
    ptr[len] = '\0';
}

int main(void) {

    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    printf("The reversed string is: ");
    reverse(str);
    printf("%s\n", str);

    return 0;
}