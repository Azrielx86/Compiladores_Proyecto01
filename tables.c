#include "tables.h"
#include <stdlib.h>
#include <string.h>

int insertConstant(Constants *const_table, float item)
{
	const_table->table[const_table->count] = item;
	const_table->count++;
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

// =============================================================================
Strings *allocStringsTable()
{
	Strings *table;
	table = malloc(sizeof(Strings));
	table->count = 0;
	return table;
}

void freeStringsTable(Strings *str_table)
{
	for (int i = 0; i < str_table->count; i++)
		free(str_table->strings[i]);
	free(str_table);
}

int insertString(Strings *str_table, char *item)
{
	str_table->strings[str_table->count] = malloc(sizeof(char) * 40);
	strcpy(str_table->strings[str_table->count], item);
	str_table->count++;
	return str_table->count - 1;
}

void printStringsTable(Strings *str_table)
{
	printf("==== Tabla de cadenas ====\nItem\tValue\n");
	for (int i = 0; i < str_table->count; i++)
		printf("%d\t%s\n", i, str_table->strings[i]);
}
