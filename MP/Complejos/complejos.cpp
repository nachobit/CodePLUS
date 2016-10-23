// Programa para el proceso de número complejos
#include <iostream>
using namespace std;

struct Complejo
{
    double real;
    double imag;
};

Complejo LeerComplejo()
{
    Complejo c;

    cout << "\n     Introducir parte real: ";
    cin >> c.real;

    cout << "     Introducir parte imaginaria: ";
    cin >> c.imag;

    return c;
}

Complejo SumaComplejos(Complejo c1, Complejo c2)
{
    Complejo c;

    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;

    return c;
}

void ImprimirComplejo(Complejo c)
{

    cout << endl;
    cout << "     " << c.real << "+" << c.imag << "i" << endl;
}

int main()
{
   Complejo c1, c2, c_s;

   cout <<"Introducir complejo 1";
   c1=LeerComplejo();

   cout <<"Introducir complejo 2";
   c2=LeerComplejo();

   c_s=SumaComplejos(c1, c2);

   cout <<"La suma es: ";
   ImprimirComplejo(c_s);
}
