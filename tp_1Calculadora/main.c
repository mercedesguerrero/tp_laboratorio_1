#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Calculadora.h"


int main()
{
    float numeroA;
    float numeroB;
    float resultado;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        numeroA=
        numeroB=
        printf("\nCALCULADORA>>> Seleccione una opcion: \n\n");
        printf("1- Ingresar 1er operando(A=%.2f)\n"), numeroA);
        printf("2- Ingresar 2do operando (B=%.2f)\n"), numeroB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

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



    return 0;
}
