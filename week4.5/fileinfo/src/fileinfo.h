#ifndef FILEINFO_H
#define FILEINFO_H

#include <stddef.h>

typedef struct {
    char directory[512];
    char filename[256];
    char extension[64];
} FileInfo;

int parse_path(const char *path, FileInfo *out);

void print_fileinfo(const FileInfo *info);

#endif
