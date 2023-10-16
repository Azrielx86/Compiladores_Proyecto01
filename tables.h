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
	int type[MAX_ITEMS];
	int count;
} Literals;

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
int insertConstant(Constants *const_table, float item);

/**
 * Imprime en pantalla la tabla de constantes
 */
void printConstantsTable(Constants *const_table);

// =============================================================================
void *allocLiteralsTable();
int findLiteral(Literals *lit_table, char *item);
int insertLiteral(Literals *lit_table, char *item);
void freeLiteralsTable(Literals *lit_table);
void printLiteralsTable(Literals* lit_table);

#endif
