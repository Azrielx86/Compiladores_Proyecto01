#ifndef ERRORS_H_
#define ERRORS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Define un error, incluyendo la línea donde se encuentra
 * y el valor detectado.
 */
typedef struct Error
{
	int line;
	char *value;
} Error;

/**
 * @brief Define una tabla de errores, en la que se almacenan los
 * errores detectados
 */
typedef struct ErrorsTable
{
	int count;
	Error errors[100];
} ErrorsTable;

/**
 * @brief Aloja espacio en memoria para crear la tabla de errores
 * 
 * @return ErrorsTable* Puntero a una tabla de errores.
 */
ErrorsTable *allocErrorsTable();

/**
 * @brief Inserta un valor en la tabla de errores.
 * 
 * @param table Tabla de errores.
 * @param line Línea donde se encuentra el error.
 * @param value Valor del error.
 */
void insertErrorsTable(ErrorsTable *table, int line, char *value);

/**
 * @brief Imprime la tabla de errores en stdout.
 * 
 * @param table Tabla de errores.
 */
void printErrorsTable(ErrorsTable *table);

/**
 * @brief Libera la memoria ocupada por la tabla de errores.
 * 
 * @param table Tabla de errores.
 */
void freeErrorsTable(ErrorsTable *table);

#endif
