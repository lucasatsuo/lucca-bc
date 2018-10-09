mybc:	main.o parser.o lexer.o keywords.o stack.o symtable.o
	gcc main.o parser.o lexer.o keywords.o stack.o symtable.o -o mybc

lexer.o: lexer.c
	gcc -c lexer.c -I.

parser.o: parser.c
	gcc -c parser.c -I.

main.o: main.c
	gcc -c main.c -I.

keywords.o: keywords.c
	gcc -c keywords.c -I.

stack.o: stack.c
	gcc -c stack.c -I.

symtable.o: symtable.c
	gcc -c symtable.c -I.

clean:
	rm *.o
