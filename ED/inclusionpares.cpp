/*

Usando la clase SET de la STL, construir una función para determinar 
si un conjunto tiene todos los elementos pares incluídos dentro de otro.

*/

#include <iostream>
#include <set>
using namespace std;

bool inclusionpares (const set<int> &c1, const set<int> &c2){
	set<int>::iterator p;
	
	for(p=c1.begin(); p!=c1.end(); ++p)
		if(*p%2 == 0)
			if(!c2.find(*p))
				return false;
			else
				++p;
	return true;
}