/*
      Este programa utiliza un módulo que acepta un vector de enteros y
      devuelve otro vector con los elementos pares del primero
*/

#include <iostream>
using namespace std;

void SoloPares(const int v[], int util_v, int vPares[], int &util_vPares)
{
   util_vPares=0;
   for (int i=0; i<util_v; i++)
       if ( v[i]%2 == 0)
       {
           vPares[util_vPares]=v[i];
           util_vPares++;
       }
}

void LecturaVector (int v[], int util_v)
{
     cout << "\nIntroduzca valores enteros:\n";
     for (int i=0 ; i<util_v ; i++)
     {
         cout << "Posición " << i << ": ";
         cin >> v[i];
     }
}

void ImprimeVector (const int v[], int util_v)
{
    for (int i=0; i<util_v; i++)
       cout << v[i] << endl;
}

int main()
{
    const int MAX = 1000;
    int vector[MAX], vector_pares[MAX];
    int util_vector, util_vector_pares;

    do{
         cout << "Introduzca número de componentes: ";
         cin >> util_vector;
    }while (util_vector > MAX || util_vector < 0);

    LecturaVector(vector, util_vector);

    SoloPares(vector, util_vector, vector_pares, util_vector_pares);

    cout << "Los elementos del vector con los pares son: " << endl;
    ImprimeVector(vector_pares, util_vector_pares);
}
