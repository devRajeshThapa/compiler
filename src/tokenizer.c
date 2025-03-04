#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "tokenizer.h"
#include "token.h"
#include "error_handler.h"

bool is_keyword(char* buffer){
	char *keywords[] = {"int", "string", "bool", "if", "else", "return", "while"};
	int keyword_count = 7;

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

	if(is_keyword(buffer)){
		token.type = T_KEYWORD;
	}else if(strchr("+-*=<>", buffer[0])){
		token.type = T_OPERATOR;
	}else if(buffer[0] == '"' && buffer[strlen(buffer)-1] == '"'){
		token.type = T_STRING;
	}else if(isalpha(buffer[0])){
		token.type = T_IDENTIFIER;
	}else if(isdigit(buffer[0])){
		token.type = T_NUMBER;
	}else{
		handle_unexpected_token(buffer, line_number);
	}

	return token;
}

