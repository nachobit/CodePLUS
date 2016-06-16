/*   En este programa lee dos reales distintos a cero y muestra un menú para
     operar con ellos (suma, resta, multiplicación y división)
*/
 
   #include <iostream>
   #include <cmath>
   using namespace std;
 
   //***************************************************************************
   void Leer2Reales(double &x, double &y)
   {
        cout << "Introducir primer dato: ";
        cin >> x;
       
        cout << "Introducir segundo dato: ";
        cin >> y;
   }
 
   //***************************************************************************
   void SumaResta(double a, double b, double &suma, double &resta)
   {
       suma = a + b;
       resta = a - b;
   }
 
   //***************************************************************************
   void MostrarResultados(double suma, double resta)
   {
       cout << "\n\nSuma: " << suma << "  Resta: " << resta << endl;
   }
  
   // P R O G R A M A   P R I N C I P A L //////////////////////////////////////
   int main()
   {
      double x, y, s, r;
 
      //ENTRADAS
      Leer2Reales(x, y);
      
      //PROCESO
      SumaResta(x, y, s, r);
      
      //SALIDA
      MostrarResultados(s, r);
   }
   
