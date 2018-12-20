#include "lectura_escritura_T.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void escribirFichero (const char nombreFich[], tTexto texto){
int i;
FILE *pf;
pf=fopen (nombreFich,"w");
if (pf != NULL){
i=0;
while ((i < MAXCADENAS) && (strlen (texto[i]))) {
fputs (texto[i], pf);
fputc ('\n',pf);
i++;
}
fclose (pf);
}
}


int leerFichero (const char nombreFich[], tTexto texto){
int i;
FILE *pf;
tCadena linea;
int okApertura;
okApertura=1;
pf=fopen (nombreFich,"r");
if (pf != NULL){
i=0;
leerCadena (linea, MAXLONGITUD, pf);
while ((i < MAXCADENAS) && (!feof(pf))) {
strcpy(texto[i], linea);
i++;
leerCadena (linea, MAXLONGITUD, pf);
}
fclose (pf);
}
else
okApertura=0;
return okApertura; // devuelve 1 si no hay error en la apertura
}


void leerCadena(char cadena[], int numCar, FILE *pf){
fgets(cadena, numCar, pf);
if (cadena[strlen ( cadena )-1]=='\n')
cadena[strlen ( cadena )-1]= '\0';
}

void inicializarTexto (tTexto texto){
int i;
for(i=0; i< MAXCADENAS; i++){
strcpy (texto [i],"");
}
}

