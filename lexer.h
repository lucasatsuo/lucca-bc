#define MAXIDLEN 63

/** FUNCTION: skipspaces
 * INPUT: FILE*
 * OUTPUT: void
 * DESCRIPTION: skipspaces advances the file pointer
 * to the first non-space char **/
void skipspaces(FILE *tape);

/** FUNCTION: gettoken
 * INPUT: FILE*
 * OUTPUT: int (token)
 * DESCRIPTION: gettoken will read the tape
 * trying to classify a substring as one of the tokens
 * using functions that abstract automatas **/
int gettoken(FILE *tape);

/** FUNCTION: isID
 * INPUT: FILE*
 * OUTPUT:int (token)
 * DESCRIPTION: if the substring read in the input tape
 * matches the following regular expression, return the
 * ID token defined in tokens.h 
 * REGEX: [a-zA-Z][a-zA-Z0-9_]* **/
int isID(FILE *tape);

/** FUNCTION: isNUM
 * INPUT: FILE*
 * OUTPUT:int (token)
 * DESCRIPTION: if the substring read in the input tape
 * matches one of the following regular expressions, 
 * return the appropriate token defined in tokens.h 
 * REGEX:  **/
int isNUM(FILE *tape);

/** FUNCTION: chk_Exp
 * INPUT:FILE *, int
 * OUTPUT: int
 * DESCRIPTION: if the substring read in the input
 * matches the exp regex it will return the new position for
 * lexeme, otherwise it returns the old position
 * REGEX:[Ee][/+/-]?[0-9]+ **/
int chk_Exp(FILE* tape, int i0);

/** Function: clearLexeme
 * INPUT: void
 * OUTPUT:void
 * DESCRIPTION: this function makes all chars in lexeme
 * turn to 0 **/
void clearLexeme(void);