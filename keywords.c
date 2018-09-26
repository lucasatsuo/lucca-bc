#include <string.h>
#include <stdlib.h>
#include <keywords.h>

char *keyword[] = {
	"quit", "exit", "bye", "logout", NULL
};

int iskeyword(const char* symbol){
	//return i + 2048; YES
	//return 0; NO

	for (int i = 0; i < KEYWORD_ARR_SIZE; ++i){
		if (!strcmp(symbol,keyword[i])){
			return i + QUIT;
		}
	} 
	return 0;
}

