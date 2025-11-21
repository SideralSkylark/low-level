#include <stddef.h>
#include <stdio.h>
#include <limits.h>

void join(char *buff, size_t size, const char *path, const char *file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Please provide a path followed by a file name as arguments.\n");
        return 1;
    }

    char buff[PATH_MAX];
    join(buff, PATH_MAX, argv[1], argv[2]);

    printf("result: %s", buff);
    return 0;
}

void join(char *buff, size_t size, const char *path, const char *file) {
    snprintf(buff, PATH_MAX, "%s/%s", path, file);
}
