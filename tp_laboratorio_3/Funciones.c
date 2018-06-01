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

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

/**< INICIALIZA ESTADO EN LIBRE*/
int eMovie_init (eMovie movies[],int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && movies != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            movies[i].estado= LIBRE;

            //movies[i].idMovie= 0;
        }
    }
    return retorno;
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
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

void loadData(typedef struct eMovie* p)
{
    getString("\nIngrese genero: ",p->genero);
    p->duracion=getInt("\nIngrese duracion: ");
    getString("\nIngrese descripcion:",p->descripcion);
    p->duracion=getInt("\nIngrese puntaje: ");
}

int saveMovie(typedef struct eMovie* p)
{
    FILE* fp;
    fp=fopen("movies.dat","ab+"); // append binario, lo crea si no existe
    if(fp==NULL)
    {
        printf("Error opening file");
        return -1;
    }
    fwrite(p,sizeof(typedef struct eMovie),1,fp); // escribo una struct al final

    fclose(fp);

    return 0;
}


