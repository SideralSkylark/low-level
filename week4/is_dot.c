#include <stdio.h>
#include <string.h>

int is_dot(const char *name);

int main(int argc, char *argv[]) {
    if (!argv[1]) {
        fprintf(stderr, "Please provide an argument.\n");
        return 1;
    }

    return is_dot(argv[1]);
}

int is_dot(const char *name) {
    if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
        printf("Is dot.\n") ;       
        return 1;
    }
    
    printf("Is not dot.\n");
    return 0;
}
