#define KEYWORD_ARR_SIZE 5

enum{
	QUIT = 2048, EXIT, BYE, LOGOUT
};

extern char *keyword[KEYWORD_ARR_SIZE];

int iskeyword(const char* symbol);