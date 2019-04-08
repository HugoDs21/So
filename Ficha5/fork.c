#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  printf("PID: %d\n", getpid());
  /* fork a child process */
  printf("-----1º Fork------\n");
  int filho = fork();
  printf("Pai: %d\n", getpid());
  printf("Filho: %d\n", filho);
  /* fork another child process */
  // printf("-----2º Fork------\n");
  // int filho2 = fork();
  // printf("Pai: %d\n", getpid());
  // printf("Filho: %d\n", filho2);
  // printf("-----3º Fork------\n");
  // int filho3 = fork();
  // printf("Pai: %d\n", getpid());
  // printf("Filho: %d\n", filho3);
  return EXIT_SUCCESS;
}
