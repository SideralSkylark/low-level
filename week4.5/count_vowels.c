#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>


size_t count_vowels(const char *s);

int main(void) {
    printf("vowels: %zu", count_vowels("sIdik"));
}

size_t count_vowels(const char *s) {
    size_t counter = 0;

    for (int i = 0; s[i]; i++) {
        char c = tolower(s[i]);
        switch (c) {
            case 'a':
                counter++;
                break;
            case 'e':
                counter++;
                break;
            case 'i':
                counter++;
                break;
            case 'o':
                counter++;
                break;
            case 'u':
                counter++;
                break;
        }
    }

    return counter;
}
