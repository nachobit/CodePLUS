#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main ()
{
    ofstream fo;

    fo.open ("fichero_salida");

    if ( fo.fail() )     // También es válido:  if (!fo)
    {
          cout << "Error: no pudo crearse fichero_salida\n";
          exit (1);
    }

    fo << "Esto es una prueba ..." << endl;

    fo.close();

    return (0);
}
