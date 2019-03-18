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
  //p2 occore em p1?
  if (strstr(p1, p2)) {
    printf("Ocorre\n");
  } else {
    printf("Nao Ocorre\n");
  }
  return 0;
}
