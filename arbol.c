/* Crea un árbol binario y lo recorre en preorden, inorden, y en postorden */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/* estructura autorreferencia */
struct nodoArbol   {
        struct nodoArbol *ptrIzq; /* apuntador al subárbol izquierdo */
        int dato; /* valor del nodo */
        struct nodoArbol *ptrDer; /* apuntador al subárbol derecho */
        }; /* fin de la estructura nodoArbol */

typedef struct  nodoArbol NodoArbol; /* sinonimo de la estructura nodoArbol */
typedef NodoArbol *ptrNodoArbol;      /* sinonimo de NodoArbol * */

/* prototipos */
void insertaNodo ( ptrNodoArbol *ptrArbol, int valor );
void inOrden ( ptrNodoArbol ptrArbol );
void preOrden ( ptrNodoArbol  ptrArbol);
void postOrden ( ptrNodoArbol ptrArbol);

/* la funcion main comienza la ejecuci�n del programa */

int main ()
{
int i; /* contador para el ciclo de 1 a 10 */
int elemento; /* variable para almacenar valores al azar */
ptrNodoArbol ptrRaiz = NULL; /* arbol inicialmente vacio */

srand ( time (NULL));
printf ( "Los numeros colocados en el arbol son: \n");

/* inserta valores al azar entre 1 y 15 en el arbol */
for (i=1; i <= 10; i++) {
    elemento = rand () % 15;
    printf ("%3d", elemento);
    insertaNodo ( &ptrRaiz, elemento);
} /* fin de for */

/* recorre el arbol en preorden */
printf ("\n\n El recorrido en preorden es: \n");
preOrden (ptrRaiz);


/* recorre el arbol en in inorden */
printf ("\n\nEl recorrido en inorden es: \n");
inOrden (ptrRaiz);


/* recorre el arbol en posorden */
printf ("\n\nEl recorrido en posorden es: \n");
preOrden (ptrRaiz);
getch();
return 0;  /* indica terminacion exitosa */

} /* fin de main */

/* inserta un nodo dentro del arbol */
void insertaNodo (ptrNodoArbol *ptrArbol, int valor)
{
     /* si el arbol esta vacio */
     if ( *ptrArbol == NULL) { 
            *ptrArbol = malloc (sizeof (NodoArbol));

        /* si la memoria esta asignada, entonces asigna el dato */
         if (*ptrArbol != NULL) {
            (*ptrArbol)->dato = valor;
            (*ptrArbol)->ptrIzq = NULL;
            (*ptrArbol)->ptrDer = NULL;
} /* fin de if */
else { 
   printf ("no se inserto %d. No hay memoria disponible. \n", valor);
} /* fin de else */

} /* fin de if */
else { /* el arbol no esta vacio */

/* el dato a insertar es menor que el dato en el nodo actual */
if (valor < ( *ptrArbol )->dato ) {
insertaNodo ( & ( ( *ptrArbol )->ptrIzq), valor);

} /* fin de if */

/* el dato a insertar es mayor que el dato en el nodo actual */
else if (valor > ( *ptrArbol) ->dato) {
        insertaNodo (& ( (*ptrArbol)->ptrDer ), valor );
 } /* fin de else if */

else { /* ignora el valor duplicado del dato */
      printf ("dup");
} /* fin de else */

} /* fin de else */

} /* fin de la funcion insertaNodo */

/* comienza el recorrido inorden del arbol */
void inOrden ( ptrNodoArbol ptrArbol )
{

     /* si el arbol  no esta vacio, entonces recorrelo */
    if (ptrArbol != NULL) {
              inOrden (ptrArbol->ptrIzq);
              printf ("%3d",  ptrArbol->dato);
              inOrden ( ptrArbol->ptrDer);
} /* fin de if */

} /* fin de la funcion inOrden */
/* comienza el recorrido preorden del arbol */
void preOrden ( ptrNodoArbol ptrArbol)
 {

/* si el Arbol no esta vacio, entonces recorrelo */
if (ptrArbol != NULL ) {
    printf ("%3d", ptrArbol->dato);
    preOrden ( ptrArbol->ptrIzq );
    preOrden ( ptrArbol->ptrDer);
} /* fin de if */

} /* fin de la funcion preOrden */

/* comienza el recorrido postorden del arbol */
void postOrden ( ptrNodoArbol ptrArbol)
{

/* si el arbol no esta vacio, entonces recorrelo */
if ( ptrArbol != NULL) {
  postOrden ( ptrArbol->ptrIzq);
 postOrden ( ptrArbol->ptrDer);
 printf ("3%d", ptrArbol->dato);
} /* fin de if */

} /* fin de la funcion posOrden */
