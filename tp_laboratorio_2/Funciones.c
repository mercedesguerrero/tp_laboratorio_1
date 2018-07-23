#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu()
{
    system("cls");

    printf("\nPERSONAS>>> Seleccione una opcion: \n\n");

    printf("1- Agregar una persona \n");
    printf("2- Borrar una persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}


void inicializarPersonasEstado(ePersona personas[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        personas[i].estado = LIBRE;
    }
}

void inicializarPersonasHardCode(ePersona personas[])
{
    char nombre[15][20]= {"Cecilia","Mara","Marcelo","Vanesa","Juan","Laura","Luis","Micaela","Guillermo","Pedro","Stella","Antonela","Gabriela","Carlos","Bruno"};
    int edad[15]= {20,16,21,14,34,46,33,64,15,36,17,13,42,15,71};
    long int dni[15]= {42153281,45783294,39492384,23864398,34152378,52152237,23872235,39271452,24847392,56783256,34567238,41296374,60221378,33678219,63245632};

    int i;

    for(i=0; i<15; i++)
    {
        strcpy(personas[i].nombre, nombre[i]);
        personas[i].edad= edad[i];
        personas[i].dni= dni[i];
        personas[i].estado= OCUPADO;
    }
}

int obtenerEspacioLibre(ePersona personas[], int limite)
{
    int retorno = -2;
    int i;

    if(limite > 0 && personas != NULL)
    {
        retorno = -1;
        for(i=0; i<limite; i++)
        {
            if(personas[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }

    if(retorno<0)
    {
        printf("No hay lugar libre\n");
    }
    return retorno;
}

void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf("%s", input);
    fflush(stdin);
}

int esSoloLetras(char str[])
{
   int i=0;
   int retorno=1;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           retorno=0;
       i++;
   }
   return retorno;
}

int getValidString(char mensaje[], char error[], char input[], int limite)
{
    int j;
    char auxString[limite+100]; //por si se pasa
    int retorno=0;

    do
    {
        fflush(stdin);
        getString(mensaje, input);
        j= strlen(input);

        if(j>= limite || esSoloLetras(input)==0)
        {
            printf("%s", error);
        }
        else
        {
            strcpy(auxString, input);
            retorno=1;
        }
    }while(j>= limite || esSoloLetras(input)==0);

    return retorno;
}

int pedirNumEntero(char mensaje[])
{
    int numeroEntero;

    printf("%s", mensaje);
    scanf("%d", &numeroEntero);

    return numeroEntero;
}

long int pedirNumEnteroLong(char mensaje[])
{
    long int numeroLong;

    printf("%s", mensaje);
    scanf("%ld", &numeroLong);

    return numeroLong;
}

char getLetra(char mensaje[])
{
    char auxiliar;

    printf("%s", mensaje);
    scanf("%c", &auxiliar);

    return auxiliar;
}

int altaDePersona(ePersona personas[],int limite)
{
    int retorno=-1;
    int index;
    long int dni;
    char nombre[30];
    int edad;

    if(limite>0 && personas!= NULL)
    {
        retorno=-2;
        index= obtenerEspacioLibre(personas, limite);

        if(index>= 0)//HAY LUGAR
        {
            getValidString("Ingrese nombre: \n", "Puede ingresar hasta 20 letras\n", nombre, 20);
            strcpy(personas[index].nombre, nombre);
            edad= pedirNumEntero("Ingrese edad: \n");
            personas[index].edad = edad;
            dni= pedirNumEnteroLong("Ingrese DNI: \n");
            personas[index].dni = dni;
            personas[index].estado = OCUPADO;
            retorno = 0;
        }
        else
        {
            printf("\n No hay lugar para cargar personas");
        }
    }

    return retorno;
}

void ordenarListadoDePersonas(ePersona personas[], int limite)
{
    ePersona auxiliar[limite];

    for(int i=0; i<limite-1; i++)
    {
        for(int j=i+1; j<limite; j++)
        {
             if(personas[i].estado==OCUPADO)
             {
                 if((strcmp(personas[i].nombre,personas[j].nombre))> 0)
                    {
                         auxiliar[i]= personas[i];
                         personas[i]=personas[j];
                         personas[j]=auxiliar[i];
                    }
             }
        }
    }
}

void mostrarUnaPersona(ePersona personas[], int indice)
{
    printf(" -------------------------------------------------------\n");
    printf("| %s    \t\t | %d \t\t | %ld     |\n", personas[indice].nombre, personas[indice].edad, personas[indice].dni);
    printf(" -------------------------------------------------------\n");
}

int borrarUnaPersona(ePersona personas[], int limite)
{
    int i;
    long int DniABuscar;
    int retorno= -1;
    char confirma;

    if(mostrarListadoDePersonas(personas, limite)==0)
    {
        DniABuscar= pedirNumEnteroLong("\nIngrese el DNI de la persona que desea borrar: ");
        retorno= -2;

        for(i=0; i<limite; i++)
        {
            retorno= -3;
            if(personas[i].estado == OCUPADO && personas[i].dni == DniABuscar)
            {
                fflush(stdin);
                mostrarUnaPersona(personas, i);
                confirma= getLetra("\nEsta seguro que desea borrar s/n?");

                if(confirma=='s')
                {
                    personas[i].dni= 0;
                    personas[i].estado=LIBRE;
                    printf("\nSe borro la persona seleccionada\n");

                    retorno=0;
                }
                else
                {
                    printf("\nCancelado\n");
                    retorno=1;
                }
            }
        }
    }

    return retorno;
}

int mostrarListadoDePersonas(ePersona personas[], int limite)
{
    int i;
    int retorno=-2;

    ordenarListadoDePersonas(personas, limite);

    printf("\n");
    printf(" -------------------------------------------------------\n");
    printf("%s    \t\t %s \t %s\n","| Nombre","| Edad", "| DNI          |");
    printf(" -------------------------------------------------------\n");

/**< Recorre el listado y si el estado es igual a OCUPADO lo muestra */
    for(i=0; i<limite; i++)
    {
        retorno=-1;

        if(personas[i].estado==OCUPADO)
        {
            printf("| %s    \t\t | %d \t\t | %ld     |\n", personas[i].nombre, personas[i].edad, personas[i].dni);
            retorno=0;
        }
    }
    printf(" -------------------------------------------------------\n");
    return retorno;
}

void graficoPersonas(ePersona personas[], int limite)
{
    char columna1[limite][2];
    char columna2[limite][2];
    char columna3[limite][2];
    int i;
    int w=0;
    int j=0;
    int k=0;

    for(i=0;i<=limite;i++)
    {
        strcpy(columna1[i]," ");
        strcpy(columna2[i]," ");
        strcpy(columna3[i]," ");
    }

    for(i=0;i<limite;i++)
    {
        if(personas[i].estado==OCUPADO)
        {
            if(personas[i].edad <= 18 && personas[i].edad >0)
            {
                fflush(stdin);
                strcpy(columna1[w], "*");
                w++;
            }

            if(personas[i].edad > 18 && personas[i].edad <=35)
            {
                fflush(stdin);
                strcpy(columna2[k], "*");
                k++;
            }

            if(personas[i].edad > 35)
            {
                fflush(stdin);
                strcpy(columna3[j], "*");
                j++;
            }
        }
    }
    printf("\n");

    for(i=limite;i>=0;i--)
    {
        if( (strcmp(columna1[i],"*")==0) || (strcmp(columna2[i],"*")==0) || (strcmp(columna3[i],"*")==0)  )
        {
            printf("  %d-| %s      ", i+1, columna1[i]);
            printf("%s       ", columna2[i]);
            printf("%s\n", columna3[i]);
        }
    }
    printf("  __|_________________________\n");
    printf("     <18   19-35    >35\n\n");
    printf("Grafico para una estadistica de:\n* %d personas con edad menor a 18,\n* %d personas con edades entre 19 y 35,\n* %d personas con edades mayores a 35.\n", w,k,j);
}



