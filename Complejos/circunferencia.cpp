// Programa que utiliza un módulo que comprueba si un punto está dentro de
// una circunferencia

#include <iostream>
#include <cmath>
using namespace std;

struct Punto
{
   double x;
   double y;
};
struct Circunferencia
{
   Punto centro;
   double radio;
};


Punto LeerPunto()
{
    Punto p;

    cout << "       Introducir x: ";
    cin >> p.x;

    cout << "       Introducir y: ";
    cin >> p.y;

    return p;
}

Circunferencia LeerCircunferencia()
{
    Circunferencia c;

    c.centro = LeerPunto();

    cout << "Introducir radio: ";
    cin >> c.radio;

    return c;
}

double DistanciaEuclidea(Punto p1, Punto p2)
{
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

bool EstaPuntoCircunferencia(Punto p,
                             Circunferencia c)
{
    if (DistanciaEuclidea(p, c.centro) <= c.radio)
       return true;
    else
       return false;
}

int main()
{
   Punto p;
   Circunferencia c;

   cout <<"Introducir punto a comprobar: " << endl;
   p=LeerPunto();

   cout <<"Introducir circunferencia: " << endl;
   c=LeerCircunferencia();

   if (EstaPuntoCircunferencia(p,  c))
       cout << "El punto está dentro de la circunferencia" << endl;
   else
       cout << "El punto no está dentro de la circunferencia" << endl;
}
