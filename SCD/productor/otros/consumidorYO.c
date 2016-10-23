#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

#define MAX_BUFFER 1024			// tamaño del buffer
#define DATOS_A_PRODUCIR 100000	// datos a producir


void * consumidor( void * ){ 
	for(unsignedi=0; i<num_items; i++){ 
		int dato ;
		// falta: leer ”dato” desde el vector intermedio consumir_dato( dato ) ;
	}
	return NULL ;
}

//consumir dato
void consumir_dato( int dato ) {
	cout << "dato recibido: " << dato << endl ;
}


//var b: integer;
int b;
begin
	while true{
		//wait(mutex);
		sem_wait(puede_leer);
		b := x;
		consumidos := consumidos + 1;
		//signal(mutex);
		sem_signal(puede_escribir);
		UsarValor(b);
	}
end


sem_wait(&mutex);
cout << "hebra numero: " << ((unsigned long) p) << ". " << endl ;
sem_post(&mutex);