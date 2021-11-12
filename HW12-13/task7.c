#include <stdio.h>
#include <stdlib.h>

//Problem 7

void inputArray(unsigned int*, unsigned int);
void printArray(unsigned int*, unsigned int);

int compareInt(const void*, const void*);

unsigned int binSearch(unsigned int*, unsigned int, unsigned int);

int main(void) {

    unsigned int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted array: ");
    inputArray(arr,n);
    
    //if we dont input sorted array, to sort it first
    /*qsort(arr, n, sizeof(unsigned int), compareInt);
    printArray(arr, n); */

    unsigned int key;
    printf("Enter key: ");
    scanf("%d", &key);

    unsigned int indx = binSearch(arr, n, key);
    if(indx == -1) { //0xFFFF
        //printf("%x", indx);
        printf("Key %d is not found in the array\n", key);
    }
    else {
        printf("Key is at index: %d\n", indx);
    }

    return 0;
}

void inputArray(unsigned int* arr, unsigned int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(unsigned int* arr, unsigned int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int compareInt(const void* a, const void* b) {
    return *(unsigned int*)a - *(unsigned int*)b;
}

unsigned int binSearch(unsigned int* pArray, unsigned int uArraySize, unsigned int uValue) {
    int l = 0, r = uArraySize - 1;

    while(l <= r) {
        int m = (l + r) / 2;
        if(pArray[m] < uValue) {
            l = m + 1;
        }
        else if(pArray[m] == uValue) {
            return m;
        }
        else {
            r = m - 1;
        }
    }
    return -1; //0xFFFF
}