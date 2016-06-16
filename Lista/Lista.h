#ifndef EJERCICIO23_LISTA_H
#define EJERCICIO23_LISTA_H

struct Celda {
    double info;
    Celda *sig;
};

class Lista {
public:
    Celda *l;

    Lista();
    void anadirAlFinal(double valor);

    void eliminarUltimo();

    void eliminar();

    void imprimir() const;

    void anadirDespues(Celda *celda, double valor);

    void anadirPrimero(double valor);

    void anadirAntes(Celda *celda, double valor);
};


#endif //EJERCICIO23_LISTA_H
