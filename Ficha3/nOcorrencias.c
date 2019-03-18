#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64

int main(int argc, char const *argv[]) {
  char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
  char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));

  strcpy(p1, argv[1]);
  strcpy(p2, argv[2]);

  int count = 0;

  while ((p2 = strstr(p2,p1)) != NULL) {
    count++;
    p2 += strlen(p1);
  }
  printf("%d\n", count);
  return 0;
}
