#include <iostream>
using namespace std;

// <<<<< demo_write >>>>>>>
int main ()
{
    int numero=1222957230;

    cout.write( (char*)&numero, 2);
    cout << endl;
    cout.write( (char*)&numero, sizeof(int) );
    cout << endl;
    cout.write( "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10 );
    cout << endl;
}

// <<<<< tamaño >>>>>>>
int main () {
    const int TAM_BUFFER = 10;
    char buffer[TAM_BUFFER];
    int tam = 0;

    while ( cin.read(buffer, TAM_BUFFER) ) 
           tam += TAM_BUFFER;

    tam += cin.gcount();
    cout << "\nTamanio = " << tam << endl;
    return 0;
}


// <<<<< copia >>>>>>>
int main () 
{
    const int TAM_BUFFER = 10;
    char buffer[TAM_BUFFER];

    while (cin.read(buffer, TAM_BUFFER)) 
         cout.write(buffer, TAM_BUFFER);

    cout.write(buffer, cin.gcount());
    return (0);
}
