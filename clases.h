#ifndef CLASE_H_
#define CLASE_H_

#include <stdio.h>

/**
 * @brief Tabla de palabras reservadas.
 */
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

/**
 * @brief Conteo de la tabla de palabras reservadas.
 */
static const int palabras_reservadas_size = 10;

/**
 * @brief Tabla de operadores relacionales.
 */
static const char *op_relacional[] = {
    "^^",
    "^\"",
    "==",
    "^^=",
    "^\"=",
    "<>"};

/**
 * @brief Conteo de operadores relacionales 
 */
static const int op_relacional_size = 6;

/**
 * @brief Tabla de operadores de asignación.
 */
static const char *op_asignacion[] = {
    "~",
    "+~",
    "-~",
    "*~",
    "/~",
    "$~"};

/**
 * @brief Conteo de los operadores de asignación.
 */
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
