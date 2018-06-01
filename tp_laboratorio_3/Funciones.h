#ifndef ESTRUCTURAMOVIE_H_INCLUDED
#define ESTRUCTURAMOVIE_H_INCLUDED

#define OCUPADO 1
#define LIBRE 0


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
}eMovie;

void mostrarMenu();
void presionarContinuar();

int eMovie_init(eMovie[],int limite);

int getInt();
char getChar();
void getString(char mensaje[],char input[]);

void loadData(typedef struct eMovie* p);
int saveMovie(typedef struct eMovie* p);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie movies);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie movies);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(eMovie lista[], char nombre[]);

#endif // ESTRUCTURAMOVIE_H_INCLUDED
