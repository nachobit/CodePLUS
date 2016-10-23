#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

int main (int argc, char **argv)
{
    ifstream f;
    string nombre;
    char c;

    cout << "\nNombre del fichero: ";
    cin >> nombre;

    f.open ( nombre.c_str() );

    if (!f)
    {
        cout << "Error: no puedo abrir " << nombre << endl;
        exit (1);
    }

    c = f.get();
    while ( !f.eof() )
    {
        cout.put (c);
        c = f.get();
    }

    f.close();

    return (0);
}
