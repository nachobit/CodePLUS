
/*
      Este programa que utiliza un módulo que determina si dos matrices son
      iguales
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

bool SonIgMatrices (const int m1[][MAX_COL], int utilFil_m1, int utilCol_m1,
                    const int m2[][MAX_COL], int utilFil_m2, int utilCol_m2)
{
    bool iguales = true;

    if (utilFil_m1 != utilFil_m2 || utilCol_m1 != utilCol_m2)
       iguales = false;
    else
        for (int i=0; i<utilFil_m1 && iguales; i++)
            for (int j=0; j<utilCol_m1 && iguales; j++)
                if (m1[i][j] != m2[i][j])
                   iguales = false;

    return iguales;
}

int main()
{
    int m1[MAX_FIL][MAX_COL], m2[MAX_FIL][MAX_COL];
    int utilFil_m1, utilCol_m1, utilFil_m2, utilCol_m2;

    do{
        cout << "Introducir el numero de filas: ";
        cin >> utilFil_m1;
    }while ( (utilFil_m1<1) || (utilFil_m1>MAX_FIL) );

    do{
       cout << "Introducir el numero de columnas: ";
       cin >> utilCol_m1;
    }while ( (utilCol_m1<1) || (utilCol_m1>MAX_COL) );

    LecturaMatriz(m1, utilFil_m1, utilCol_m1);

    do{
        cout << "Introducir el numero de filas: ";
        cin >> utilFil_m2;
    }while ( (utilFil_m2<1) || (utilFil_m2>MAX_FIL) );

    do{
       cout << "Introducir el numero de columnas: ";
       cin >> utilCol_m2;
    }while ( (utilCol_m2<1) || (utilCol_m2>MAX_COL) );

    LecturaMatriz(m2, utilFil_m2, utilCol_m2);

    if ( SonIgMatrices(m1, utilFil_m1, utilCol_m1, m2, utilFil_m2, utilCol_m2) )
        cout << "Las matrices son iguales" << endl;
    else
        cout << "Las matrices no son iguales" << endl;
}
