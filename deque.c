#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node_t;


node_t* createNode(int data) {
    node_t* n = malloc(sizeof(node_t));
    if(n == NULL) {
        printf("Could not allocate memory! \n");
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    return n;
}

int isEmpty(node_t* front) {
    return (front == NULL ? 1 : 0);
}

void addInfront(node_t** front, node_t** back, int value) {
    node_t* n = createNode(value);
    if(n == NULL) {
        printf("Could not add none existing node! \n");
        return;
    }
    if(isEmpty(*front)) {
        *front = n;
        *back = n;
        return;
    }
    n->next = *front;
    (*front)->prev = n;
    *front = n;
}

void addAtBack(node_t** front, node_t** back, int value) {
    node_t* n = createNode(value);
    if(n == NULL) {
        printf("Could not add none existing node! \n");
        return;
    }
    if(isEmpty(*back)) {
        *front = n;
        *back = n;
        return;
    }

    n->prev = *back;
    (*back)->next = n;
    *back = n;
}

void deleteFromFront(node_t** front, node_t** back) {
    if(isEmpty(*front)) {
        printf("It is empty. Could not delete anything. \n");
        return;
    }
    node_t* n = *front;

    if(*front == *back) {
        *front = NULL;
        *back = NULL;
    }
    else {
        *front = (*front)->next;
        (*front)->prev = NULL;
    }

    free(n);
}

void deleteFromBack(node_t** front, node_t** back) {
    if (isEmpty(*back)) {
        printf("It is empty. Could not delete anything. \n");
        return;
    }
    node_t* n = *back;

    if(*front == *back) {
        *front = NULL;
        *back = NULL;
    } 
    else {
        *back = (*back)->prev;
        (*back)->next = NULL;
    }

    free(n);
}

void deleteDeq(node_t** front, node_t** back) {
    *back = NULL;

    while(*front != NULL) {
        node_t* n = *front;
        (*front)->prev = NULL;
        *front = (*front)->next;

        free(n);
    }
    printf("The deque is deleted! \n");
}

void printDeq(node_t* front) {
    node_t* current = front;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

int main() {

    node_t* front = NULL, *back = NULL;
    addInfront(&front, &back, 10);
    addInfront(&front, &back, 20);
    addAtBack(&front, &back, 30);
    addAtBack(&front, &back, 40);
    printDeq(front);
    deleteFromFront(&front, &back);
    deleteFromBack(&front, &back);
    printDeq(front);

    deleteDeq(&front, &back);
    return 0;
}