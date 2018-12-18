/**********************************************************************
*  PROGRAMACION I. CURSO 2018-2019. PRACTICA 4.                       *
*  PROYECTO SETI                                                      *
*  La aplicación procesa señales que llegan a la tierra desde el      *
*  espacio exterior. Este proceso incluye:                            *
*       1.- Añadir una nueva captura, que es la señal recibida        *
*           junto con la fecha y radiotelescopio de recepción.        *
*       2.- Analizar las capturas en busca de señales candidatas      *
*           a tener un origen no natural y escribir los datos de      *
*           las mismas por la salida estándar y en un fichero de      *
*           texto (la escritura en fichero se realiza en la fase      *
*           final de la práctica).                                    *
*       3.- Visualizar datos de una captura.
                                AbbEI
                                Hola humanos
                                QQFW
                                0FFFF

*
*                                                                     *
* NOTA: EL ALUMNO DEBERÁ COMPLETAR ESTE ESQUELETO, SIN MODIFICAR LO   *
*       QUE YA ESTÁ ESCRITO. SE DEBEN DEFINIR LOS TIPOS DE DATOS      *
*       DE LA APLICACIÓN CON LOS MISMOS NOMBRES QUE APARECEN EN EL    *
*       ENUNCIADO. SE AÑADIRÁN EL RESTO DE CONSTANTES, PROTOTIPOS Y   *
*       DEFINICIONES DE FUNCIONES DE LA APLICACIÓN.                   *
**********************************************************************/
#include <stdio.h>
#include <string.h>
#INCLUDE "lectura_escritura_T.h"


/******     CONSTANTES    ******/

/** Longitud maxima del campo senial (emisión interestelar recibida) */
#define MAX_SENIAL 80

/** Longitud maxima del campo fecha */
#define MAX_FECHA 12

/** Longitud maxima del nombre de radiotelescopio */
#define MAX_NOMBRE 20

/** Número máximo de capturas que se pueden almacenar.
    Para poder probar la funcionalidad de la aplicación se ha reducido a 5 */
#define MAX_CAPTURAS 5

/** Longitud maxima de cada secuencia (subcadena) candidata a tener un origen no natural */
#define MAX_SUBCADENA 15

/** Número de secuencias candidatas a tener un origen no natural almacendas */
#define MAX_SUBCADENAS 5








/******     TIPOS DE DATOS   ******/

/** Tipo de dato para la variable que almacena las secuencias con posible origen no natural */
typedef char tSubcadena[MAX_SUBCADENA];
typedef tSubcadena tSubcadenas[MAX_SUBCADENAS];
//typedef char tCadena [MAXLONGITUD];
//typedef tCadena tTexto [MAXCADENAS];
typedef char tNombre [MAX_NOMBRE];
typedef char tFecha [MAX_FECHA];
typedef char tSenial [MAX_SENIAL];


typedef struct {tNombre nombre;
                tFecha fecha;
                tSenial senial;
                }tCaptura;
typedef struct {tCaptura captura;
                int cupado;
                }tMiembroSeti;

typedef tMiembroSeti tSeti [MAX_CAPTURAS];




/******     PROTOTIPOS    ******/


/**************************************************************************************
 Función: inicializarCapturas
        Inicializa la estructura de datos.
    Parámetro de salida:
        capturas: estructura que almacena la información de la aplicación
 ***************************************************************************************/
void inicializarCapturas(tSeti capturas);

/**************************************************************************************
 Función: incluirCaptura
       Incluye una nueva captura, que es la señal recibida
       junto con la fecha y radiotelescopio de recepción.
    Parámetro de entrada/salida:
        capturas: estructura que almacena la información de la aplicación
***************************************************************************************/
void incluirCaptura (tSeti capturas);

/**************************************************************************************
 Función: haySitioEnCapturas
       Analiza si hay sitio en capturas para añadir una nueva captura.
    Parámetro de entrada:
        capturas: estructura que almacena la información de la aplicación
    Parámetro de salida (por referencia):
        sitio: índice del array donde hay sitio, en el caso de que lo haya.
    Parámetro de salida (valor devuelto por la función):
             1 si hay sitio
             0 si no hay sitio
    Postcondición: sólo en el caso de que el valor devuelto por la función
                    sea 1 tiene sentido el valor del parámetro "sitio"
***************************************************************************************/
int haySitioEnCapturas (const tSeti capturas, int *sitio);

/**************************************************************************************
 Función: existeCaptura
       Analiza si existe en capturas una captura con el nombre de
       radiotelescopio igual a "nom".
    Parámetros de entrada:
        capturas: estructura que almacena la información de la aplicación
        nom: nombre del radiotelescopio que se busca
    Parámetro de salida (por referencia):
        pos: índice del array donde está la captura asociada al radiotelescopio
              de nombre "nom", en el caso de que exista dicha captura.
    Parámetro de salida (valor devuelto por la función):
             1 existe
             0 no existe
    Postcondición: sólo en el caso de que el valor devuelto por la función
                    sea 1 tiene sentido el valor del parámetro "pos"
*******************************************************************************/
int existeCaptura(const tSeti capturas, const tNombre nom, int *pos);

/**************************************************************************************
 Función: analizarCapturas
       El análisis consiste en buscar, en la señal de cada captura, la
       aparición de alguna secuencia candidata a tener un origen no natural.
       Si una señal incluye alguna de estas secuencias, se convierte
       en señal prometedora y los datos de la captura que la contiene
       se imprimen por pantalla.
    Parámetros de entrada:
        capturas: estructura que almacena la información de la aplicación
        secuencias: array de cadenas de caracteres que contiene las
                    subcadenas (secuencias) candidatas a tener un origen
                    no natural.

***************************************************************************************/
void analizarCapturas(const tSeti capturas, const tSubcadenas secuencias);
void datosCaptura(void);
int menu(void);











int main (void)
{
    int opcion;

	do
	{
		opcion=menu();
		switch(opcion)
		{
            case 1: /*Incluir una captura */
				incluirCaptura();
				break;

			case 2: /* Analizar captura */
				printf("funcion 1");//analizarCapturas();
				break;

			case 3: /*  Visualizar datos de un radiotelescopio */
				printf("funcion 1");//datosCaptura();
				break;

			case 4:
				printf("\n\nFIN DEL PROGRAMA.\n\n");
				break;

			default:
				printf("\n\nOpcion incorrecta.\n\n");
		}

	} while(opcion != 4);

return 0;
}

    /** Array que contiene secuencias de origen no natural.
       En la última fase de la práctica estos datos
       se leerán del fichero de texto "emisionesInteligentes.txt" */
    const tSubcadenas subcs={"ABBEI", "010011","Hola humanos", "QQFW", "0FFFF"};


/* Fin del main */

/* FUNCIONES */

/* Codificación completa de menu  */

int menu(void){
    int opcion;
    printf("\n\n1.- Incluir una captura \n2.- Analizar captura \n3.- Visualizar datos de un radiotelescopio \n4.- Salir\nESCOJA UNA OPCION:");
    scanf("%d",&opcion);
    fflush(stdin);

    return(opcion);

}
//Función inicializar capturas
 void inicializarCapturas(tSeti capturas);

 //Función incluirCaptura
void incluirCaptura (tSeti capturas)
{
    char nombrerad[MAX_NOMBRE];
    printf("Escriba nombre del radiotelescopio :/n");
    leerCadena(nombrerad,MAX_NOMBRE, stdin);
    int i=existeCaptura();
    if (i=0)
       {if (haySitioEnCapturas()==1)
{
        printf("No hay capturas previas de este radiotelescopio. Se anade a la red\n");
}    do{iguales=*nombre==}

}
