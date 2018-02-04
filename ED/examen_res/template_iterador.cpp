/**
Implementa un iterador que itere sobre los elementos que cumplan la propiedad 
de que la suma de los elementos del bintree<int> sea un nº par.
Implementar las clases begin() y end()
**/

#include <unordered_map>
#include <arbolbinario.h>
using namespace std;

int Suma(Arbolbinario<int>::nodo n){
	if (n.nulo()) return 0;
	else return (*n)+Suma(n.hi())+Suma(n.hd());
}

//Contenedor de pares de elementos {clave, bintree<int>}
template<typename T>
class contenedor{
private: 
	unordered_map<T,Arbolbinario<int> > datos;
public:
	//...
	class iterator{
	private:
		typename unordered_map<T,Arbolbinario<int> >::iterator it,final;
	public:
		iterator(){}
		bool operator==(const iterator &i)const{
			return i.it==it;
		}
		bool operator!=(const iterator &i)const{
			return i.it!=it;
		}
		pair<const T, Arbolbinario<int> > & operator* (){
			return (*it);
		}
		iterator & operator++(){
			++it;
			bool salir=false;
			while (it!=final && !salir){
				if (suma((*it).second.getRaiz())%2==0)
					salir=true;
				else
					++i;
			}
			return *this;
		}
		friend class contenedor;
	};

	iterator begin(){
		iterator i;
		i.it = datos.begin();
		i.final = datos.end();
		if (suma((*(i.it)).second.getRaiz())%2==1) ++i;
		return i;
	}

	iterator end(){
		iterator i;
		i.it=datos.end();
		i.final = datos.end();
		return i;
	}
};