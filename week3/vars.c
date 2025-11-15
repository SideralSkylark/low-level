#include <stdio.h>

int main(void) {
    int age = 20;
    char* name = "John Doe";
    float height = 1.8;
    printf("%f", height);

    if (height >= 1.8 && height <= 2.0) {
        if (name) {
            printf("Subject identified.\nname: %s \nage: %d \nheight: %f", name, age, height);
            return 0;
        }
    }
    return 1;
}       
