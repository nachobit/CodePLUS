#include <iostream>
using namespace std;
#include <string>


// <<<<< eco >>>>>>>
int main ()
{
    char c;

    cin.get(c); // Lectura anticipada
    while ( !cin.eof() ) 
    {
        cout.put (c);
        cin.get(c); // Siguiente lectura
    }
    //return 0;
}


// <<<<< getline >>>>>>>
int main ()
{
    const int TAM = 80;
    char cad1[TAM], cad2[TAM];

    cout << endl;

    cout << "Introducir una cadena: ";
    cin.getline (cad1, TAM);

    cout << "Introducir otra cadena: ";
    cin.getline (cad2, TAM);

    cout << endl;

    cout << "\nPrimera cadena : " << cad1;
    cout << "\nSegunda cadena : " << cad2;
    cout << endl;
}


// <<<<< ignore >>>>>>>
int main () 
{
    int a, b;
    cin.ignore(100, '.');
    cin >> a;
    cin.ignore(100, '-');  
    cin >> b;
    cout << "a: " << a << " b: " << b << endl;
}


// <<<<< cuenta_lineas >>>>>>>
int main ()
{
    char c;
    int contador = 0;
    
    c = cin.get(); // Lectura adelantada
    while (!cin.eof()) 
    {
        if (c == '\n') 
           contador++;   
        c = cin.get(); // Nueva lectura
    }
    
    cout << "Num. de lineas = " << contador << endl;  
    return (0);
}

