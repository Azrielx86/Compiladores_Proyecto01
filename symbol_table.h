#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__

typedef struct Symbols
{
	int index, currentSize;
	unsigned int *table;
} Symbols;

Symbols *allocTable();
Symbols *reallocTable(Symbols* table);
void freeTable(Symbols *table);
int search(Symbols *table, char *token);
void insert(Symbols *table, char *token);
void printTable(Symbols* table);


unsigned int hashString(char* string);

#endif
