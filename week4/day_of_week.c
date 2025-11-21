// Escreve uma função que retorna o nome de um dia da semana
// 0 -> "Sunday", 1 -> "Monday", etc. até 6 -> "Saturday"
// Se o número for inválido, retorna "Unknown"
// Não deve usar malloc, apenas literais.
#include <stdio.h>

const char *day_of_week(int day);

int main(void) {
    printf("%s\n", day_of_week(0)); // Esperado: Sunday
    printf("%s\n", day_of_week(5)); // Esperado: Friday
}

const char *day_of_week(int day) {
    if (day == 0) 
        return "Sunday";
    else if (day == 1)
        return "Monday";
    else if (day == 2)
        return "Thuesday";
    else if (day == 3)
        return "Wednesday";
    else if (day == 4)
        return "Thursday";
    else if (day == 5)
        return "Friday";
    else if (day == 6)
        return "Saturday";
    else
     return "Unknown";

}
