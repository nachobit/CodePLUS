/**
Dado un árbol binario de búsqueda, implementa una función para imprimir las etiquetas de los nodos
en orden de mayor a menor profundidad. Si tienen la misma profundidad pueden aparecer en cualquier orden.

Ejemplo:

		5
	  /   \
	3		8
   / \	   / \
  1	  4	  6	  9
  		   \
  			7
  			
Resultado: 7,1,4,6,9,3,8,5

**/

#include "arbolbinario.h"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

//sin usar iteradores

void ImprimeProfundidad(ArbolBinario<int> &ab){
	queue<ArbolBinario<int>::nodo> q;
	ArbolBinario<int>::nodo n = ab.getRaiz();
	q.push(n);
	stack<ArbolBinario<int>::nodo> p;
	while (!q.empty()){
		n=q.front();
		q.pop();
		p.push(n);
		q.push(n.hd());
		q.push(n.hi());
	}
	while (!p.empty()){
		n=p.top();
		cout <<*n<<" ";
		p.pop();
	}
}
