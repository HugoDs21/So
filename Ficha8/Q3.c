#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define READ 0
#define WRITE 1
#define LINESIZE  256
int main(int argc, char* argv[]) {
	int   n, r, fd[2];
	pid_t pid;
	char  line[LINESIZE];
	if (pipe(fd) < 0) {
		exit(EXIT_FAILURE);
	}
	if ((pid = fork()) < 0) {
		exit(EXIT_FAILURE);
	}
	else if (pid > 0) {
		/* parent */
		close(fd[WRITE]);
		while(r = read(fd[READ], line, LINESIZE) != 0) {

		write(STDOUT_FILENO, line, r);
	}
		close(fd[READ]);
		/* wait for child and exit */
		exit(EXIT_SUCCESS);
	}
	else {
		/* child */
		close(fd[READ]);

		FILE* fp = fopen(argv[1], "r");

		char c;
		while(fread(&c, 1, 1, fp) != 0) {
			n = write(fd[WRITE], &c, 1);
		}
		close(fd[WRITE]);
		fclose(fp);
		/* exit gracefully */
		exit(EXIT_SUCCESS);
	}
	return EXIT_SUCCESS;
}