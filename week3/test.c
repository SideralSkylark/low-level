#include <stdio.h>
struct person {
    int age;
    char *name;
};

int main(void) {
    struct person p1;
    int i = p1.age = 10;
    char *j = p1.name = "John";

    printf("age: %d\nname: %s", i, j);
}
