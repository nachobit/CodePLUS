// Programa de ejemplo de procesamiento de un vector de complejos

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
    
    cout << "       Introducir parte imaginaria: ";
    cin >> c.imag;
    
    return c;
}

double ModuloComplejo(Complejo c)
{
    return sqrt(c.real*c.real+c.imag*c.imag);
}

void ImprimirComplejo(Complejo c)
{
    
    cout << endl;
    cout << "     " << c.real << "+" << c.imag << "i";
}

void IntercambiaComplejo(Complejo &c1, Complejo &c2)
{
    Complejo tmp=c1;
    c1=c2;
    c2=tmp;
}

void OrdBurbuja (Complejo v[], int Util_v)
{
     int izda, i;
     bool cambio;

     cambio= true;
     for (izda=0; izda<Util_v && cambio; izda++)
     {
          cambio=false;
          for (i=Util_v-1 ; i>izda ; i--)
              if ( ModuloComplejo(v[i]) < ModuloComplejo(v[i-1]) )
              {
                  IntercambiaComplejo(v[i], v[i-1]);
                  cambio=true;
              }
     }
}

int main() 
{
   const int MAX = 1000;
   Complejo v[MAX];
   int Util_v;
   
   do{
        cout << "Numero de compejos (<=" << MAX << "):";
        cin >> Util_v;
   }while (Util_v <= 0 || Util_v > MAX);
   
   for(int i=0; i<Util_v; i++)
   {
        cout << "\nEntrada del complejo: " << i << endl;
        v[i]=LeerComplejo();
   }
   
   OrdBurbuja (v, Util_v);
   
   cout << "\nLos complejos ordenados por su modulo son:" << endl;

   for(int i=0; i<Util_v; i++)
   {
       ImprimirComplejo(v[i]);      
       
       cout << " mod: " << ModuloComplejo(v[i]) << endl;
   }
   system("pause");
}
