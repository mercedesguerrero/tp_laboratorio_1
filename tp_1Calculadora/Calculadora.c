#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "Calculadora.h"

/** \brief Realiza la operaci�n suma
 * \param Float Primer operando
 * \param Float Segundo operando
 * \return Float Resultado de la operaci�n
 */
float sumar(float numeroA, float numeroB)
{
    float resultado;

    resultado = numeroA + numeroB;


    return resultado;
}

/** \brief Realiza la operaci�n resta
 * \param Float Primer operando
 * \param Float Segundo operando
 * \return Float Resultado de la operaci�n
 */
float restar(float numeroA, float numeroB)
{
    float resultado;

    resultado = numeroA - numeroB;


    return resultado;
}

/** \brief Realiza la operaci�n divisi�n
 * \param Float Primer operando
 * \param Float Segundo operando
 * \return Float Resultado de la operaci�n
 */
float dividir(float numeroA, float numeroB)
{
    float resultado;

    resultado = numeroA / numeroB;


    return resultado;
}

/** \brief Realiza la operaci�n multiplicaci�n
 * \param Float Primer operando
 * \param Float Segundo operando
 * \return Float Resultado de la operaci�n
 */
float multiplicar(float numeroA, float numeroB)
{
    float resultado;

    resultado = numeroA * numeroB;


    return resultado;
}

/** \brief Realiza la operaci�n factorial validando que el numero no sea negativo ni decimal
 * \param float N�mero a calcular factorial
 * \return int Resultado de la operaci�n
 */
int factorial(float numeroA)
{
    int i;
    int retorno=-1;
    int factorial=1;
    int numeroInt= (int)numeroA;

    if(numeroA==0 || numeroA==1)
    {
        retorno=1;
    }
    else if(numeroA<0)
    {
        printf("\n> No se puede calcular el factorial de un numero negativo\n");
        retorno= -2;
    }
    else if((numeroA - numeroInt)!=0)
    {
        printf("\n> No se puede calcular el factorial de un numero decimal\n");
        retorno=-3;
    }
    else
    {
        for(i=1; i<=numeroInt; i++)
        {
            factorial= i*factorial;
        }
        retorno= factorial;
    }

    return retorno;
}


