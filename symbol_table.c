#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Symbols *allocTable()
{
	Symbols *symbolTable = malloc(sizeof(Symbols));
	symbolTable->table = malloc(sizeof(unsigned int) * 100);
	symbolTable->currentSize = 100;
	symbolTable->index = 0;
	return symbolTable;
}

/**
 * @brief Función para obtener el hash de una cadena
 *
 * Fuente: http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned int hashString(char *string)
{
	unsigned int hash;
	char c;

	while ((c = *string++))
		hash = ((hash << 5) + hash) + c;

	hash = hash << 2;

	return hash;
}

// void freeTable(Symbols *table);
// int search(Symbols *table, char *token);
void insert(Symbols *table, char *token)
{
	table->table[table->index] = hashString(token);
	table->index++;
}

void printTable(Symbols *table)
{
	for (int i = 0; i < table->index; i++)
		printf("[%d, %u]\n", i, table->table[i]);
}