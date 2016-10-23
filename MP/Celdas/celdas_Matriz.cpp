//MATRIZ como celdas enlazadas de vectores
#include <iostream>
using namespace std;

struct Celda{
	int *dato;
	Celda *sig;
};

void ReservarCeldas(Celda *&L, int num){
	L=0;
	if (num>0){
		L=new Celda;
		L->sig=0;
		Celda *p=L;
		for (int i = 1; i < num; ++i){
			p->sig=new Celda;
			p=p->sig;
			p->sig=0;
		}
	}
}

int main(){
	int f,c;
	cout << "¿Cuantas filas?: ";
	cin >> f;
	cout << "¿Cuantas columnas?: ";
	cin >> c;

	if (f>0 && c>0){
		Celda *m;
		ReservarCeldas(m,f);
	}

	Celda *p=m;
	for (int i = 0; i < f; ++i){
		p->dato=new int[c];
		p=p->sig;
	}

	p=m;
	for (int i = 0; i < f; ++i){
		for (int j = 0; i < c; ++i){
			cin >> p->dato[j];
		}
		p=p->sig;
	}
}