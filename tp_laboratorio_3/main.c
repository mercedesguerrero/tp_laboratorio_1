#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    eMovie* p;

    int opcion= 0;
    char seguir= 's';
    char cargar= 's';

    do
    {
        mostrarMenu();
        opcion= getInt("\nLa opcion es: ");

        switch(opcion)
        {
            case 1:
                do
                {
                    system("cls");

                    loadData(&p);
                    saveMovie(&p);

                    cargar= getChar("\nDesea ingresar otra pelicula? s/n: ");
                }while(cargar=='s');

                break;
            case 2:
                //mostrarlistMovies(listMovies, SIZE_MOVIE);

                //eMovie_baja(listMovies, SIZE_MOVIE, eMovie_buscarPorId(listMovies, SIZE_MOVIE, pedirNumEntero("\nIngrese ID a dar de baja: ")));

                pressContinue("\nPresione cualquier tecla para continuar ");
                break;
            case 3:
                //mostrarlistMovies(listMovies, SIZE_MOVIE);

                //eMovie_modificacion(listMovies, SIZE_MOVIE, eMovie_buscarPorId(listMovies, SIZE_MOVIE, pedirNumEntero("\nIngrese ID a modificar: ")));

                pressContinue("\nPresione cualquier tecla para continuar ");
                break;
            case 4:
                //GENERAR PÁGINA WEB
                pressContinue("\nPresione cualquier tecla para continuar ");
                break;
            case 5:
                seguir= 'n';
                break;
        }
    }while(seguir== 's');

    return 0;
}
