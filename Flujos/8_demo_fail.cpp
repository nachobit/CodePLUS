#include <iostream>
using namespace std;

int LeerEntero()
{
     int x;
     
     cin >> x;
     
     while ( cin.fail() ) 
     { 
            cin.clear(); 
            
            cin.ignore (256, '\n'); 
      
            cout << "Volver a introducir valor entero: ";
            cin >> x;
     }
     
     return x;
}

int main ()
{
    const int NUM_DATOS = 5; 
    int datos[NUM_DATOS]; 
    
    for (int i=0; i<NUM_DATOS; i++) 
    {
        cout << "Introducir valor entero " << i << ": ";
        datos[i] = LeerEntero();
    }
    
    cout << "Valores guardados: " << endl;
    for (int i=0; i<NUM_DATOS; i++) 
       cout << "Num. de orden: " << i << ". " << "Valor = " << datos[i] << endl;
}
