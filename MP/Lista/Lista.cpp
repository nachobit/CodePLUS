#include <iostream>
#include "Lista.h"

Lista::Lista() {
    l = 0;
}

void Lista::anadirAlFinal(double valor) {
    if(l != 0) {
        // Lista no vacia
        Celda *p = l;
        while (p->sig != 0) {   // Mover p hasta el ultimo elemento
            p = p->sig;
        }
        p->sig = new Celda;
        p->sig->info = valor;
        p->sig->sig = 0;

    } else {
        // Lista vacia
        l = new Celda;
        l->sig = 0;
        l->info = valor;
    }
}

void Lista::eliminarUltimo() {
    if(l != 0) {
        // Lista no vacia
        if(l->sig != 0) {
            // Lista con mas de un elemento
            Celda *p = l;
            while(p->sig->sig != 0)     // Mover p hasta el penultimo elemento
                p=p->sig;
            delete p->sig;
            p->sig=0;
        } else {
            // Lista con un elemento
            delete l;
            l = 0;
        }
    }
}

void Lista::eliminar() {
    Celda *p = l, *p_siguiente = 0;
    while(p != 0) {                     // Recorrer toda la lista, incluyendo el ultimo elemento
        p_siguiente = p->sig;
        delete p;
        p = p_siguiente;
    }
    l = 0;

    /* Implementacion alternativa: */
    /* while(p->sig != 0) {
         p_siguiente = p->sig;
         delete p;
         p = p_siguiente;
       }
       delete p; // <-- necesario, porque el ultimo elemento de la lista no se ha liberado
       l = 0;
     */
}

void Lista::imprimir() const {
}

void Lista::anadirDespues(Celda *celda, double valor) {
}

void Lista::anadirPrimero(double valor) {
}

void Lista::anadirAntes(Celda *celda, double valor) {
    // Mover p hasta el elemento anterior a 'celda'
}
