#include <stdio.h>

//Problem 6

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int* pArray, unsigned int uLen) {
    for (int i = 0; i < uLen; i++) {
        int swapped = 0;
        for (int j = 0; j < uLen - 1 - i; j++){
            if (pArray[j] > pArray[j + 1]) {
                swap(&pArray[j], &pArray[j + 1]);
                swapped = 1;
            }
        }
        if(!swapped) {
            return; 
        }
    }
}

int main(void) {

    int arr[100], n;
    printf("Enter a size for array: ");
    scanf("%d", &n);

    printf("Enter array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubble(arr, n);

    printf("The sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}