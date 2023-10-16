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

int buscar_valor(const char *clase[], const int table_size, const char *valor);

#endif
