/*   En este programa se incluye un ejemplo del paso por referencia
*/

   #include <iostream>
   using namespace std;

   ////////////////////////////////////////////////////////////////
   void IntercambiarMAL(int a, int b)         ////// PASO POR VALOR
   {
       int tmp=a;
       a=b;
       b=tmp;
   }

   //////////////////////////////////////////////////////////////////
   void IntercambiarBIEN(int &a, int &b)   ////// PASO POR REFERENCIA
   {
       int tmp=a;
       a=b;
       b=tmp;
   }

   ///////////////////////////////////////////////////////////////////
   int main()
   {
       int dato1=30, dato2=90;

       cout << "dato1: " << dato1 << "  dato2: " << dato2 << endl;

       IntercambiarMAL(dato1, dato2);

       cout << "\nDespues de IntercambiarMAL: " << endl;

       cout << "\ndato1: " << dato1 << "  dato2: " << dato2 << endl;

       IntercambiarBIEN(dato1, dato2);

       cout << "\nDespues de IntercambiarBIEN: " << endl;

       cout << "\ndato1: " << dato1 << "  dato2: " << dato2 << endl;
   }
