#include <stdio.h>
#include <stdlib.h>
#include "error_handler.h"

void handle_no_argument(){
	printf("Error: No input files \n");
	printf("Usage: lync <lyn_file.ly> \n");
	printf("Try: lync -h or lync --help \n");
	exit(EXIT_FAILURE);
}

void handle_invalid_argument(){
	printf("Usage: lync <lyn_file.ly> \n");
	printf("Try: lync -h or lync --help \n");
	exit(EXIT_FAILURE);
}
