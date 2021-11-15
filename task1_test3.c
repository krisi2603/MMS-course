#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 10

typedef struct  {
    double x;
    double y;
} point_t;

typedef struct {
    point_t a;
    point_t b;
} rectangle_t;

typedef struct node {
    rectangle_t data;
    struct node* next;
}node_t;

int randomInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randomReal(void){
    return (double)rand() / RAND_MAX;
}

double randomRealRange(double min, double max){
    return min + randomReal() * (max - min);
}

void printRect(rectangle_t arr) {
    printf("A(%.1lf, %.1lf), B(%.1lf, %.1lf)\n",
            arr.a.x, arr.a.y, arr.b.x, arr.b.y );
}

rectangle_t generateRect(rectangle_t* arr) {
    arr->a.x = randomRealRange(-10,10);
    arr->a.y = randomRealRange(-10,10);
    arr->b.x = randomRealRange(-10,10);
    arr->b.y = randomRealRange(-10,10);

    return *arr;
}

void addNodeInRectList(node_t** n, rectangle_t value) {
    node_t* node = malloc(sizeof(node_t));
    if(!n) {
        printf("Could not allocate memory!\n");
        return;
    }
    node->data = generateRect(&value);
    node->next = *n;
    *n = node;
}

void printRectList(node_t* n) {
    node_t* current = n;

    while(current != NULL) {
        printRect(current->data);
        current = current-> next;
    }
    putchar('\n');
}

int isRectListEmpty(node_t* n) {
    return (n == NULL ? 1 : 0); 
}

void deleteRectFromBeginnig(node_t** n) {
    if(isRectListEmpty(*n)) {
        printf("The book list is empty!\n");
        return;
    }
    node_t* temp = *n;
    *n = (*n)->next;
    free(temp);
}

void freeBookList(node_t** n) {
    node_t* current = *n;
    node_t* temp = current;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *n = NULL;
}

double area(rectangle_t rect) {
    return fabs(rect.a.x - rect.b.x) * fabs(rect.a.y - rect.b.y);
}

double areaRects(node_t* list) {
    double area = 0, currentArea;
    node_t* current = list;
    while(current != NULL) {
        currentArea = (fabs(current->data.a.x - current->data.b.x) 
                    * fabs(current->data.a.y - current->data.b.y));
        area += currentArea;
        current = current->next;
    }
    return area;
}

void filterRects(node_t** list, double min, double max) {
    
}

int main(void) {
    srand(time(NULL));
    node_t* rects = NULL;
    rectangle_t rect;
    for(int i = 0; i < COUNT; i++) {
        addNodeInRectList(&rects, rect);
    }
    printRectList(rects);
    //double areaRects = areaRects(rects);



    return 0;
}