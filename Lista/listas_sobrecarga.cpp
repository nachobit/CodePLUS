#include <iostream>
#include <cassert>
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
    
    void CopiarDesde(const MiLista& otra_lista);

  public:
     MiLista();
     MiLista(int x);
     
     ~MiLista();
     
     void Clear();
     
     MiLista (const MiLista &otra_lista); //CONSTRUCTOR DE COPIA
     
     MiLista & operator=(const MiLista &otra_lista); // SOBRECARGA = 
     
     void Push_first ( int x );
     void Pop_first ();
     void Push_back ( int x );
     
     MiLista operator+(const MiLista &otra_lista) const;
     
     friend MiLista operator+(int x, const MiLista &lista);
     
     int & operator[](int indice);
     const int & operator[](int indice) const;
     
     bool operator==(const MiLista &otra_lista) const;
     
     friend istream &operator>>( istream &is, MiLista &lista );
     friend ostream &operator<<( ostream &os, const MiLista &lista );
};

////////////////////////////////////////////////////////////////////////////////
int main ()
{
     MiLista l1, l2;
     
     cout << "Introducir elementos lista1 (x1, ..., xi, ... 0): ";
     cin >> l1;

     cout << "Introducir elementos lista1 (x1, ..., xi, ... 0): ";
     cin >> l2;

     if ( l1 == l2 )
         cout << endl << "Son iguales" << endl;
     else
         cout << endl << "NO son iguales" << endl;    

     cout << "El resultado es: " << l1 + l2 << endl;    
      
     cout << "El resultado es: " << 100 + l2 << endl;
     
     cout << "El resultado es: " << l1 + 500 << endl;  
     
     cout << "El elemento es: " << l1[2] << endl;
     
     l1[0] = -500;
     
     cout << "Lista l1 es: " << l1 << endl;
     
     system("pause");
}

///////////////////////////////////////////////////////////////
MiLista::MiLista() : l(0) {}

MiLista::MiLista (int x)
{
      l = new Celda;
      l->info = x;
      l->sig = 0;
}

MiLista::~MiLista()
{
    Clear ();

}

void MiLista::Clear()
{
    while ( !Vacia() )
          Pop_first ();

    l = 0;
}

void MiLista::CopiarDesde(const MiLista& otra_lista)
{
     Celda *nuevo, *anterior;
     
     l = 0;
     for ( Celda *p=otra_lista.l; p != 0; p=p->sig )
     {
          nuevo = new Celda;
          nuevo->info = p->info;
          nuevo->sig = 0;
          
          if ( l == 0 )
              l = nuevo;
          else
              anterior->sig = nuevo;
              
          anterior = nuevo;
     }
}

MiLista::MiLista (const MiLista &otra_lista) //CONSTRUCTOR DE COPIA 
{
     CopiarDesde(otra_lista);
}

MiLista & MiLista::operator=(const MiLista &otra_lista) //SOBRECARGA =
{

     if (this != &otra_lista)
     {
           Clear();
      
           CopiarDesde(otra_lista);
     }
     
     return *this;
}

void MiLista::Push_back (int x)
{
  Celda *nuevo;
  Celda *p;
  
  if ( l == 0 )
      Push_first ( x );
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

bool MiLista::Vacia()
{
     return l == 0;
}

void MiLista::Push_first (int x)
{
     Celda *nuevo;

     nuevo = new Celda;
     nuevo->info = x;
     nuevo->sig = l;
     l = nuevo;
}

void MiLista::Pop_first()
{
     Celda *p;

     if (l != 0)
     {
	      p = l;
	      l = l->sig;
	      delete p;
     }
}

MiLista MiLista::operator+(const MiLista &otra_lista) const
{
         MiLista trozo(*this);
         Celda *p;    
         
         for ( p=otra_lista.l; p != 0; p=p->sig )
            trozo.Push_back(p->info);
              
         return trozo;     
}

int & MiLista::operator[](int indice)
{
    int contador = 0;
    bool encontrado = false;
    Celda *p=l;
    
    while ( p != 0 && !encontrado )
        if ( indice == contador )
            encontrado = true;
        else
        {
            contador ++;   
            p = p->sig;
        }
             
    assert(encontrado);
    
    return p->info;       
}

const int & MiLista::operator[](int indice) const
{
    int contador = 0;
    bool encontrado = false;
    Celda *p=l;
    
    while ( p != 0 && !encontrado )
        if ( indice == contador )
            encontrado = true;
        else
        {
            contador ++;   
            p = p->sig;
        }
                      
    assert(encontrado);
    
    return p->info;       
}

MiLista operator+(int x, const MiLista &lista)
{
         MiLista trozo(lista);
         
         trozo.Push_first(x);
         
         return trozo;     
}

bool MiLista::operator==(const MiLista &otra_lista) const
{
       bool iguales = true;
       
       Celda *p, *q;
       
       p=l;
       q=otra_lista.l;
       
       while ( p!=0 && q!=0 && iguales )
       {
            if ( p->info != q->info )
               iguales = false;      
               
            p = p->sig;
            q = q->sig;   
       }

       if ( p!=0 || q!=0 )
           iguales = false;
           
       return iguales;     
}

// Sobrecarga de cin ...
istream &operator>>(istream &is, MiLista &lista)
{
     int x;
     
     lista.Clear();

     is >> x;
     while (x != 0)
     {
         lista.Push_back(x);
         is >> x;
     }

     return is;
}

// Sobrecarga de cout ...
// ¡ Podemos acceder a los datos privados de MiLista porque es friend !
ostream &operator<<(ostream &os, const MiLista &lista)
{
     Celda *p=lista.l;
     while (p != 0)
     {
	    os << p->info << ' ';
	    p = p->sig;
     }

      return os;
}
 
