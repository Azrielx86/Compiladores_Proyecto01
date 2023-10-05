# Proyecto 01 Compiladores

```
Facultad de Ingeniería - UNAM
Semestre 2024-1
```

## Avance actual
- [ ] Lectura del archivo como argumento desde la terminal
- [ ] Tabla de clases (Componentes léxicos)
- [x] Tabla de constantes
- [ ] Tabla de tokens
- [ ] Detección de errores léxicos
- [ ] Tabla de símbolos para almacenar los identificadores
- [ ] Tabla de literales

## Compilación
Para compilar el proyecto directamente se puede utilizar el archivo Makefile

    make

Si se desea hacer por separado, primero se pasa por flex y posteriormente por el compilador de C de su elección.

    flex lexer.l
    clang *.c -c
    clang *.o -o lexer