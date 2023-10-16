CC = clang
FLAGS = -DDEBUG -g -Wall
#A simple makefile for building Flex / Bison template

all: lexer

lexer: lex.yy.c utils
	$(CC) lex.yy.c *.o $(FLAGS) -o lexer

lex.yy.c: lexer.l
	flex lexer.l

utils:
	$(CC) -c $(FLAGS) tables.c utils.c clases.c

clean:
	rm *.yy.c
	rm *.o
	rm lexer