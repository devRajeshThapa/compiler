#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error_handler.h"
#include "lexical_analyzer.h"

int main(int argc, char *argv[]){
	if(argc < 2){
		handle_no_argument();
	}

	if(argc > 2){
		handle_invalid_argument();
	}

	char *arg = argv[1];
	int arg_len = strlen(arg);

	if(strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0){
		//get_help();
	}else if(arg[arg_len-2] == 'l' || arg[arg_len-1] == 'y'){
		lexical_analyzer(arg);
	}else{
		handle_invalid_argument();
	}

	return 0;
}
