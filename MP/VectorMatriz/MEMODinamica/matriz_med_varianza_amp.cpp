//MEMORIA DINAMICA
//EJEMPLO NOTAS ALUMNOS MEDIA Y VARIANZA
#include <iostream>
using namespace std;

void LeerNotas(double *v, int n){
	for (int i = 0; i < n; i++)
	{
		cout << "Introduce la nota " << i;
		cin >> v[i];
	}
}

double Media(const double *v, int n){
	double m=0.0;
	for (int i = 0; i < n; i++){
		m+=v[i];
	}
	return m/n;
}

double Varianza(const double *v, int n){
	double m=Media(v,n);	//calculamos media
	double s=0.0;			//acumulamos
	for (int i = 0; i < n; i++){
		s+=(v[i]-m)*(v[i]-m);
	}
	return s/n;
}

void AmpliarM(int *&v, int &n){	//N Y V POR FERERENCIA
	int *aux = new int[n+1];
	for (int i = 0; i < n; i++)
		aux[i]=v[i];
	delete[]v;
	v=aux;
	n=n+1;
}

int main(){
	int n; //nº alumnos
	do{
		cout << "Dime nº alumnos: ";
		cin >> n;
	}while(n <=0);
double *datos = new double [n];
LeerNotas(datos,n);
double m=Media(datos,n);
double v=Varianza(datos,n);
//AmpliarM(datos,n);
cout << "Media : " << m << "Varianza: " << v;
}