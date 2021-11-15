#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node_t;

typedef struct {
    node_t* current;
    node_t* end;
}clist_t;

void addNodeInBeginning(node_t** list, int value) {
    node_t* n = malloc(sizeof(node_t));
    n->data = value;
    n->next = *list;
    *list = n;
}

int isListEmpty(node_t* list) {
    if(list == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void freeList(node_t** list) {
    node_t* current = *list;
    node_t* first = *list;
    node_t* temp  = current;

    while (current != first) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *list = NULL;
}


void print(node_t* cll) {
    node_t* current = cll;
    node_t* first = cll;

    while(current->next != first) {
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

int main(void) {

    int N;
    int arr[100];
    node_t* clist;

    printf("Enter a number: ");
    do{
        scanf("%d", &N);
    }while(N < 0);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        addNodeInBeginning(&clist, arr[i]);
    }
    print(clist);

    //freeList(&clist);
    return 0;
}