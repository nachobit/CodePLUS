#include <cassert>
#include <cstring>
#include <fstream>
#include "polilinea.h"

using namespace std;

//El constructor sin parametros (crea una linea poligonal vacia)
Polilinea::Polilinea(){
    p=0;
    num=0;
}

Polilinea::Polilinea(int n){
    if(n>0){
        p=new Punto[n];
        num=n;
    }
    else{
        p=0;
        num=0;
    }
}
//Destructor
Polilinea::~Polilinea(){
    if(p){
        delete[] p;
    }
}

//Constructor de copia
Polilinea::Polilinea(const Polilinea& other){
    copy(other);
}

//Operador de asignación
Polilinea& Polilinea::operator=(const Polilinea& polilinea){
    if (this != &polilinea){
        if(this->p)
            delete[] this->p;
        copy(polilinea);
    }
    return *this;
}

void Polilinea::copy(const Polilinea& other){
    this->p=new Punto[other.num];
    this->num=other.num;
    for(int i=0;i<this->num;++i){
        this->p[i]=(other.p)[i];
    }
}

void Polilinea::append(const Punto &punto){
    Punto *pNew=new Punto[this->num+1];

    for(int i=0;i<this->num;++i){ //copiamos puntos antiguos
        pNew[i]=p[i];
    }
    pNew[num]=punto; //insertamos el nuevo punto
    if(p){
        delete[] p;
    }
    p=pNew;

    this->num++;
}

//Operador de acceso (permite acceder a un dato de tipo Punto en una PoliLinea)
Punto& Polilinea::operator[](int i){
    assert(i>=0); assert(i<=num);
    return p[i];
}

const Punto& Polilinea::operator[](int i) const{
    assert(i>=0); assert(i<=num);
    return p[i];
}

//Operador de igualdad ==
bool Polilinea::operator==(const Polilinea& polilinea) const{
    bool iguales=true;

    if(this==&polilinea){
        return true;
    }
    if (num==polilinea.num){
        if(num>0){
            for(int i=0;i<num && iguales;++i){ // comprobar si son iguales en mismo orden
                if(p[i]!=(polilinea.p)[i]){
                    iguales=false;
                }
            }
            if(!iguales){ // si no eran iguales en mismo orden
                iguales=true;
                for(int i=0;i<num && iguales;++i){ // comprobar si son iguales en orden inverso
                    if(p[i]!=(polilinea.p)[num-i-1]){
                        iguales=false;
                    }
                }
            }
        }
    }
    else{
        iguales=false;
    }
    return iguales;
}

//Operador de desigualdad !=
bool Polilinea::operator!=(const Polilinea& polilinea) const{
    return !(*this==polilinea);
}

//Sobrecarga del operador + (para añadir un punto a luna linea poligonal...)
Polilinea operator+(const Polilinea& polilinea,const Punto &punto){
    Polilinea polResultado=polilinea;

    polResultado.append(punto);
    return polResultado;
}

Polilinea operator+(const Punto &punto, const Polilinea& polilinea){
    Polilinea polResultado(polilinea.getNPoints()+1);

    polResultado[0]=punto;
    for(int i=0;i<polilinea.getNPoints();++i){
        polResultado[i+1]=polilinea[i];
    }
    return polResultado;
}

ostream& operator<<(ostream &flujo,const Polilinea &polilinea){
    flujo<<polilinea.num<<endl;
    for(int i=0;i<polilinea.num;++i){
        flujo<<(polilinea.p)[i]<<endl;
    }
    return flujo;
}

istream& operator>>(istream &flujo,Polilinea &polilinea){
    flujo>>polilinea.num;
    if(polilinea.p){
      delete[] polilinea.p;
    }
    polilinea.p=new Punto[polilinea.num];
    for(int i=0;i<polilinea.num;++i){
        flujo>>(polilinea.p)[i];
    }
    return flujo;
}


/*
El fichero siempre comienza por la cadena POLILINEA 
El comentario es opcional y, en caso de estar:
    Comienza por el caracter # 
    Solo ocupa una linea
    No hay limite de caracteres
    N es el numero de puntos que tiene la polilinea
    Despues de N tenemos la lista de coordenadas de cada punto
    Cada punto se escribe en una nueva linea y las coordenadas estan separadas por un espacio
*/
//Implementar un metodo para cargar en memoria una PoliLinea desde un fichero:
void Polilinea::LeerPolilinea(const char *nombre){
    ifstream file(nombre);
    char cadena[1000];

    if(file){
        file>>cadena;
        if(strcmp(cadena,"POLILINEA")!=0){
            cerr<<"Error de lectura: Esperaba la cadena POLILINEA"<<endl;
            return;
        }

        char caracter;
        file>>caracter;
        if(caracter=='#'){
            file.getline(cadena,1000);
        }
        else{
            file.unget();
        }
        file>>this->num;
        if(this->p){
            delete[] this->p;
        }
        this->p=new Punto[this->num];
        for(int i=0;i<(this->num);++i){
            file>>(this->p)[i];
        }
    }
    else{
        cerr<<"Error: No se pudo abrir el fichero "<<nombre<<endl;
        return;
    }
}

//Implementar un metodo para escribir en un fichero una PoliLinea:
void Polilinea::EscribirPolilinea(const char *nombre, const char *comentario) const{
    ofstream file(nombre);
    if(file){
        file<<"POLILINEA"<<endl;
        if(comentario){
            file<<"#"<<comentario<<endl;
        }
        file<<this->num<<endl;
        for(int i=0;i<this->num;++i){
            file<<(this->p)[i]<<endl;
        }
    }
    else{
        cerr<<"Error: No se pudo abrir el fichero "<<nombre<<endl;
        return;
    }
}
