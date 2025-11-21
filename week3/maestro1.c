#include "dirent.h"
#include "sys/stat.h"
#include<stdio.h>
#include <string.h>

int is_cat_dir(struct dirent *entry);  
char *get_category(char *filename);
char *get_extension(char *filename);

const int cat_n = 3;
const char *categories[3] = {"Document", "Image", "Other"};

int main(int argc, char *argv[]) {
    if (!argv[1]) {
        fprintf(stderr, "No path provided.\n");
    }

    const char *dir_name = argv[1];

    DIR *dir = opendir(dir_name);
    if (!dir) {
        fprintf(stderr, "Directory provided does not exist.\n");
    }
    
    for (int i = 0; i < cat_n; i++) {
        char path[PATH_MAX];
        snprintf(path, PATH_MAX, "%s/%s", dir_name, categories[1]);
        struct stat st;

        if (stat(path, &st) == -1) {
            if (mkdir(path, 0777) == -1) {
                fprintf(stderr, "Failed to created dir named %s\n", categories[i]);
                continue;
            } else {
                printf("Created dir named %s", categories[i]);
            }
        }
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") || strcmp(entry->d_name, "..")) continue;

        if (is_cat_dir(entry) == 1) {
            printf("Skipping category folder\n");
            continue;
        }
        
        char from[PATH_MAX];
        char to[PATH_MAX];
        snprintf(from, PATH_MAX, "%s/%s", dir_name, entry->d_name);
        snprintf(to, PATH_MAX, "%s/%s/%s", dir_name, get_category(entry->d_name), entry->d_name);

        if (rename(from, to) != 0) {
            fprintf(stderr, "Could not move %s to %s\n", from, to); 
        }
    }

    closedir(dir);
    return 0;
}

int is_cat_dir(struct dirent *entry) {
    for (int i = 0; i < cat_n; i++) {
        if (strcmp(entry->d_name, categories[i])) return 0;
    }

    return 1;
}

char *get_category(char *filename) {
    char *extension = get_extension(filename);

    if (!extension)
        return "Unkown";

    if (strcmp(extension, "txt") == 0 || strcmp(extension, "pdf") == 0 || strcmp(extension, "md") == 0)
        return "Document";
    else if (strcmp(extension, "jpg") == 0 || strcmp(extension, "png") == 0 || strcmp(extension, "gif") == 0)
        return "Image";
    else
        return "Other";
}

char *get_extension(char *filename) {
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return NULL;
    return dot + 1;
}
