
//LEER 2 MATRICES max 10x10
//MOSTRAR MATRIZ SUMA

#include <iostream>
#include <cassert>
using namespace std;

const int MAX_FIL=10;
const int MAX_COL=10;

void LeerMatriz(int m[][MAX_COL], int &nf, int &nc){
	do{
		cout << "Introduce nº de FILAS: ";
		cin >> nf;
	}while(nf <=0 || nf>MAX_FIL);
	do{
		cout << "Introduce nº de COLUMNAS: ";
		cin >> nc;
	}while(nc <=0 || nc>MAX_COL);

	for (int i = 0; i < nf; i++){
		for (int j = 0; j < nc; i++){
			cout << "m[" << i << "][" << j << "]=";
			cin >> m[i][j];
		}
	}
}

//SUMA MATRICES
void Sumar(const int m1[][MAX_COL], int f1, int c1, const int m2[][MAX_COL], int f2, int c2, int m3[][MAX_COL]){
	assert(f1==f2 && c1==c2);
	for (int i = 0; i < f1; i++){
		for (int j = 0; j < c1; j++){
			m3[i][j]=m1[i][j]+m2[i][j];
		}
	}
}

//MATRIZ TRASPUESTA
void Traspuesta(const int m[][MAX_COL], int f1, int c1, int mt[][MAX_FIL]){
		for (int i = 0; i < c1; ++i)
			for (int j = 0; j < f1; j++)
				mt[i][j]=m[j][i];
}

//MULTIPLICACION MATRICES
void Multiplicar(const int m1[][MAX_COL], int f1, int c1, const int m2[][MAX_COL], int f2, int c2, int m3[][MAX_COL]){
	assert(c1==f2);
	for (int i = 0; i < f1; i++)
		for (int j = 0; j < c2; j++){
			m3[i][j]=0;
			for (int k = 0; k < c1; k++){
				m3[i][j] += m1[i][k]*m2[k][j];
			}
		}
}

int main(){
	int mimatriz1[MAX_FIL][MAX_COL];
	int nf1,nc1;
	LeerMatriz(mimatriz1,nf1,nc1);

	int mimatriz2[MAX_FIL][MAX_COL];
	int nf2,nc2;
	LeerMatriz(mimatriz2,nf2,nc2);

	int m3[MAX_FIL][MAX_COL];
	Sumar(mimatriz1,nf1,nc1,mimatriz2,nf2,nc2,m3);
}