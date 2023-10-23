CC = clang
FLEX = flex
# -g : Información de debug.
# -gdwarf-4 : Para utilizar valgrind y clang.
# -Wall : Para advertencias adicionales
FLAGS = -g -gdwarf-4 -Wall

all: lexer

lexer: lex.yy.c utils
	$(CC) lex.yy.c *.o $(FLAGS) -o lexer

lex.yy.c: lexer.l
	$(FLEX) lexer.l

utils:
	$(CC) -c $(FLAGS) tables.c utils.c clases.c tokens.c errors.c

clean:
	rm *.yy.c
	rm *.o
	rm lexer