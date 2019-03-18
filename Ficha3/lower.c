#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64
void lower(char* p){
  int i = 0;
  while(*(p+i) != '\0'){
    *(p+i) = tolower(*(p+i));
    i++;
  }
}

int main(int argc, char const *argv[]) {
  char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
  strcpy(p1, argv[1]);
  lower(p1);
  printf("p1 holds:%s\n", p1);
  return 0;
}
