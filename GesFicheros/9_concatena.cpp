#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/************************************************/
void concatenar (ofstream & salida, ifstream & entrada)
{
    int c;

    c = entrada.get();
    while (!entrada.eof())
    {
         salida.put (c);
         c = entrada.get();
    }
}

/************************************************/
int main (int argc, char **argv)
{
    ifstream fi;
    ofstream fo;

    if (argc < 2)
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: "<< argv[0]<<" <fichE1> <fichS>\n";
        exit (1);
    }

    fo.open ( argv[2], ios::app );
    if (!fo)
    {
        cout << "Error: no puedo abrir " << argv[2] << endl;
        exit (1);
    }

    fi.open ( argv[1] );
    if ( !fi )
    {
        cout << "Error: no puedo abrir " << argv[1] << endl;
        exit (1);
    }
    
    fo << "\nFichero: " << argv[1] << endl;
  
    concatenar (fo, fi);
    
    fi.close();

    fo.close();

    return (0);
}
