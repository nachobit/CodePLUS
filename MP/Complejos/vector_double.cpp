/*
      Este programa trabaja con la estructura vector_double
*/

#include <iostream>
using namespace std;

struct vector_double
{
   double vector [1000];
   int util;
};

vector_double LecturaVector_double ()
{
     vector_double v;

     do{
       cout << "Introduzca número de componentes: ";
       cin >> v.util;
     }while (v.util>1000 || v.util<0);

     cout << "\nIntroduzca valores reales:\n";
     for (int i=0 ; i<v.util ; i++)
     {
         cout << "Posición " << i << ": ";
         cin >> v.vector[i];
     }

     return v;
}

void Intercambiar (double &a, double &b)
{
   double tmp = a;
   a = b;
   b = tmp;
}

void OrdenarVector_double (vector_double &v)
{
      int izda, i;

      for (izda=0; izda<v.util; izda++)
          for (i = v.util - 1; i>izda; i--)
             if (v.vector[i] < v.vector[i-1])
                Intercambiar(v.vector[i], v.vector[i-1]);
}
void ImprimeVector_double (vector_double v)
{
     for (int i=0; i<v.util; i++)
         cout << v.vector[i] << endl;
}

int main()
{
    vector_double v;

    v=LecturaVector_double();

    OrdenarVector_double(v);

    cout << "El vector ordenado es: " << endl;
    ImprimeVector_double(v);
}
