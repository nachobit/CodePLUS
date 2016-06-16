#include <iostream>
using namespace std;

const int MAX = 1000;

class MiMatrizDin
{
   private:
     double **m;
     int nfil;
     int ncol;

   public:
     MiMatrizDin ( int fil, int col );
 
     int NFilas (); 
     int NColumnas ();
     
     void Destruir();

     double Get ( int fil, int col ); 
     void Set ( double x, int fil, int col );
     
     void EliminarColumna( int col );
};

////////////////////////////////////////////////////
int main()
{
     int nf, nc, columna_eliminar;
     double x;
     
     cout << "\n Introducir numero filas: ";
     cin >> nf;
     
     cout << "\n Introducir numero columnas: ";
     cin >> nc;

     MiMatrizDin m(nf, nc);
     
     for(int i=0; i<m.NFilas(); i++)
          for(int j=0; j<m.NColumnas(); j++)
          {
               cout << "\n Introducir elemento: " << i << " " 
                    << j << ": ";
               cin >> x;   
               
               m.Set(x, i, j);
          }     
     
     cout << "\nLa matriz es: \n";
     for(int i=0; i<m.NFilas(); i++)
     {
          for(int j=0; j<m.NColumnas(); j++)
             cout << m.Get(i, j) << ' ';
            
          cout << endl;  
     }

     cout << "\n Introducir columna a eliminar: ";
     cin >> columna_eliminar;
     //cin >> fila_eliminar;


     m.EliminarColumna( columna_eliminar );
     //m.EliminarFila( fila_eliminar );

     cout << "\nLa nueva matriz es: \n";
     for(int i=0; i<m.NFilas(); i++)
     {
          for(int j=0; j<m.NColumnas(); j++)
             cout << m.Get(i, j) << ' ';
            
          cout << endl;  
     }

     m.Destruir();

     system("pause");
}

////////////////////////////////////////////////////
MiMatrizDin::MiMatrizDin ( int nf, int nc  )
{
     nfil = nf;
     ncol = nc;
                         
     m = new double*[nfil];
     for (int i=0; i<nfil; i++)
        m[i] = new double[ncol];
        
     for (int i=0; i<nfil; i++)
         for (int j=0; j<ncol; j++)  
            m[i][j] = 0; 
}

int MiMatrizDin::NFilas () 
{
     return nfil;
}

int MiMatrizDin::NColumnas ()
{
     return ncol;
}

void MiMatrizDin::Destruir ()
{
     if ( m != 0 )
     {
         for(int i=0; i<nfil; i++)
            delete [] m[i];
    
         delete [] m;
         m = 0; 
         nfil = ncol = 0;
     }
}

double MiMatrizDin::Get ( int fil, int col ) 
{
     if ( 0 <= fil && fil < nfil && 0 <= col && col < ncol )
         return m[fil][col];
}

void MiMatrizDin::Set ( double x, int fil, int col )
{
     if ( 0 <= fil && fil < nfil && 0 <= col && col < ncol )
         m[fil][col] = x;
}

void MiMatrizDin::EliminarColumna( int col )
{
    double *temporal;
    int c;
 
    if ( 0 <= col && col < ncol )               //nfil
    {
        // delete [] m[fil];        
        for (int i= 0; i<nfil; i++)   //se omite en eliminar fila
        {             
            temporal = new double [ ncol - 1 ]; //nfil
    
            c = 0; 
            for (int j= 0; j<ncol; j++)
                if ( j != col )
                {
                    temporal[c] = m[i][j];
                    c ++;
                }
               
           delete [] m[i];
           // delete [] m;
    
           m[i] = temporal;
           // m = temporal;
           // nfil --;
        }
        
        ncol --;    //se omite
    }
}

 
