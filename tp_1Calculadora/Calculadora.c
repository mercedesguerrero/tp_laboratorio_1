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

float restar(float numeroA, float numeroB)
{
    float resultado;

    resultado = numeroA - numeroB;


    return resultado;
}

float dividir(float numeroA, float numeroB)
{
    float resultado;

    resultado = numeroA / numeroB;


    return resultado;
}

float multiplicar(float numeroA, float numeroB)
{
    float resultado;

    resultado = numeroA * numeroB;


    return resultado;
}

int factorial(float numeroA)
{
    int i=0;
    int factorial=1;

    for (i=1; i<=numeroA; i++)
    {
        factorial= i*factorial;
    }

    return factorial;
}


