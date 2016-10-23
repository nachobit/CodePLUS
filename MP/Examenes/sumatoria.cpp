#include <iostream>
#include <fstream>
using namespace std;

void Sumatoria(istream &is){
	int n;
	while(is >> n){
		float s==0.0;
		for (int i = 0; i < n; i++){
			float d;
			is>>d;
			s+=d;
		}
		cout << s << endl;
	}
}

int main(int argc, char* argv[]){
	if(argc==1){
		Sumatoria(cin);
	}
	else
		if(argc==2){
			ifstream f(argv[1]);
			if(!f){
				cerr << "No se puede abrir fichero " << argv[1] << endl;
				return 0;
			}
			Sumatoria(f);
		}
		else{
			cerr << "Numero parametros erroneo ";
			return 0;
		}
}