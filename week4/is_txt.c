// Escreve uma função que verifica se um arquivo tem extensão ".txt"
// Retorna 1 se for txt, 0 caso contrário
#include <stdio.h>
#include <string.h>
int is_txt(const char *filename);

int main(void) {
    printf("%d\n", is_txt("teste.txt"));    // 1
    printf("%d\n", is_txt("document.pdf")); // 0
}

int is_txt(const char *filename) {
    char *extension = strrchr(filename, '.');
    extension = extension + 1;

    if (strcmp(extension, "txt") == 0) {
        return 1;
    }

    return 0;
}
