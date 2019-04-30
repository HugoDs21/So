#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// ./piper "ls -l | wc -l"
int main(int argc, char const *argv[]) {
  int i = 0;
  char* cmd1[2];
  char* cmd2[2];
  char* token = strtok(argv[1], " ");
  while (token != NULL) {
    cmd1[i++] = token;
    if (strcmp(token, "|") == 0) {
      cmd1[i -1] = NULL;
    }
    token = strtok(NULL, " ");
  }
  i = 0;

  for (int j = 0; j < 2; j++) {
    printf("%s\n", cmd1[j]);
  }
  for (int j = 0; j < 2; j++) {
    printf("%s\n", cmd2[j]);
  }
  int fd[2];
  pid_t pid;
  if (pipe(fd) < 0) {
    printf("ERROR\n");
    return 0;
  }
  if ((pid = fork()) < 0) {
    printf("ERROR\n");
    return 0;
  }
  if (pid > 0) {
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO); // stdout to pipe
    close(fd[1]);
    // parent writes to the pipe
    if (execvp(cmd1[0], cmd1) < 0) {
      printf("ERROR\n");
      return 0;
    }
  } else {
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO); // stdin from pipe
    close(fd[0]);
    if (execvp(cmd2[0], cmd2) < 0) {
      printf("ERROR\n");
      return 0;
    }
  }
  return 0;
}
