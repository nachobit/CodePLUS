/*
      Este programa utiliza un módulo para quitar los elementos repetidos
      de un vector de caracteres guardando el resultado en otro
*/

#include <iostream>
using namespace std;

void QuitarRepetidos (const char original[], int util_original, 
                            char destino[],  int &util_destino)
{
    bool encontrado;
    int j;

    util_destino = 0;

    for (int i=0 ; i<util_original ; i++)
    {
          j = 0;
          encontrado = false;
          while (j<util_destino && !encontrado)
               if (original[i] == destino[j])
                  encontrado=true;
               else
                  j++;

          if (!encontrado)
          {
              destino[util_destino] = original[i];
              util_destino++;
          }
    }
}

void LecturaVector (char v[], int util_v)
{
     cout << "\nIntroduzca caracteres:\n";
     for (int i=0 ; i<util_v ; i++)
     {
         cout << "Posición " << i << ": ";
         cin >> v[i];
     }
}

void ImprimeVector (const char v[], int util_v)
{
    for (int i=0; i<util_v; i++)
        cout << v[i] << endl;
}

int main()
{
    const int MAX = 1000;
    char v[MAX], vSin[MAX];
    int util_v, util_vSin;

    do{
       cout << "Introduzca número de componentes: ";
       cin >> util_v;
    }while (util_v > MAX || util_v < 0);

    LecturaVector(v, util_v);

    QuitarRepetidos(v, util_v, vSin, util_vSin);

    cout << "El vector sin repetidos es: " << endl;
    ImprimeVector(vSin, util_vSin);
}
