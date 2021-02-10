#include <stdio.h>
#include <stdlib.h>
#include "stsplit.h"
#define UNUSED __attribute__((unused))

int main (UNUSED int arg, UNUSED char *argv[]){
	long nlines = 0L;
	char buf[BUFSIZ];
	int exitStatus = EXIT_SUCCESS;
	char **nwords;
	long numberWords = 0L;

	while (fgets(buf, sizeof buf, stdin) != NULL){
	   nlines++;
	nwords = stsplit(buf); /* returns array of char strings */
	stfree(nwords);
	
	for(int index = 0; nwords[index] != NULL; index++){
		numberWords++;

	}
}
	printf("%8ld\n", numberWords);
	return exitStatus;
}
