#include <climits>
#include <stddef.h>
#include <stdio.h>

int *min(int *array, size_t size);

int main(void) {
    int size = 6;
    int array[] = {3,6,2,4,0,8};


    printf("Min number is: %d", *min(array, size));
}

int *min(int *array, size_t size) {
    if (size == 0) return 0;

    int *min_p = &array[0];

    for (size_t i = 1; i < size; i++) {
        if (array[i] < *min_p) {
            min_p = &array[i];
        }
    }

    return min_p;
}
