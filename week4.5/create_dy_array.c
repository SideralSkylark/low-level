#include <stddef.h>
#include <stdlib.h>

int *create_array(size_t n, int initial_value);
int *resize_array(int *arr, size_t new_size);

int main(void) {
    size_t n = 10;
    create_array(n, 3);
}

int *create_array(size_t n, int initial_value) {
    if (n == 0) return NULL;

    int *array = (int*)calloc(n, sizeof(int));

    if (array == NULL) return NULL;
    array[0] = initial_value;

    return array;
}


int *resize_array(int *arr, size_t new_size) {
    if (!arr) return NULL;
    if (new_size == 0) return NULL;

    int *array = (int*) realloc(arr, new_size * sizeof(int));

    if (array == NULL) return NULL;

    return array;
}

void safe_free(void **ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        ptr = NULL;
    }
}
