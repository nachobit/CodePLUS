
/* Algoritmo genérico */

template<class T>
void escribir_elementos(const T & contenedor){
	typename T:: const_iterator p;
	for (p = c.begin(); p !=c.end(); ++p)
		cout << *p << endl;
}

typedef double * iterator;

iterator begin(double *v, int n){
	return v;
}

iterator end(double *v, int n){
	return v+n;
}

void anular_elementos(double *v, int n){
	iterator p;
	for(p=begin(v,n); p!=end(v,n); ++p)
		*p==0;
}

void escribir_elementos(const double *v, int n){
	const_iterator p;
	for(p=begin(v,n); p!=end(v,n); ++p)
		cout << *p << endl;
}


/**/
#include <iostream>
#include <vector.h>
#include <cassert>
#include <string>
using namespace std;

void cargar_indices(vector<int> & v){
	for(int i=0; i<v.size(); ++i)
		v[i]=i;
}

template <class T> T maximo(const vector<T> & v){
	assert (v.begin()!=v.end());	//assert: compare to 0
	typename vector<T>::const_iterator max = v.begin();
	for(vector<T>::const_iterator p=v.begin(); p!=v.end();++p){
		if(*max < *p)
			max=p;
	}
	return *max;
}

int main(){
	vector<int> vec(3);
	vector<string>cadenas(4);
	cargar_indices(vec);
	cout <<"Maximo de" << vec.size() << " elementos enteros: " << maximo(vec) << endl;
	vec.resize(10);
	cargar_indices(vec);
	cout <<"Maximo de" << vec.size() << " elementos enteros: " << maximo(vec) << endl;
	cadenas[0] = "Esto";
	cadenas[1] = "es";
	cadenas[2] = "una";
	cadenas[3] = "prueba";
	cout <<"Maximo de" << cadenas.size() << " elementos cadena: " << maximo(cadenas) << endl;
	return 0;
}