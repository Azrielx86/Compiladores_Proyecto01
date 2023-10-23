#ifndef ERRORS_H_
#define ERRORS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Error
{
	int line;
	char *value;
} Error;

typedef struct ErrorsTable
{
	int count;
	Error errors[100];
} ErrorsTable;

ErrorsTable *allocErrorsTable();
void insertErrorsTable(ErrorsTable *table, int line, char *value);
void printErrorsTable(ErrorsTable *table);
void freeErrorsTable(ErrorsTable *table);

#endif
