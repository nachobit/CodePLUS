#include "vectordinamico.h"

//Constructor con dos argumentos: numero de casillas y valor para inicializar todas las casillas.
//(podemos implementar todos los constructores con un unico metodo si usamos valores por defecto).
VectorDinamico::VectorDinamico(int casillas, int inicializador){
    p = new int[casillas];
    utilizados=0;
    for(int i=0; i<casillas; i++){
        p[i] = inicializador;
        utilizados++;
    }
}

//Constructor con un argumento, que indica el numero de posiciones
//deseadas en el vector, e inicializa todos los elementos a 0.
VectorDinamico::VectorDinamico(int elemtos){
    VectorDinamico(elemtos, 0);
}

//Constructor sin argumentos, que crea un vector vacío.
VectorDinamico::VectorDinamico(){
    VectorDinamico(0, 0);
}

//Destructor
VectorDinamico::~VectorDinamico(){
    delete [] p;
    p=0;
    utilizados=0;
}

//Metodo para consultar el tamaño del vector.
int VectorDinamico::getTamanio(){
    return utilizados;
}
//Metodo para obtener el valor en la posicion i.
int VectorDinamico::get(int i){
    if(i<utilizados)
        return p[i];
}
//Metodo para modificar el valor de la posicion i.
void VectorDinamico::set(int i, int valor){
    p[i]=valor;
}

//Metodo para aumentar el tamaño del vector en un determinado numero de posiciones
//(pasado como argumento). Los nuevos elementos se inicializan a 0, pero el metodo
//se encarga de preservar todos los que hubiese.
void VectorDinamico::agrandar(int nuevo_tama){
    if(nuevo_tama>utilizados){
        int * aux = new int[utilizados];
        for(int i=0; i<utilizados; i++)
            aux[i] = p[i];
        delete [] p;
        p = new int[nuevo_tama];
        for(int i=0; i<utilizados; i++)
            p[i] = aux[i];
        for(int i=utilizados; i<nuevo_tama; i++)
            p[i] = 0;
    }
    else{
        cerr <<  "No puedes agrandar el vector a un tamanio mas pequenio..." << endl;
    }
}
