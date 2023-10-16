%{
#include <stdio.h>
#include "utils.h"
#include "tables.h"
#include "clases.h"

Constants* constantes;

%}

%option noyywrap
%option yylineno

MAYUS           [A-Z]
MINUS           [a-z]
DIG             [0-9]


/* 0. Palabras reservadas */
P_RESV          cadena|caracter|else|entero|for|if|real|return|void|while
/* 1. Operadores aritméticos */
OP_ARITH        [+\-*/$]
/* 2. Operadores de asignación */
OP_ASIG         ({OP_ARITH}|\?)?~
/* 3. Simbolos especiales */
SIMB_ESP        [\(\)\{\}\[\]&,;]
/* 4. Operadores relacionales */
OP_RELAC        ((\^\^|\^\"|=)=?)|<>
/* 5. Identificadores */
INDENTIf        ({MAYUS}|{MINUS})({MAYUS}|{MINUS}|{DIG}){0,4}_
INV_IDENT       {MAYUS}|{MINUS})({MAYUS}|{MINUS}|{DIG}
/* 6. Constantes numericas */
INT_CONST       (-?){DIG}{1,6}
/* 7. Constantes numericas reales */
FLT_CONST       {DIG}*\.{DIG}*
/* 8. Constantes cadena */
CADENA          \"(.){2,38}\"
/* 9. Constantes caracter */
CARACTER        \'(.)\'

ESPACIO         [[:space:]]+

%%

{P_RESV}        {
                    int id = buscar_valor(palabras_reservadas, palabras_reservadas_size, yytext);
                    if (id == -1)
                        fprintf(yyout, "[WARNING] - Palabra reservada no encontrada: %s", yytext);
                    fprintf(yyout, "(%d)[Palabra reservada: %s - ID: %d]\n", yylineno, yytext, id); 
                }

{OP_ARITH}      { 
                    fprintf(yyout, "(%d)[Operador aritmetico: %s]\n", yylineno, yytext);
                }

{OP_ASIG}       { fprintf(yyout, "(%d)[Operador de asignacion: %s]\n", yylineno, yytext); }

{SIMB_ESP}      {
                    fprintf(yyout, "(%d)[Simbolo especial: %s]\n", yylineno, yytext);
                }

{OP_RELAC}      {
                    fprintf(yyout, "(%d)[Operador relacional: %s]\n", yylineno, yytext);
                }

{INV_IDENT}     {
                    fprintf(yyout, "(%d)[Identificador inválido: %s]\n", yylineno, yytext);
                }

{INDENTIf}      { 
                    fprintf(yyout, "(%d)[Identificador: %s]\n", yylineno, yytext);
                }

{FLT_CONST}     {
                    fprintf(yyout, "(%d)[Constante numerica flotante: %s]\n", yylineno, yytext);
                    // insertConstant(constantes, atoi(yytext));
                }

{INT_CONST}     {
                    fprintf(yyout, "(%d)[Constante numerica: %d (Convertido de: %s)]\n", yylineno, atoi(yytext), yytext);
                    insertConstant(constantes, atoi(yytext));
                }

{CADENA}        {
                    fprintf(yyout, "(%d)[Cadena: %s]\n", yylineno, yytext);
                }

{CARACTER}        {
                    fprintf(yyout, "(%d)[Caracter: %s]\n", yylineno, yytext);
                }

\n              { }

{ESPACIO}       { }

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