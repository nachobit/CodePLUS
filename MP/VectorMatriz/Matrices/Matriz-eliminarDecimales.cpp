/*
      Este programa lee una matriz de reales, elimina los decimales de sus
      elementos y finalmente muestra por pantalla la matriz resultante
*/

#include <iostream>
#include <cmath>
using namespace std;

const int MAX_FIL = 100, MAX_COL = 100;   // Constantes Globales

void LecturaMatriz (double m[][MAX_COL], int utilFil_m, int utilCol_m)
{
    for (int i=0; i<utilFil_m; i++)
        for (int j=0; j<utilCol_m; j++)
        {
             cout << "Introducir el elemento (" << i << "," << j << "): ";
             cin >> m[i][j];
        }
}

void EliminarDecimales (double m[][MAX_COL], int utilFil_m, int utilCol_m)
{
    for (int i=0; i<utilFil_m; i++)
        for (int j=0; j<utilCol_m; j++)
            m[i][j] = floor(m[i][j]);

}

void ImprimeMatriz (const double m[][MAX_COL], int utilFil_m, int utilCol_m)
{
   for (int i=0; i<utilFil_m; i++)
        for (int j=0; j<utilCol_m; j++)
        {
             cout << m[i][j] << endl;
        }
}

int main()
{
    int i, j;
    double m[MAX_FIL][MAX_COL];
    int utilFil_m, utilCol_m;

     do{
        cout << "Introducir el numero de filas: ";
        cin >> utilFil_m;
    }while ( (utilFil_m<1) || (utilFil_m>MAX_FIL) );

    do{
       cout << "Introducir el numero de columnas: ";
       cin >> utilCol_m;
    }while ( (utilCol_m<1) || (utilCol_m>MAX_COL) );

    LecturaMatriz(m, utilFil_m, utilCol_m);

    EliminarDecimales(m, utilFil_m, utilCol_m);

    ImprimeMatriz(m, utilFil_m, utilCol_m);
}
