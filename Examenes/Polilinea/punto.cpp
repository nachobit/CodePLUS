#include <iostream>
#include "punto.h"

std::ostream& operator<<(std::ostream &flujo,const Punto &punto){
    flujo<<punto.x<<" "<<punto.y;
    return flujo;
}

std::istream& operator>>(std::istream &flujo,Punto &punto){
    flujo>>punto.x>>punto.y;
    return flujo;
}
