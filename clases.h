#ifndef CLASE_H_
#define CLASE_H_

#include <stdio.h>

static const char *palabras_reservadas[] = {
    "cadena",
    "caracter",
    "else",
    "entero",
    "for",
    "if",
    "real",
    "return",
    "void",
    "while"};

static const int palabras_reservadas_size = 10;

static const char *op_relacional[] = {
    "^^",
    "^\"",
    "==",
    "^^=",
    "^\"=",
    "<>"};

static const int op_relacional_size = 6;

static const char *op_asignacion[] = {
    "~",
    "+~",
    "-~",
    "*~",
    "/~",
    "$~"};

static const int op_asignacion_size = 6;

/**
 * @brief Busca un ítem en una tabla de clases.
 * 
 * @param clase Tabla de clases.
 * @param table_size Tamaño de la tabla.
 * @param valor Valor a buscar.
 * @return int Índice del item si se encuentra, -1 en caso contrario.
 */
int buscar_valor(const char *clase[], const int table_size, const char *valor);

#endif
