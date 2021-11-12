#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10

typedef struct {
    char title[150];
    char author[100];
    int pages;
    double price;
} Book;

typedef struct node {
    Book data;
    struct node* next;
} bookNode;

Book generateBooks(Book*);
int isBookListEmpty(bookNode*);
void addNodeInBookList(bookNode**, Book);
void deleteBookFromBeginnig(bookNode**);
void freeBookList(bookNode**);

bookNode* sortedMerge(bookNode*, bookNode*, int(*)(const void*, const void*));
void frontBackSplit(bookNode*, bookNode**, bookNode**);
void mergeSort(bookNode**, int(*)(const void*, const void*));
int compareBookByTitle(const void*, const void*);

void printBooks(Book);
void printBookList(bookNode*);

int randomInt(int, int);
double randomReal(void);
double randomRealRange(double, double);

int main(void) {
    srand(time(NULL));
    bookNode* books = NULL;
    Book b;
    for(int i = 0; i < COUNT; i++) {
        addNodeInBookList(&books, b);
    }
    //printf("Initial book list: \n");
    //printBookList(books);
    mergeSort(&books, compareBookByTitle);
    printf("Sorted book list: \n");
    printBookList(books);

    freeBookList(&books);
    return 0;
}

void addNodeInBookList(bookNode** b, Book value) {
    bookNode* book = malloc(sizeof(bookNode));
    if(!book) {
        printf("Could not allocate memory!\n");
        return;
    }
    book->data =  generateBooks(&value);
    book->next = *b;
    *b = book;
}

void deleteBookFromBeginnig(bookNode** b) {
    if(isBookListEmpty(*b)) {
        printf("The book list is empty!\n");
        return;
    }
    bookNode* temp = *b;
    *b = (*b)->next;
    free(temp);
}

void freeBookList(bookNode** book) {
    bookNode* current = *book;
    bookNode* temp = current;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *book = NULL;
}

bookNode* sortedMerge(bookNode* listA, bookNode* listB, int(*cmp)(const void*, const void*)){
    bookNode* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if(cmp(&(listA->data), &(listB->data)) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}

void frontBackSplit(bookNode* list, bookNode** front, bookNode** back){
    bookNode* slow = list;
    bookNode* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(bookNode** list, int(*cmp)(const void*, const void*)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    bookNode *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}

void printBookList(bookNode* b) {
    bookNode* current = b;

    while(current != NULL) {
        printBooks(current->data);
        current = current-> next;
    }
    putchar('\n');
}

int isBookListEmpty(bookNode* b) {
    return (b == NULL ? 1 : 0); 
}

Book generateBooks(Book* books) {
    books->pages = randomInt(5, 2000);
    books->price = randomRealRange(1.00, 1000.00);

    int size = randomInt(10, 20);
    books->title[0] = randomInt('A','Z');
    books->author[0] = randomInt('A','Z');
    for(int j = 1; j < size; j++) {
        books->title[j] = randomInt('a','z');
        books->author[j] = randomInt('a','z');
    }
    books->title[size] = '\0';
    books->author[size] = '\0';

    return *books;
} 

int compareBookByTitle(const void* a, const void* b) {
    Book* book1 = (Book*)a;
    Book* book2 = (Book*)b;

    return strcmp(book2->title, book1->title);
}

void printBooks(Book b) {
    printf("Title: %20s, Author: %20s, Pages: %4d, Price: %4.2lf lv\n",
            b.title, b.author, b.pages, b.price);
    printf("\n");
}

int randomInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randomReal(void){
    return (double)rand() / RAND_MAX;
}

double randomRealRange(double min, double max){
    return min + randomReal() * (max - min);
}