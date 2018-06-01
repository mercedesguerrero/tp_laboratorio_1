#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

#define SIZE_MOVIE 50


int main()
{
    typedef struct eMovie p;

    char seguir='s';
    int opcion=0;


    eMovie listMovies[SIZE_MOVIE];


    do
    {
        mostrarMenu();
        opcion= getChar("\nLa opcion es: ");

        switch(opcion)
        {
            case 1:
                //eMovie_alta(listMovies, SIZE_MOVIE);
                do
                {
                    loadData(&p);
                    saveMovie(&p);
                    seguir= getChar("Desea ingresar otra pelicula? s/n:");
                }while(seguir=='s');

                presionarContinuar();
                break;
            case 2:
                //mostrarlistMovies(listMovies, SIZE_MOVIE);

                //eMovie_baja(listMovies, SIZE_MOVIE, eMovie_buscarPorId(listMovies, SIZE_MOVIE, pedirNumEntero("\nIngrese ID a dar de baja: ")));

                presionarContinuar();
                break;
            case 3:
                //mostrarlistMovies(listMovies, SIZE_MOVIE);

                //eMovie_modificacion(listMovies, SIZE_MOVIE, eMovie_buscarPorId(listMovies, SIZE_MOVIE, pedirNumEntero("\nIngrese ID a modificar: ")));

                presionarContinuar();
                break;
            case 4:
                //GENERAR PÁGINA WEB
                presionarContinuar();
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');

    presionarContinuar();

    return 0;
}
