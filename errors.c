#include "errors.h"
#include <stdlib.h>
#include <string.h>

ErrorsTable *allocErrorsTable()
{
	ErrorsTable *table;
	table = malloc(sizeof(ErrorsTable));
	table->count = 0;
	return table;
}

void insertErrorsTable(ErrorsTable *table, int line, char *value)
{
	Error *error = malloc(sizeof(Error));
	error->line = line;
	error->value = malloc(sizeof(char) * 32);
	strcpy(error->value, value);
	table->errors[table->count] = *error;
	free(error);
	table->count++;
}

void printErrorsTable(ErrorsTable *table)
{
	printf("==== Errores ====\n");
	for (int i = 0; i < table->count; i++)
		printf("Error: \t%s en la linea %d\n", table->errors[i].value, table->errors[i].line);
}

void freeErrorsTable(ErrorsTable *table)
{
	for (int i = 0; i < table->count; i++)
	{
		free(table->errors[i].value);
	}
	free(table);
}
