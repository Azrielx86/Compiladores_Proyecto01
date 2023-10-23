#include "clases.h"
#include <string.h>

int buscar_valor(const char *clase[], const int table_size, const char *valor)
{
	for (int i = 0; i < table_size; ++i)
		if (strcmp(clase[i], valor) == 0)
			return i;
	return -1;
}
