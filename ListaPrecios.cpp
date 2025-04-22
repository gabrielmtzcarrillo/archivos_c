/*

 Una empresa vende 3 tipos de articulos y
 dependiendo de la suma del precio de los
 artículos, se aplicarán los siguientes
 descuentos:

  A) Si el precio de los artículos esta
     entre $6000 y $8000, se aplica un 10%
     de descuento.

  B) Si el precio de los artículos esta
     entre $8000 y $10000, se aplica un 20%
     de descuento.

  C) Si el precio de los artículos esta
     entre $10000 y $50000, se aplica un 25%
     de descuento.

 en el caso contrario, no se aplica el
 descuento. NOTA: solo se pueden comprar 6
 artículos, sin importar el precio de los
 mismos.

----------------------------------------------'
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    float Descuento,ST,Total,PD;   //se declaran como flotante de simple precision porque necesita-
                                   //remos hacer operaciones que requieren que el resultado sea con
                                   //decimales.

    unsigned int ArtA,ArtB,ArtC,SA;//se usa el unsigned porque el número de artículos, así como la
                                   //cantidad de los mismos NO puede ser negativa.
    SA=0;
	printf("---------.\n");
	printf(" Compras  \\\n");
	printf("_______________________________________________________\n\n");
    while(SA<6)
    {
        printf("\nIntroduzca el numero de Articulos A\nPrecio: $2,000.00\n");
        scanf("%d",&ArtA);
        printf("\nIntroduzca el numero de Articulos B\nPrecio: $1,000.00\n");
        scanf("%d",&ArtB);
        printf("\nIntroduzca el numero de Articulos C\nPrecio: $2,500.00\n");
        scanf("%d",&ArtC);
        SA=ArtA+ArtB+ArtC;
        if (SA<6)
        {
         printf("\n---Debe de ordenar como minimo 6 articulos en total---\n");
        }
    }
    ST=(ArtA*2000)+(ArtB*1000)+(ArtC*2500);
    if (ST>6000 && ST<8000)
    {
      PD=0.1;
    }
    if (ST>=8000 && ST<=10000)
    {
      PD=0.2;
    }
    if (ST>=10000 && ST<=50000)
    {
      PD=0.25;
    }
    if (ST<=6000 || ST>=50000)
    {
      PD=0;
    }
    Descuento=PD*ST;
    Total=ST-Descuento;
    printf("\n-------------------------------------\n\n");
    printf("Articulos A: %d * 2,000.00 = %5d.00\n",ArtA,(ArtA*2000));
    printf("Articulos B: %d * 1,000.00 = %5d.00\n",ArtB,(ArtA*1000));
    printf("Articulos C: %d * 2,500.00 = %5d.00\n",ArtC,(ArtA*2500));
    if (PD!=0)
    {
    printf("\nDescuento obtenido: %0.0f%c\n",PD*100,37);
    }
    else
    {
    printf("\nLa compra fue procesada, pero no tiene descuento\n");
    }
    printf("\n-------------------------------------\n");
    printf("\nSubtotal: %26.2f\n",ST);
    printf("Menos el descuento: %16.2f \n",Descuento);
    printf("\n-------------------------------------\n");
    printf("Total: $%28.2f\n\n",Total);
    system("pause");
    return 0;
}
