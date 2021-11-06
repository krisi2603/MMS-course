#include <stdio.h>

#define SIZE(array) (sizeof(array) / sizeof(array[0]))

int areSameElements(int*, size_t);
int secondMax(int*, size_t, int*);

int main() {

    int arr[] = {12, 34, 5, 70, 46};
    int myarr[] = {11, 4, 98, 32, 6, 77, 22};
    int scndMax, scndMax2;
    
    int result = secondMax(arr,SIZE(arr), &scndMax);

    if(result == -1) {
        printf("The array is empty!\n");
    }
    else if(result == -2) {
        printf("The array has only one element\n");
    }
    else if(result == -3) {
        printf("The array has only equal numbers, so no second max element\n");
    }
    else {
        printf("%d\n", scndMax);
    }
    secondMax(myarr,7,&scndMax2);
    printf("%d\n", scndMax2);

    return 0;
}

int areSameElements(int* arr, size_t n) {
    int x = arr[0];
    for(int i = 1; i < n; i++) {
        if( arr[i] != x) {
            return 0;
        }
    }
    return 1;
}

int secondMax(int* arr, size_t n, int* secondMax) {
    if(n == 0) {
        return -1;
    }
    if(n == 1) {
        return -2;
    }
    if(areSameElements(arr,n)) {
        return -3;
    }
    
    int max = arr[0];
    *secondMax = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            *secondMax = max;
            max = arr[i];
        }
        else if(arr[i] > *secondMax && arr[i] < max) {
            *secondMax = arr[i];
        }
    }
    return 0;
}
