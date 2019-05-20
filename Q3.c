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
		if(fp == NULL) {
			printf("%s: cannot open %s\n", argv[0], argv[1]);
			return EXIT_FAILURE;
		}

		char c;
		while(fread(&c, 1, 1, fp) != 0) {
			if ((n = write(fd[write], c, 1)) < 0 ) {
				fprintf(stderr, "Unable to read from pipe: %s\n", strerror(errno));
			}
		}
		kkkjhkj
		close(fd[WRITE]);
		/* exit gracefully */
		exit(EXIT_SUCCESS);
	}
	return EXIT_SUCCESS;
}