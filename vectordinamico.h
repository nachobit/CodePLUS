#include <iostream>
using namespace std;

class VectorDinamico{
    private:
        int * p;
        int utilizados;

    public:
        VectorDinamico(int casillas, int inicializador);
        VectorDinamico(int elemtos);
        VectorDinamico();
        ~VectorDinamico();
        int getTamanio();
        int get(int i);
        void set(int i, int valor);
        void agrandar(int nuevo_tama);
};
