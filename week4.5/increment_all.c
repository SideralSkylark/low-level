#include <stdio.h>

void increment_all(int *array, int size);
void print_array(int *array, int size);

int main(void) {
    int size = 6;

    int arr[] = {3, 6, 2, 4, 0, 8};
    increment_all(arr, size);
    print_array(arr, size);
}

void increment_all(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i]++;
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("position -> %d, value: %d\n", i, array[i]);
    }
} 
