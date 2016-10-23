
/*
      Este programa comprueba si un vector se  corresponde con alguna de las
      filas de una matriz (consideramos que el tamaño del vector es igual al
      número de columnas de la matriz)
*/

#include <iostream>
using namespace std;

const int MAX_FIL = 100, MAX_COL = 100;   // Constantes Globales

void LecturaMatriz (int m[][MAX_COL], int utilFil_m, int utilCol_m)
{
    for (int i=0; i<utilFil_m; i++)
        for (int j=0; j<utilCol_m; j++)
        {
             cout << "Introducir el elemento (" << i << "," << j << "): ";
             cin >> m[i][j];
        }
}

void LecturaVector (int v[], int util_v)
{
     for (int i=0 ; i<util_v ; i++)
     {
         cout << "Posición " << i << ": ";
         cin >> v[i];
     }
}

bool SonIgVectorFila (const int m[][MAX_COL], int utilFil_m, int utilCol_m,
                      const int v[], int fila)
{
    bool iguales = true;

    for (int j=0; j<utilCol_m && iguales; j++)
        if (m[fila][j] != v[j])
            iguales = false;

    return iguales;
}

int main()
{
    bool encontrado;
    int m[MAX_FIL][MAX_COL], v[MAX_COL], fila;
    int utilFil_m, utilCol_m, util_v;

    do{
        cout << "Introducir el numero de filas: ";
        cin >> utilFil_m;
    }while ( (utilFil_m<1) || (utilFil_m>MAX_FIL) );

    do{
       cout << "Introducir el numero de columnas: ";
       cin >> utilCol_m;
    }while ( (utilCol_m<1) || (utilCol_m>MAX_COL) );

    LecturaMatriz(m, utilFil_m, utilCol_m);

    util_v = utilCol_m;

    LecturaVector(v, util_v);

    fila=0;
    encontrado=false;
    while (fila<utilFil_m && !encontrado)
         if ( SonIgVectorFila (m, utilFil_m, utilCol_m, v, fila) )
            encontrado=true;
         else
            fila++;

    if (encontrado)
        cout << "El vector corresponde a la fila: " << fila << endl;
    else
        cout << "El vector NO se corresponde con ninguna fila" << endl;
}
