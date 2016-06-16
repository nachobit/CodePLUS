/*
      Este programa que utiliza un módulo que determina si dos vectores son
      iguales
*/

#include <iostream>
using namespace std;

bool SonIgVectores (const int v1[], int util_v1, const int v2[], int util_v2)
{
    bool iguales = true;

    if (util_v1 != util_v2)
        iguales = false;
    else
        for (int i=0; i<util_v1 && iguales; i++)
                if (v1[i] != v2[i])
                   iguales = false;

    return iguales;
}

void LecturaVector (int v[], int util_v)
{
     for (int i=0 ; i<util_v ; i++)
     {
         cout << "Posición " << i << ": ";
         cin >> v[i];
     }
}

int main()
{
    const int MAX = 1000;
    int v1[MAX], v2[MAX];
    int util_v1, util_v2;

    do{
       cout << "Introduzca número de componentes: ";
       cin >> util_v1;
    }while (util_v1 > MAX || util_v1 < 0);

    LecturaVector(v1, util_v1);

    do{
       cout << "Introduzca número de componentes: ";
       cin >> util_v2;
    }while (util_v2>MAX || util_v2<0);

    LecturaVector(v2, util_v2);

    if ( SonIgVectores(v1, util_v1, v2, util_v2) )
        cout << "Los vectores son iguales" << endl;
    else
        cout << "Los vectores NO son iguales" << endl;
}
