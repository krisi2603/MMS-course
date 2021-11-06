#include <stdio.h>
#include <stdlib.h>

void inputArray(int*, size_t);
void printArray(int*, size_t);
void swap(int*, int*);

int partition(int*, int, int);

void quickSort(int*, int, int);

int main() {

    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array: ");
    inputArray(arr,n);

    quickSort(arr,0,n - 1);

    printArray(arr,n);

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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int l, int h) {
    int pivot = arr[h];
    int pp = l;
    for(int i = l; i < h; i++) {
        if(arr[i] < pivot) {
            swap(&arr[i], &arr[pp]);
            pp += 1;
        }
    }
    swap(&arr[pp], &arr[h]);

    return pp;
}

void quickSort(int* arr, int l, int h) {
    if(l < h) {
        int mid = partition(arr,l,h);
        quickSort(arr, l, mid -1);
        quickSort(arr, mid + 1, h);
    }
}