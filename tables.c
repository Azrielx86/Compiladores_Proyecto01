#include "tables.h"

void insertConstant(Constants *const_table, float item) {
    const_table->table[const_table->count] = item;
    const_table->count++;
#ifdef DEBUG
    printf("\n [DEBUG] [Tabla de Constantes] Item insertado\n\t[%d] -> %f\n\n", const_table->count, item);
#endif
}

Constants *allocConstantsTable(Constants *const_table) {
    const_table = malloc(sizeof(Constants));
    const_table->count = 0;
    return const_table;
}

void freeConstantsTable(Constants *const_table) { free(const_table); }

void printConstantsTable(Constants *const_table) {
    printf("==== Tabla de constantes ====\nItem\tValue\n");
    for (int i = 0; i < const_table->count; i++)
        printf("%d\t%f\n", i, const_table->table[i]);
}

Tokens *allocTokensTable(Tokens *tok_table)
{
	tok_table = malloc(sizeof(Tokens));
	tok_table->count = 0;
	return tok_table;
}

void freeTokensTable(Tokens *tok_table) { free(tok_table); }

void insertToken(Tokens *tok_table, int line, int item)
{
	tok_table->table[tok_table->count][0] = line;
	tok_table->table[tok_table->count][1] = item;
	tok_table->count++;
}
