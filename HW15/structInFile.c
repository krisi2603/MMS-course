#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COUNT 8
//#define RW 1

typedef struct {
    char title[150];
    char author[100];
    int pages;
    double price;
} Book;


int randomInt(int, int);
double randomReal(void);
double randomRealRange(double, double);

void generateBooks(Book*, size_t);
void printBooks(Book*, size_t);


int main(int argc,char** argv) {
    srand(time(NULL));

    if(argc != 2) {
        printf("No enough arguments!\n");
        exit(EXIT_FAILURE);
    }

    Book books [COUNT];

    //#if RW == 1

    generateBooks(books, COUNT);
    FILE* fp = fopen(argv[1],"wb");
    if(fp == NULL) {
        printf("Could not open the file!\n");
        exit(EXIT_FAILURE);
    }

    fwrite(books, sizeof(Book), COUNT, fp);
    fclose(fp);
    /*#else

    FILE* fp = fopen(argv[1], "rb");
    fread(books, sizeof(Book), COUNT, fp);
    printBooks(books, COUNT);
    fclose(fp);

    #endif */
    return 0;
}

void generateBooks(Book* books, size_t n) {
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

void printBooks(Book* books, size_t n) {
    for(int i = 0; i < n; i++) {
        printf("Title: %20s, Author: %20s, Pages: %4d, Price: %4.2lf lv\n",
                books[i].title, books[i].author, books[i].pages, books[i].price);
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
