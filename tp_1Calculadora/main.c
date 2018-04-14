#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Calculadora.h"
#include "Consola.h"

void mostrarMenu(float numeroA, float numeroB, int AestaCargado, int BestaCargado);
float escanearNumero();

int main()
{
    float numeroA;
    float numeroB;
    int AestaCargado=0;
    int BestaCargado=0;

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

                numeroA=escanearNumero();
                AestaCargado=1;
                break;
            case 2:

                numeroB= escanearNumero();
                BestaCargado=1;
                break;
            case 3:
                resultado= sumar(numeroA, numeroB);

                printf("\nEl resultado de la suma es = %.2f \n", resultado);

                presionarContinuar();

                break;
            case 4:
                resultado= restar(numeroA, numeroB);

                printf("\nEl resultado de la resta es = %.2f \n", resultado);

                presionarContinuar();

                break;
            case 5:
                resultado= dividir(numeroA, numeroB);

                printf("\nEl resultado de la division es = %.2f \n", resultado);

                presionarContinuar();

                break;
            case 6:
                resultado= multiplicar(numeroA, numeroB);

                printf("\nEl resultado de la multiplicacion es = %.2f \n", resultado);

                presionarContinuar();
                break;
            case 7:
                resultado= factorial(numeroA);

                printf("\nEl factorial del número ingresado es = %.2d\n", factorial);

                presionarContinuar();
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');


    return 0;
}
