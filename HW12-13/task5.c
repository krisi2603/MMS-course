#include <stdio.h>

//Problem 5

#define SIZE 10

typedef struct {
    int values[SIZE];
    int top; 
    int bottom; 
    int count;
}queue;

void initialize(queue** arr) {
    (*arr)->top = 0;
    (*arr)->bottom = 0;
    (*arr)->count = 0;
}

int isEmpty(queue* arr) {
    if(arr->count == 0) {
        return 0;
    }
    return 1;
}

int isFull(queue* arr) {
    if(arr->count == SIZE) {
        return 0;
    }
    return 1;
}
void push(queue *arr, int nNewValue) {
    if(!isFull) {
        printf("The queue is full! You can not add elements!\n");
    }
    int next;
    next = arr->bottom + 1;
    
    arr->values[arr->bottom] = nNewValue;
    arr->bottom = next;
    arr->count +=1;
}

int pop(queue* arr) {
    if(!isEmpty) {
        printf("The queue is empty. No elements to pop!\n");
        return -1;
    }
    int number;
    number = arr->values[arr->top];
    arr->top = arr->top + 1;
    arr->count = arr->count - 1;

    return number;
}

void printQueue(queue* arr) {
    int begin = arr->top;
    int end = arr->bottom;

    for(int i = begin; i < end; ++i) {
        printf("%d ", arr->values[i]);
    }
    putchar('\n');
}

int main(void) {

    queue* arr;
    initialize(&arr);
    push(arr, 10);
    push(arr, 12);
    push(arr, 2);
    push(arr, 8);
    push(arr, 4);
    push(arr, 2);
    printQueue(arr);
    int num;
    pop(arr);
    num = pop(arr);
    printQueue(arr);
    printf("%d \n", num);

    return 0;
}