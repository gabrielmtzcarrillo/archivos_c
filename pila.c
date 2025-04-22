/*programa de pila dinámica*/

#include <stdio.h>
#include <stdlib.h>

//Estructura auto-referenciada 
struct nodoPila{
       int dato;                    
       struct nodoPila *ptrSiguiente; /*apuntador a nodoPila */
       }; /* fin de la estructura nodoPila */
       
typedef struct nodoPila NodoPila; /* sinónimo de la estructura nodoPila*/
typedef NodoPila *ptrNodoPila; /* sinónimo para NodoPila* */

/* funciones */
void empujar ( ptrNodoPila *ptrCima, int info );
int sacar (ptrNodoPila *ptrCima);
int estaVacia( ptrNodoPila ptrCima);
void imprimePila (ptrNodoPila ptrCima);
void instrucciones (void);

/* La función main comienza la ejecición del programa */
int main()
{
    ptrNodoPila ptrPila = NULL; /*apunta al tope de la pila */
    int eleccion; 
    int valor; 
    
    instrucciones(); /*despliega el menú principal */
    printf("?");
    scanf("%d", &eleccion);
    
    /*mientras el usuario no introduzca 3 */
    while (eleccion!=3) {
          switch (eleccion) {
                 /* empuja el valor dentro de la pila */
                 case 1:
                      printf("Introduzca un entero: ");
                      scanf("%d",&valor);
                      empujar(&ptrPila, valor);
                      imprimePila(ptrPila);
                      break;
                 /* saca el valor de la pila */
                 case 2:
                       /* si la pila no está vacía */
                       if(!estaVacia(ptrPila)){
                                              printf("El valor sacado es %d.\n", sacar(&ptrPila));
                                              } /*fin de if */
                                              
                                              imprimePila(ptrPila);
                                              break;
                 default:
                         printf("Elecci�n no valida.\n\n");
                         
                         instrucciones();
                         break;
                 } /* fin de switch */
                 
                 printf( "? " );
                 scanf( "%d", &eleccion );
                 
          } /* fin del while */
                         
                 printf( "Fin del programa. \n" );
                 
                 return 0; /* indica terminación exitosa */
                 
} /*fin del main */
          
/* despliega las instrucciones del programa para el usuario */
void instrucciones ( void )
{
     printf( "Instroduzca su eleccion: \n"
         "1 para empujar un valor dentro de la pila\n"
         "2 para sacar un valor de la pila\n"
         "3 para terminar el programa\n");
         
} /*fin de la función instrucciones */

/* Inserta un nodo en la cima de la pila */
void empujar( ptrNodoPila *ptrCima, int info )
{
     ptrNodoPila ptrNuevo; /* apuntador al nuevo al nodo */
     
     ptrNuevo = malloc( sizeof ( NodoPila ) );
     
     /* inserta el nodo en la cima de la pila */
     if ( ptrNuevo != NULL ) {
          ptrNuevo ->dato = info;
          ptrNuevo ->ptrSiguiente = *ptrCima;
          *ptrCima = ptrNuevo;
     } /* fin de if */
     
     else { /* no queda espacio disponible */
          printf( "%d no se inserto. Memoria insuficiente. \n", info );
     } /* fin de else */
     
} /* fin de la función empujar */

/* Elimina un nodo de la cima de la pila */ 
int sacar( ptrNodoPila *ptrCima )
{
    ptrNodoPila ptrTemp; /* apuntador a un nodo temporal */
    int valorElim; /* valor del nodo */
    
    ptrTemp = *ptrCima;
    valorElim = ( *ptrCima )->dato;
    *ptrCima = ( *ptrCima )->ptrSiguiente;
    free( ptrTemp );
    
    return valorElim;
    
} /* fin de la función sacar */

/* Imprime la pila */
void imprimePila( ptrNodoPila ptrActual )
{
     /* si la pila está vacía */
     if ( ptrActual == NULL ) {
          printf( "La pila est� vac�a. \n\n" );
     } /* fin de if */
     
     else {
       printf( "La pila es: \n" );
       
       /* mientras no sea el final de la pila */
       while ( ptrActual != NULL ) {
             printf( "%d -> ", ptrActual->dato );
             ptrActual = ptrActual->ptrSiguiente;
       } /* fin del while */
       
       printf( "NULL\n\n" );
     } /* fin de else */
     
} /* fin de la función imprimePila */

/* Devuelve 1 si la pila está vacía, de lo contrario 0 */
int estaVacia ( ptrNodoPila ptrCima )
{
    return ptrCima == NULL;
    
} /* fin de la función estaVacia */
