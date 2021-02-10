#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNUSED __attribute__((unused))

int main (UNUSED int arg, UNUSED char *argv[]){
	long nlines = 0L;
	char buf[BUFSIZ];
	int exitStatus = EXIT_SUCCESS;
	char **nwords;
	long numCharacters = 0L;

	while (fgets(buf, sizeof buf, stdin) != NULL){
	   nlines++;
	
	

	numCharacters += strlen(buf);

	}

	printf("%8ld\n", numCharacters);
	return exitStatus;
}
