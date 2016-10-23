#ifndef __POLILINEA_H
#define __POLILINEA_H

#include <iostream>


#include "punto.h"

class Polilinea{

public:
    Polilinea();
    ~Polilinea();
    Polilinea(int n);
    Polilinea(const Polilinea& other);
    Polilinea& operator=(const Polilinea& other);
    int getNPoints() const {return num;};
    Punto& operator[](int i);
    const Punto& operator[](int i) const;
    bool operator==(const Polilinea& rhs) const;
    bool operator!=(const Polilinea& rhs) const;
    void LeerPolilinea(const char *nombre);
    void EscribirPolilinea(const char *nombre, const char *comentario=0) const;

    friend std::ostream& operator<<(std::ostream &flujo,const Polilinea &polilinea);
    friend std::istream& operator>>(std::istream &flujo,Polilinea &polilinea);
    friend Polilinea operator+(const Polilinea& polilinea,const Punto &punto);
    friend Polilinea operator+(const Punto &punto,const Polilinea& polilinea);

private:
    Punto *p;
    int num;
    void copy(const Polilinea& other);
    void append(const Punto &punto);
};

Polilinea operator+(const Polilinea& polilinea,const Punto &punto);
Polilinea operator+(const Punto &punto,const Polilinea& polilinea);

#endif // __POLILINEA_H
