extern int lookahead;
extern char lexeme[MAXIDLEN + 1];
extern FILE* source;

/** FUNCTION: match
 * INPUT: int (expected token)
 * OUTPUT: void
 * DESCRIPTION: match compares the token stored on lookahead
 * against a provided expected token. If it matches it loads the next token
 * otherwise it stops with an error **/

void match (int expected);

void expr(void);

void fact(void);

void exec_negate(void);

void mybc(void);

int cmdquit();

int cmdsep();

int is_FIRST_expr();