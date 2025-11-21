// Escreve uma função que transforma todos os caracteres de uma string em maiúsculas
// Recebe char * e modifica diretamente
#include <ctype.h>
#include <stdio.h>

void uppercase(char *str);

int main(void) {
    char s[] = "hello world";
    uppercase(s);
    printf("%s\n", s); // Esperado: HELLO WORLD
}

void uppercase(char *str) {
    for (int i = 0; str[i]; i++) str[i] = toupper(str[i]);
    //no need to return because we are modifying a buffer not a literal so it is modifiable
}
