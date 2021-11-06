#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 5

typedef struct {
    char title[150];
    char author[100];
    int pages;
    double price;
} book;

void swapUni(void*, void*, size_t);
void bubbleSort(void*, size_t, ssize_t, int (*)(const void*, const void*));
void* linearSearch(void*, size_t, size_t, const void*, int(*)(const void*, const void*)); 

int compareBookByAuthor(const void*, const void*);
int compareBookByTitle(const void*, const void*);
int compareBookByPages(const void*, const void*);
int compareBookByPrice(const void*, const void*);

int randomInt(int, int);
double randomReal(void);
double randomRealRange(double, double);

void generateBooks(book*, size_t);
void printBooks(book*, size_t);


int main(void) {
    srand(time(NULL));
    book books [COUNT] = {  {"Ali", "AliBaba", 34, 8.9},
                            {"Eliza", "Leila", 123, 5.5},
                            {"Hello", "Mila", 89,12.6},
                            {"Leo", "Zoro", 99, 15.9},
                            {"Nesseber", "Ivailo", 400, 20.5} };
    //uncomment when not trying searching
    //generateBooks(books, COUNT);

    printf("Books sorted by title: \n");
    bubbleSort(books, COUNT, sizeof(book), compareBookByTitle);
    printBooks(books, COUNT);

    printf("Books sorted by author: \n");
    bubbleSort(books, COUNT, sizeof(book), compareBookByAuthor);
    printBooks(books, COUNT);

    printf("Books sorted by pages: \n");
    bubbleSort(books, COUNT, sizeof(book), compareBookByPages);
    printBooks(books, COUNT);

    printf("Books sorted by price: \n");
    bubbleSort(books, COUNT, sizeof(book), compareBookByPrice);
    printBooks(books, COUNT);

    book* key;
    key->price = 20.50;

    book* b = (book*)linearSearch(books, COUNT, sizeof(book), key, compareBookByPrice);
    if(b == NULL) {
        printf("There is no such book!\n");
    }
    else  {
        printf("Title of book: %s\n ", b->title);
    }
    return 0;
}

void swapUni(void* a, void* b, size_t n) {
    char temp[n];
    memmove(temp, a, n);
    memmove(a, b, n);
    memmove(b, temp, n);
}

void bubbleSort(void* arr, size_t n, ssize_t size, int (*cmp)(const void*, const void*)) {
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

void* linearSearch(void* arr, size_t n, size_t size, const void* key, int(*cmp)(const void* a, const void* b)) { 
    for(int i = 0; i < n * size; i += size) {
        if(cmp(arr + i, key) == 0) {
            return arr + i;
        }
    }
    return NULL;
}

int compareBookByAuthor(const void* a, const void* b) {
    book* book1 = (book*)a;
    book* book2 = (book*)b;
    
    return strcmp(book2->author, book1->author);
}

int compareBookByTitle(const void* a, const void* b) {
    book* book1 = (book*)a;
    book* book2 = (book*)b;

    return strcmp(book1->title, book2->title);
}

int compareBookByPages(const void* a, const void* b) {
    book* book1 = (book*)a;
    book* book2 = (book*)b;

    return book1->pages - book2->pages;
}

int compareBookByPrice(const void* a, const void* b) {
    book* book1 = (book*)a;
    book* book2 = (book*)b;

    if(book1->price > book2->price) {
        return 1;
    } 
    else if(book1->price < book2->price) {
        return -1;
    }
    return 0;
}

void generateBooks(book* books, size_t n) {
    for(int i = 0; i < n; i++) {
        books[i].pages = randomInt(5,2000);
        books[i].price = randomRealRange(1.00, 1000.00);

        int size = randomInt(10, 20);
        books[i].title[0] = randomInt('A','Z');
        books[i].author[0] = randomInt('A','Z');
        for(int j = 1; j < size; j++) {
            books[i].title[j] = randomInt('a','z');
            books[i].author[j] = randomInt('a','z');
        }
        books[i].title[size] = '\0';
        books[i].author[size] = '\0';
    }
} 

void printBooks(book* arr, size_t n) {
    for(int i = 0; i < n; i++) {
        printf("Title: %20s, Author: %20s, Pages: %4d, Price: %4.2lf lv\n",
                arr[i].title, arr[i].author, arr[i].pages, arr[i].price);
    }
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
