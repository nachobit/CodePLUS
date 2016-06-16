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
        cout << "Uso: " << argv[0]<< " <fichE_bin> <fichS_text>\n";
        exit (1);
    }

    fi.open (argv[1], ios::binary); 
                       
    if (!fi) 
    {
        cout << "Error: no puedo abrir " << argv[1] << endl;
        exit (1);
    }

    fo.open (argv[2]); 
                                    
    if (!fo) 
    {
        cout << "Error: no puedo crear " << argv[2] << endl;
        exit (1);
    }

    while ( fi.read ( (char *) (&x), sizeof (double) ) )
         fo << x <<endl;
         
    fi.close(); 
    fo.close();
    
    return (0);
}
