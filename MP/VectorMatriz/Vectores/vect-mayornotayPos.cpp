/*
      Este programa determina la mayor nota y la posición que ocupa dentro
      de un vector
*/

#include <iostream>
using namespace std;

int main(){
    const int MAX = 1000;
    double notas[MAX], mayor;
    int util_notas, pos_mayor;

    do{
        cout << "Introduzca el número de alumnos (entre 1 y " << MAX << "): ";
        cin >> util_notas;
    }while (util_notas < 1 || util_notas > MAX);

    for (int i=0; i<util_notas; i++)
    {
        cout << "Nota[" << i << "] --> ";
        cin >> notas[i];
    }

    mayor = notas[0];
    pos_mayor = 0;

    for (int i=1; i<util_notas; i++)
       if (notas[i] > mayor)
       {
          mayor = notas[i];
          pos_mayor = i;
       }

    cout << "\nMayor: " << mayor << " Se encuentra en: " << pos_mayor << endl;
}
