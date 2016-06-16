#include <iostream>
#include "Lista.h"

using namespace std;

void rellenar(Lista * lista, int maxTam);

int main() {
    Lista *lista = new Lista;

    lista->anadirAlFinal(3.5);
    cout << endl << "Añadimos un valor: ";
    lista->imprimir();

    cout << endl << "Añadimos un segundo valor: ";
    lista->anadirAlFinal(2.4);
    lista->imprimir();

    cout << endl << "Añadimos un tercer valor: ";
    lista->anadirAlFinal(5.6);
    lista->imprimir();

    cout << endl << "Eliminamos el último valor (x1): ";
    lista->eliminarUltimo();
    lista->imprimir();
    cout << endl << "Eliminamos el último valor (x2): ";
    lista->eliminarUltimo();
    lista->imprimir();
    cout << endl << "Eliminamos el último valor (x3): ";
    lista->eliminarUltimo();
    lista->imprimir();

    cout << endl << "Eliminamos el último valor (x4): ";
    lista->eliminarUltimo();
    lista->imprimir();

    lista->anadirAlFinal(7.6);
    cout << endl << "Añadimos un valor: ";
    lista->imprimir();

    cout << endl << "Eliminamos todo: ";
    lista->eliminar();
    lista->imprimir();

    cout << endl << "Nueva lista: ";
    rellenar(lista, 5);
    lista->imprimir();

    cout << endl << "Añadir elemento 9 despues de la posicion 2: ";
    lista->anadirDespues(lista->l->sig->sig, 9);
    lista->imprimir();

    cout << endl << "Añadir elemento 7 en primera posicion: ";
    lista->anadirPrimero(7);
    lista->imprimir();

    cout << endl << "Añadir elemento 8 antes de la posicion 2: ";
    lista->anadirAntes(lista->l->sig->sig, 8);
    lista->imprimir();

}

void rellenar(Lista * lista, int maxTam) {
    for(int i=0; i<maxTam; i++)
        lista->anadirAlFinal(i+1);
}