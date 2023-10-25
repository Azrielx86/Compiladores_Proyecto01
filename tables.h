#ifndef TABLES_H_
#define TABLES_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

/**
 * Estructura para la tabla de literales.
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

typedef struct Strings
{
	int count;
	char *strings[MAX_ITEMS];
} Strings;

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
/**
 * @brief Aloja espacio en memoria para la tabla de literales.
 */
void *allocLiteralsTable();

/**
 * @brief Encuentra una de las literales, por si ya se ha añadido a la tabla.
 * 
 * @param lit_table Tabla de literales.
 * @param item Literal a buscar.
 * @return int Índice de la literal si se encuentra, -1 en caso contrario.
 */
int findLiteral(Literals *lit_table, char *item);

/**
 * @brief Inserta una literal en la tabla de literales.
 * 
 * @param lit_table Tabla de literales.
 * @param item Item a insertar.
 * @return int Índice donde se insertó el item.
 */
int insertLiteral(Literals *lit_table, char *item);

/**
 * @brief Libera el espacio en memoria ocupado por la tabla de literales.
 * 
 * @param lit_table Tabla de literales.
 */
void freeLiteralsTable(Literals *lit_table);

/**
 * @brief Imprime la tabla de literales en stdout.
 * 
 * @param lit_table Tabla de literales.
 */
void printLiteralsTable(Literals *lit_table);

// =============================================================================

Strings *allocStringsTable();

/**
 * Libera la tabla de cadenas.
 */
void freeStringsTable(Strings *str_table);

/**
 * Inserta un item en la tabla de cadenas.
 */
int insertString(Strings *str_table, char* item);

/**
 * Imprime en pantalla la tabla de cadenas.
 */
void printStringsTable(Strings *str_table);
#endif
