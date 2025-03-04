#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "lexer.h"
#include "error_handler.h"
#include "token.h"
#include "tokenizer.h"

void lexical_analyzer(char *file_name){
	FILE* file = fopen(file_name, "r");

	if(!file){
		handle_file_doesnot_exist(file_name);
	}

	char buffer[32];
	int index = 0;
	char ch;
	bool in_comment = false;
	int line_number = 1;

	while((ch = fgetc(file)) != EOF ){
		if(in_comment){
			if (ch == '*' && (ch = fgetc(file)) == '/') {  
				in_comment = 0;
				continue;
			}

		}
		else if(ch == '/' && (ch = fgetc(file)) == '/'){
			while(ch != '\n' && ch != EOF){
				ch = fgetc(file);
			}
			continue;
		}
		else if(ch == '/' && (ch = fgetc(file)) == '*'){
			in_comment = true;
			continue;
		}
		else if(isalnum(ch)){
			buffer[index++] = ch;
		} 
		else {
			buffer[index] = '\0';
			struct Token token = tokenize(buffer, line_number);
			printf("Token: %-12s Type: %d\n", token.value, token.type);
			memset(buffer, 0, sizeof(buffer)); 
			index = 0;
		}

		line_number++;
	}

	fclose(file);
}

