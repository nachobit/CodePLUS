#include <iostream>
#include <time.h>	//  time()
#include <unistd.h>	//  usleep()	
#include <stdlib.h>	//  rand()
#include <semaphore.h>
#include <pthread.h>
#include <string>

using namespace std;

enum ingrediente{PAPEL,CERILLAS,TABACO,BOQUILLA};

const unsigned int numero_hebras=4;       
sem_t puede_fumar[numero_hebras];
sem_t puede_poner, mutex;                           
ingrediente mostrador;                                           

void fumar()
{
	const unsigned miliseg = 100U + (rand() % 1900U);
	usleep(1000U*miliseg);
}
void* fumador(void* i){
	int id = *((int*) (&i));
	string ing_esperado;
	ingrediente ing_cogido;

	if(id==0)
		ing_esperado="Papel";
	else if(id==1)
		ing_esperado="Tabaco";
	else if (id==2)
		ing_esperado="Cerillas";
    else
        ing_esperado="boquillas";

	while(true){
		sem_wait(&mutex);
		cout << "Fumador " << id+1 << ": " << "Espera: " << ing_esperado << endl;
		sem_post(&mutex);
		sem_wait(&puede_fumar[id]);

		ing_cogido = mostrador;     // coger el ingrediente desde el mostrador

		sem_post(&puede_poner);
		
		sem_wait(&mutex);
		cout << "Fumador " << id+1 <<  " Fumando..." << endl;
		sem_post(&mutex);
		fumar();
		sem_wait(&mutex);
		cout << "Fumador " << id+1 << " ha acabado de fumar" << endl;
		sem_post(&mutex);
	}
    return NULL;
}

ingrediente generar_ingrediente(){
	int i=rand()%4;
	ingrediente generado;

	if(i==0)
		generado=PAPEL;
	else if(i==1)
		generado=TABACO;
	else if (i==2)
		generado=CERILLAS;
	else
        generado=BOQUILLA;
    return generado;
}

void* estanquero(void*){
	ingrediente seleccionado;
	int turno;
	
	while(true){
		seleccionado = generar_ingrediente();
	
		sem_wait(&puede_poner);
		
		mostrador = seleccionado;
		sem_wait(&mutex);
		cout << "Estanquero: El mostrador contiene el ingrediente: ";		
		sem_post(&mutex);

		if(mostrador==PAPEL){
			sem_wait(&mutex);
			cout << "Papel" << endl;
			sem_post(&mutex);
		}
		else if(mostrador==TABACO){
			sem_wait(&mutex);
			cout << "Tabaco" << endl;
			sem_post(&mutex);
		}
        else if (mostrador==BOQUILLA){
			sem_wait(&mutex);
			cout << "Boquilla" << endl;
			sem_post (&mutex);
        }
		else {
			sem_wait(&mutex);
			cout << "Cerillas" << endl;
			sem_post(&mutex);
		}

		if(mostrador==PAPEL)
			turno=0;
		else if(mostrador==TABACO)
			turno=1;
		else if (mostrador==CERILLAS)
			turno=2;
        else if (mostrador==BOQUILLA);
        	sem_wait(&mutex);

			cout << "Estanquero: fumador numero " << turno + 1 << " puede fumar..." << endl;
			sem_post(&mutex);
			sem_post(&puede_fumar[turno]);
	}
	return NULL;
}

int main(){
	srand( time(NULL) );    // inicializa la semilla aleatoria
	pthread_t hebras_fumadoras[numero_hebras];
	pthread_t hebra_estanquero;
	
	sem_init(&mutex,0,1);
	sem_init(&puede_poner,0,1);
	for(int i=0; i<numero_hebras; i++)
		sem_init(&puede_fumar[i],0,0);
	
	pthread_create(&hebra_estanquero,NULL, estanquero, NULL);

	for(int i=0; i<numero_hebras; i++)
		pthread_create(&hebras_fumadoras[i], NULL, fumador, (void*)i);

	pthread_join(hebra_estanquero, 	NULL);
	for(int i=0; i<numero_hebras; i++)
		pthread_join(hebras_fumadoras[i], NULL);
	
	
	sem_destroy(&puede_poner);
	sem_destroy(&mutex);

	for(int i=0; i<numero_hebras; i++)
		sem_destroy(&puede_fumar[i]);
} 	
