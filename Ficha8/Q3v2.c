#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define LINESIZE 256

int main(int argc, char* argv[]) {
  int n, r, fd[2];
  pid_t pid;
  char line[LINESIZE];
  if (pipe(fd) < 0) {
    perror("pipe error");
    exit(EXIT_FAILURE);
  }
  if ((pid = fork()) < 0) {
    perror("fork error");
    exit(EXIT_FAILURE);
  }
  else if (pid > 0) {
    /* parent */
    close(fd[WRITE]);
    while ((r = read(fd[READ], line, LINESIZE)) != 0) {
      write(STDOUT_FILENO, line, r);
    }
    close(fd[READ]);
    exit(EXIT_SUCCESS);
  }
  else {
    /* child */
    close(fd[READ]);
    FILE* fp = fopen(argv[1], "r");
    int n;
    while ((n = fread(line, sizeof(char), LINESIZE, fp)) != 0) {
      write(fd[WRITE], line, n);
    }
    close(fd[WRITE]);
    fclose(fp);
    /* exit gracefully */
    exit(EXIT_SUCCESS);
  }
}
