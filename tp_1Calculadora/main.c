#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Calculadora.h"


int main()
{
    float numeroA;
    float numeroB;
    int AestaCargado;
    int BestaCargado;
    float resultado;
    char seguir='s';
    int opcion=0;

    do
    {
        mostrarMenu(numeroA, numeroB, AestaCargado, BestaCargado);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                resultado= sumar(numeroA, numeroB);

                printf("\nEl resultado de la suma es = %.2f \n", resultado);

                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }


    while(seguir=='s')
    {

    }






    return 0;
}
