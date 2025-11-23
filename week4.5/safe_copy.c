#include <stddef.h>
void safe_copy(char *dest, size_t size, const char *src);

int main(void) {
    size_t size = 5;
    const char *src = "skjdh";
    char res[size];
    safe_copy(res, size, src);
}

void safe_copy(char *dest, size_t size, const char *src) {
    if (size <= 0) return;
    
    size_t i = 0;

    while (i < size - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    } 

    dest[i] = '\0';
}
