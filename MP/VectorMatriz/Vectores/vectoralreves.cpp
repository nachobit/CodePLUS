/*
      Este muestra al revés un vector de 15 reales
*/

#include <iostream>
using namespace std;

int main(){
    const int MAX = 15;
    double v[MAX];

    for (int i=0; i<MAX; i++)
    {
        cout << "Introducir dato : ";
        cin >> v[i];
    }

    for (int i=MAX-1; i>=0; i--)
        cout << v[i] << endl;
}
