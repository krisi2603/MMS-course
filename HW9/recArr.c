#include <stdio.h>

void inputArray(int*, size_t);
void printArray(int*, size_t);
int sumDigit(int);

int recFunction(unsigned int* arr, int n, int position, int * checked) {
    int steps = 0;

    //out of the array
    if(position > n || position < 0) {
        return steps;
    }
    
    //loop
    if(checked[position]) {
        return steps;
    }

    checked[position] = 1;
    
    if(sumDigit(arr[position]) % 2 == 0) {
        steps = recFunction(arr, n, position + 3, checked) + 1;
    }
    else {
        steps = recFunction(arr, n, position - 2, checked) + 1;
    }
}

int main(void) {

    unsigned int arr[100], n, position;
    int checkedPositions[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array: ");
    inputArray(arr,n);
    for(int i = 0; i < n; i++) {
        checkedPositions[i] = 0;
    }

    printf("Enter starting position: ");
    scanf("%d", &position);

    int steps = recFunction(arr, n, position, checkedPositions);
    printf("Number of steps: %d\n", steps);

    return 0;
}

int sumDigit(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
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