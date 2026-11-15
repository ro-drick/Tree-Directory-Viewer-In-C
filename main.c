#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file(const char *name, int is_dir, int indent) {
  if (indent > 0) {
    printf("%*c", indent * 2, ' ');
  }
  if (is_dir)
    printf("\033[0;34m%s\033[0m\n", name);
  else
    printf("%s\n", name);
}
int walk(const char *path, int indent) {
  DIR *dir = opendir(path);
  if (!dir) {
    perror("opendir");
    return 1;
  }
  struct dirent *dp;
  while ((dp = readdir(dir)) != NULL) {
    const char *name = dp->d_name;
    if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
      continue;
    char fullpath[1024];

    int written = snprintf(fullpath, sizeof(fullpath), "%s/%s", path, name);
    if (written < 0 || (size_t)written >= sizeof(fullpath)) {
      fprintf(stderr, "Path too long: %s/%s\n", path, name);
      continue;
    }

    struct stat st;
    if (stat(fullpath, &st) != 0) {
      perror(fullpath);
      continue;
    }
    int is_dir = S_ISDIR(st.st_mode);
    print_file(name, is_dir, indent);

    if (is_dir) {
      walk(fullpath, indent + 1);
    }
  }
  closedir(dir);
  return 0;
}
int main(int argc, char **argv) {
  const char *path = "."; // default path is current dir

  if (argc > 1) {
    path = argv[1];
  }

  printf("path %s\n", path);

  int err = walk(path, 0);
  return err;
}
