#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "Calculadora.h"


float sumar(float numeroA, float numeroB)
{
    float resultado;

    resultado = numeroA + numeroB;


    return resultado;

}


float escanearNumero( )
{
    float numero;

    printf("Ingrese un operando: \n");
    scanf("%f", &numero);

    return numero;

}

float mostrarNumero

