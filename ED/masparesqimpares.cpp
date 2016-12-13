/*

Usando la clase SET de la STL, diseñar una función que divida 1 conjunto de ?
en 2 subconjuntos cpar y cimpar que contienen respectivamente los elementos
pares e impares de c y que devuelva true si el número de elementos de cpar 
es mayor que el de cimpar y falso en caso contrario.

*/

#include <iostream>
#include <set>
using namespace std;

bool masparesqimpares (const set<int> & c, set<int> &cpar, set<int> &cimpar){
	set<int>::iterator p;

	for(p=c.begin(); p!=c.end(); ++p)
		if(*p%2==0)
			cpar.insert(*p);
		else
			cimpar.insert(*p);

	return (cpar.size() > cimpar.size());
/*
	if(cpar.size() > cimpar.size())
		return true;
	else
		return false;
*/
}