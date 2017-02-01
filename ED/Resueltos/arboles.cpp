/*

Sea A un árbol binario con n nodos. Se define el ancestro más cercano (AMC) entre 2 nodos
v y w como el ancestro de > profundidad que tiene a v,w como descendientes.
Diseñar una función que tenga como entrada un árbol binario de enteros y 2 nodos
v y w. Como salida el AMC (v,w)

*/

nodo AMC(ArbolBinario<T> &ab, nodo v, nodo w){
	vector<nodo> vnodos;
	while(v->padre()!=0){
		vnodos.insert(v->padre());
		v=v->padre();
	}
	bool find=false;
	vector<nodo>::iterator it;
	while(find && w->padre()!=0){
		it=vnodos.find(w->padre());
		if(it!=vnodos.end())
			find=true;
		else	w=w->padre();
	}
	if(find)	return *it;
	else	return nodo();
}


/*
Construir una función que devuelva para un ABB, el nivel del nodo con mayor valor de la clave
*/

int nivel(ABB<T>A){
	Nodo n;
	n=A.raiz();
	contador=0;
	while(n!=nodonulo){
		n=A.drcha(n);
		contador++;
	}
	return contador;
}


/*

Sea T un árbol binario con n nodos. Se define k como un nodo v que cumple la condición de que
el nº de descendientes en el subárbol izquierdo de v difiere del nº de descendientes del subárbol
derecho en al menos 5. Usando el TDA bintree construir una función que encuentre los 5 nodos de T.

*/

bool cinconodo(const bintree<int>:: nodo n){
	if abs(contar(n.left()) - contar(n.rigth()))
		return true;
	else	return false;
}

int contar(bintree<int>::nodo n){
	if n=null()	return 0;
	else	return 1+contar(n.left()) + contar(n.rigth())
}
int recuento(bintree<int> &a){
	int num=0;
	bintree<int>::preorder_iterator p=a.begin();
	while (p!=a.end())
		if cinconodo(p)	numero++;
	++p;
}

/*

Dado un árbol binario de enteros, implementar una función que cuente el nº de caminos cuya suma
de valores de las etiquetas de los nodos que los componen sea exactamente k

*/

int numerocaminos(bintree<int> &ab, int k, bintree<int>::nodo n){
	if(n.left()==bintree<int>null() && n.right()==bintree<int>null())
		if(*n==k)	return 1;
	else	return 0;

	else{
		int contador=0;
		if(n.left()!=bintree<int>::null())
			contador+=numerocaminos(ab, k-*n, n.left());
		if(n.right()!=bintree<int>::null())
			contador+=numerocaminos(ab, k-*n, n.right());
		return contador;
	}
}

/* 

Usando el TDA ABB construir una función que tenga como entrada un ABB<int> y que devuelva 
el nº de nodos con un valor de etiqueta dentro de un intervalo [a,b] con a.b enteros.

*/

int contar(int a,b, ABB<int>T){
	if(T.raiz()==0)	return
	else if(T.etiqueta(T.raiz())>b)
		return contar(a,b,T.izqda(T.raiz(),T))
	else if(T.etiqueta(T.raiz())<a)
		return contar(a,b,T.drcha(T.raiz(),T))
	else
		return 1+contar(a,b,T.izqda(T.raiz(),T)) + contar(a,b,T.drcha(T.raiz(),T));
}


/* OTROS */

bool inclusion(const conjunto & c1, const conjunto & c2){
	for(const ABB::const_iterator p=c1.begin(); p!=c1.end(); ++p)
		if(!c2.petercene(*p))	return false;
	return true;
}



void inordenrecursivo(Arbolbinario<int> A){
	stack<nodo> pilanodos;
	Nodo p=A.root();
	while(p!=nodonulo){
		while(p!=nodonulo){
			//meter en la pila el hijo dercha y el propio nodo
			if(A.hijodrcha(p))
				pilanodos.push(A.hijodrcha(p));
			pilanodos.push(p);
			p=A.hijodrcha(p);
		}
		//pop de un nodo sin hijo izqda
		p=pilanodos.pop();
		//visita todos los nodos que no tienen hijo a la drcha
		while(!pilanodos.empty() && A.hijodrcha(p)==nulo){
			cout << A.etiqueta(p);
			p=pilanodos.pop();
		}
		//visita el 1er nodo con un hijo a la drcha (si hay)
		cout << A.etiqueta(p);
		if(!pilanodos.empty())
			p=pilanodos.pop();
		else p=nodonulo;
	}
}


