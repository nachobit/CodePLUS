/*
      Este programa lee una matriz de reales y muestra por pantalla la fila y
      columna del mayor
*/

#include <iostream>
using namespace std;

int main()
{
    const int MAX_FIL = 100, MAX_COL = 100;

    int i, j, i_mayor, j_mayor;
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

    for (i=0; i<utilFil_m; i++)
        for (j=0; j<utilCol_m; j++)
        {
             cout << "Introducir el elemento (" << i << "," << j << "): ";
             cin >> m[i][j];
        }

    i_mayor = 0;
    j_mayor = 0;
    for (i=0; i<utilFil_m; i++)
        for (j=0; j<utilCol_m; j++)
            if (m[i][j] > m[i_mayor][j_mayor])
            {
                i_mayor = i;
                j_mayor = j;
            }

    cout << "El mayor elemento se encuentra en: " << i_mayor << ',' << j_mayor << endl;
}
