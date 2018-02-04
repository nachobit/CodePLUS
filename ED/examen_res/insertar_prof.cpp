/**
Un heap-doble es una estructura jerárquica que tiene como propiedad fundamental que 
para cualquier nodo Z a profundidad par la clave almacenada en Z es menor que 
la del padre pero mayor que la del abuelo (cuando existen), y para cualquier nodo Z
a profundidad impar, la clave almacenada en Z es mayor que la del padre pero menor 
que la del abuelo (cuando existen), siendo un árbol binario y estando las hojas
empujadas a la izquierda. Diseña una función para insertar un nuevo nodo en la
estructura y aplicarla a la construcción de un heap-doble con las claves 
{30, 25, 12, 16, 10, 15, 5 ,18, 23, 32, 4, 17}
**/


#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class heap_doble{
private:
	vector<int> datos;
public:
	void insertar(int clave){
		int pos = datos.size();
		datos.push_back(clave);
		int padre = (pos-1)/2;
		int abuelo = (padre-1)/2;
		int profundidad = (log(pos+1)/log(2));	//indexa desde 0
		bool colocado = false;
		while (pos>0 && !colocado){
			if (padre>0){
				if (profundidad%2==0){
					if (datos[padre]>datos[pos] && datos[abuelo]<datos[pos])
						colocado=true;
					else{
						if (datos[padre]<datos[pos]){
							swap(datos[padre],datos[pos]);
							pos = padre;
							padre = abuelo;
							abuelo = (padre-1)/2;
						}
						else if (datos[abuelo]>datos[pos]){
							swap(datos[abuelo],datos[pos]);
							pos = abuelo;
							padre = (pos-1)/2;
							abuelo = (padre-1)/2;
						}
					}
				}
				else{
					if (datos[padre]<datos[pos] && datos[abuelo]>datos[pos])
						colocado=true;
					else{
						if (datos[padre]>datos[pos]){
							swap(datos[padre],datos[pos]);
							pos = padre;
							padre = abuelo;
							abuelo = (padre-1)/2;
						}
						else if (datos[abuelo]<datos[pos]){
							swap(datos[abuelo],datos[pos]);
							pos = abuelo;
							padre = (pos-1)/2;
							abuelo = (padre-1)/2;
						}
					}
				}
			}
			else{
				if (datos[padre]<datos[pos]){
					colocado=true;
				}
				else{
					swap(datos[padre],datos[pos]);
					pos = padre;
					colocado=true;
					//se sale porque pos es 0
				}
			}
			profundidad--;
		}
	}
}