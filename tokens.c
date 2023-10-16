#include "tokens.h"
#include <stdio.h>

Tokens *allocTokensTable(Tokens *tok_table)
{
	tok_table = malloc(sizeof(Tokens));
	tok_table->count = 0;
	return tok_table;
}

void freeTokensTable(Tokens *tok_table) { free(tok_table); }

void insertToken(Tokens *tok_table, int clase, int item)
{
	tok_table->table[tok_table->count][0] = clase;
	tok_table->table[tok_table->count][1] = item;
	tok_table->count++;
}

void printTokenTable(Tokens *tok_table)
{
	printf("==== Tabla de tokens ====\nItem\tValue\n");
	for (int i = 0; i < tok_table->count; i++)
		printf("(%d,%d)\n", tok_table->table[i][0], tok_table->table[i][1]);
}
