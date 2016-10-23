/*
      Este programa que determina las posiciones de las vocales dentro
      de un vector que almacena caracteres
*/

#include <iostream>
using namespace std;

int main(){
    const int MAX = 1000;
    char v[MAX];
    int util_v;

    do{
        cout << "Introduzca el número de caracteres (entre 1 y " << MAX << "): ";
        cin >> util_v;
    }while (util_v < 1 || util_v > MAX);


    for (int i=0; i<util_v; i++)
    {
        cout << "Introducir caracter: ";
        cin >> v[i];
    }

    for (int i=0; i<util_v; i++)
       if (v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u')
           cout << "En: " << i << " esta: " << v[i] << endl;
}
