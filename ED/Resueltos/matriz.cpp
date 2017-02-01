

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