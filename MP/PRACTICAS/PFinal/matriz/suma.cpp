#include <iostream>
#include <string>
#include <cstring>
#include "pgm.h"
#include "imagen.h"
#include "byte.h"
using namespace std;

int main(int argc, char *argv[]){

        if(argc != 5){
            cerr << "Error en el uso: ./suma <img1>.pgm <img2>.pgm <img_resultado>.pgm (t)exto/(b)inario" << endl;
            exit(-1);
        }

        Imagen primera, segunda;
        char nombre[100];
        bool es_binario;

        if(*argv[4]=='t')
            es_binario=false;
        else if(*argv[4]=='b')
            es_binario=true;
        else{
            cerr << "Formato de salida desconocido..." << endl;
            exit(-1);
        }
        strcpy(nombre, argv[1]);
        if(!primera.leerImagen(nombre)){
            cerr << "Error leyendo la primera imagen..." << endl;
            exit(-1);
        }
        strcpy(nombre, argv[2]);
        if(!segunda.leerImagen(nombre)){
            cerr << "Error leyendo la segunda imagen..." << endl;
            exit(-1);
        }

        //Si llegamos hasta aqui, no ha habido errores de lectura
        Imagen resultado = primera+segunda;
        strcpy(nombre, argv[3]);
        if(!resultado.escribirImagen(nombre, es_binario)){
            cerr << "Error al escribir en imagen de destino..." << endl;
            exit(-1);
        }else
            cout << "\nConcatenacion realizada. Comprueba el fichero de salida." << endl;

        return 0;
}
