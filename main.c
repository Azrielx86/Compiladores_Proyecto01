#include "symbol_table.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	char strings[][8] = {"Hola", "Mundo", "Esto", "Es", "Una", "Lista", "De", "Strings"};
	unsigned int hashes[8];

	for (int i = 0; i < 8; i++)
		hashes[i] = hashString(strings[i]);

	for (int i = 0; i < 8; i++)
	{
		printf("Word: %s\n", strings[i]);
		printf("Hash: %u\n\n", hashes[i]);
	}

	return 0;
}