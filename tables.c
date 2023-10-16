#include "tables.h"
#include <stdlib.h>
#include <string.h>

int insertConstant(Constants *const_table, float item)
{
	const_table->table[const_table->count] = item;
	const_table->count++;
#ifdef DEBUG
	printf("\n [DEBUG] [Tabla de Constantes] Item insertado\n\t[%d] -> %f\n\n", const_table->count, item);
#endif
	return const_table->count - 1;
}

Constants *allocConstantsTable(Constants *const_table)
{
	const_table = malloc(sizeof(Constants));
	const_table->count = 0;
	return const_table;
}

void freeConstantsTable(Constants *const_table) { free(const_table); }

void printConstantsTable(Constants *const_table)
{
	printf("==== Tabla de constantes ====\nItem\tValue\n");
	for (int i = 0; i < const_table->count; i++)
		printf("%d\t%f\n", i, const_table->table[i]);
}

// =============================================================================
void *allocLiteralsTable()
{
	Literals *table;
	table = malloc(sizeof(Literals));
	table->count = 0;
	return table;
}

int findLiteral(Literals *lit_table, char *item)
{
	for (int i = 0; i < lit_table->count; ++i)
		if (strcmp(lit_table->table[i], item) == 0)
			return i;
	return -1;
}

int insertLiteral(Literals *lit_table, char *item)
{
	int idx = findLiteral(lit_table, item);
	if (idx != -1) return idx;
	lit_table->table[lit_table->count] = malloc(sizeof(char) * 8);
	strcpy(lit_table->table[lit_table->count], item);
	lit_table->type[lit_table->count] = -1;
	lit_table->count++;
	return lit_table->count - 1;
}

void freeLiteralsTable(Literals *lit_table)
{
	for (int i = 0; i < lit_table->count; i++)
		free(lit_table->table[i]);
	free(lit_table);
}

void printLiteralsTable(Literals *lit_table)
{
	printf("==== Tabla de literales ====\nItem\tValue\tTipo\n");
	for (int i = 0; i < lit_table->count; i++)
		printf("%d\t%s\t%d\n", i, lit_table->table[i], lit_table->type[i]);
}
