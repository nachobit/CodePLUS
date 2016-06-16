/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "pgm.h"
#include "byte.h"
#include "imagen.h"
#include "lista.h"
using namespace std;

const int MAXLONG = 1000000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(int argc, char *argv[]){
    char ficheroGrises[MAXLONG];
    char ficheroImagen[MAXLONG];
    Imagen origen;
    Lista celdas;

	if(argc != 3){
		cerr << "ERROR: Uso --> ./arteASCII2 <nombre_imagen>.pgm <nombre_grises>.txt" << endl;
		exit(-1);
	}

    // Leer la imagen desde fichero
	strcpy(ficheroImagen, argv[1]);
    if (!origen.leerImagen(ficheroImagen)){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;
		return 1;
    }

	// Leer cadenas desde fichero
	strcpy(ficheroGrises, argv[2]);
	if (celdas.leerLista(ficheroGrises)){
		// realizar las conversiones
		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}
		else{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}
	}else{
		cerr << "Error lista de grises " << ficheroGrises << endl;
	}
	return 0;
}
