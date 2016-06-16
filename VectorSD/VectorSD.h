#ifndef EJERCICIO22_VECTORSD_H
#define EJERCICIO22_VECTORSD_H

class VectorSD {
    double *info;
    int util;
    int reservado;

public:
    VectorSD(int reserva);
    void anadirElemento(double valor);
    void imprimir();
    VectorSD copiar();
    VectorSD *copiarPtr();
    VectorSD &copiarRef();
    void liberar();
    double obtenerElemento(int pos);
    int obtenerUtiles();
};

#endif //EJERCICIO22_VECTORSD_H
