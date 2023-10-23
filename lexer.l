%{
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "tables.h"
#include "clases.h"
#include "tokens.h"
#include "errors.h"

Constants* constantes;
Tokens* tokens;
Strings *stringsTable;
Literals *literals;
ErrorsTable* errorsTable;

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
SIMB_ESP        [\(\)\{\}\[\]&,:]
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
                    {
                        fprintf(yyout, "[WARNING] - Palabra reservada no encontrada: %s", yytext);
                    }
                    fprintf(yyout, "(%d)[Palabra reservada: %s - ID: %d]\n", yylineno, yytext, id);
                    insertToken(tokens, 0, id);
                }

{OP_ARITH}      {
                    fprintf(yyout, "(%d)[Operador aritmetico: %s]\n", yylineno, yytext);
                    insertToken(tokens, 1, (int)*yytext);
                }

{OP_ASIG}       { 
                    int id = buscar_valor(op_asignacion, op_asignacion_size, yytext);
                    if (id == -1)
                    {
                        fprintf(yyout, "[WARNING] - Operador de asignacion no encontrado: %s", yytext);
                    }
                    fprintf(yyout, "(%d)[Operador de asignacion: %s]\n", yylineno, yytext);
                    insertToken(tokens, 2, id);
                }

{SIMB_ESP}      {
                    fprintf(yyout, "(%d)[Simbolo especial: %s]\n", yylineno, yytext);
                    insertToken(tokens, 3, (int)*yytext);
                }

{OP_RELAC}      {
                    int id = buscar_valor(op_relacional, op_relacional_size, yytext);
                    if (id == -1)
                    {
                        fprintf(yyout, "[WARNING] - Operador relacional no encontrado: %s", yytext);
                    }
                    fprintf(yyout, "(%d)[Operador relacional: %s]\n", yylineno, yytext);
                    insertToken(tokens, 4, id);
                }

{INV_IDENT}     {
                    fprintf(yyout, "(%d)[Identificador inválido: %s]\n", yylineno, yytext);
                    insertErrorsTable(errorsTable, yylineno, yytext);
                }

{INDENTIf}      { 
                    fprintf(yyout, "(%d)[Identificador: %s]\n", yylineno, yytext);
                    int id = insertLiteral(literals, yytext);
                    insertToken(tokens, 5, id);
                }

{FLT_CONST}     {
                    fprintf(yyout, "(%d)[Constante numerica flotante: %s]\n", yylineno, yytext);
                    // insertConstant(constantes, atoi(yytext));
                    insertToken(tokens, 7, 888);
                }

{INT_CONST}     {
                    fprintf(yyout, "(%d)[Constante numerica: %d (Convertido de: %s)]\n", yylineno, atoi(yytext), yytext);
                    int id = insertConstant(constantes, atoi(yytext));
                    insertToken(tokens, 6, id);
                }

{CADENA}        {
                    fprintf(yyout, "(%d)[Cadena: %s]\n", yylineno, yytext);
                    int idx = insertString(stringsTable, yytext);
                    insertToken(tokens, 8, idx);
                }

{CARACTER}      {
                    fprintf(yyout, "(%d)[Caracter: %s]\n", yylineno, yytext);
                    int idx = insertString(stringsTable, yytext);
                    insertToken(tokens, 9, idx);
                }

\n              { }

{ESPACIO}       { }

.               {
                    fprintf(yyout, "(%d)[Item no válido: %s]\n", yylineno, yytext);
                    insertErrorsTable(errorsTable, yylineno, yytext);
                }

%%

int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Uso: %s <nombre_del_archivo>\n", argv[0]);
        return 1; // Terminar el programa con código de error
    }

    // =================== Inicializacion de las tablas ========================
    // ===== Tabla de constantes
    constantes = allocConstantsTable(constantes);
    tokens = allocTokensTable(tokens);
    stringsTable = allocStringsTable();
    literals = allocLiteralsTable();
    errorsTable = allocErrorsTable();
    
    /*yyin = fopen("text.txt", "r");*/
    yyin = fopen(argv[1], "r");
    if (yyin == NULL){
        perror("Error al abrir el archivo");
        return 1; // Terminar el programa con código de error
    }
    yylex();

    // ====================== Impresion de las tablas ==========================
    printf("\n\n");
    printConstantsTable(constantes);
    printLiteralsTable(literals);
    printTokenTable(tokens);
    printErrorsTable(errorsTable);
    printStringsTable(stringsTable);

    freeConstantsTable(constantes);
    freeTokensTable(tokens);
    freeLiteralsTable(literals);
    freeErrorsTable(errorsTable);
    freeStringsTable(stringsTable);

    return 0;
}