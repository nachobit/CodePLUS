#include <iostream>
using namespace std;

class MiArrayDin_int
{
   private:
     int *vd;
     int util_vd;

   public:
     MiArrayDin_int ();
     
     void Borrar ();

     int Size ();

     void Clear ();

     void Push_Back ( int x );
     void Pop_Back ();

     int Get ( int indice );
     void Set ( int x, int indice );

     void OrdenacionPorSeleccion ();
};


////////////////////////////////////////////////////
int main()
{
     MiArrayDin_int v;
     int n;

     cout << "Introducir entero (hasta 0): ";
     cin >> n;
     while (n != 0)
     {
         v.Push_Back ( n );

         cout << "Introducir entero (hasta 0): ";
         cin >> n;
     }

     v.OrdenacionPorSeleccion();

     cout << "El vector ordenado es: " << endl;
     for ( int i = 0; i < v.Size(); i++ )
        cout << v.Get(i) << ' ';

    cout << endl << endl;

    system("pause");
}

////////////////////////////////////////////////////
MiArrayDin_int::MiArrayDin_int (): vd(0), util_vd(0) {}

void MiArrayDin_int::Borrar ()
{
     if ( util_vd > 0 )
        delete [] vd;
}

int MiArrayDin_int::Size ()
{
     return util_vd;
}

void MiArrayDin_int::Clear ()
{
     if ( util_vd > 0 )
        delete [] vd;

     vd = 0;

     util_vd = 0;
}

void MiArrayDin_int::Push_Back ( int x )
{
    int *vd_ampliado = new int[ util_vd + 1 ];

    for (int i= 0; i<util_vd; i++)
        vd_ampliado[i] = vd[i];

    delete [] vd;

    vd = vd_ampliado;

    vd[util_vd] = x;

    util_vd ++;
}

void MiArrayDin_int::Pop_Back ()
{
    if ( util_vd > 0 )
    {
        int *vd_ampliado = new int[ util_vd - 1 ];

        for (int i= 0; i<util_vd; i++)
            vd_ampliado[i] = vd[i];

        delete [] vd;

        vd = vd_ampliado;

        util_vd --;
    }
}

int  MiArrayDin_int::Get ( int indice )
{
     if ( 0 <= indice && indice < util_vd )
        return vd[indice];
}

void MiArrayDin_int::Set ( int x, int indice )
{
     if ( 0 <= indice && indice < util_vd )
        vd[indice] = x;
}

////////////////////////////////////////////////////
void MiArrayDin_int::OrdenacionPorSeleccion()
{
        int pos_min, aux;

        for (int i = 0; i < Size(); i++)
        {
             pos_min=i;

             for (int j = i+1; j < Size(); j++)
                 if ( Get(j) < Get(pos_min) )
                      pos_min=j;

             aux = Get(i);
             Set ( Get(pos_min), i );
             Set ( aux, pos_min);
        }
}

 
