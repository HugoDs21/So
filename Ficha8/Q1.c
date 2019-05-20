#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	/* check if argv[1] can be opened and is readable */
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL) {
		printf("%s: cannot open %s\n", argv[0], argv[1]);
		return EXIT_FAILURE;
	}
	int countChar = 0;
	int countLine = 1;
	char c;
	while(fread(&c, 1, 1, fp) != 0) {
		countChar++;
		if (c == '\n') {
			countLine++;
		}
	}
	printf("%d Chars, %d Lines\n", countChar, countLine);
	return EXIT_SUCCESS;
}