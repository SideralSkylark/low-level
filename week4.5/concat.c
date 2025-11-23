#include <stddef.h>

void safe_concat(char *dst, size_t size, const char *src);

int main(void) {
    char dst[10] = "Mr.";
    const char *src = "John";
    size_t size = 10;
    safe_concat(dst, size, src);
}

void safe_concat(char *dst, size_t size, const char *src) {
    if (size <= 0) return;

    size_t dest_size = 0;
    while (dst[dest_size] != '\0') {
        dest_size++;
    }

    if (dest_size >= size) return;

    size_t i = 0;
    while (dest_size + i < size - 1 && src[i] != '\0') {
        dst[dest_size] = src[i];
        dest_size++;
        i++;
    }

    dst[dest_size] = '\0';

}
