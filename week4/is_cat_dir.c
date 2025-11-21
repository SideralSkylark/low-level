#include <stdio.h>
#include <string.h>

const char *categories[3] = {"Doc", "Img", "Other"};
const int cat_n = 3;

int is_cat_dir(const char *name);

int main(int argc, char *argv[]) {
    if (!argv[1]) {
        fprintf(stderr, "Please provide an argument.\n");
        return 1;
    }

    is_cat_dir(argv[1]);
    return 0;
}

int is_cat_dir(const char *name) {
    for (int i = 0; i < cat_n; i++) {
        if (strcmp(name, categories[i]) == 0) {
            printf("Is cat dir.\n");
            return 1; 
        }
    }

    printf("is not cat dir.\n");
    return 0;
}
