#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main ()
{
    ifstream fi;
    int n, cont=0, sum=0;

    fi.open ("datos");

    if (!fi)
    {
        cout << "Error: no pudo abrirse fich. datos\n";
        exit (1);
    }

    cout<< "\n(Suma acumulada = " << sum << "). ";

    while (fi >> n)
    {
        cout <<"Valor leido num. " << cont+1 <<" : " << n << endl;
        sum += n;

        cont++;

        cout << "(Suma acumulada = " << sum << "). ";
    }

    cout << "\nLa suma total de los " << cont;
    cout << " enteros leidos es " << sum << endl;

    fi.close();

    return (0);
}

