#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

/************************************************/
void espaciado (ofstream & s, ifstream & e, int n)
{
    int c;
    c = e.get();

    while (!e.eof()) 
    {
        s.put (c);
        
        if (c == '\n')
            for (int i=1; i<=n; i++) 
                 s.put (c);
                 
        c = e.get();
    } 
}

/************************************************/
int main (int argc, char **argv)
{
    ifstream fi;
    ofstream fo;
    int n;

    if ( (argc < 3) || (argc > 4) )  
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: " << argv[0]<< "<fichE> <fichS>[<lin>]\n";
        exit (1);
    }

    if (argc == 3) // No se da valor a <lin>
         n = 0; // valor por defecto
    else 
    {
         n = atoi(argv[3]);
         if (n < 0) 
            cout << "Error: <lin> debe ser >= 0\n";
         exit (1);
    }
    
    fi.open (argv[1]);
    if (!fi) 
    {
        cout << "Error: no puedo abrir "<< argv[1] << endl;
        exit (1);
    }
    
    fo.open (argv[2]);
    if (!fo) 
    {
       cout << "Error: no puedo crear " << argv[2] << endl;
       exit (1);
    }
    
    espaciado (fo, fi, n);
    
    fi.close ();
    fo.close ();
    
    return (0);
}
