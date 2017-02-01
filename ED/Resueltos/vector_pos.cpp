/*

Vector gran tam que almacena claves enteras ordenadas que puede contener
de forma consecutiva un nº indefinido de veces: {11111,444,55555,...}
Construir una función que dada pos i del vector original, devuelva
el valor almacenado en esa pos tras diseñar una representación de almacenaje.

Representación:

	  0	    1	  2
v [ [1|5] [4|3] [5|5] ...]

*/

int valor_pos(int i){
	j=0;
	while(i >= 0){
		i=i-v[j].num;
		++j
	}
	return j-1;
}

/* 

Pila Doble 

							  n-3 n-2
[ | | | | | | ...		... | | | | ] | [ | ]
 0 1 2 3 4 5				n-4 n-2
 			elementos					 top

*/

private:
	T * elementos;
	int top[2];

template <class T>
void Pila<T>::pop(int indicepila){
	top[indicepila]=top[indicepila]-(indicepila ? 1 : -1);
}

void Pila::quitar(){
	assert(nelem > 0);
	nelem--;
	if(nelem <= reservados/4)	resize(reservados/2);
}

void Pila::poner(){
	if(nelem == reservados)	resize(2*reservados);
	datos[nelem]=c;
	nelem--;
}

/*
Una pila es inversa a una cola cuando el listado de los elementos de la pila 
coincide con el listado de los de la cola en orden inverso.
Usando "static" y "queue", diseñar una función para determinarlo.

*/

template <class T>
bool soninversas(<static<T>, s, queue<T> q){
	if(s.size()!=q.size())	return false;
	else{
		static<T> aux;
		while(!q.empty()){
			aux.push(q.front());
			q.pop();
		}
		while(!aux.empty()){
			if(aux.top()!=s.top())	return false;
			aux.pop();
			s.pop();
		}
	return true;
	}
}

Pila & Pila::operator= (const Pila & p){
	Pila paux(p);
	CeldaPila *aux;
	aux=this -> primera;
	this -> primera = paux.primera;
	paux.primera=aux;
	return *this;
}


/*

Usando el TDA lista, construir una función que tenga como entrada dos listas
y devuelva 1, si la primera está contenida en la segunda (tienen mismos elementos)
y 0 en otro caso.

*/

bool secuencia(list<int> &l1, list<int> &l2){
	list<int> iterator::p,q;
	int x;
	x=l1.front();
	p=l1.begin();
	q=l2.find(l2.begin(), l2.end(),x);
	while(p!=l1.end())
		if(*p!=*q)	return false;
		else{
			++p;
			++q;
		}
	return true;
}



void invertir(cola & c){
	while(!c.empty()){
		int aux=c.front();
		c.pop();
		invertir(c);
		c.push(aux);
	}
}

bool comprobar(pila &p, cola &c){
	invertir();
	while(!c.empty())
		if(c.front()!=p.front())	return false;
	else{
		c.pop();
		p.pop();
	}
	return true;
}


void vectorDisperso::cambiar_valor_defecto(const string &nv){
	v_def=nv;
	map<int,string>::iterator it=M.begin();
	while(it!=M.end()){
		if(*it).second==nv)
			it=M.erase(it);
		elementos++it;
	}
}


/*

Usando el TDA list<int>, construir una función void agrupar_elemento que agrupe
de forma consecutiva en la lista de entrada todas las apariciones del elemento k en la lista,
a partir de todas las apariciones del elem k en la lista, a partir de la 1ª ocurrencia.

	Ej: Si entrada= {1,3,4,1,4} y k=1 => entrada= {1,1,3,4,4}
		Si entrada= {3,1,4,1,4,1,1} y k=1 => entrada= {3,1,1,1,1,4,4}

*/

void agrupar_elemento(list<int> &entrada, int k){
	list<int> iterator::p,q;
	p=entrada.find(entrada.begin(), entrada.end(), k);
	q=++p;
	//cuando se encuentra una --> inserta elem p y borra elemento
	while(q!=entrada.end())
		if(*q==k){
			entrada.insert(p,k);
			q=entrada.erase(q);
		}
		else   ++q;
}


/*

Usando el TDA list<int>, construir una función template<class T> que agrupe
en la 1ª parte de la lista los elem < k y en la 2ª los elem >= k.
NOTA: no se puede modificar el tam de la lista y usar iteradores.

Ej: Si entrada = {1,3,4,14,11,9,7,16,25,19,7,8,9} => entrada={1,3,4,7,7,  9,11,16,25,19,14,8,9}
k=8
*/

typename list<T> ::iterator it=list.begin();
while(it!=lista.end()){
	if(*it > k){
		lista.push_back(*it);
		it=lista.erase(it);
	}
	else 	++it;
}


/*

Dada una lista<int> con elem repetidos, diseñar una función que construya a partir de ella
una lista ordenada de listas, de forma que en la lista res los elementos iguales, se agrupen
en la misma sublista.

Ej: entrada={1,3,4,5,6,3,2,1,4,5,5,1,1,7} => salida={{1,1,1,1}, {2}, {3,3}, {4,4}, {5,5,5}}

*/

list<list<int>> final;
list<int> l1,l2;
list<list<int> > iterator::q;
list<int>> iterator::p;
l1.sort();
while(!l1.empty()){
	q=final.begin();
	p=l1.begin();
	elem=*p;
	while(*p==elem){
		l2.insert(l2.begin(), elem);
		p=l1.erase(p);
	}
	final.insert(q,l2);
	l2.elem();
	++q;
}



list<pair <int,float>> lista;
pair<int,float> par;
for(int i=0; i<5; ++i){
	par.first=i;
	par.send=0.5*i;
	lista.push_back(par);
}

list<pair<int,float>>::iterator p;
for(p=lista.begin(); p!=lista.end(); ++p)
	if((*p).second<3.0 && (*p).first>3)
		lista.pop(p);






/*
Para gestionar un doc, se usa un TDA Documento. Este TDA tiene una tabla Hash en la que
cada palabra del doc tiene asociada una lista ordenada con las posiciones en las que
aparece la palabra en el mismo.
Implementar una función que devuelva la distancia min en la que aparecen las palabras
pal1 y pal2 en el doc. Para la representación de la tabla se usa hashing abierto.
*/

//TDA map

class Documento{
	std::map<string,list<int>> Tabla_hash;

};

int Documento::min_distancia(string pal1, stirng pal2){
	list<int>:: l1 = tabla_hash[pal1];
	list<int>:: l2 = tabla_hash[pal2];

	int minima = numeric_limits<int>::max();

	for(list<int>::iteraror it1 = l1.begin(); it!=l1.end(); ++it1)
		for(list<int>::iteraror it2 = l2.begin(); it2!=l2.end(); ++it2){
			int d=abs(*it1 - *it2);
			if(d<minima) 	minima = d;
		}
	return minima;
}






lista mezcla(lista *listas, int n){
	tlista l;
	tlista aux1,aux2;
	int i;
	if(n==2)	l=mezcla2(listas[0],listas[1]);
	else{
		//mezcla de los 2 primeros
		aux1=mezcla2(listas[0],listas[1]);
		//mezcla de los restantes menos el último
		for(i=2; i<n-1; i++)
			if(i%2){		//impar
				aux1=mezcla2(listas[i],aux2);
				destruir(aux2);
			}
			else{			//par
				aux2=mezcla2(listas[i], aux1);
				destruir(aux1);
			}
			if((n-1)%2){	//mezcla del último
				l=mezcla2(listas[(4-1)],aux2);
				destruir(aux2);
			}
			else{
				l=mezcla2(listas[(4-1)],aux1);
				destruir(aux1);
			}
	}
	return l;
}