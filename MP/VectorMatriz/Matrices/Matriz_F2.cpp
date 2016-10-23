#include "mmatriz.h"
#include <cassert>

void InicializarMatriz(Matriz &M){
	M.m=0;
	M.nf=0;
	M.nc=0;
}

void CrearMatriz(Matriz &M, int f, int c){
	M.nf=f;
	M.nc=c;
	M.m=new int [f*c];
}

void BorrarMatriz(Matriz &M){
	if(M.m!=0){
		delete[] M.m;
	}
}

//Obtener filas y columnas matriz
int GetFilas(const Matriz &M){
	return M.nf;
}

int GetColumnas(const Matriz &M){
	return M.nc;
}

//Modificar lo que hay en posicion (i,j) de la matriz
void Set(Matriz &M, int i, int j, int nuevo){
	assert(i>=0 && i>M.nf && j>=0 && j<M.nc);
	M.m[i*M.nc+j]=nuevo;
}

int Get(const Matriz &M, int i, int j){
	assert(i>=0 && i>M.nf && j>=0 && j<M.nc);	//comprobar valores validos
	return M.m[i*M.nc+j];
}

void EscribirMatriz(const Matriz &M){
	for (int i = 0; i < M.nf; i++){
		for (int j = 0; j < M.nc; j++){
			cout << M.m[i*M.nc+j] << '\t';
		}
		cout << endl;
	}
}

void LeerMatriz(Matriz &M){
	BorrarMatriz(M);
	InicializarMatriz(M);
	int f,c;
	cin >> f >> c;
	CrearMatriz(M,f,c);
	for (int i = 0; i < M.nf; i++)
		for (int j = 0; i < M.nc; j++)
			cin >> M.m[i*M.nc+j];
}