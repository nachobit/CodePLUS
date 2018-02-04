/**
La clase liga almacena los resultados de los enfrentamientos en una liga de baloncesto.
- Implenta un método que dado un código de equipo obtenga el nº de enfrentamientos que ha ganado.
- Implementa un iterador dentro de la clase Liga que permita recorrer los enfrentamientos en los que el resultado ha sido el empate. 
Implementar los métodos begin() y end()
**/

#include <iostream>
#include <list>
using namespace std;

struct enfrentamiento{
	unsigned char eq1, eq1;
	unsigned int puntos_eq1, puntos_eq2;
};

class liga{
private:
	list<enfrentamiento>res;
public:
	//...
	int Ganados(unsigned char code){
		list<enfrentamiento>::iterator i;
		int n=0;
		for(i=res.begin(); i!=res.end(); ++i){
			if ((*i).eq1==code && (*i).puntos_eq1>(*i).puntos_eq2) n++;
			else
				if ((*i).eq2==code && (*i).puntos_eq2>(*i).puntos_eq1) n++;
		}
		return n;
	}

	class iterator{
	private:
		list<enfrentamiento>:: iterator it.final();
	public:
		iterator(){}
		bool operator==(const iterator &i)const{
			return i.it==it;
		}
		bool operator!=(const iterator &i)const{
			return i.it!=it;
		}
		enfrentamiento& operator* (){
			return (*it);
		}
		iterator & operator++(){
			++it;
			bool salir = false;
			while (it!=final && !salir){
				if ((*i).puntos_eq1==(*it).puntos_eq2) salir=true;
				else ++it;
			}
			return *this;
		}
		friend class liga;
	
};

iterator begin(){
	iterator i;
	i.it = res.begin();
	i.final = res.end();
	if (!(*(i.it)).puntos_eq1==(*(i.it)).puntos_eq2) ++i;
	return i;
}

iterator end(){
	iterator i;
	i.it=res.end();
	i.final = res.end();
	return i;
}