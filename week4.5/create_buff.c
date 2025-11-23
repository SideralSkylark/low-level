#include <stdlib.h>
char *alocate(size_t size);

int main(void) {
    char *buff = alocate(7);
    free(buff);
}


char *alocate(size_t size) {
    if (size == 0) return NULL;
    char *buffer = malloc(size);

    return buffer;
}
