/*

Usando la clase SET de la STL, diseñar una función que dados 2 conjuntos c1 y c2,
determine el conjunto de los elementos de c1 que no están en c2 y todos los de c2 
que no están en c1.

*/

#include <iostream>
#include <set>
using namespace std;

set<int> no_comunes (set<int> c1, set<int> c2){
	set<int>::iterator p,q;
	set<int> solucion;

	for(p=c1.begin(); p!=c1.end(); ++p)
		if(!c2.count(*p))
			solucion.insert(*p);
	for(q=c2.begin(); q!=c2.end(); ++q)
		if(!c1.count(*p))
			solucion.insert(*q);

	return solucion;
}