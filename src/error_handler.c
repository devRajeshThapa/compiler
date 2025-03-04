#include <stdio.h>
#include <stdlib.h>
#include "error_handler.h"

void handle_no_argument(){
	printf("Error: No argument \n");
	printf("Usage: lync <your_program_name.ly> \n");
	printf("Try: lync -h or lync --help \n");
	exit(EXIT_FAILURE);
}

void handle_invalid_argument(){
	printf("Error: Invalid argument \n");
	printf("Usage: lync <your_program_name.ly> \n");
	printf("Try: lync -h or lync --help \n");
	exit(EXIT_FAILURE);
}

void handle_file_doesnot_exist(char *file_name){
	printf("Error: File with the name %s doesn't exist in this directory  \n", file_name);
	printf("Try: lync -h or lync --help \n");
	exit(EXIT_FAILURE);

}

void handle_unexpected_token(char *buffer, int line_number){
	printf("Error: Unexpected token %s at line number %d \n", buffer, line_number);
}
