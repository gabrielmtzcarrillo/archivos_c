/*Operacion y mantenimiento de una cola*/


#include<stdio.h>
#include<stdlib.h>

/*estructura autorreferenciada*/
struct nodoCola {
       char dato;                        /* define dato como un char*/
       struct nodoCola *ptrSiguiente;    /* apuntador nodoCola*/
       }; /* fin de la estructura nodoCola*/

typedef struct nodoCola NodoCola;
typedef NodoCola *ptrNodoCola;

/* prototipos de las funciones*/
void imprimeCola(ptrNodoCola ptrActual);
int estaVacia(ptrNodoCola ptrCabeza);
char retirar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon);
void agregar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, 
char valor);
void instrucciones(void);

/* la funcion main comienza ña ejecucion del programa*/
int main()
{
    ptrNodoCola ptrCabeza = NULL;        /* inicializa ptrCabeza */
    ptrNodoCola ptrTalon = NULL;         /* inicializa ptrTalon */
    int eleccion;                        /* eleccion de menu del usuario */
    char elemento;                       /* entrada char del usuario */

    instrucciones();  /* despliega el menu */
    printf( "? ");
    scanf("%d",&eleccion);

    /* mientras el usuario no introduzca 3 */
    while(eleccion != 3){

        switch(eleccion){
            
            /* agrega el valor */
            case 1:
                printf("Introduzca un caracter:");
                scanf("\n%c", &elemento);
                agregar(&ptrCabeza, &ptrTalon, elemento);
                imprimeCola(ptrCabeza);
                break;
                
            /* retira el valor */
            case 2:
                
                /* si la cola no esta vacia */
                if (!estaVacia(ptrCabeza)){
                    elemento = retirar(&ptrCabeza, &ptrTalon);
                    printf("se desenfilo %c.\n", elemento);
                } /* fin del if */
                    
                imprimeCola(ptrCabeza);
                break;
                    
            default:
                printf("Eleccion no valida.\n\n");
                instrucciones();
                break;
                    
            } /* fin del switch */
            
            printf("? ");
            scanf("%d", &eleccion);
    } /* fin del while */
    
    printf("Fin del programa.\n");
    
    return 0; /* indica terminacion exitosa */

} /* fin de main */

/* despliega las instrucciones del programa para el usuario */
void instrucciones(void)
{
    printf("Introduzca su eleccion:\n"
    " 1 para retirar un elemento a la cola\n"
    " 2 para eliminar un elemento de la cola\n"
    " 3 para terminar\n");
} /* fin de la funcion instrucciones */

/* inserta un nodo al final de la cola */
void agregar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon,char valor)

{
    ptrNodoCola ptrNuevo; /* apuntador a un nuevo nodo */
    ptrNuevo = malloc(sizeof(NodoCola));
                                    if(ptrNuevo != NULL){ /* es espacio disponible */
                                    ptrNuevo->dato = valor;
                                    ptrNuevo->ptrSiguiente = NULL;
                                    
                                    /* si esta vacia inserta un nodo en la cabeza */
                                    if(estaVacia(*ptrCabeza)){
                                    *ptrCabeza = ptrNuevo;
                                    } /* fin del if */
                                    else{
                                         (*ptrTalon)->ptrSiguiente = ptrNuevo;
                                         } /* fin de else */
                                         *ptrTalon = ptrNuevo;
                                         } /* fin del if */
                                         else{
                                              printf("no se inserto %c. No hay memoria disponible.\n",valor);
                                              } /* fin del else */
                                              
                                              } /* fin de la funcion agregar */
                                              
                                              /* elimina el nodo de la cabeza de la cola */
                                              char retirar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon)
                                              {
                                                   char valor; /* valor del nodo */
                                                   ptrNodoCola tempPtr; /* apuntador a un nodo temporal */
                                                   
                                                   valor = (*ptrCabeza)->dato;
                                                   tempPtr = *ptrCabeza;
                                                   *ptrCabeza = (*ptrCabeza)->ptrSiguiente;
                                                   
                                                   /* si la cola esta vacia */
                                                   if(*ptrCabeza == NULL){
                                                                 *ptrTalon = NULL;
                                                                 } /* fin de if */
                                                                 
                                                                 free(tempPtr);
                                                                 
                                                                 return valor;
                                                                 
                                                                 } /* fin de la funcion retirar */
                                                                 
                                                   /* Devuelve 1 si la cola esta vacia, de lo contrario devuelve 0 */
                                                   int estaVacia(ptrNodoCola ptrCabeza)
                                                   {
                                                       return ptrCabeza == NULL;
                                                       
                                                       } /* fin de la funcion estaVacia */
                                                       
                                                       /* Imprime la cola */
                                                       void imprimeCola(ptrNodoCola ptrActual)
                                                       {
                                                            /* si la cola esta vacia */
                                                            if(ptrActual == NULL){
                                                                         printf("La cola esta vacia. \n\n");
                                                                         } /* fin de if */
                                                                         else {
                                                                              printf("La cola es:\n");
                                                                              
                                                                              /* mientras no sea el final de la cola */
                                                                              while (ptrActual != NULL){
                                                                                    printf("%c ->", ptrActual->dato);
                                                                                    ptrActual = ptrActual->ptrSiguiente;
                                                                                    } /* fin del while */
                                                                                    
                                                                                    printf("NULL\n\n");
                                                                                    
                                                                                    } /* fin de else */
                                                                                    
                                                                                    } /* fin de la funcion imprimeCola */
                                                                                    
                                                                                
                                                                                        
       
