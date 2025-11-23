#include <stdio.h>
float mid(const int array[], int size);

int main(void) {
    int size = 6;
    int array[6] = {2, 8, 4, 0, 3, 7}; 
    printf("%f", mid(array, size));
}

float mid(const int array[], int size) {
    if (size <= 0) return 0;

    float mid = 0;
    for (int i = 0; i < size; i++) {
        mid += (float)array[i];
    }

    return mid / size;
}
