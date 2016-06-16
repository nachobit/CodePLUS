#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main (int argc, char **argv)
{
    const int TAM_BUFFER = 1024; 
    char buffer [TAM_BUFFER]; 
    ifstream fi; 
    ofstream fo; 

    if (argc != 3) 
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: " << argv[0]<< " <fichE> <fichS>\n";
        exit (1);
    }
    
    fi.open (argv[1], ios::binary); 
    if (!fi) 
    {
        cout << "Error: no puedo abrir " << argv[1] << endl;
        exit (1);
    }
    
    fo.open (argv[2], ios::binary); 
    if (!fo) 
    {
        cout << "Error: no puedo crear " << argv[2] << endl;
        exit (1);
    }
    
    while ( fi.read (buffer, TAM_BUFFER) )
          fo.write (buffer, TAM_BUFFER);
    
    fo.write(buffer, fi.gcount()); 
    
    fi.close (); 
    fo.close (); 
    
    return (0);
}
