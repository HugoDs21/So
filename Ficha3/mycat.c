#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  char ch;
  for (size_t i = 1; i < argc; i++) {
    FILE *fp;
    fp = fopen (argv[i],"r");
    if (fp == NULL) {
      printf("WRONG FILE M8\n");
      continue;
    }
    while ((ch = fgetc(fp)) != EOF) {
      printf("%c", ch);
    }
  }
  return 0;
}
