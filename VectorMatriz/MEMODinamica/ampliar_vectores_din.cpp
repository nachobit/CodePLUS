#include <iostream>
using namespace std;

void AmpliarVD(int * &vd, int nelems, int nadicional)
{
    int *vd_ampliado = new int[nelems + nadicional];

    for (int i= 0; i<nelems; i++)
        vd_ampliado[i] = vd[i];

    delete [] vd;

    vd = vd_ampliado;
}

int main()
{
     bool primera_vez=true;
     int *vd, x, nelems;
     double media;

     cout << "Introducir real (hasta 0): ";
     cin >> x;
     while (x != 0)
     {
         if (primera_vez)
         {
            vd = new int [1];
            vd[0]=x;
            nelems=1;

            primera_vez=false;
         }
         else
         {
            AmpliarVD(vd, nelems, 1);
            vd[nelems]=x;
            nelems++;
         }

         cout << "Introducir real (hasta 0): ";
         cin >> x;
     }

     // Calcular la media
    media=0;
    for (int i= 0; i<nelems; i++)
      media = media + vd[i];

    cout << "La media es: " << media / nelems << endl;

    // Liberar memoria
    delete [] vd;

    system("pause");
}
 
