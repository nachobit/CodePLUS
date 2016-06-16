#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

/************************************************/
int main (int argc, char **argv)
{
    double x1, x2;
    ifstream fi_1, fi_2;
    ofstream fo;

    if (argc < 3)
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: "<< argv[0]<<" <fichE1> <fichE2> <fichS>\n";
        exit (1);
    }

    fi_1.open ( argv[1] );
    if ( !fi_1 )
    {
        cout << "Error: no puedo abrir fichE1" << endl;
        exit (1);
    }

    fi_2.open ( argv[2] );
    if ( !fi_2 )
    {
        cout << "Error: no puedo abrir fichE2" << endl;
        exit (1);
    }

    fo.open (argv[3]);
    if ( !fo )
    {
        cout << "Error: no puedo abrir fichS" << endl;
        exit (1);
    }

    fi_1 >> x1;
    fi_2 >> x2;

    while ( ! fi_1.eof() && ! fi_2.eof() )
          if ( x1 < x2 )
          {
              fo << x1 << endl;
              fi_1 >> x1;
          }
          else
         {
              fo << x2 << endl;
              fi_2 >> x2;
          }

    if ( fi_1.eof() )
        while( ! fi_2.eof() )
        {
              fo << x2 << endl;
              fi_2 >> x2;
        }
    else
        while ( ! fi_1.eof() )
        {
              fo << x1 << endl;
              fi_1 >> x1;
        }

    fi_1.close();
    fi_2.close();
    fo.close();

    return 0;
}
