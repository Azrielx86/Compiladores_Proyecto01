%{
#include <stdio.h>
#include "utils.h"
#include "tables.h"

Constants* constantes;

%}

%option noyywrap
%option yylineno

MAYUS           [A-Z]
MINUS           [a-z]
DIG             [0-9]

/* Palabras reservadas */
/* Operadores aritméticos */
OP_ARITH        [+\-*/$]
/* Operadores de asignación */
OP_ASIG         ({OP_ARITH}|\?)?~
/* Simbolos especiales */
/* Operadores relacionales */
/* Identificadores */
INDENTIf        ({MAYUS}|{MINUS})({MAYUS}|{MINUS}|{DIG}){0,4}_

/* Constantes numericas */
INT_CONST       [-?]{DIG}+

/* TODO: Probablemente para esta sección sea necesario crear regex para cada palabra reservada */
P_RESV          cadena|caracter|else|entero|for|if|real|return|void|while

ESPACIO         [[:space:]]+

%%

{P_RESV}        {
                    fprintf(yyout, "(%d)[Palabra reservada: %s]\n", yylineno, yytext); 
                }

{OP_ARITH}      { 
                    fprintf(yyout, "(%d)[Operador aritmetico]\n", yylineno);
                }

{OP_ASIG}       { fprintf(yyout, "(%d)[Operador de asignacion]\n", yylineno); }

{INDENTIf}      { 
                    fprintf(yyout, "(%d)[Identificador: %s]\n", yylineno, yytext);
                }

{INT_CONST}     {
                    fprintf(yyout, "(%d)[Constante numerica: %d]\n", yylineno, atoi(yytext));
                    insertConstant(constantes, atoi(yytext));
                }

{ESPACIO}       { }
\n              { }

.               {
                    fprintf(yyout, "(%d)[Item no válido: %s]\n", yylineno, yytext);
                }

%%

int main()
{
    // =================== Inicializacion de las tablas ========================
    // ===== Tabla de constantes
    constantes = allocConstantsTable(constantes);


    yyin = fopen("text.txt", "r");
    yylex();

    // ====================== Impresion de las tablas ==========================
    printf("\n\n");
    printConstantsTable(constantes);
    freeConstantsTable(constantes);

    return 0;
}