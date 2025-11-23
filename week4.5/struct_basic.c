#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[36];
    int age;
} Person;

void print_person(const Person *p);
Person *create_person(const char *name, int age);
Person *create_people(size_t n);

int main(void) {
    Person *p1 = create_person("John", 32);
    print_person(p1);
    free(p1);
    p1 = NULL;
}

void print_person(const Person *p) {
    printf("Name: %s\nAge: %d", p->name, p->age);
}

Person *create_person(const char *name, int age) {
    Person *p = malloc(sizeof(Person));
    if (!p) return NULL;

    strcpy(p->name, name);
    p->age = age;
    return p;
}

Person *create_people(size_t n) {
    if (n == 0) return NULL;

    Person *people = (Person*) malloc(n * sizeof(Person));

    return people;
}
