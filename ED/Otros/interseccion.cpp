/*

Usando la clase SET de la STL, diseñar una función que determine la intersección
de dos conjuntos c1 y c2.

*/

#include <iostream>
#include <set>
using namespace std;

void comunes (set<int> c1, set<int> c2, set<int> &solucion){
	set<int>::iterator p,q;
	
	for(p=c1.begin(); p!=c1.end(); ++p)
		if(c2.count(*p))
			solucion.insert(*p);
}