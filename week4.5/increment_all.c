#include <stdio.h>

void increment_all(int *array[], int size);
void print_array(int *array[], int size);

int main(void) {
    int size = 6;
    int a = 3, b = 6, c = 2, d = 4, e = 0, f = 8;
    int *array[6] = {&a, &b, &c, &d, &e, &f};

    increment_all(array, size);
    print_array(array, size);
}

void increment_all(int *array[], int size) {
    for (int i = 0; i < size; i++) {
        int a = *array[i];
        *array[i] = ++a;
    }
}

void print_array(int *array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("position -> %d, value: %d\n", i, *array[i]);
    }
} 
