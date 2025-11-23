#include "fileinfo.h"
#include <string.h>
#include <stdio.h>


int parse_path(const char *path, FileInfo *out) {
    if (!path || !out) return -1;

    const char *last_slash = strchr(path, '/');
}


void print_fileinfo(const FileInfo *info) {

}
