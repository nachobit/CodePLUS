#include <fstream>
using namespace std;

int main ()
{
    int n = 5, *pi = &n;
    float r = 7.33, *pf = &r;
    char *cad = "Hola";

    ofstream fo;

    fo.open ("sal_demo_out");

    fo << "Literal de cadena" << endl;
    fo << n << endl << r << endl;
    fo << *pi << " "<< pi << endl << *pf << " "<< pf << endl;
    fo << cad << " "<< static_cast <void *> (cad)<< endl;

    fo.close ();

    return (0);
}
