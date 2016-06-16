//Celdas enlazadas
#include <iostream>
using namespace std;

struct Celda{
	int dato;
	Celda *sig;
};

void LeerDatos(Celda * &L){
	int d;
	cin >> d;

	if (d!=-1){
		L=new Celda;
		L->dato=d;
		L->sig=0;
		Celda *p = L;
		cin >> d;

		while(d!=-1){
			p->sig=new Celda;
			p=p->sig;
			p->dato=d;
			p->sig=0;
		}
	}
	else
		L=0;
}

void InsertarDatos(Celda *&L, int posicion, int nuevo){
	Celda * aux=new Celda;
	aux->dato = nuevo;

	if (posicion==0){
		aux->sig=L;
		L=aux;
	}
	else{
		Celda *p=L;
		for (int i = 0; i < posicion-1; ++i)
			p=p->sig;
		aux->sig=p->sig;
		p->sig=aux;
	}
}

void BorrarDatos(Celda *&L, int posicion){
	Celda *aux;

	if (posicion==0){
		aux=L;
		L=aux->sig;
		delete aux;
	}
	else{
		Celda *p=L;
		for (int i = 0; i < posicion-1; ++i)
			p=p->sig;
		aux=p->sig;
		p->sig=aux->sig;
		delete aux;
	}
}

void LiberarMemoria(Celda *L){
	while(L!=0){
		Celda *aux=L;
		L=L->sig;
		delete aux;
	}
}

int Longitud(Celda *L){
	Celda * p=L;
	int cont=0;
	while(p!=0){
		p=p->sig;
		cont++;
	}
	return cont;
	//for(Celda *p=L, cont=0; p!=0; p=p->sig; cont++)	OTRA FORMA
}

void Invertir(Celda *&L){
	Celda *lout=0, *aux;
	while(L!=0){
		aux=L;
		L=L->sig;
		aux->sig=lout;
		lout=aux;
	}
}

int main(){
	Celda *milista;

	//LeerDatos
	LeerDatos(milista);
	//Insertar Datos
	int d;
	cout << "Dato: ";
	cin >> d;
	cout << "Posicion: ";
	int pos;
	cin >> pos;
	InsertarDatos(milista,pos,d);
	//Borrar datos
	BorrarDatos(milista,2);		//Borrar en pos 2
}