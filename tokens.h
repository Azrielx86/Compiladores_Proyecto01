#ifndef TOKENS_H
#define TOKENS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

/**
 * Estructura para la tabla de tokens.
 * Se almacenan de la forma [clase, valor]
 */
typedef struct Tokens
{
	int table[MAX_ITEMS][2];
	int count;
} Tokens;

/**
 * @brief Aloja memoria para almacenar la tabla de tokens.
 * @param tok_table
 * @return
 */
Tokens *allocTokensTable(Tokens *tok_table);

/**
 * @brief Libera la memoria utilizada por la tabla de tokens.
 * @param tok_table
 */
void freeTokensTable(Tokens *tok_table);

/**
 * @brief Inseta un token en la tabla de tokens.
 * @param tok_table Tabla de tokens.
 * @param clase Clase del token.
 * @param item Valor del token.
 */
void insertToken(Tokens *tok_table, int clase, int item);

/**
 * @brief Imprime la tabla de tokens en stdout.
 * @param tok_table
 */
void printTokenTable(Tokens *tok_table);

/**
 * @brief Guarda la tabla de tokens en el archivo tokens.csv
 * @param tok_table
 */
void guardarArchivoTokens(Tokens *tok_table);

#endif
