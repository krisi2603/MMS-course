#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 8

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


void printBooks(Book*, size_t);
void printBook(Book);

void addNodeInBookList(bookNode**, Book);
void printBookList(bookNode*);
void freeBookList(bookNode**);

bookNode* sortedMerge(bookNode*, bookNode*, int(*)(const void*, const void*));
void frontBackSplit(bookNode*, bookNode**, bookNode**);
void mergeSort(bookNode**, int(*)(const void*, const void*));
int compareBookByTitle(const void*, const void*);


int main(int argc,char** argv) {
    if(argc != 3) {
        printf("No enough arguments!\n");
        exit(EXIT_FAILURE);
    }
    Book books [COUNT];
    FILE* fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        printf("Could not open the file!\n");
        exit(EXIT_FAILURE);
    }
    fread(books, sizeof(Book), COUNT, fp);
    printBooks(books, COUNT);

    bookNode* b = NULL;
    for(int i = 0; i < COUNT; i++) {
        addNodeInBookList(&b, books[i]);
    }
    mergeSort(&b, compareBookByTitle);
    printf("Sorted book list: \n");
    printBookList(b);
//until here it's working

    FILE* fw = fopen(argv[2], "wb");
    if(fw == NULL) {
        printf("Could not open the file!\n");
        exit(EXIT_FAILURE);
    }
    fwrite(&(b->data), sizeof(Book), COUNT, fw);
    fclose(fw);

    freeBookList(&b);
    fclose(fp);
    return 0;
}

void addNodeInBookList(bookNode** b, Book value) {
    bookNode* book = malloc(sizeof(bookNode));
    if(!book) {
        printf("Could not allocate memory!\n");
        return;
    }
    book->data =  value;
    book->next = *b;
    *b = book;
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

int compareBookByTitle(const void* a, const void* b) {
    Book* book1 = (Book*)a;
    Book* book2 = (Book*)b;

    return strcmp(book2->title, book1->title);
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

void printBooks(Book* books, size_t n) {
    for(int i = 0; i < n; i++) {
        printf("Title: %20s, Author: %20s, Pages: %4d, Price: %4.2lf lv\n",
                books[i].title, books[i].author, books[i].pages, books[i].price);
    }
    printf("\n");
}

void printBook(Book b) {
    printf("Title: %20s, Author: %20s, Pages: %4d, Price: %4.2lf lv\n",
            b.title, b.author, b.pages, b.price);
    printf("\n");
}

void printBookList(bookNode* b) {
    bookNode* current = b;

    while(current != NULL) {
        printBook(current->data);
        current = current-> next;
    }
    putchar('\n');
}
