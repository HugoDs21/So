#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#define MAX 100

int main(int argc, char* argv[]) {
	char input[MAX];
	scanf("%s", input);
	while(strcmp(input, "quit") != 0){
		pid_t pid;
/* fork a child process */
		if ((pid = fork()) < 0 ) {
			printf("%s: cannot fork()\n", argv[0]);
			return EXIT_FAILURE;
		}else if (pid == 0) {
/* child process */
			if (execlp(input,input,NULL) < 0) {
				printf("bummer, did not exec %s\n", input);
				return EXIT_FAILURE;
			}
		}else {
/* parent process */
			if (waitpid(pid, NULL, 0) < 0) {
				printf("%s: cannot wait for child\n", argv[0]);
				return EXIT_FAILURE;
			}
		}
		scanf("%s", input);
	}
	return EXIT_SUCCESS;
}