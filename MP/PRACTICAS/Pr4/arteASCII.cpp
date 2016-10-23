#include <iostream>
#include <fstream>
#include <string>
#include "byte.h"
#include "imagen.h"
#include "pgm.h"
using namespace std;


void lee_linea(char c[], int tamano){
    do{
        cin.getline(c, tamano);
    }while(c[0] == '\0');
}


int main(){

    //const int MAX = 200000;
    const int LONG = 60;

    //char arteASCII[MAX];
    char nombre_imagen[LONG];     //nombre de la imagen de entrada
    char nombre_grises[LONG];        //nombre del fichero de caracteres de entrada
    char img_salida[LONG];         //nombre parcial de las imagenes de salida
    ifstream entrada;
    Imagen origen;

    int n_cadenas; //numero de cadenas que hay en <nombre_grises>
    char aux[100];

    cout << "imagen de entrada (imagenes/<nombre>.pgm): ";
    lee_linea(nombre_imagen, LONG);
    cout << "fichero de cadenas (<nombre>.txt): ";
    lee_linea(nombre_grises, LONG);
    cout << "fichero de salida: ";
    lee_linea(img_salida, LONG);

    entrada.open(nombre_grises);

    //Leemos el fichero de grises (comprobando errores) -->
    if(entrada){
        entrada.getline(aux, 80);    //ignoramos la primera linea
        entrada >> n_cadenas;        //capturamos el numero de cadenas de <nombre_grises>

        if(!entrada){
            cerr << "Error de lectura del fichero de caracteres...\n";
        }

        //Aqui leemos el resto del fichero y almacenamos en los ficheros de salida
        string nombre;
        for(int i=0; i<=n_cadenas; i++){
            if(entrada){
                //defino el nombre del archivo de salida
                nombre = img_salida + to_string(i) + ".txt";
                ofstream fsalida(nombre);
                char auxiliar[LONG];
                entrada.getline(auxiliar, LONG);
                fsalida << auxiliar;
                fsalida.close();
            }
        }
        entrada.close();
    }
    else{
        cerr << "Error de apertura del fichero de caracteres...\n";
    }

    //Leemos la imagen de entrada y creamos los ficheros ASCII correspondientes
    if(!origen.leerImagen(nombre_imagen)){
        cout << "Error leyendo imagen " << nombre_imagen << "...";
        return 1;
    }

    // cout << "\nLa imagen en arte ASCII es:\n";
    // if(origen.aArteASCII(grises, arteASCII, MAX))
    //     cout << arteASCII;
    // else
    //     cout << "La conversion no ha sido posible" << endl;

    return 0;
}
