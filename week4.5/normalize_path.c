char *normalize(char *path);

int main(void) {
    char path[] = "/home/user//docs///file";
    normalize(path);
}

char *normalize(char *path) {
    int i = 0;
    int j = 0;

    while (path[i] != '\0') {
        if (path[i] == '/') { 
            path[j] = '/';
            j++;

            while (path[i] == '/') {
                i++;
            }
        } else {
            path[j] = path[i];
            i++;
            j++;
        }
    }

    path[j] = '\0';
    return path;
}

// My rational is simple whe iterate until the end of the string.
// if we find '/' we write it at path[j] and then move j one index.
// then we move until i is in a regular char.
// then we shift from i -> '\0' to j because we incremented j. And incremente them both then repeat.
// this allows to override extra '/' withouth having to treat the array as a linked list
