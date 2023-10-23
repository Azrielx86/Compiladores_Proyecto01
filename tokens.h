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
 * @param tok_table
 * @return
 */
Tokens *allocTokensTable(Tokens *tok_table);

/**
 * @param tok_table
 */
void freeTokensTable(Tokens *tok_table);

/**
 * @param tok_table
 * @param line
 * @param item
 */
void insertToken(Tokens *tok_table, int clase, int item);

/**
 * @param tok_table
 */
void printTokenTable(Tokens *tok_table);

#endif
