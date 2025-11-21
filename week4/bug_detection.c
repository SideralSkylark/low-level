


#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {

}

//maybe we should extract the .txt from name but from the parameter i cant tell if its the whole file name, or just the extension
int is_txt(const char *name) {
    if (strcmp(name, ".txt") == 0) {
        return 1;
    }

    return 0;
}

char *category() {
    char buff[50];//wont use pathmax since source is literal with fixed length
    strcpy(buff, "Hello");
    return buff; // dont understand the bug maybe the fact that we are returning an address
}


void make_dir(const char *d) {
    if (mkdir(d, 0777) != 0) {
        fprintf(stderr, "error creating dir");
    }
    printf("Created %s", d);
}
