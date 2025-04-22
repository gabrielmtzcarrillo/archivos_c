#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

int DEBUGMODE=0;//debería de ser del tipo bool, pero propiamente dicho, este tipo de datos
                //en c no existe sin una implementación.
int correctas[11] = {0,0,0,0,0,0,0,0,0,0,0};//Respuestas correctas, indicamos con un int
                // el orden de las respuestas correctas, más adelante, estos valore se
                //cambiarán aleatoriamente. int ocupa menos espacio en memoria que float y long
                //también tomando en consideración que el 
                
int orden[10] = {0,0,0,0,0,0,0,0,0,0};//igual que la anterior
int suma_correctas;//también en este caso usaremos int, puesto que no necesitaremos usar números grandes.
char resp[10][2];//aqui se almacenarán las respuestas. se usarán int para usar menos memoria, claro que se
                 //si usamos un char, se usaría menos memoria, pero sera más complicado a la hora de
                 //trabajar con als respuestas (que son letras, y en cada caso habría que convertirlas en
                 //minúsculas/mayúsculas...)
int resp2int; //esta variable nos ervirá ala hora de pasar de caracteres a números enteros (que son los
              //los que usamos

unsigned int i,p; //nuestros contadores, en este caso no necesitaremos usar números negativos

int r2i(char r)
{
    if (tolower(r)=='a')
    return 0;

    if (tolower(r)=='b')
    return 1;

    if (tolower(r)=='c')
    return 2;
}

void calificar()
{
    for(i=0;i<10;i++)
    { 
        resp2int=r2i(resp[i][0]);
        if(DEBUGMODE==1)
        printf("==Pregunta %d==\nRepuesta correcta = %d\nRespuesta Usuario = %d\n\n",i+1,correctas[i],resp2int);
        
        if (resp2int==correctas[i])
        suma_correctas++;
    } 
}

int main(int argc, char *argv[])
{   
    int tmp;
    int control=0;
    int existe;
    int completo=0;

    if (argv[1]!=NULL)
    {
        if(strcmp(argv[1],"-debugmode")==0)
        {
        DEBUGMODE=1;
        printf("Debugmode: Activado\n");
        system("PAUSE");
        system("CLS");
        }
    }

    
    char preguntas[11][60] = {"¿cuanto es 1+1?",
                              "¿cuanto es 2+2?",
                              "¿cuanto es 3+3?",
                              "¿cuanto es 4+4?",                              
                              "¿cuanto es 5+5?",
                              "¿cuanto es 6+6?",
                              "¿cuanto es 7+7?",
                              "¿cuanto es 8+8?",
                              "¿cuanto es 9+9?",
                              "¿cuanto es 10+10?",
                              "¿cuanto es 11+11?"};
                              
    char respuestas[11][3][30] = {{"2","3","4"},
                                  {"4","5","6"},
                                  {"6","7","8"},
                                  {"8","9","10"},
                                  {"10","11","12"},
                                  {"12","13","14"},
                                  {"14","15","16"},
                                  {"16","17","18"},
                                  {"18","19","20"},
                                  {"20","21","22"},
                                  {"22","23","24"}};
    
    srand(time(NULL));
    
    for (i=0;i<10;i++)//aqui se hace la asignación al azar de las respuestas,
    {                 //misma que se utilizará para mostrar las respuestas posibles
        correctas[i]=rand()%3;
        if(DEBUGMODE==1)
        printf("DEBUG: Pregunta %3d resp. correcta: %d\n",i+1,correctas[i]);
    }

        if(DEBUGMODE==1)
        system("PAUSE");
            
    while(control<10&&completo==0)
    {
        tmp=rand()%11;
        existe=0;
        
        for (i=0;i<=control;i++)
        {
            if (orden[i]==tmp)
            existe=1;
            
            if (i==9)//marca que se completó la última asignación
            completo=1;
        }
        
        if (existe==0)
        {
            control++;
            orden[i]=tmp;
        }
    }
        if(DEBUGMODE==1)
        {
            system("CLS");                        
            for (i=0;i<10;i++)
            printf("DEBUG: Orden[%d]=%d\n",i,orden[i]);
            
            system("PAUSE");
            system("CLS");
        }
    for(p=0;p<=9;p++)
    {
        system("CLS");
        printf("\n== Pregunta %2d  ====================\n\n",p+1);
        printf("%s\n",preguntas[orden[p]]);      
               
        if (correctas[p]==0)
        {
                printf("a)%s\n",respuestas[orden[p]][0]);
                printf("b)%s\n",respuestas[orden[p]][1]);
                printf("c)%s\n",respuestas[orden[p]][2]);
        }
        if (correctas[p]==1)
        {
                printf("a)%s\n",respuestas[orden[p]][1]);
                printf("b)%s\n",respuestas[orden[p]][0]);
                printf("c)%s\n",respuestas[orden[p]][2]);
        }
        if (correctas[p]==2)
        {
                printf("a)%s\n",respuestas[orden[p]][2]);
                printf("b)%s\n",respuestas[orden[p]][1]);
                printf("c)%s\n",respuestas[orden[p]][0]);
        }

        printf("\nrespuesta:");
        scanf("%s",&resp[p]);
    }
    suma_correctas=0;
    calificar();
    printf(" Tu calificación es: %2d\n",suma_correctas);
    system("PAUSE");
    return 0;
}
