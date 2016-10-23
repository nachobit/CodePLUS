/*
      Este programa utiliza un módulo que busca un elemento x en un
      vector v
*/

#include <iostream>
using namespace std;

int Buscar(const int v[], int util_v, int x)
{
    int i;
    bool encontrado;

    i=0;
    encontrado=false;
    while (i<util_v && !encontrado)
         if (v[i] == x)
            encontrado=true;
         else
            i++;

    if (encontrado)
        return i;
    else
        return -1;
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

int main()
{
    const int MAX = 1000;
    int v[MAX];
    int x, util_v, pos;

    do{
       cout << "Introduzca número de componentes: ";
       cin >> util_v;
    }while (util_v > MAX || util_v < 0);

    LecturaVector(v, util_v);

    cout << "Introduzca elemento a buscar: ";
    cin >> x;

    pos = Buscar(v, util_v, x);

    if (pos!=-1)
       cout << x << " se encuentra en la posición: " << pos << endl;
    else
       cout << x << " NO se encuentra en el vector" << endl;
}
