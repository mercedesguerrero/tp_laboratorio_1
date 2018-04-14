#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "Consola.h"

void mostrarMenu(float numeroA, float numeroB, int AestaCargado, int BestaCargado)
{
    system("cls");

    printf("\nCALCULADORA>>> Seleccione una opcion: \n\n");

    if(AestaCargado==0)
    {
        printf("1- Ingresar 1er operando(A=x)\n");
    }
    else
    {
        printf("1- Ingresar 1er operando(A=%.2f)\n", numeroA);
    }
    if(BestaCargado==0)
    {
        printf("2- Ingresar 2do operando (B=y)\n");
    }
    else
    {
        printf("2- Ingresar 2do operando (B=%.2f)\n", numeroB);
    }

    printf("3- Calcular la suma (A+B)\n");
    printf("4- Calcular la resta (A-B)\n");
    printf("5- Calcular la division (A/B)\n");
    printf("6- Calcular la multiplicacion (A*B)\n");
    printf("7- Calcular el factorial (A!)\n");
    printf("8- Calcular todas las operaciones\n");
    printf("9- Salir\n");

    printf("\nLa opcion es: ");
}

float escanearNumero()
{
    float numero;
    printf("\nIngrese un numero: ");
    scanf("%f", &numero);

    return numero;

}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}



