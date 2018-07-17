#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Calculadora.h"
#include "Consola.h"

int main()
{
    float numeroA;
    float numeroB;
    int AestaCargado=0;
    int BestaCargado=0;

    int resultadoInt=0;
    float resultado=0;
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
                if(AestaCargado==1 && BestaCargado==1)
                {
                    resultado= sumar(numeroA, numeroB);

                    printf("\n> El resultado de la suma es %.2f + %.2f = %.2f \n\n", numeroA, numeroB, resultado);
                }
                else
                {
                    printf("\n> Debe ingresar dos operandos para realizar esta operacion\n");
                }

                presionarContinuar();

                break;
            case 4:
                if(AestaCargado==1 && BestaCargado==1)
                {
                    resultado= restar(numeroA, numeroB);

                    printf("\n> El resultado de la resta es %.2f - %.2f = %.2f \n\n", numeroA, numeroB, resultado);
                }
                else
                {
                    printf("\n> Debe ingresar dos operandos para realizar esta operacion\n");
                }

                presionarContinuar();

                break;
            case 5:
                if(AestaCargado==1 && BestaCargado==1)
                {
                    if(numeroB==0)
                    {
                        printf("\n> Error! Numero invalido para realizar esta operacion\n");
                    }
                    else
                    {
                        resultado= dividir(numeroA, numeroB);

                        printf("\n> El resultado de la division es %.2f / %.2f = %.2f \n\n", numeroA, numeroB, resultado);
                    }
                }
                else
                {
                    printf("\n> Debe ingresar dos operandos para realizar esta operacion\n");
                }

                presionarContinuar();

                break;
            case 6:
                if(AestaCargado==1 && BestaCargado==1)
                {
                    resultado= multiplicar(numeroA, numeroB);

                    printf("\n> El resultado de la multiplicacion es %.2f x %.2f = %.2f \n\n", numeroA, numeroB, resultado);
                }
                else
                {
                    printf("\n> Debe ingresar dos operandos para realizar esta operacion\n");
                }

                presionarContinuar();
                break;
            case 7:
                if(AestaCargado==1)
                {
                    resultadoInt= factorial(numeroA);
                    if(resultadoInt<0)
                    {
                        printf("\n> Reingrese el primer operando\n");
                    }
                    else
                    {
                        printf("\n> El factorial de %.0f! es = %d\n\n", numeroA, resultadoInt);
                    }
                }
                else
                {
                    printf("\n> Debe seleccionar la opcion 1 e ingresar un numero\n");
                }


                presionarContinuar();
                break;
            case 8:
                system("cls");

                if(AestaCargado==1 && BestaCargado==1)
                {
                    printf("\n> El resultado de la suma es %.2f + %.2f = %.2f \n", numeroA, numeroB, sumar(numeroA, numeroB));
                    printf("\n> El resultado de la resta es %.2f - %.2f = %.2f \n", numeroA, numeroB, restar(numeroA, numeroB));
                    if(numeroB==0)
                    {
                        printf("\n> Error! Numero invalido para realizar la operacion division\n");
                    }
                    else
                    {
                        resultado= dividir(numeroA, numeroB);

                        printf("\n> El resultado de la division es %.2f / %.2f = %.2f \n\n", numeroA, numeroB, resultado);
                    }
                    printf("\n> El resultado de la multiplicacion es %.2f x %.2f = %.2f \n", numeroA, numeroB, multiplicar(numeroA, numeroB));

                    resultadoInt= factorial(numeroA);
                    if(resultadoInt<0)
                    {
                        printf("\n> Reingrese el primer operando\n");
                    }
                    else
                    {
                        printf("\n> El factorial de %.0f! es = %d\n\n", numeroA, resultadoInt);
                    }
                }
                else
                {
                    printf("> Debe ingresar dos numeros para poder realizar las operaciones\n");
                }

                presionarContinuar();
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');


    return 0;
}
