/*

 Algoritmo de multiplicación usando una tabla la primera columna (A) es el
 primer número que se desea multiplicar, la segunda (B) es el otro número y
 la tercera columna (C) muestra el valor de (A) si es non
 A    B    C
 A/2  B*2  SI A es non (-1^A; NON -1, PAR 1


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long A;//nuestro primer número (grande) a multiplicar, no se usa double porque el
           //algoritmo solo trabaja con números enteros.
           
    long B;//igual que el anteior.
    
    long C=0;//aquí guardaremos el valor de nuestra multiplicaciión, como necesitamos
             // números enteros garndes usamos long.
             
    int P;//esta variable nos servirí paras aber si un ímero es par (si ním^-1=1)
          // o si es non (ním^-1=-1)
    
  printf("Escriba un numero\n");
  scanf("%i",&A);

  printf("Escriba otro numero\n");
  scanf("%i",&B);
  
  printf("\n------------------------------------------\n");  
  printf("%8s\t%8s\t%8s\n","A","B","C");
  printf("------------------------------------------\n");
  while (A>=1)
  {
        P=pow(-1,A);
        if (P == -1)
        {
         C=C+B;
         printf("%8d\t%8d\t%8d\n",A,B,B);
        }
        else
        {
         printf("%8d\t%8d\t%8s\n",A,B,"-");
        }

        A=A/2;
        B=B*2;
  }
  printf("------------------------------------------\n");
  printf("\t\t%24d\n\n",C);
  printf(" = El resultado es: %d =\n\n",C);
  system("PAUSE");	
  return 0;
}
