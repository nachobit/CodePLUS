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
     void Leer();
     void Escribir();
     void Ordenar();
     void MezclarOrd ( const MiLista &lista1, const MiLista &lista2 );
     void MezclarOrd_sinNew ( MiLista &lista1, MiLista &lista2 );
};

////////////////////////////////////////////////////////////////////////////////
int main ()
{
     int x;
     MiLista lista, lista1, lista2;
     
     cout << "Introducir la primera lista:";
     lista1.Leer();
     
     cout << "Introducir la segunda lista:";
     lista2.Leer();
      
     lista1.Ordenar();
     lista2.Ordenar();
     
     lista.MezclarOrd_sinNew ( lista1, lista2 );

     cout << endl << "La lista ordenada es: " << endl;
     lista.Escribir();
     
     lista1.Destruir();
     lista2.Destruir();
     lista.Destruir();
     
     system("pause");
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

void MiLista::Ordenar()
{
     Celda *pmin;
     
     if ( l != 0 )
     {
         for ( Celda *p = l; p->sig != 0; p = p->sig )
         {
             pmin = p;
             for ( Celda *q = p->sig; q != 0; q = q->sig )
                    if( pmin->info > q->info )
                       pmin = q;
            
             int tmp = pmin->info;
             pmin->info = p->info;
             p->info = tmp;
         }           
    }
}

void MiLista::MezclarOrd ( const MiLista &lista1, const MiLista &lista2 )
{
     Celda *p, *q, *r, *nuevo;
     
     while ( !Vacia() )
          Eliminar_primero ();
     
     p = lista1.l;
     q = lista2.l;
     while ( p != 0 && q != 0 )
        if ( p->info < q->info )
        {
            Aniadir_final (p->info);
            
            p = p->sig;
        } 
        else
        {
            Aniadir_final (q->info);
            
            q = q->sig;            
        } 
        
     if ( p == 0 )
        for ( Celda *t = q; t != 0; t = t->sig )
            Aniadir_final ( t->info );
     else    
        for ( Celda *t = p; t != 0; t = t->sig )
            Aniadir_final ( t->info );

}

void MiLista::MezclarOrd_sinNew ( MiLista &lista1, MiLista &lista2 )
{
     Celda *p, *q, *r, *nuevo;
     
     while ( !Vacia() )
          Eliminar_final ();
     
     p = lista1.l;
     q = lista2.l;
     while ( p != 0 && q != 0 )
        if ( p->info < q->info )
        {       
            if ( l == 0 )
                l = r = p;
            else
            {
                r->sig = p;
                r = p;
            }      
            
            p = p->sig;
            r->sig = 0;
        } 
        else
        {
            if ( l == 0 )
                l = r = q;
            else
            {
                r->sig = q;
                r = q;
            }
            
            q = q->sig;   
            r->sig = 0;         
        }
        
     if ( p == 0 )
     {
        if ( l != 0 )
            r->sig = q;
     }  
     else
     {
        if ( l != 0 )
            r->sig = p;
     }  

     lista1.l = lista2.l = 0;
}
 
