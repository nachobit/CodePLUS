#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/************************************************/
void copiar (ostream & salida, istream & entrada)
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

    if (argc > 2)
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: "<<argv[0]<<" [<ficheroE>]\n";
        exit (1);
    }

    if (argc == 1)
        copiar (cout, cin);
    else
    {
        fi.open (argv[1]);

        if (!fi)
        {
            cout << "Error: no puedo abrir " << argv[1] << endl;
            exit (1);
        }

        copiar (cout, fi);

        fi.close();
    }

    return (0);
}
