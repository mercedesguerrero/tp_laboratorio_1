#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define OCUPADO 1
#define LIBRE 0
#define CANTIDAD 20

typedef struct {

    char nombre[30];
    int edad;
    long int dni;
    int estado;

}ePersona;

void inicializarPersonasEstado(ePersona[], int cantidad);
void inicializarPersonasHardCode(ePersona[]);

void mostrarMenu();
void presionarContinuar();

int mostrarListadoDePersonas(ePersona[], int limite);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona listaDePersonas[], int limite);

int altaDePersona(ePersona[], int cantidad);

void getString(char mensaje[], char input[]);
void getValidString(char mensaje[], char error[], char input[], int limite);
int pedirNumEntero(char mensaje[]);
int pedirNumEnteroLong(char mensaje[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona listaDePersonas[], long int dni, int limite);


int borrarUnaPersona(ePersona[], int limite);


#endif // FUNCIONES_H_INCLUDED

