#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main (int argc, char **argv)
{
    const int TAM_BUFFER = 1024; // Num. de bytes del buffer de lectura
    char buffer [TAM_BUFFER]; // Buffer de lectura

    ifstream fi; 
    int sum = 0; 

    if (argc != 2) 
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: " << argv[0]<< " <fich>\n";
        exit (1);
    }

    fi.open (argv[1], ios::binary); 
    
    if (!fi) 
    {
        cout << "Error: no puedo abrir " << argv[1] << endl;
        exit (1);
    }

    //while ( fi.read(reinterpret_cast<char*>(buffer), TAM_BUFFER) )
    
    while ( fi.read( buffer, TAM_BUFFER ) )
          sum += TAM_BUFFER;
    
    sum += fi.gcount(); 
    
    fi.close (); 
    
    cout << "\nFichero: " << argv[1] << ':' 
         << sum << " bytes, "
         << sum/1024.0<< " Kbytes\n\n";
    
    return (0);
}
