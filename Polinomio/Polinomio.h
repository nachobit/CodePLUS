#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
using namespace std;

class Polinomio {

private:
    /**
    * Array con los coeficientes del polinomio
    */
    float *coeficientes;

    /**
    * Grado del polinomio
    */
    int grado;

    /**
    * Maximo grado posible: limitacion debida a la implementacion
    * de la clase: el array de coeficientes tiene un tamaño limitado
    */
    int maximoGrado;

    /**
    * Metodo auxiliar para inicializar los datos miembro
    */
    void inicializar();

    /**
     * Método auxiliar para liberar manualmente la memoria dinámica reservada
     * para los coeficientes del polinomio
     */
    void liberar();


public:

    /**
    * Constructor
    * @param maxGrado (default 10)
    */
    Polinomio(int maxGrado = 10);


    /**
     * Constructor de copia
     * @param p Objeto que se copiará
     */
    Polinomio(const Polinomio &p);

    /**
    * Obtiene el grado del polinomio
    * @return grado
    */
    inline int obtenerGrado() const {
        return grado;
    }

    /**
    * Permite acceder a los coeficientes del objeto. Si no se
    * trata de un coeficiente valido, devuelve 0
    * @param indice asociado al coeficiente
    * @return coeficiente solicitado
    */
    inline float obtenerCoeficiente(int indice) const {
        return ((indice > grado || indice < 0) ? 0.0 : coeficientes[indice]);
    }

    /**
     * Permite asignar el coeficiente asociado a un determinado término
     * @param i indice asociado al coeficiente
     * @param c coeficiente para asignar
     */
    void asignarCoeficiente(int i, float c);

    /**
     * Imprime un polinomio
     */
    void imprimir() const;

    /**
     * Suma dos polinomios
     * @param pol Polinomio que se sumará al objeto
     * @return Polinomio suma resultado
     */
    Polinomio sumar(const Polinomio &pol) const;

    /**
     * Destructor
     */
    ~Polinomio();

    /**
     * Operador de suma
     */
    Polinomio operator+(const Polinomio &p);

    /**
     * Operador de asignación
     */
    Polinomio & operator=(const Polinomio &p);

    /**
     * Operador de indexación (obtenerCoeficiente no es necesario)
     * @param i Entero en el rango [0, maximoGrado]
     */
    float & operator[](int i);

    /**
     * Operador de indexación para constantes (obtenerCoeficiente no es necesario)
     * @param i Entero en el rango [0, maximoGrado]
     */
    const float & operator[](int i) const;

};

ostream & operator<<(ostream & flujo, const Polinomio &p);
istream & operator>>(istream & flujo, Polinomio &p);

#endif //POLINOMIO_H
