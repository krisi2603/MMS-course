#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct {
    char model[100];
    uint8_t maxspeed;
    double price;
} car;

void generateCars(car*, size_t);
void printCars(car*, size_t);

int compareByModeInc(const void*, const void*);
int compareByModelDec(const void*, const void*);
int compareBySpeedInc(const void*, const void*);
int compareBySpeedDec(const void*, const void*);
int compareByPriceInc(const void*, const void*);
int compareByPriceDec(const void*, const void*); 

int(*getComparator(int n))(const void*, const void*);

int randInt(int, int);
double randReal(double, double);

int main(void) {
    srand(time(NULL));
    car cars[10];
    generateCars(cars,10);

    int number;
    printf("Enter a number between 1-6: ");
    scanf("%d", &number);

    int(*f)(const void*, const void*);
    f = getComparator(number);
    if(f == NULL) {
        printf("You have entered incorrect number! Enter new number between 1-6\n");
        scanf("%d", &number);
    }
    qsort(cars, LEN(cars), sizeof(car), f);
    printCars(cars, LEN(cars));

    return 0;
}

void generateCars(car* cars, size_t n) {
    for(int i = 0; i < n; i++) {
        cars[i].maxspeed = randInt(100,300);
        cars[i].price = randReal(1000.00, 100000.00);

        int size = randInt(4, 10);
        cars[i].model[0] = randInt('A','Z');
        for(int j = 1; j < size; j++) {
            cars[i].model[j] = randInt('a','z');
        }
        cars[i].model[size] = '\0';
    }
} 

void printCars(car* arr, size_t n){
    for (int i = 0; i < n; i++){
        printf("Model: %10s, Max speed: %4d, Price %8.2lf\n", 
        arr[i].model, arr[i].maxspeed, arr[i].price);
    }
}

int compareByModelInc(const void* a, const void* b){
    car* car1 = (car*)a;
    car* car2 = (car*)b;
    return strcmp(car1->model, car2->model);
}

int compareByModelDec(const void* a, const void* b){
    car* car1 = (car*)a;
    car* car2 = (car*)b;
    return strcmp(car2->model, car1->model);
}

int compareBySpeedInc(const void* a, const void* b) {
    car* car1 = (car*)a;
    car* car2 = (car*)b;

    return car1->maxspeed - car2->maxspeed;
}

int compareBySpeedDec(const void* a, const void* b) {
    car* car1 = (car*)a;
    car* car2 = (car*)b;

    return car2->maxspeed - car1->maxspeed;
}

int compareByPriceInc(const void* a, const void* b) {
    car* car1 = (car*)a;
    car* car2 = (car*)b;

    if(car1->price > car2->price) {
        return 1;
    } 
    else if(car1->price < car2->price) {
        return -1;
    }
    return 0;
}

int compareByPriceDec(const void* a, const void* b) {
    car* car1 = (car*)a;
    car* car2 = (car*)b;

    if(car1->price < car2->price) {
        return 1;
    } 
    else if(car1->price > car2->price) {
        return -1;
    }
    return 0;
}

int(*getComparator(int n))(const void* a, const void* b) {
    if(n == 1) {
        return compareByModelInc;
    }
    if(n == 2) {
        return compareByModelDec;
    }
    if(n == 3) {
        return compareBySpeedInc;
    }
    if(n == 4) {
        return compareBySpeedDec;
    }
    if(n == 5) {
        return compareByPriceInc;
    }
    if(n == 6) {
        return compareByPriceDec;
    }
    return NULL;
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1); 
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}