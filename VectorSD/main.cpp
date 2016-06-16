#include <iostream>
#include "VectorSD.h"

using namespace std;

int main() {

    // VectorSD bad{0};

    VectorSD vector(5);
    for(int i=0; i<5; i++)
        vector.anadirElemento( (i+1)*5);
    cout << "vector: ";
    vector.imprimir();

    VectorSD * vectorP = new VectorSD(5);
    vectorP->anadirElemento(3.3);
    cout << "elemento 0: " << vectorP->obtenerElemento(0) << endl;
    cout << "vectorP: ";
    vectorP->imprimir();
    vectorP->liberar();     // liberar 'info'
    delete vectorP;         // liberar 'vectorP'

    VectorSD copia = vector.copiar();
    cout << "copia: ";
    copia.imprimir();
    copia.liberar();

    VectorSD * copiaPtr = vector.copiarPtr();
    cout << "copiaPtr: ";
    copiaPtr->imprimir();
    copiaPtr->liberar();    // liberar 'info'
    delete copiaPtr;        // liberar 'copiaPtr'

    VectorSD & copiaRef = vector.copiarRef();
    cout << "copiaRef: ";
    copiaRef.imprimir();
    copiaRef.liberar();     // liberar 'info'
    delete &copiaRef;       // liberar variable con alias 'copiaRef'
                            // ¡Esta mezcla de 'new' y referencias no es una buena práctica de programación!

    vector.liberar();

    return 0;
}