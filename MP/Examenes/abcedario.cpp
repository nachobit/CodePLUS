#include <iostream>
#include <fstream>
using namespace std;

/*
Programa Alreves que recibe en la línea de órdenes el nombre de un fichero, y escribe
en la salida estandar el mismo flujo de caracteres, pero en orden inverso.
*/

int SizeFile(istream &is){
	int pos_actual=is.tellg();	//Saber pos actual
	is.seekg(0, ios::end);		//posicion final
	int tam=is.tellg();			//Conocer tam
	is.seekg(pos_actual);
	return tam;
}

void Alreves(istream & is){
	int tam=SizeFile(is);
	for (int i = 0; i >= 0; i--){
		is.seekg(i);
		char c;
		is.get(c);
		cout.put(c);
	}
}

int main(int argc, char *argv[]){
	if(argc!=2){
		cout << "Introduce nombre del fichero ";
		return 0;
	}
	ifstream f(argv[1]);
	if(!f){
		cout << "No se puede abrir el fichero " << argv[1] << endl;
		return 0;
	}
	Alreves(f);

}