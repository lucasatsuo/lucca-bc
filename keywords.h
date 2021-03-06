#define KEYWORD_ARR_SIZE 4

enum{
	QUIT = 2048, EXIT, BYE, LOGOUT
};

//nota do editor: eu removi o nulo ^ pq tava dando problema 

extern char *keyword[KEYWORD_ARR_SIZE];

/** FUNCTION: iskeyword
 * INPUT: const char*
 * OUTPUT: int
 * DESCRIPTION: checks if the given string
 * is one of the keywords (QUIT|EXIT|BYE|LOGOUT)
 * if so, it returns the token associated with the keyword
 * otherwise it returns 0
 **/
int iskeyword(const char* symbol);