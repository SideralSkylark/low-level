#include <stddef.h>
#include <stdlib.h>
#include <string.h>
char *duplicate(const char *src);


int main(void) {
    const char *original = "John";
    char *clone = duplicate(original);
}


char *duplicate(const char *src) {
    if (src == NULL) return NULL;

    size_t size = strlen(src);

    char *clone = malloc(size + 1);

    if (clone == NULL) return NULL;

    size_t i = 0;
    while(src[i] != '\0') {
        clone[i] = src[i];
        i++;
    }

    clone[i] = '\0';

    return clone;
}


