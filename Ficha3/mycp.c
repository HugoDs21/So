#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

int main(int argc, char const *argv[]) {
  char ch;
  FILE *f1;
  f1 = fopen(argv[1], "r");
  FILE *f2;
  f2 = fopen(argv[2], "w");
  if (f1 == NULL || f2 == NULL) {
    printf("EMPTY FILE M8\n");
    fclose(f1);
    fclose(f2);
    return 1;
  }
  while ((ch = fgetc(f1)) != EOF) {
    fputc(ch, f2);
  }
  fputc(ch, f2);
  fclose(f1);
  fclose(f2);
  return 0;
}
