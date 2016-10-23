#include <iostream>
#include <fstream>
using namespace std;

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int d, int m, int a){
            dia=d;
            mes=m;
            anio=a;
        }
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        Fecha& operator=(const Fecha &otra){
            this->dia = otra.dia;
            this->mes = otra.mes;
            this->anio = otra.anio;
            return (*this);
        }
};

class Hora{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        Hora(int h, int m, int s){
            hora=h;
            minuto=m;
            segundo=s;
        }
        int getHora(){return hora;}
        int getMinuto(){return minuto;}
        int getSegundo(){return segundo;}
        Hora& operator=(const Hora &otra){
            this->hora = otra.hora;
            this->minuto = otra.minuto;
            this->segundo = otra.segundo;
            return *this;
        }
};

class Instante{
    private:
        Fecha fecha;
        Hora hora;
    public:
        Instante(Fecha f, Hora h){
            fecha=f;
            hora=h;
        }
        Fecha getFecha(){return fecha;}
        Hora getHora(){return hora;}
        Instante getInstante(){
            Fecha f(20,10,1995);
            Hora h(13,13);
            Instante salida(f,h);
            return salida;
        }
        double intervaloTiempo(const Instante & otro) const{
            return 12.0;
        }
};

class Punto{
    private:
        double latitud;
        double longitud;
        double altura;
    public:
        Punto(int lat, int lon, int alt){
            latitud=lat;
            longitud=lon;
            altura=alt;
        }
        double getLatitud(){return latitud;}
        double getLongitud(){return longitud;}
        double getAltura(){return altura;}
        Punto getPosicion(){
            Punto salida(0, 1, 2);
            return salida;
        }
        double distanciaAPunto(const Punto & otro) const{
            return 15.0;
        }
};

//////////////////////////////////////////////////////////////////////////////

struct PuntoDeRecorrido{
    Punto punto;
    Instante instante;
};

class Recorrido{
    private:
        PuntoDeRecorrido *puntos;       //Puntero a un array de "num_puntos" datos "PuntoDeRecorrido"
        int num_puntos;                             //Numero de puntos del recorrido
        bool activo;                                      //Indica si el recorrido esta activo
    public:
        Recorrido(bool estado){
            if(!estado){
                puntos = NULL;
                num_puntos = 0;
                activo = true;
            }
            else{
                activo = true;
                puntos = new PuntoDeRecorrido[];
                PuntoDeRecorrido aux;
            }
        }

        Recorrido(const Recorrido &old){
            puntos = new PuntoDeRecorrido[];
            for(int i=0; i<old.num_puntos; i++)
                this->puntos[i] = old.puntos[i];
            this->num_puntos = old.num_puntos;
        }

        ~Recorrido(){
            delete [] puntos;
            num_puntos = 0;
            activo = false;
        }

        Recorrido& operator=(const Recorrido &otro){
            delete [] puntos;
            puntos = new PuntoDeRecorrido[];
            for(int i=0; i<otro.num_puntos; i++)
                this->puntos[i] = otro.puntos[i];
            this->num_puntos = otro.num_puntos;
        }

        void FinRecorrido(PuntoDeRecorrido ultimo){
            activo = false;
            puntos[num_puntos].punto = ultimo.punto.getPosicion();
            puntos[num_puntos].instante = ultimo.instante.getInstante();
            num_puntos++;
        }

        double DistanciaRecorrido(){
            double suma=0;
            for(int i=1; i<num_puntos; i++)
                suma += puntos[i].punto.distanciaAPunto(puntos[i-1]);
            return suma;
        }

        double TiempoRecorrido(){
            double suma=0;
            for(int i=1; i<num_puntos; i++)
                suma += puntos[i].instante.intervaloTiempo(puntos[i-1]);
            return suma;
        }

        double velocidadMedia(){
            return ((DistanciaRecorrido()/1000)/(TiempoRecorrido()/3600));
        }

        void leerRecorrido(){

        }
};


/////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]){
    bool estado=true;
    Recorrido(estado);
}
