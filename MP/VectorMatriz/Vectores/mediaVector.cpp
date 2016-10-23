/*
      Este programa utiliza tres módulos para trabajar con vectores
*/

#include <iostream>
using namespace std;

void LecturaVector (double v[], int util_v)
{
     cout << "\nIntroduzca valores reales:\n";
     for (int i=0 ; i<util_v ; i++)
     {
         cout << "Posición " << i << ": ";
         cin >> v[i];
     }
}

double MediaVector (const double v[], int util_v)
{
    double media = 0;
    int i;
    
    for (i=0 ; i<util_v ; i++)
       media = media + v[i];

    return media / util_v;
}

void ImprimeVector (const double v[], int util_v)
{
    for (int i=0; i<util_v; i++)
       cout << v[i] << endl;
}

int main()
{
    const int MAX = 1000;
    double vector[MAX];
    int util_vector;

    do{
       cout << "Introduzca numero de componentes: ";
       cin >> util_vector;
    }while (util_vector>MAX || util_vector<0);

    LecturaVector(vector, util_vector);

    cout << "La media del vector es: " 
         << MediaVector(vector, util_vector) << endl;;

    cout << "Los elementos del vector son: " << endl;
    ImprimeVector(vector, util_vector);
    
    system("pause");
}
