#include <stdio.h>
#include <stdlib.h>

void inputArray(int*, size_t);
void printArray(int*, size_t);

int compareInt(const void*, const void*);

int binarySearch(int*, size_t, int);

int main(void) {

    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array: ");
    inputArray(arr,n);
    
    //if we dont input sorted array, to sort it first
    qsort(arr, n, sizeof(int), compareInt);
    printArray(arr,n);

    int key;
    printf("Enter key: ");
    scanf("%d", &key);

    int indx = binarySearch(arr,n,key);
    if(indx == -1) {
        printf("Key %d is not found in the array\n", key);
    }
    else {
        printf("Key is at index: %d\n", indx);
    }

    return 0;
}

void inputArray(int* arr, size_t n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int* arr, size_t n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int binarySearch(int* array, size_t n, int key) {
    int l = 0, r = n - 1;

    while(l <= r) {
        int m = (l + r) / 2;
        if(array[m] < key) {
            l = m + 1;
        }
        else if(array[m] == key) {
            return m;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}
