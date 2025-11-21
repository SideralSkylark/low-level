#include <stdio.h>
#include <stdlib.h>
const char *color_of_day(int day);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Provide and argument of type int.\n");
        return 1;
    }

    int day = atoi(argv[1]);

    printf("Color: %s", color_of_day(day));
}

const char *color_of_day(int day) {
    if (day == 0) {
        return "Blue";
    } else if (day == 1) {
        return "Yellow";
    } else if (day == 2) {
        return "Purple";
    } else {
        return "Unkown";
    }
}
