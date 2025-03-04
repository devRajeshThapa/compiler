#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "tokenizer.h"
#include "token.h"
#include "error_handler.h"

const char *keywords[] = {"int", "string", "if", "else", "while", "break", "continue", "switch", "for", "return"};

bool is_keyword(char* buffer){
	int keyword_count = sizeof(keywords)/sizeof(keywords[0]);

	for(int i=0; i<keyword_count; i++){
		if(strcmp(buffer, keywords[i]) == 0){
			return true;
		}
	}

	return false;
}

struct Token tokenize(char *buffer, int line_number){	
	struct Token token;
	strcpy(token.value, buffer);

	if(buffer[0] == '"' && buffer[strlen(buffer)-1] == '"'){
		token.type = T_STRING;
	}else if(is_keyword(buffer)){
		token.type = T_KEYWORD;
	}else if(strchr(OPERATORS, buffer[0])){
		token.type = T_OPERATOR;
	}else if(strchr(DELIMITERS, buffer[0])){
		token.type = T_DELIMITER;	
	}else if(isalpha(buffer[0])){
		token.type = T_IDENTIFIER;
	}else if(isdigit(buffer[0])){
		token.type = T_NUMBER;
	}else{
		handle_unexpected_token(buffer, line_number);
	}

	return token;
}

