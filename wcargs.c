#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UNUSED __attribute__((unused))

int main(UNUSED int argc, UNUSED char *argv[]){
	int opt;
	bool doChar, doLine, doWord, haveFlag;

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
	}

	if (doLine){
		printf("Counting lines \n");
	}

	if (doWord){
		printf("Counting words \n");
	}
	
	if (doChar){
		printf("Counting characters \n");
	}
	

	//printf("%d\n", optind);
	//printf("%d\n", argc);
	if(optind == argc){
		//0 files given, no non-option arguments provided
		printf("Processing standard input and no total line \n");
	}

	if(argc == (optind + 1)){
		// just one file
		printf("Processing %s and no total line \n",argv[optind]);
	}
	
	if (argc > (optind + 1)){
	printf("Processing ");

	while (argv[optind] != NULL){
		printf("%s,", argv[optind]);
		optind++;

	}
	printf("and a total line\n");
	}
	/*
	for (int index = 1; index < argc; index++){
		
		printf("<%s>,", argv[index]);
	
	}
	printf("and a total line\n");
	}
	*/
	//now i want to process files
	//optind is an index, if there is a file optind is always one more than argc
	//argc is the number of arguments


	return EXIT_SUCCESS;
}
