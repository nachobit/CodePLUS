#include <iostream>
#include <pthread.h>
#include "fun_tiempo.h"
using namespace std;

const unsigned long m = 100;  //nº muestras
const unsigned long n = 10 ;  //nº hebras
double res_parcial[n];  //vector resultados parciales

double f(double x){ // implementa funcion  f:
   return 4.0/(1+x*x); //f(x)=4/(1+x^2)
}

void *funcion_hebra(void *ih_void) //funcion que ejecuta cada hebra
{
  unsigned long ih = (unsigned long) ih_void; //numero o ındice de esta hebra
  double sumap = 0.0 ; //calcular suma parcial en ”sumap”
  for(unsigned long i=ih*(m/n); i<(ih+1)*(m/n); i++)
    sumap+=f((i+0.5)/m);
  res_parcial[ih] = sumap; // guardar suma parcial en vector.
}

double calcular_integral_concurrente(){ 
  pthread_t id_hebra[n];
  unsigned long suma_p=0.0;
  double suma_t=0.0;

  for (unsigned i=0; i<m; i++){
    pthread_create(&(id_hebra[i%n]),NULL,funcion_hebra,(void *)i); //crear y lanzar n hebras

    pthread_join(id_hebra[i%n], (void **) (&suma_p)); // esperar (join) a que termine cada hebra     
  }    
  for (unsigned i=0; i<n; i++){  	//sumar las sumas parciales y poner en suma_t
    suma_t=suma_t+res_parcial[i];
	}
  return suma_t/m;  
}

int main(){
  double suma;
  struct timespec inicio = ahora();
  suma=calcular_integral_concurrente();
  struct timespec fin = ahora();
  cout<< "la suma total : "<<suma<<"\n";
  cout<< "tiempo transcurrido == " << duracion(&inicio, &fin) << " seg. " << endl;
}