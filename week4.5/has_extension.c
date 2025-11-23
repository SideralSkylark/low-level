#include <string.h>

int has_extension(const char *filename, const char *ext);

int main(void) {
    const char *filename = "Music.mp3";
    has_extension(filename, "mp3");
}

int has_extension(const char *filename, const char *ext) {
    const char *dot = strrchr(filename, '.');

    if (dot == NULL || *(dot + 1) == '\0') return 0;

    return strcmp(dot + 1, ext) == 0;
}
