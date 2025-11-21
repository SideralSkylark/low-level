
#include <stdio.h>
#include <sys/stat.h>

// Escreve uma função que cria um diretório e retorna:
// 0 se sucesso, -1 se falha
int create_dir(const char *dir_name);

int main(void) {
    int res = create_dir("mydir");
    if (res == 0) printf("Created successfully\n");
    else printf("Failed\n");
}

int create_dir(const char *dir_name) {
    return mkdir(dir_name, 0777);
}
