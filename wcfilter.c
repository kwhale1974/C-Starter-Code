#include <stdio.h>
#include <stdlib.h>
#include "stsplit.h"
#include <string.h>
#define UNUSED __attribute__((unused))

void countLWC(FILE *fd, long *nl, long *nw, long *nc){
	//do actual work to find lines,words,chars
	

	int numberLines = 0;
	int numberWords = 0;
	int numberCharacters = 0;
	char buf[BUFSIZ];
	char ** characterArray;

	while (fgets(buf, sizeof buf, fd) != NULL){
		numberLines++;
	characterArray  = stsplit(buf);

	stfree(characterArray);

	numberCharacters += strlen(buf);
	
	for(int index = 0; characterArray[index] != NULL; index++){
		numberWords++;
	}

	*nl = numberLines;
	*nw = numberWords;
	*nc = numberCharacters;

}
}

int main (UNUSED int arg, UNUSED char *argv[]){
	long nlines;
	int exitStatus = EXIT_SUCCESS;
	long numberWords;
	long numberCharacters;

	
	//passing countLWC addresses 
	countLWC(stdin, &nlines, &numberWords, &numberCharacters); //calling void funct, run all logic

	printf("%8ld%8ld%8ld\n", nlines, numberWords, numberCharacters);

	return exitStatus;
}
