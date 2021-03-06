#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAMPERSONA 20



int main()
{
    /**< Array lista de personas */
    ePersona listaDePersonas[TAMPERSONA];
    /**< Inicializo la lista */
    inicializarPersonasEstado(listaDePersonas, TAMPERSONA);
    inicializarPersonasHardCode(listaDePersonas);

    char seguir='s';
    int opcion=0;

    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaDePersona(listaDePersonas, TAMPERSONA);
                presionarContinuar();
                break;
            case 2:
                borrarUnaPersona(listaDePersonas, TAMPERSONA);
                presionarContinuar();
                break;
            case 3:
                mostrarListadoDePersonas(listaDePersonas, TAMPERSONA);
                presionarContinuar();
                break;
            case 4:
                graficoPersonas(listaDePersonas, TAMPERSONA);
                presionarContinuar();
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');

    return 0;
}
