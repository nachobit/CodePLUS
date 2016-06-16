#include "racional.h"

Racional::Racional(){
    numerador = new int(0);
    denominador = new int(1);
}

Racional::Racional(const int & valor){
    numerador = new int(valor);
    denominador = new int(1);
}

Racional::Racional(const int &a, const int &b){
    numerador = new int(a);
    denominador = new int(b);
}

Racional::~Racional(){
    delete numerador;
    delete denominador;
}

int Racional::getNumerador(){
    return *numerador;
}

void Racional::setNumerador(int valor){
    *numerador=valor;
}

int Racional::getDenominador(){
    return *denominador;
}

void Racional::setDenominador(int valor){
    *denominador=valor;
}
