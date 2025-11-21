#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Please provide 2 integers as arguments.\n");
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("Pre operation, a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("Post operation, a: %d, b: %d\n", a, b);

    return 0;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
