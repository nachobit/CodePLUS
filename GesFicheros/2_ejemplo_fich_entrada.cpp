#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    int n;
    float r;
    char cad[50];

    ifstream fi ("fichero_entrada");

    fi >> n >> r >> cad;

    fi.close ();

    cout << "\nValores leidos: \n";
    cout << " Entero: " << n << endl;
    cout << " Real: " << r << endl;
    cout << " Cadena: " << cad << endl << endl;

    return (0);
}
