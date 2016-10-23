#include <iostream>
using namespace std;

int main(){
	int f,c;
	cout << "¿Cuantas filas?: ";
	cin >> f;
	cout << "¿Cuantas columnas?: ";
	cin >> c;
	if (f>0 && c>0){
		int *m;				//int **m;			vector de vectores
		m=new int [f*c];	//m=new int*[f]		vector de vectores

		//Puntero a vector:
		m[0] = new int[f*c];
		for (int i=1; i<f; ++i)
    		m[i] = m[i-1]+c;
	
	//Leer los elemntos de la matriz
	for (int i = 0; i < f; i++)
		//m[i]=new int[c];						vector de vectores
		for (int j = 0; j < c; j++){
			cout << "m[" << i << "][" << j << "]=";
			cin >> m[i*c+j];	//desplazar al inicio y entre elementos
		}
		//delete[] m;

		//Liberar memoria:
		for (int i = 0; i < f; i++)
			delete[] m[i];
		delete[] m;

		//Liberar memoria (Puntero a vector):
		delete[] m[0];
		delete[] m;
	}
}