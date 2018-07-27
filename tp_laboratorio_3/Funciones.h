#ifndef ESTRUCTURAMOVIE_H_INCLUDED
#define ESTRUCTURAMOVIE_H_INCLUDED

#define OCUPADO 1
#define LIBRE 0


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[50];
}eMovie;

void mostrarMenu();
void pressContinue();

int getInt();
int getIntRango(char* mensaje, int desde, int hasta);
char getChar();
void getString(char mensaje[],char input[]);

void loadData(eMovie*);
int saveMovie(eMovie*);

/**
 *  Agrega una pelicula al archivo binario
 *  @param eMovie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie movies);

/**
 *  Borra una pelicula del archivo binario
 *  @param eMovie la estructura a ser eliminada del archivo
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
