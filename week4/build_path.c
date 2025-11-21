#include <limits.h>
#include <stddef.h>
#include <stdio.h>

// Junta um diretório e um arquivo num caminho seguro
void join_path(char *buff, size_t size, const char *dir, const char *file);

int main(void) {
    char path[PATH_MAX];
    join_path(path, PATH_MAX, "/home/user", "document.txt");
    printf("%s\n", path); // Esperado: /home/user/document.txt
}


void join_path(char *buff, size_t size, const char *dir, const char *file) {
    snprintf(buff, size, "%s/%s", dir, file);
}
