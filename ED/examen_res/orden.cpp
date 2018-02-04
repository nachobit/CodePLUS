/**
Implementa una función int orden(const list<int> &L); que devuelva:
	1 si L está ordenada de forma ascendente de principio a fin
	2 si lo está descendente
	0 si no está ordenada
**/

#include <iostream>
#include <list>
using namespace std;

int orden(const list<int> &L){
	list<int>::const_iterator it1, it2;
	it1=L.cbegin();
	if (it1==L.cend()){
		it2=it1;
		++it2;
		unsigned int sentido;
		if (*it1<=*it2){
			sentido=1;
		}
		else sentido=2;
		++it1;
		++it2;
		while (it2!=L.cend()){
			if (sentido==1 && !(*it1<=*it2))
				return 0;
			else if (sentido == 2 && !(*it2<=*it1))
				return 0;
			++it1;
			++it2;
		}
		return sentido;
	}
	return 0;
}

int orden (list<int> L){
	bool es_ascendente=true;
	bool es_descenente=true;

	list<int>::iterator it1 = L.begin();
	list<int>::iterator it2 = L.begin();
	if (L.empty()) return 1;
	else{
		++it2;
		while ((es_ascendente || es_descenente) && it2 != L.end()){
			if ((*it1) < (*it2))
				es_descenente=false;
			else if ((*it1) > (*it2))
				es_ascendente=false;
			++it1;
			++it2;
		}
	}

	if (es_ascendente) return 1;
	else if (es_descenente)	return 2;
	else return 0;

}