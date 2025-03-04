enum TokenType{
	T_KEYWORD,
	T_OPERATOR,
	T_IDENTIFIER,
	T_STRING,
	T_NUMBER
};

struct Token{
	TokenType type;
	char value[32];
};
