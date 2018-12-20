/**********************************************************************
*  PROGRAMACION I. CURSO 2018-2019. PRACTICA 4.                       *
*  PROYECTO SETI                                                      *
*  La aplicaci�n procesa se�ales que llegan a la tierra desde el      *
*  espacio exterior. Este proceso incluye:                            *
*       1.- A�adir una nueva captura, que es la se�al recibida        *
*           junto con la fecha y radiotelescopio de recepci�n.        *
*       2.- Analizar las capturas en busca de se�ales candidatas      *
*           a tener un origen no natural y escribir los datos de      *
*           las mismas por la salida est�ndar y en un fichero de      *
*           texto (la escritura en fichero se realiza en la fase      *
*           final de la pr�ctica).                                    *
*       3.- Visualizar datos de una captura.
                                AbbEI
                                Hola humanos
                                QQFW
                                0FFFF

*
*                                                                     *
* NOTA: EL ALUMNO DEBER� COMPLETAR ESTE ESQUELETO, SIN MODIFICAR LO   *
*       QUE YA EST� ESCRITO. SE DEBEN DEFINIR LOS TIPOS DE DATOS      *
*       DE LA APLICACI�N CON LOS MISMOS NOMBRES QUE APARECEN EN EL    *
*       ENUNCIADO. SE A�ADIR�N EL RESTO DE CONSTANTES, PROTOTIPOS Y   *
*       DEFINICIONES DE FUNCIONES DE LA APLICACI�N.                   *
**********************************************************************/
#include <stdio.h>
#include <string.h>
#include "lectura_escritura_T.h"


/******     CONSTANTES    ******/

/** Longitud maxima del campo senial (emisi�n interestelar recibida) */
#define MAX_SENIAL 80

/** Longitud maxima del campo fecha */
#define MAX_FECHA 12

/** Longitud maxima del nombre de radiotelescopio */
#define MAX_NOMBRE 20

/** N�mero m�ximo de capturas que se pueden almacenar.
    Para poder probar la funcionalidad de la aplicaci�n se ha reducido a 5 */
#define MAX_CAPTURAS 5

/** Longitud maxima de cada secuencia (subcadena) candidata a tener un origen no natural */
#define MAX_SUBCADENA 15

/** N�mero de secuencias candidatas a tener un origen no natural almacendas */
#define MAX_SUBCADENAS 5








/******     TIPOS DE DATOS   ******/

/** Tipo de dato para la variable que almacena las secuencias con posible origen no natural */
typedef char tSubcadena[MAX_SUBCADENA];
typedef tSubcadena tSubcadenas[MAX_SUBCADENAS];

typedef char tNombre [MAX_NOMBRE];
typedef char tFecha [MAX_FECHA];
typedef char tSenial [MAX_SENIAL];


typedef struct {tNombre nombre;
                tFecha fecha;
                tSenial senial;
                }tCaptura;
typedef struct {tCaptura captura;
                int ocupado;
                }tMiembroSeti;

typedef tMiembroSeti tSeti [MAX_CAPTURAS];




/******     PROTOTIPOS    ******/


/**************************************************************************************
 Funci�n: inicializarCapturas
        Inicializa la estructura de datos.
    Par�metro de salida:
        capturas: estructura que almacena la informaci�n de la aplicaci�n
 ***************************************************************************************/
void inicializarCapturas(tSeti capturas);

/**************************************************************************************
 Funci�n: incluirCaptura
       Incluye una nueva captura, que es la se�al recibida
       junto con la fecha y radiotelescopio de recepci�n.
    Par�metro de entrada/salida:
        capturas: estructura que almacena la informaci�n de la aplicaci�n
***************************************************************************************/
void incluirCaptura (tSeti capturas);

/**************************************************************************************
 Funci�n: haySitioEnCapturas
       Analiza si hay sitio en capturas para a�adir una nueva captura.
    Par�metro de entrada:
        capturas: estructura que almacena la informaci�n de la aplicaci�n
    Par�metro de salida (por referencia):
        sitio: �ndice del array donde hay sitio, en el caso de que lo haya.
    Par�metro de salida (valor devuelto por la funci�n):
             1 si hay sitio
             0 si no hay sitio
    Postcondici�n: s�lo en el caso de que el valor devuelto por la funci�n
                    sea 1 tiene sentido el valor del par�metro "sitio"
***************************************************************************************/
int haySitioEnCapturas (const tSeti capturas, int *sitio);

/**************************************************************************************
 Funci�n: existeCaptura
       Analiza si existe en capturas una captura con el nombre de
       radiotelescopio igual a "nom".
    Par�metros de entrada:
        capturas: estructura que almacena la informaci�n de la aplicaci�n
        nom: nombre del radiotelescopio que se busca
    Par�metro de salida (por referencia):
        pos: �ndice del array donde est� la captura asociada al radiotelescopio
              de nombre "nom", en el caso de que exista dicha captura.
    Par�metro de salida (valor devuelto por la funci�n):
             1 existe
             0 no existe
    Postcondici�n: s�lo en el caso de que el valor devuelto por la funci�n
                    sea 1 tiene sentido el valor del par�metro "pos"
*******************************************************************************/
int existeCaptura(const tSeti capturas, const tNombre nom, int *pos);

/**************************************************************************************
 Funci�n: analizarCapturas
       El an�lisis consiste en buscar, en la se�al de cada captura, la
       aparici�n de alguna secuencia candidata a tener un origen no natural.
       Si una se�al incluye alguna de estas secuencias, se convierte
       en se�al prometedora y los datos de la captura que la contiene
       se imprimen por pantalla.
    Par�metros de entrada:
        capturas: estructura que almacena la informaci�n de la aplicaci�n
        secuencias: array de cadenas de caracteres que contiene las
                    subcadenas (secuencias) candidatas a tener un origen
                    no natural.

***************************************************************************************/
void analizarCapturas(const tSeti capturas, const tSubcadenas secuencias);
//void datosCaptura(void);
//int menu(void);

void datosCaptura(tSeti capturas);

int menu(void);







int main (void)
{
    /** Array que contiene secuencias de origen no natural.
       En la �ltima fase de la pr�ctica estos datos
       se leer�n del fichero de texto "emisionesInteligentes.txt" */
    const tSubcadenas subcs={"ABBEI", "010011","Hola humanos", "QQFW", "0FFFF"};

    printf("/************************************************************************\n"
           "/*  PROGRAMACION I. CURSO 2018-2019. PRACTICA 4.                        *\n"
           "/*  PROYECTO SETI                                                       *\n"
           "/*  La aplicacion procesa se�ales que llegan a la tierra desde el       *\n"
           "/*  espacio exterior. El usuario puede:                                 *\n"
           "/*       1.- Incluir una nueva captura, que es la se�al recibida        *\n"
           "/*           junto con la fecha y radiotelescopio de recepcion.         *\n"
           "/*       2.- Analizar las capturas en busca de se�ales candidatas       *\n"
           "/*           a tener un origen no natural y escribir los datos de       *\n"
           "/*           las mismas en un fichero.                                  *\n"
           "/*       3.- Visualizar datos de una captura.                           *\n"
           " ************************************************************************ \n");

    tSeti capturas;
    inicializarCapturas(capturas);
    int opcion;

	do
	{
		opcion=menu();
		switch(opcion)
		{
            case 1: /*Incluir una captura */
				incluirCaptura(capturas);
				break;

			case 2: /* Analizar captura */
				analizarCapturas(capturas,subcs);
				break;

			case 3: /*  Visualizar datos de un radiotelescopio */
				datosCaptura(capturas);
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


/* Fin del main */

/* FUNCIONES */

/* Codificaci�n completa de menu  */

int menu(void){
    int opcion;
    printf("\n\n1.- Incluir una captura \n2.- Analizar captura \n3.- Visualizar datos de un radiotelescopio \n4.- Salir\nESCOJA UNA OPCION:");
    scanf("%d",&opcion);
    fflush(stdin);

    return(opcion);

}
//Funci�n analizar capturas
 void analizarCapturas(const tSeti capturas, const tSubcadenas secuencias){
    int i;
    int b;

    for(i=0;i<MAX_CAPTURAS;i++){
        for(b=0;b<MAX_CAPTURAS;b++){
            //printf("La captura es : %s\n",capturas[i].captura.senial.senial);
            //printf("La secuencia es: %s\n",secuencias[b]);
            if(strstr(capturas[i].captura.senial,secuencias[b]) != NULL) {
                  printf("Captura prometedora.... :\n");
                  printf("\n*********\n%s\n----------\n%s----------\n%s\n",capturas[i].captura.nombre,capturas[i].captura.fecha,capturas[i].captura.senial);

            }
        }
    }

}
//datos Captura
void datosCaptura(tSeti capturas){
    tSubcadena telescopio;
    int i;
    printf("Introduzca el nombre del radiotelescopio: \n");

    scanf("%s",telescopio);
    fflush(stdin);
    int contador=0;
    int pos;
    for (i=0;i<MAX_CAPTURAS;i++){
        if(strcmp(capturas[i].captura.nombre,telescopio)==0)
            contador = contador +1;
            pos = i;
    }
    if(contador >=1){
        printf("\n\n\n*********\n%s\n----------\n%s----------\n%s",telescopio,capturas[pos].captura.fecha,capturas[pos].captura.senial);
    }else{
        printf("No existen datos de ese radiotelescopio\n\n");
    }
}

 //Funci�n incluirCaptura
/**void incluirCaptura (tSeti capturas)
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

}**/
void incluirCaptura (tSeti capturas){

    tNombre nombre;
    tSenial senial;
    tFecha fecha;
    int pos;
    int sitio =0;

    fflush(stdin);

    printf("Escriba el nombre del radiotelescopio\n");
    scanf("%s",&nombre);
    // printf("post nombre\n");


    int existe = existeCaptura(capturas,nombre,&pos);
    // printf("post existe\n");
    // printf("El valor de existe es: %d\n",existe);

    if (existe==0){
        printf("Ya existe un radiotelescopio con ese nombre. Se sustituye la senial recibida.\n");

          printf("Introduzca la senial (emision interestelar):\n");

            fflush(stdin);

            fgets(senial,MAX_SENIAL, stdin);

            strcpy(capturas[pos].captura.senial,senial);

            printf("Introduzca la fecha con formato dd-mm-aa:\n");

            fflush(stdin);

            fgets(fecha,MAX_FECHA, stdin);

            strcpy(capturas[pos].captura.fecha,fecha);
    }
    else if(existe == 1){
        printf("No hay capturas previas de este radiotelescopio.\n");

        if(haySitioEnCapturas(capturas,&sitio)){
            // printf("Se aniade a la red\n");
            // printf("El sitio es %d\n",sitio);
            // printf("El nombre es %s\n",nombre.nombre);

            strcpy(capturas[sitio].captura.nombre,nombre);
            // printf("El nombre guardado en la posicion %d de memoria es: %s\n",sitio,capturas[sitio].captura.nombre.nombre);
            capturas[sitio].ocupado = 1;
            // printf("Se ha puesto como ocupado la posicion %d, su valor es %d\n", sitio, capturas[sitio].ocupado);

            printf("Introduzca la senial (emision interestelar):\n");

            fflush(stdin);

            fgets(senial,MAX_SENIAL, stdin);

            strcpy(capturas[sitio].captura.senial,senial);

            printf("Introduzca la fecha con formato dd-mm-aa:\n");

            fflush(stdin);

            fgets(fecha,MAX_FECHA, stdin);

            strcpy(capturas[sitio].captura.fecha,fecha);

            // printf("La senial de la captura en el sitio %d es %s , su fecha es:'%s'",sitio,  capturas[sitio].captura.senial.senial, capturas[sitio].captura.fecha.fecha);

        }else{
            printf("Lo sentimos no hay sitio para mas capturas\n");
        }
    }
}
//HaysitioenCapturas
int haySitioEnCapturas (const tSeti capturas, int *sitio){

    int i;
    int posicion=0;
    for(i=0;i<MAX_CAPTURAS;i++){
        if(capturas[i].ocupado == 0){
            *sitio = i;
            posicion++;
        }
    }
    if (posicion >=1){
        return 1;
    }else{
        return 0;
    }
}
//existeCapturas
int existeCaptura(const tSeti capturas, const tNombre nom, int *pos){

   // printf("Existe captura\n");
    int i;
    int existe=0;
    // printf("Existe captura2\n");
    // printf("el nombre dentro de existe captura es: %s\n",nom.nombre);
    // printf("Existe captura3\n");

   // printf("%s\n",capturas[1].captura.nombre.nombre);

    for(i=0;i<MAX_CAPTURAS;i++){

        if(strcmp(capturas[i].captura.nombre,nom)==0){
        *pos = i;
           existe = existe + 1;

        }
    }

    if(existe >=1){
        return 0;
    }else{
        return 1;
    }

}
//inicializarCapturas
void inicializarCapturas(tSeti capturas){

    int i;
    for(i=0;i<MAX_CAPTURAS;i++){
        capturas[i].ocupado = 0;
       // strcpy(capturas[i].captura.nombre.nombre,"NOXE");

    }
}

