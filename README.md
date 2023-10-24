# Proyecto 01 Compiladores

```
Facultad de Ingeniería - UNAM
Semestre 2024-1
```

## Avance actual
- [x] Lectura del archivo como argumento desde la terminal
- [x] Tabla de clases (Componentes léxicos)
- [x] Tabla de constantes
- [x] Tabla de tokens
- [x] Detección de errores léxicos
- [x] Tabla de símbolos para almacenar los identificadores
- [x] Tabla de cadenas

## Compilación
Para compilar el proyecto directamente se puede utilizar el archivo Makefile

    make

Si se desea hacer por separado, primero se pasa por flex y posteriormente por el compilador de C de su elección.

    flex lexer.l
    clang *.c -c
    clang *.o -o lexer

## Salidas obtenidas

### Texto ingresado

```shell
cadena a_,b2,c1_;
if x_ ^^ (-23+c1_) 
"Hola Mundo!"
'a'
```

### Salida

```shell
$ ./lexer
(1)[Palabra reservada: cadena - ID: 0]
(1)[Identificador: a_]
(1)[Simbolo especial: ,]
(1)[Identificador inválido: b2]
(1)[Simbolo especial: ,]
(1)[Identificador: c1_]
(1)[Item no válido: ;]
(2)[Palabra reservada: if - ID: 5]
(2)[Identificador: x_]
(2)[Operador relacional: ^^]
(2)[Simbolo especial: (]
(2)[Constante numerica: -23 (Convertido de: -23)]
(2)[Operador aritmetico: +]
(2)[Identificador: c1_]
(2)[Simbolo especial: )]
(3)[Cadena: "Hola Mundo!"]
(4)[Caracter: 'a']


==== Tabla de constantes ====
Item    Value
0       -23.000000
==== Tabla de literales ====
Item    Value   Tipo
0       a_      -1
1       c1_     -1
2       x_      -1
==== Tabla de tokens ====
Item    Value
(0,0)
(5,0)
(3,44)
(3,44)
(5,1)
(0,5)
(5,2)
(4,0)
(3,40)
(6,0)
(1,43)
(5,1)
(3,41)
(8,0)
(9,1)
==== Errores ====
Error:  b2 en la linea 1
Error:  ; en la linea 1
==== Tabla de literales ====
Item    Value
0       "Hola Mundo!"
1       'a'
```
