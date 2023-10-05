%{
#include <stdio.h>
#include "utils.h"
#include "symbol_table.h"

Symbols* symbolTable;

%}

%option noyywrap

MAYUS           [A-Z]
MINUS           [a-z]
DIG             [0-9]

/* Palabras reservadas */
/* Operadores aritméticos */
OP_ARITH        [+,\-,*,/,$]
/* Operadores de asignación */
OP_ASIG         ({OP_ARITH}|\?)?~
/* Simbolos especiales */
/* Operadores relacionales */
/* Identificadores */
INDENTIf        ({MAYUS}|{MINUS})({MAYUS}|{MINUS}|{DIG}){0,4}_
%%

{OP_ARITH}      { 
                    fprintf(yyout, "[Operador aritmético]"); 

                }

{OP_ASIG}       { fprintf(yyout, "[Operador de asignación]"); }

{INDENTIf}      { 
                    fprintf(yyout, "[Identificador: %s]", yytext); 
                    insert(symbolTable, yytext);
                }

%%

int main()
{
    say_hello();
    symbolTable = allocTable();
    yyin = fopen("text.txt", "r");
    yylex();
    printTable(symbolTable);
    return 0;
}