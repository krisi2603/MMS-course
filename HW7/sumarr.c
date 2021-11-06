#include <stdio.h>

unsigned sumArrayDigits(int*, size_t);

int main() {

    int arr[] = {12, 34, 5, 70};
    int myarr[5] = {11, 456, 2, 90, 0};

    printf("Sum array digits: %d\n", sumArrayDigits(arr,4));
    printf("Sum array digits: %d\n", sumArrayDigits(myarr,5));

    return 0;
}

unsigned sumArrayDigits(int* arr, size_t n) {
    unsigned result = 0;
    for(int i = 0; i < n; i++) {
        while(arr[i] > 0) {
            result += arr[i] % 10;

            arr[i] /= 10;
        }
    }
    return result;
}