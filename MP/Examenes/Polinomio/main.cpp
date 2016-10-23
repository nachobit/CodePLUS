#include "Polinomio.h"
#include <iostream>

using namespace std;

int main() {
    // Prueba de la suma
    Polinomio sumando1(5);
    sumando1.asignarCoeficiente(0,3.8);
    sumando1.asignarCoeficiente(1,7.3);
    sumando1.asignarCoeficiente(2,-2.38);
    sumando1.asignarCoeficiente(3,-8.13);
    sumando1.asignarCoeficiente(4,6.63);
    sumando1.asignarCoeficiente(5,12.98);
    cout << "Sumando1: ";
    sumando1.imprimir();

    Polinomio sumando2(4);
    sumando2.asignarCoeficiente(0,5.8);
    sumando2.asignarCoeficiente(1,2.3);
    sumando2.asignarCoeficiente(2,-1.67);
    sumando2.asignarCoeficiente(3,4.56);
    sumando2.asignarCoeficiente(4,5.75);
    cout << "Sumando2: ";
    sumando2.imprimir();

    Polinomio resultado=sumando1.sumar(sumando2);
    cout << "Resultado: ";
    resultado.imprimir();

    Polinomio p1(sumando1);  // p1 inicializado con constructor de copia
    Polinomio p2 = p1;       // p2 inicializado con constructor de copia

    Polinomio *p3 = new Polinomio(p2);  // p3 inicializado con constructor de copia
    cout << "Polinomio dinamico: ";
    p3->imprimir();
    delete p3;

    Polinomio p5;
    p5 = sumando1 + sumando2;   // sobrecarga de '+'
    cout << "Resultado suma con sobrecarga de '+': ";
    p5.imprimir();

    Polinomio p6;
    p6 = p5;    // sobrecarga de '='
    cout << "Imprimir con sobrecarga de '=' y '<<': ";
    cout << p6; // sobrecarga de '<<'

    return 0;
}