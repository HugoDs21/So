#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;
  char msg[] = "Hello World";
  for(i = 0; i < sizeof(msg); i++){
    printf("%c <--> %c\n", msg[i], *(msg + i));
  }
  return 0;
}
