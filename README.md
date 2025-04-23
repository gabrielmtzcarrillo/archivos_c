# Ejericios de programación en C/C++

Este repositorio contiene ejercicios y ejemplos en lenguaje C y C++ realizados durante mis años de estudiante. Muchos de ellos exploran estructuras de datos básicas y algoritmos fundamentales.

## Requisitos

- [Tiny C Compiler (TCC)](https://bellard.org/tcc/)
- Entorno Windows (para el script `build.bat`) o usar compilación manual en otros sistemas.

## Archivos

### C

- **Algmulti.c**: Multiplicación de matrices. Demuestra el uso de arreglos bidimensionales y bucles anidados.
- **arbol.c**: Implementación básica de un árbol binario. Incluye inserción y recorrido en preorden.
- **cola.c**: Simulación de una cola (FIFO) usando arreglos. Incluye funciones para encolar, desencolar y mostrar elementos.
- **pila.c**: Implementación de una pila (LIFO) con funciones para insertar y eliminar elementos.

### C++

- **ListaPrecios.cpp**: Gestión de una lista de productos con precios. Incluye búsqueda, ordenamiento y visualización.
- **examen.cpp**: Código relacionado con una evaluación o práctica de programación. Puede incluir varios conceptos combinados.

### Otros

- **build.bat**: Script en Windows para compilar todos los archivos `.c` y `.cpp` (a completar).
- **.gitignore**: Evita subir archivos generados por el compilador.
- **LICENSE**: Licencia MIT.

## Cómo compilar (ejemplo con TCC)

```bash
tcc -o pila pila.c
tcc -o cola cola.c
tcc -o arbol arbol.c
tcc -o algmulti Algmulti.c
```

Para C++ puedes usar g++ u otro compilador compatible.

## Licencia

Este proyecto está bajo la licencia MIT.
