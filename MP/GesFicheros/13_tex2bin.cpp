#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main (int argc, char **argv)
{
    double x; 
    ifstream fi; 
    ofstream fo;
    
    if (argc != 3) 
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: " << argv[0]<< " <fichE_text> <fichS_bin>\n";
        exit (1);
    }

    fi.open (argv[1]); 
                       
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

    while ( fi >> x )
        fo.write ( (const char *) (&x), sizeof (double) );
    
    fi.close(); 
    fo.close();
    
    return (0);
}
