#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swapUni(void*, void*, size_t);
int compareInt(const void*, const void*);
void bubbleSort(void*, size_t, size_t, int (*)(const void*, const void*));

void printArray(int*, size_t);

void (*getSorting(const char* fname))(void*, size_t, size_t, int (*)(const void*, const void*)) {
    if(!strcmp(fname,"qsort")) {
        return qsort;
    }
    if(!strcmp(fname,"bubble Sort")) {
        return bubbleSort;
    }
    return NULL;
}


int main(void){

    int arr[] = {8, 4, 1, 7, 3, 0, 9, 2};

    void (*sortF)(void*, size_t, size_t, int (*)(const void*, const void*));
    sortF = getSorting("qsort");
    if(sortF == NULL) {
        printf("No sorting func\n");
        return 1;
    }

    sortF(arr, 8, sizeof(int), compareInt);
    printArray(arr, 8);

    return 0;
}

void swapUni(void* a, void* b, size_t n) {
    char temp[n];
    memmove(temp, a, n);
    memmove(a, b, n);
    memmove(b, temp, n);
}

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void bubbleSort(void* arr, size_t n, size_t size, int (*cmp)(const void*, const void*)) {
    for (int j = 0; j < n; j++) {
        int swapped = 0;
        for (int i = 0; i < (n - 1 - j) * size; i += size){
            if (cmp(arr + i, arr + i + size) > 0) { 
                swapUni(arr + i, arr + i + size, size);
                swapped = 1;
            }
        }
        if(!swapped) {
            return;
        }
    }
}

void printArray(int* arr, size_t n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}