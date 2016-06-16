#include <iostream>
using namespace std;

struct Celda
{
     int info;
     Celda *sig;
};

class MiLista
{
  private:
     Celda *l;
     bool Vacia();

  public:
     MiLista();
     void Destruir();
     void Aniadir_primero (int x);
     void Eliminar_primero();
     void Aniadir_final (int x);
     void Eliminar_final();
     void Escribir();
};

////////////////////////////////////////////////////////////////////////////////
int main ()
{
     int x;
     MiLista lista, otra_lista;
     
     cout << "Introducir elemento: ";
     cin >> x;
     while ( x != 0 )
     {
         lista.Aniadir_primero( x );   
           
         cout << "Introducir elemento: ";
         cin >> x;
     }     
     
     cout << "La lista es: " << endl;
     lista.Escribir();
     
     lista.Destruir();
}

///////////////////////////////////////////////////////////////
MiLista::MiLista() : l(0) {}

void MiLista::Destruir()
{
    while ( !Vacia() )
          Eliminar_primero ();
    
    l = 0;
}

bool MiLista::Vacia()
{
     return l == 0;
}

void MiLista::Aniadir_primero (int x)
{
     Celda *nuevo;

     nuevo = new Celda;
     nuevo->info = x;
     nuevo->sig = l;
     l = nuevo;
}

void MiLista::Eliminar_primero()
{
     Celda *p;

     if (l != 0)
     {
	      p = l;
	      l = l->sig;
	      delete p;
     }
}

void MiLista::Aniadir_final (int x)
{
  Celda *nuevo;
  Celda *p;
  
  if ( l == 0 )
      Aniadir_primero ( x );
  else
  {    
      nuevo=new Celda;  
      
      nuevo->info=x;    
      nuevo->sig = 0;   
      
      p = l;            
      while(p->sig!=0)
         p = p->sig;
         
      p->sig= nuevo;   
  }
}

void MiLista::Eliminar_final()
{
    Celda *p, *pant;

    if( l != 0 )
    {
            p = l;
            while( p->sig != 0 )
            {
                pant = p;
                p = p->sig;
            }
            
            if ( p == l )
            {
                 delete l;
                 l = 0;
            }
            else
            {
                 delete p;   
                 pant->sig = 0;
            }
    }
}

void MiLista::Escribir()
{
     Celda *p=l;
     while (p != 0)
     {
 	    cout << p->info << ' ';
	    p = p->sig;
     }
}
 
