/*
      Este programa utiliza tres módulos para trabajar con 
      vectores dinamicos
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
    double *vd;
    int util_vector;

    cout << "Introduzca numero de componentes: ";
    cin >> util_vector;

    vd = new double [util_vector];

    LecturaVector(vd, util_vector);

    cout << "La media del vector es: " 
         << MediaVector(vd, util_vector) << endl;;

    cout << "Los elementos del vector son: " << endl;
    ImprimeVector(vd, util_vector);
    
    delete [] vd;
    
    system("pause");
}
