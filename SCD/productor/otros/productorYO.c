#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER 1024			// tamaño del buffer
#define DATOS_A_PRODUCIR 100000	// datos a producir

sem_t mutex = 1;
semaforo vacio = N;
semaforo lleno = 0;


void * productor( void * )
{ 
	for(unsignedi=0; i<num_items; i++){
		int dato = producir_dato() ; 
		// falta: insertar ”dato” en el vector
	}
	return NULL ; 
}
//Producir dato/item
int producir_dato() {
	static int contador = 1 ;
	return contador ++ ;
}

//var a: integer;
int a;
begin
	while true{
		//wait(mutex);
		a := producir_dato();
		sem(vacio);
		sem(mutex);
		sem_wait(puede_escribir);
		x := a;
		producidos := producidos + 1;
		sem(mutex);
		sem(lleno);
		sem_signal(puede_leer);
	}
end