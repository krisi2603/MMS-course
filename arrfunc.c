#include <stdio.h>

void arrayEvaluate(int*, size_t, int(*)(int*,int));
int sum(int*,int);
int minEl(int*,int);

int main() {
    int arr[] = {1, 2, 3};
    arrayEvaluate(arr, 3, sum);
    arrayEvaluate(arr,3,minEl);

    return 0;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)) {

    printf("Value: %d\n", f(arr,n));
}

int sum(int* arr, int n) {
    int result = 0;
    for(int i = 0; i < n; i++){
        result += arr[i];
    }
    return result;
}

int minEl(int* arr, int n) {
    int min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
