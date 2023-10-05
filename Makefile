CC = clang

#A simple makefile for building Flex / Bison template

lexer: lex.yy.c utils
	$(CC) lex.yy.c utils.o symbol_table.o -o lexer

lex.yy.c: lexer.l
	flex lexer.l

utils: utils.o symbol_table.o
	$(CC) -c utils.c -o utils.o
	$(CC) -c symbol_table.c -o symbol_table.o

clean:
	rm *.yy.c
	rm *.o
	rm lexer
	rm *.o