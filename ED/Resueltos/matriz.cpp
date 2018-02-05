
/*
Disponemos de un TDA matriz_de_enteros (se almacenan los datos por filas) y se quiere
definir un iterador que itere por columnas sobre los elementos pares de la matriz.
Para ello hay que implementar los operadores ++ y *, así como las funciones
begin() y end() en la clase matriz.
*/

class Matriz{
	int **datos;
	int nf,nc;

public:
	class iterador{
	private:
		int *d;
	public:
		int & operator *() const{
			return *d;
		}
		iterator & operator++();
	};
};
iterator end(){
	Matriz::iterator id.d=& (datos[nf-1][nc]){
		return it;
	}
}
iterator begin(){
	Matriz::iterator it;
	it.d = & datos[0][0];
	it(*it.d)%2==0
		return it;
	else
		++it;
	return it;
}

Matriz::iterator & operator++(){
	int f = (d- &(datos[0][0]))/nc;	//fil donde apunta
	int c = (d- &(datos[0][0]))%nc;	//col donde apunta

	while(true){
		if(f>=nf-1 && c>=nc-1){	//no hay más elementos
			d= &(datos[nf-1][nc]);
			return *this;	//devolvemos end
		}
		else
			if(f<nf-1){
				f=f+1;	//en la misma col, el siguiente
				d=&(datos[f][c]);
				if(*d%2 == 0)	return *this;
			}
			else{
				f=0;
				c=c+1;
				d=&(datos[f][c]);
				if(*d%2==0)	return *this;
			}
	}
}
friend class Matriz;