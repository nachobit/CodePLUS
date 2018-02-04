
/* Algoritmo genérico */

template<class T>
void escribir_elementos(const T & contenedor){
	typename T:: const_iterator p;
	for (p = c.begin(); p !=c.end(); ++p)
		cout << *p << endl;
}


