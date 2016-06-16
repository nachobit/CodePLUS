#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main (int argc, char **argv)
{
    const int MAX_LINE=8; // Num. de enteros por línea
    int n; // Para almacenar cada número aleatorio
    ifstream fi; // Flujo de entrada
    
    // Comprobar el número de argumentos
    if (argc != 2) 
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: " << argv[0]<< " <fichE>\n";
        exit (1);
    }

    fi.open (argv[1], ios::binary); // Apertura (para lectura)
                                    // en modo binario
    if (!fi) 
    {
        cout << "Error: no puedo crear " << argv[1] << endl;
        exit (1);
    }
    
    int contador = 1;
    while ( fi.read ( (char *) (&n), sizeof (int) ) )
    {
        cout << setw (6) << n;
        
        if ( contador % MAX_LINE == 0 ) 
            cout << endl;
            
        contador++;    
    }
    
    fi.close(); 
    
    return (0);
}
