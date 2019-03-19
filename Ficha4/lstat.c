#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
  struct stat info;
  int i = 1;
  int size = 0;
  int blocks = 0;
  while (argv[i] != NULL) {

    if (lstat(argv[i], &info) == -1) {
      fprintf(stderr, "fsize: Can’t stat %s\n", argv[i]);
      return EXIT_FAILURE;
    }
    size += (int)info.st_size;
    blocks += (int)info.st_blocks;
    printf("%s size: %d bytes, disk_blocks: %d\n", argv[i], (int)info.st_size, (int)info.st_blocks);

    i++;
  }
  printf("Size: %d  Blocks: %d\n", size, blocks);
  return EXIT_SUCCESS;
}
