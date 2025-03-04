#include <stdio.h>
#include <stdlib.h>

#include "lexical_analyzer.h"
#include "error_handler.h"

void lexical_analyzer(char *file_name){
	FILE* file = fopen(file_name, "r");

	if(!file){
		handle_file_doesnot_exist(file_name);
	}
}
