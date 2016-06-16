#include "Matriz.h"

void Matriz::Reservar(int f, int c){
	nc=0;
	datos=0;
	
	if (f>0){
		datos=new Celda;
		datos->v=new int[c];
		Celda* p=datos;
		for (int i = 1; i < f; i++){	
			p->sig=new Celda;
			p=p->sig;
			p->v=new int[c];
		}
		p->sig=0;
	}
}
	
void Matriz::Borrar(){
	while(datos!=0){
		Celda *aux=datos;
		datos=datos->sig;
		delete[]aux->v;
		delete aux;
	}
}

int Matriz::GetFilas()const{
	Celda *p=datos;
	int con=0;
	while(p!=0){
		con++;
		p=p->sig;
	}
	return con;
}

void Matriz::Copiar(const Matriz& M){
	int f=M.GetFilas();
	Reservar(f,M.nc);
	Celda *p=datos;
	Celda *q=M.datos;
	while(q!=0){
		for (int j = 0; j < nc; j++){
			p->v[j]=q->v[j];
		}
		p=p->sig;
		q=q->sig;
	}
}

Matriz::Matriz(){
	datos=0;
	nc=0;
}

Matriz::Matriz(int nf, int nc){
	Reservar(nf,nc);
}

Matriz::Matriz(const Matriz& M){
	Copiar(M);
}

Matriz::~Matriz(){
	Borrar();
}

Matriz& Matriz::operator=(const Matriz& M){
	if (this!=&M){
		Borrar();
		Copiar(M);
	}
	return *this;
}

int Matriz::Get(int i, int j)const{
	Celda *p=datos;
	for (int r = 0; r < i; r++){
		p=p->sig;
	}
	return p->v[j];
}

void Matriz::Set(int i, int j, int nuevo){
	Celda *p=datos;
	for (int r = 0; r < i; r++){
		p->v[j]=nuevo;
	}
}

//OTROS OPERADORES

bool Matriz::operator==(const Matriz& M){
	if (GetFilas()!=M.GetFilas() || nc!=M.nc)
		return false;
	int f=GetFilas();
	for (int i = 0; i < f; ++i)
		for (int j = 0; j < nc; j++)
			if (Get(i,j)!=M.Get(i,j))
				return false;
		}
	return true;
}

Matriz Matriz::operator+(const Matriz& M){
	Matriz Msuma(*this);
	int f=GetFilas();
	for (int i = 0; i < f; i++){
		for (int j = 0; j < nc; j++){
			int d=M.Get(i,j);
			int v=Msuma.Get(i,j);
			Msuma.Set(i,j,d+v);
		}
	}
	return Msuma;	
}

int & Matriz::operator()(int i, int j){
	Celda * p=datos;
	for (int r = 0; r < i; r++){
		p=p->sig;
	}
	return p->v[j];
}

//FUNICONES AMIGAS
void Imprimir(const Matriz &M){
	Celda *p=M.datos;
	while(p!=0){
		for (int j = 0; j < M.nc; j++)
			cout << p->v[j] << ' ';
		cout << endl;
		p=p->sig;
	}
}

ostream& operator<<(ostream &os, const Matriz &M){
	Celda *p=M.datos;
	while(p!=0){
		for (int j = 0; j < M.nc; j++)
			os << p->v[j] << ' ';
		os << endl;
		p=p->sig;
	}
	return os;
}

istream& operator>>(istream& is, Matriz M){
	M.Borrar();
	int f,c;
	is>>f>>c;
	M.Reservar(f,c);
	for (int i = 0; i < f; i++){
		for (int j = 0; j < c; j++){
			int d;
			is>>d;
			M.Set(i,j,d)
		}
	}
	return is;
}