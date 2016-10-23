#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdlib>

using namespace std;


/************************************************/
void cuenta ( ifstream & f, int & nl, int & np, int & nc )
{
    bool en_palabra=false;
    char c;

    nl = np = nc = 0;

    c = f.get ();
    while ( !f.eof() )
    {
        nc++;
        
        if ( isspace(c) )
        {
            en_palabra = false;
            
            if (c == '\n')
                nl++;
        }
        else
            if (!en_palabra)
            {
                np ++;
                en_palabra = true;
            }    

        c = f.get ();
    }
}

/************************************************/
int main (int argc, char **argv)
{
    ifstream fi;

    int nlineas, npalabras, ncaracteres;
    int tot_lineas,tot_palabras,tot_caracteres;
    int i, num_args = argc;

    if (argc == 1)
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: " << argv[0]<< " <fich1> ";
        cout << "[<fich2>...<fichn>]\n\n";
        exit (1);
    }

    tot_lineas = tot_palabras = tot_caracteres = 0;

    for (i=1; i<=num_args-1; i++)
    {
        fi.open (argv[i]);

        if (!fi)
            cout << "Error: no puedo abrir " << argv[i] << endl;
        else
        {
            cuenta (fi, nlineas, npalabras, ncaracteres);

            fi.close ();

            tot_caracteres += ncaracteres;
            tot_lineas += nlineas;
            tot_palabras += npalabras;

            cout << setw(7) << nlineas << setw(8) << npalabras << setw(8) << ncaracteres << " " << argv[i] << endl;
        }
    }

    if (num_args > 2)
       cout << setw(7) << tot_lineas << setw(8) << tot_palabras << setw(8) << tot_caracteres << " total\n";

    return (0);
}
