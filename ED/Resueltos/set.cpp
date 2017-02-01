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
		if(!c2.count(*p))	solucion.insert(*p);
	for(q=c2.begin(); q!=c2.end(); ++q)
		if(!c1.count(*p))	solucion.insert(*q);

	return solucion;
}


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
		//inclusion normal: if(!c2.count(*p))	return false	return true;
		if(*p%2 == 0)
			if(!c2.find(*p))
				return false;
			else
				++p;
	return true;
}




/*
Usando la clase SET de la STL, diseñar una función que divida 1 conjunto de ?
en 2 subconjuntos cpar y cimpar que contienen respectivamente los elementos
pares e impares de c y que devuelva true si el número de elementos de cpar 
es mayor que el de cimpar y falso en caso contrario.
*/
bool masparesqimpares (const set<int> &c, set<int> &cpar, set<int> &cimpar){
	set<int>::iterator p;

	for(p=c.begin(); p!=c.end(); ++p)
		if(*p%2==0)
			cpar.insert(*p);
		else
			cimpar.insert(*p);

	return (cpar.size() > cimpar.size());
} 


/*
Usando la clase SET de la STL, diseñar una función para determinar si un conjunto
tiene más de la mitad de sus elementos comunes con otro.
*/

bool masdelamitadcomunes (const set<int> &c1, const set<int> &c2){
	set<int>::const_iterator p,q;
	int n1,n2;
	n1=0;
	n2=c1.size();
	for(p=c1.begin(); p!=c1.end(); ++p){
		if(c2.count(*p))	n++;
		if(n1>n2/2)	return true;
		else return false;
	}
}


/*
Usando la clase SET de la STL, diseñar una función que determine la intersección
de dos conjuntos c1 y c2 (VECTORES)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
	std::vector<int> v1{2,3,4,5,7,11};
	std::vector<int> v1{2,3,4,5,7,11};
	std::sort(v1.begin(),v1.end());
	std::sort(v2.begin(),v2.end());
	
	std::vector<int> v_interseccion;
	//set<int> intersect;
	
	std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(), std::back_inserter(v_interseccion));
	//set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::inserter(intersect,intersect.begin()));

	for(int n:v_interseccion)
		std::cout << n << '';
}


/* Elementos Repetidos */
template<class T>
list<T> repetidos(list<T> l){
	set<T> elem_dif;
	set<T>rep;
	list<T>l_rep;
	for(typename list<T>::iterator it=l.begin(); it!=l.end(); ++it){
		if(elem_dif.find(*it)==elem_dif.end())
			elem_dif.insert(*it);
		else 	rep.insert(*it);
	}
	for(typename set<T>::iterator it=rep.begin(); it!=rep.end(); ++it){
		l_rep.push_back(*it);
	}
	return l_rep;
}

/* queue */
queue<int> multiinterssecion(queue<int> q1, queue<int> q2){
	queue<int> q;
	while(!q1.empty() && !q2.empty()){
		if(q1.front()==q2.front()){
			q.push(q1.front());
			q1.pop();
			q2.pop();
		}
		else if(q1.front()< q2.front())
			q1.pop();
		else
			q2.pop();
	}
	return q;
}


/* MULTISET */

multiset<int> multi_interseccion(const multiset<int> &m1, const multiset<int> m2){
	multiset<int>::iterator i1=m1.begin();
	multiset<int>::iterator i2=m2.begin();

	while((i1!=m1.end()) && (i2!=m2.end()){
		if(*i1=*i2){
			result.insert(*i1);
			i1++;
			i2++;
		}
		else if(*i1<*i2){
			i1++;
		}
		else 	i2++;
	}
	return result;
}
