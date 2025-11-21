#include <ctype.h>
#include <stdio.h>

char *lowercase(char *string);
void no_return(char *string);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Provide and argument of type int.\n");
        return 1;
    }

    no_return(argv[0]);
    printf("Test no return: %s\n", argv[1]);

    printf("result: %s\n", lowercase(argv[1]));
    return 0;
}

char *lowercase(char *string) {
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
// i think there is no need to return anything because we are modifying the pointer itsel no?
//update: didnt go as planed, yes you need to return, or maybe could there be a way of changing the value in the address
    return string;
}

void no_return(char *string) {
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}
