#ifndef __PUNTO_H
#define __PUNTO_H

#include <iostream>

class Punto{

public:
    Punto(){};
    Punto(int x,int y){this->x=x;this->y=y;};
    void setX(int x){this->x=x;};
    void setY(int y){this->y=y;};
    bool operator!=(const Punto &punto) const {return !(x==punto.x && y==punto.y);};
    friend std::ostream& operator<<(std::ostream &flujo,const Punto &punto);
    friend std::istream& operator>>(std::istream &flujo,Punto &punto);

private:
    int x,y;
};

#endif // __PUNTO_H
