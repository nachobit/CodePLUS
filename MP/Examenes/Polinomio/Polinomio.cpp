#include "Polinomio.h"
#include <iostream>
#include <assert.h>

using namespace std;

void Polinomio::inicializar() {
    // Se inicializa a 0 el valor de grado
    grado = 0;

    // Se reserva espacio para el array de coeficientes
    coeficientes = new float[maximoGrado + 1];

    // Se inicializan a valor 0
    for (int i = 0; i <= maximoGrado; i++) {
        coeficientes[i] = 0.0;
    }
}

Polinomio::Polinomio(int maximoGrado) {
    // Si maximo grado es negativo se hace que el programa
    // finalice
    assert(maximoGrado >= 0);

    // Si el valor de maximoGrado es correcto, se asigna su
    // valor al dato miembro
    this->maximoGrado = maximoGrado;

    // Se inicializan los demas datos miembro
    inicializar();
}

Polinomio::Polinomio(const Polinomio &p) {
    maximoGrado = p.maximoGrado;
    grado = p.grado;
    coeficientes = new float[maximoGrado+1];
    for(int i=0; i<=maximoGrado; i++) {
        coeficientes[i] = p.coeficientes[i];
    }
}

void Polinomio::asignarCoeficiente(int i, float c) {
    if (i >= 0) { // Si el indice del coeficiente es valido
        if (i > maximoGrado) { // Si necesitamos mas espacio
            float *aux = new float[i + 1]; // Reservamos nueva memoria
                for (int j = 0; j <= grado; ++j) // Copiamos coeficientes a nueva memoria
                    aux[j] = coeficientes[j];
                delete[] coeficientes; // Liberamos memoria antigua
                coeficientes = aux; // Reasignamos puntero de coeficientes
                for (int j = grado + 1; j <= i; ++j) //Hacemos 0 el resto de nuevos coeficientes
                    coeficientes[j] = 0.0;
                maximoGrado = i; // Asignamos el nuevo numero maximo grado del polinomio
        }
        coeficientes[i] = c; // Asignamos el nuevo coeficiente

        // actualizamos el grado
        if (c != 0.0 && i > grado)//Si coeficiente!=0 e indice coeficiente>antiguo grado
            grado = i; // lo actualizamos al valor i
        else
            if (c == 0.0 && i == grado)//Si coeficiente==0.0 e indice coeficiente==grado
                while (coeficientes[grado] == 0.0 && grado > 0)//Actualizamos grado con el
                    grado--; //primer termino cuyo coeficiente no sea cero
    }
}

void Polinomio::imprimir() const {
    cout << obtenerCoeficiente(obtenerGrado()); //Imprimir termino de grado mayor

    if(obtenerGrado()>0)
        cout<<"x^"<<obtenerGrado();

    for(int i=obtenerGrado()-1; i>=0; --i){ //Recorrer el resto de terminos
        if(obtenerCoeficiente(i)!=0.0){ //Si el coeficiente no es 0.0
            cout << std::showpos << obtenerCoeficiente(i) << std::noshowpos; //imprimirlo
            if(i>0)
                cout << "x^" << i;
        }
    }
    cout << endl;
}

Polinomio Polinomio::sumar(const Polinomio &pol) const {
    int gmax=(this->grado>pol.grado)?this->grado:pol.grado;

    Polinomio res(gmax);
    for(int i=0;i<=gmax;++i){
        res.asignarCoeficiente(i,this->coeficientes[i]+pol.coeficientes[i]);
    }
    return res;
}

void Polinomio::liberar(){
    delete[] coeficientes;
    grado=0;
    maximoGrado=-1;
}

Polinomio::~Polinomio() {
    delete[] coeficientes;
}

Polinomio Polinomio::operator+(const Polinomio &pol) {
    Polinomio res = this->sumar(pol);
    return res;
}

float & Polinomio::operator[](int i) {
    assert(i>=0); assert(i<=grado);
    return coeficientes[i];
}

const float & Polinomio::operator[](int i) const {
    assert(i>=0); assert(i<=grado);
    return coeficientes[i];
}

Polinomio &Polinomio::operator=(const Polinomio &p) {
    if(&p != this) {
        delete[] this->coeficientes;
        this->maximoGrado = p.maximoGrado;
        this->grado = p.grado;
        this->coeficientes = new float[this->maximoGrado + 1];
        for (int i = 0; i <= maximoGrado; i++)
            this->coeficientes[i] = p.coeficientes[i];
    }
    return *this;
}

ostream & operator<<(ostream & flujo, const Polinomio &p) {
    flujo << p.obtenerCoeficiente(p.obtenerGrado()); //Imprimir termino de grado mayor

    if(p.obtenerGrado()>0)
        flujo <<"x^"<<p.obtenerGrado();

    for(int i=p.obtenerGrado()-1; i>=0; --i){ //Recorrer el resto de terminos
        if(p.obtenerCoeficiente(i)!=0.0){ //Si el coeficiente no es 0.0
            flujo << std::showpos << p.obtenerCoeficiente(i) << std::noshowpos; //imprimirlo
            if(i>0)
                flujo << "x^" << i;
        }
    }
    flujo << endl;
    return flujo;
}

istream & operator>>(istream & flujo, Polinomio &p) {
    int g;
    float v;
    do {
        flujo >> v >> g;    // Introducir par <valor> <grado>
        if(g>=0) {
            p.asignarCoeficiente(g, v);
        }
    } while (g>=0);
    return flujo;
}



