#ifndef TABLES_H_
#define TABLES_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

/**
 * Estructura para la tabla de literales.
 * TODO : Completar los métodos para esta estructura.
 */
typedef struct Literals
{
	char *table[MAX_ITEMS];
	int count;
} Literals;

void insert_literal(Literals *lit_table, char *item);

/**
 * Estructura para la tabla de constantes, únicamente tiene la tabla y
 * un contador.
 */
typedef struct Constants
{
	float table[MAX_ITEMS];
	int count;
} Constants;

/**
 * Aloja espacio en memoria para la tabla de constantes.
 * @param const_table puntero a una tabla de constantes.
 * @return puntero a la nueva dirección de memoria.
 */
Constants *allocConstantsTable(Constants *const_table);

/**
 * Libera la tabla de constantes.
 */
void freeConstantsTable(Constants *const_table);

/**
 * Inserta un item en la tabla de constantes
 */
void insertConstant(Constants *const_table, float item);

/**
 * Imprime en pantalla la tabla de constantes
 */
void printConstantsTable(Constants *const_table);

/**
 * Estructura para la tabla de tokens.
 * Se almacenan de la forma [clase, valor]
 * TODO : Completar los métodos para esta estructura.
 */
typedef struct Tokens
{
	int table[MAX_ITEMS][2];
	int count;
} Tokens;

/**
 * TODO
 * @param tok_table
 * @return
 */
Tokens *allocTokensTable(Tokens *tok_table);

/**
 * TODO
 * @param tok_table
 */
void freeTokensTable(Tokens *tok_table);

/**
 * TODO
 * @param tok_table
 * @param line
 * @param item
 */
void insertToken(Tokens *tok_table, int line, int item);

/**
 * TODO
 * @param tok_table
 */
void printTokenTable(Tokens *tok_table);

#endif
