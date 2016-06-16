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
     ~MiLista();
     
     MiLista(const MiLista &otra_lista);
     
     void Aniadir_primero (int x);
     void Eliminar_primero();
     void Aniadir_final (int x);
     void Eliminar_final();
     
     void Leer();
     void Escribir();
};

////////////////////////////////////////////////////////////////////////////////
int main ()
{
     MiLista lista1;
     
     cout << "Introducir lista:";
     lista1.Leer();

     cout << endl << "La lista - lista1 - es: " << endl;
     lista1.Escribir(); 
     
     MiLista lista2(lista1);
      
     cout << endl << "La lista - lista2 - es: " << endl;
     lista2.Escribir(); 
     
     cout << endl;
     
     system("pause");
}

///////////////////////////////////////////////////////////////
MiLista::MiLista() : l(0) {}

MiLista::~MiLista()
{
    while ( !Vacia() )
          Eliminar_primero ();
    
    l = 0;
}

MiLista::MiLista(const MiLista & otra_lista)
{
     Celda *p=otra_lista.l;
     
     l=0;
     
     while (p != 0)
     {
 	    Aniadir_final ( p->info );
	    p = p->sig;
     }                        
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

void MiLista::Leer()
{
     int x;
     
     while ( !Vacia() )
          Eliminar_primero ();
          
     cout << endl << "Introducir elemento: ";
     cin >> x;
     while ( x != 0 )
     {
         Aniadir_final( x );   
           
         cout << "Introducir elemento: ";
         cin >> x;
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
 
