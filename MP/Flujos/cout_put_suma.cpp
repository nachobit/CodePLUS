#include <iostream>
using namespace std;

// <<<<< demo_cout >>>>>>>
int main ()
{
    int n = 5;
    float r = 7.33;
    char *cad = "Hola";
    int *pi = &n;
    float *pf = &r;

    cout << "Literal de cadena" << endl;
    cout << n << endl;
    cout << r << endl;
    cout << *pi << " " << pi << endl;
    cout << *pf << " " << pf << endl;
    cout << cad << " " << static_cast<void *>(cad)<<endl;
 }

// <<<<< demo_put >>>>>>>
int main ()
{
    char c1='H', c2='o', c3='l', c4='a';
    
    cout << c1 << c2 << c3 << c4 << endl;
    cout.put (c1);
    cout.put (c2);
    cout.put (c3);
    cout.put (c4);
    cout.put ('\n');
    cout.put(c1).put(c2).put(c3).put(c4).put('\n');
}

// <<<<< suma_int >>>>>>>
int main ()
{
    int n, cont=0, sum=0;  
    // Lectura adelantada
    cout << "\n(Suma acumulada = " << sum << "). ";
    cout << "Introducir entero n. " << cont+1 << " : ";
    cin >> n; //... se obvia este cin
    
    while ( !cin.eof() ) 
    //...  while ( cin >> n )  // (cin >> n) != 0  (>> devuelve 0 cuando encuentra eof)
    {
        sum += n;   
        cont++;
        
        // Siguiente lectura
        cout << "(Suma acumulada = " << sum << "). ";
        cout << "Introducir entero n. "<< cont+1 << " : ";
        cin >> n;  //... se obvia este cin
    }
    
    cout << "\nLa suma total de los " << cont;
    cout << " enteros introducidos es " << sum << endl;
}
