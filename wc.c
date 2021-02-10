#include <stdio.h>
#include <stdlib.h>
#include "stsplit.h"
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define UNUSED __attribute__((unused))

void printLWC(char *name, bool flags[], long counts[]){
//printing what you get from countLWC
//name is the file name we are giving it
//flags are the 3 flags we could specify, l w c
//counts could be lines, words, characters
	
	
	if(flags[0]){
		printf("%8ld ", counts[0]);
	}
	if(flags[1]){
		printf("%8ld ", counts[1]);
	}
	
	if(flags[2]){
		printf("%8ld ", counts[2]);
	}
	printf("%s\n", name); 
}

void countLWC(FILE *fd, long *nl, long *nw, long *nc){
	//do actual work to find lines,words,chars
	
	int numberLines = 0;
	int numberWords = 0;
	int numberCharacters = 0;
	char buf[BUFSIZ];
	char ** characterArray;

	while(fgets(buf, sizeof buf, fd) != NULL){
		numberLines++;
	characterArray = stsplit(buf);

	//stfree(characterArray);

	numberCharacters += strlen(buf);
	
	for(int index = 0; characterArray[index] != NULL; index++){
		numberWords++;
	}

	*nl = numberLines;
	*nw = numberWords;
	*nc = numberCharacters;

}
}


int main(UNUSED int argc, UNUSED char *argv[]){
	int opt;
	bool doChar, doLine, doWord, haveFlag;
	long numLines = 0L;
	long numWords = 0L;
	long numChars = 0L;
	bool flags[3] = {true,true,true};



	long counts[3] = {numLines, numWords, numChars};
	

	doChar = doLine = doWord = haveFlag = false;
	opterr = 0; 
	while ((opt = getopt(argc, argv, "clw")) != -1){
		switch(opt){
			case 'c': doChar = haveFlag = true;break;
			case 'l': doLine = haveFlag = true;break;
			case 'w': doWord = haveFlag = true;break;
			default: fprintf(stderr, "%s: illegal option, '-%c'\n", argv[0], optopt);
		}
	}

	if (! haveFlag){
		doChar = doLine = doWord = true;
		/*
		countLWC(fp,&numLines,&numWords,&numChars);
		counts[0] = numLines;
		counts[1] = numWords;
		counts[2] = numChars;
		printLWC(argv[optind], flags, counts);
		*/
	}

	if (!doLine){
		//i think i need to change logic here		
		flags[0] = doLine; 
	}

	if (!doWord){
		flags[1] = doWord;
	}
	
	if (!doChar){
		flags[2] = doChar;
	}

	/*
	countLWC(fp,&numLines,&numWords,&numChars);
	counts[0] += numLines;
	counts[1] += numWords;
	counts[2] += numChars;
	printLWC(argv[optind],flags,counts);
	*/


	//printf("%d\n", optind);
	//printf("%d\n", argc);
	if(optind == argc){
		//0 files given, no non-option arguments provided	
		countLWC(stdin,&numLines,&numWords,&numChars);
		counts[0] += numLines;
		counts[1] += numWords;
		counts[2] += numChars;
		printLWC(" ",flags,counts);
	}

	if(argc == (optind + 1)){
		// just one file
		FILE *file;
		file = fopen(argv[optind],"r");

		if(strcmp(argv[optind],"-") == 0){
			countLWC(stdin,&numLines,&numWords,&numChars);
		}
else{



		if(file == NULL){
			printf("open(%s) error\n", argv[optind]);
			return EXIT_FAILURE;
		}

		countLWC(file,&numLines,&numWords,&numChars);
		counts[0] += numLines;
		counts[1] += numWords;
		counts[2] += numChars;
}

		printLWC(argv[optind],flags,counts);
	}

	if (argc > (optind + 1)){
		//if I have multiple files
		//include total for flags specified
		long totalL = 0L;
		long totalW = 0L;
		long totalC = 0L;

	while (argv[optind] != NULL){
		FILE *file;
		file = fopen(argv[optind], "r");


	if(strcmp(argv[optind],"-") == 0){
			countLWC(stdin,&numLines,&numWords,&numChars);
			counts[0] = numLines;
			counts[1] = numWords;
			counts[2] = numChars;
			totalL += counts[0];
			totalW += counts[1];
			totalC += counts[2];
			printLWC(argv[optind],flags,counts);
			optind++;
		}

	else{


		if(file == NULL){
			printf("open(%s) error\n",argv[optind]);
			return EXIT_FAILURE;
		}

		countLWC(file,&numLines,&numWords,&numChars);
		counts[0] = numLines;
		counts[1] = numWords;
		counts[2] = numChars;

		totalL += counts[0];
		totalW += counts[1];
		totalC += counts[2];

	
		printLWC(argv[optind], flags, counts);
		optind++;
		}
	}

	if(flags[0]){
		printf("%8ld ",totalL);
	}
	if(flags[1]){
		printf("%8ld ",totalW);
	}
	if(flags[2]){
		printf("%8ld ",totalC);
	}
	printf("total\n");
	}
	
}

