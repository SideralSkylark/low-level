#include <stddef.h>
#include <stdio.h>

size_t count(const char *string);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Please provide a string as an argument.\n");
        return 1;
    }

    printf("Word count: %lu\n", count(argv[1]));
    return 0;
}

size_t count(const char *string) {
    size_t counter = 0;
    while (string[counter]) {
        counter++;
    }

    return counter;
}
