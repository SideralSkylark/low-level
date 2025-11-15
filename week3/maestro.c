#include <dirent.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void list_dir(const char *path);
void create_dir(const char *dir_name);
void organize_dir(const char *dir_name);
int is_category_folder(struct dirent *entry);
void move_dir_entry(const char *dir_name, struct dirent *entry);
const char *get_extension(const char *filename);
const char *categorize_file(const char *filename);

const char *categories[3] = {"Document", "Image", "Other"};
const int categories_n = 3;

int main(int argc, char *argv[]) {

  if (!argv[1]) {
    fprintf(stderr, "Pass a directory as an argument.\n");
    return 1;
  }
  list_dir(argv[1]);

  organize_dir(argv[1]);

  return 0;
}

void list_dir(const char *path) {
  DIR *dir = opendir(path);
  if (!dir) {
    fprintf(stderr, "Error opening directory '%s'\n", path);
    return;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;
    const char *category = categorize_file(entry->d_name);
    printf("%-30s -> %s\n", entry->d_name, category);
  }
}

void organize_dir(const char *dir_name) {

  for (int i = 0; i < categories_n; i++) {
    struct stat dir;
    char cat_path[PATH_MAX];
    snprintf(cat_path, PATH_MAX, "%s/%s", dir_name, categories[i]);
    int res = stat(cat_path, &dir);

    if (res == 0) {
      if (S_ISDIR(dir.st_mode)) {
        printf("Directory already exists\n");
        continue;
      }
    } else {
        create_dir(cat_path);
    }
  }

  DIR *dir = opendir(dir_name);
  if (!dir) {
    fprintf(stderr, "Couldn't open directory\n");
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (is_category_folder(entry)) {
      printf("Skipping entry.\n");
      continue;
    }

    move_dir_entry(dir_name, entry);
  }

  closedir(dir);
}

int is_category_folder(struct dirent *entry) {
  for (int i = 0; i < categories_n; i++) {
    if (strcmp(entry->d_name, categories[i]) == 0)
      return 1;
  }

  return 0;
}

void move_dir_entry(const char *dir_name, struct dirent *entry) {
  char entry_path[PATH_MAX];
  char result_path[PATH_MAX];

  snprintf(entry_path, PATH_MAX, "%s/%s", dir_name, entry->d_name);
  snprintf(result_path, PATH_MAX, "%s/%s/%s", dir_name,
           categorize_file(entry->d_name), entry->d_name);

  if (rename(entry_path, result_path) == 0) {
    perror("Failed to move entry\n");
  }
}

const char *get_extension(const char *filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot || dot == filename)
    return NULL;
  return dot + 1;
}

const char *categorize_file(const char *filename) {
  const char *extension = get_extension(filename);
  if (!extension)
    return "Unkown";

  if (strcmp(extension, "txt") == 0 || strcmp(extension, "pdf") == 0 ||
      strcmp(extension, "md") == 0)
    return "Document";
  else if (strcmp(extension, "jpg") == 0 || strcmp(extension, "png") == 0 ||
           strcmp(extension, "gif") == 0)
    return "Image";
  else
    return "Other";
}

void create_dir(const char *dir_name) {
  if (mkdir(dir_name, 0777) == -1) {
    fprintf(stderr, "Error creating directory %s\n", dir_name);
  } else {
    printf("Directory %s created successfully\n", dir_name);
  }
}
