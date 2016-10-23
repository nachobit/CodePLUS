#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main (int argc, char **argv)
{
    const int MAX_LINE=8; // Num. de enteros por línea
    int num, max; // Num. total de enteros y máximo valor
    int n; // Para almacenar cada número aleatorio
    ofstream fo; // Flujo de salida
    
    // Comprobar el número de argumentos
    if (argc != 4) 
    {
        cout << "Error: Num. de params. erroneo\n";
        cout << "Uso: " << argv[0]<< " <fichS> " << "<num> <max>\n";
        exit (1);
    }
    
    // Transformar y validar argumentos
    num = atoi(argv[2]);
    if (num <= 0) 
    {
        cout << "Error: <num> debe ser >= 0\n";
        exit (1);
    }
    
    max = atoi(argv[3]);
    if (max <= 0) 
    {
        cout << "Error: <max> debe ser >= 0\n";
        exit (1);
    }

    fo.open (argv[1], ios::binary); // Apertura (para escritura)
                                    // en modo binario
    if (!fo) 
    {
        cout << "Error: no puedo crear " << argv[1] << endl;
        exit (1);
    }
    
    cout << argv[1] << " contendra "<< num << " enteros."<< endl;
    cout << "Valores en el rango 0.." << (max-1) << endl;

    srand ( time (NULL) ); // Iniciar generador de números aleatorios
 
    // En cada iteración se genera y guarda un número aleatorio
    for (int i=1; i<=num; i++) 
    {
        n = rand() % max; 
        
        fo.write ( (const char *) (&n), sizeof (int) );
        
        cout << setw (6) << n;
        
        if ( i % MAX_LINE == 0 ) 
            cout << endl;
    }
    
    fo.close(); // coutar el fichero asociado a "fo"
    
    return (0);
}
