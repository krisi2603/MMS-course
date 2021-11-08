#include <stdio.h>
#include <string.h>

char changeNumberToLetter(char c) {
    if(c >= '0' && c <= '9'){
        c = c + ('A' - '0');
        return c;
    }
}
char changeNumberToSymbol(char c) {
    if(c == '0') {
        c = '!';
        return c;
    }

    if(c == '1') {
        c = '#';
        return c;
    }

    if(c == '2') {
        c = '/';
        return c;
    }
    if(c == '3') {
        c = '~';
        return c;
    }
    if(c == '4') {
        c = '=';
        return c;
    }
    if(c == '5') {
        c = '`'; 
        return c;
    }
    if(c == '6') {
        c = '\\';
        return c;
    }
    if(c == '7') {
        c = '>';
        return c;
    }
    if(c == '8') {
        c = '.';
        return c;
    }
    if(c == '9') {
        c = ',';
        return c;
    }
}

int main(void) {

    char number[500]; //501
    printf("Enter a number: ");
    fgets(number, 500, stdin);
    int len = strlen(number);

    for(int i = 0; i < len; i+=2) {
        number[i] = changeNumberToLetter(number[i]);
    }
    for(int i = 1; i < len; i+=2) {
        number[i] = changeNumberToSymbol(number[i]);
    }

    for(int i = 0; i < len; i++) {
        printf("%c", number[i]);
    } 

    return 0;

}