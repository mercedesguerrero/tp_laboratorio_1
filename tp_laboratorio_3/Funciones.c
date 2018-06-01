#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Funciones.h"


void mostrarMenu()
{
    system("cls");

    printf("\nMOVIECLUB>>> Seleccione una opcion: \n");

    printf("\n1- Agregar Pelicula \n");
    printf("\n2- Borrar Pelicula \n");
    printf("\n3- Modificar Pelicula\n");
    printf("\n4- Generar Pagina Web\n");
    printf("\n5- Salir\n");
}

void pressContinue(char* mensaje)
{
    printf("%s", mensaje);
    getch();
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;
}

int getIntRango(char* mensaje, int desde, int hasta)
{
    int auxiliar;
    int flag= 0;

    do
    {
        if(flag==1)
        {
            printf("\n Debe ser de: %d a %d\n", desde, hasta);
        }
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%d",&auxiliar);
        flag=1;

    }while( (auxiliar<desde) || (auxiliar>hasta) );

    return auxiliar;
}

char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

void loadData(eMovie* p)
{
    getString("\nIngrese titulo: ",p->titulo);
    fflush(stdin);
    getString("\nIngrese genero: ",p->genero);
    fflush(stdin);
    p->duracion=getInt("\nIngrese duracion en minutos: ");
    getString("\nIngrese descripcion: ",p->descripcion);
    fflush(stdin);
    p->puntaje=getIntRango("\nIngrese puntaje: ", 1, 10);
    getString("\nLink a imagen: ",p->linkImagen);
    fflush(stdin);
}

int saveMovie(eMovie* p)
{
    FILE* fp;
    fp=fopen("movies.dat","ab+"); // append binario, lo crea si no existe

    if(fp==NULL)
    {
        printf("Error opening file");
        return -1;
    }
    fwrite(p,sizeof(eMovie),1,fp); // escribo una struct al final

    fclose(fp);

    return 0;
}


