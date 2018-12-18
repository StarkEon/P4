#ifndef _LECTURA_ESCRITURA_T_H
#define _LECTURA_ESCRITURA_T_H


#define MAXLONGITUD 30
#define MAXCADENAS 10
typedef char tCadena [MAXLONGITUD];
typedef tCadena tTexto [MAXCADENAS];
/**
* Función que escribe una tabla de cadenas de caracteres en un fichero de
* texto, de nombre nombreFich. Recibe como parámetros el nombre del
* fichero y la tabla de cadenas de caracteres con el texto a escribir.
*/
void escribirFichero (const char nombreFich[], tTexto texto);
/**
* Función que lee de un fichero de texto cadenas de caracteres y
* las almacena en una tabla de cadenas de caracteres.
* Recibe como parámetros el nombre del fichero y la tabla de
* cadenas de caracteres que almacenará el texto leído.
*/
void leerFichero (const char nombreFich[], tTexto texto);
/**
* Función auxiliar que lee un numCar de caracteres desde pf y
* los almacena en cadena sin el caracter '\n'
*/
void leerCadena(char *cadena, int numCar, FILE *pf);
/**
* función auxiliar que inicializa las tablas con cadenas vacias
*/
void inicializarTexto (tTexto texto);
#endif
