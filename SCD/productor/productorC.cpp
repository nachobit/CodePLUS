#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

sem_t mutex, puede_escribir, puede_leer;
const int num_items = 80;
const int tam_buffer=20;
int buffer[tam_buffer];
int primera_ocupada=0;
int primera_libre=0;

int producir_dato(){
   static int contador=1;
   return contador++;
}

void consumir_dato(int dato){
   cout << "dato recibido: " << dato << endl;
}

void * productor (void *){
    for (unsigned i=0; i< num_items;i++){
        int dato = producir_dato();
        sem_wait(&puede_escribir);
        buffer[primera_ocupada]= dato;
        primera_ocupada=(primera_ocupada+1)%tam_buffer;
        sem_post(&puede_leer);       
    }
    return NULL;
}

void * consumidor (void *){
    for (unsigned i=0; i< num_items;i++){
    	int dato;
    	sem_wait(&puede_leer);
    	dato=buffer[primera_libre];
    	primera_libre=(primera_libre+1)%tam_buffer;
    	sem_post(&puede_escribir);
    	consumir_dato(dato);
    }
    return NULL;
}

int main(){

    pthread_t  hebra_productor,hebra_consumidor;
    
    sem_init(&mutex,0,1);
    sem_init(&puede_escribir,0,tam_buffer);
    sem_init(&puede_leer,0,0);
    
    pthread_create(&hebra_productor,NULL,productor,NULL);
    pthread_create(&hebra_consumidor,NULL,consumidor,NULL);

    pthread_join(hebra_productor,NULL);
    pthread_join(hebra_consumidor,NULL);
    
    cout << "***FIN***" << endl;

    sem_destroy(&puede_escribir);
    sem_destroy(&puede_leer);
    sem_destroy(&mutex);
}