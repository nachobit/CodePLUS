// *****************************************************************************
//
// Prácticas de SCD. Práctica 1.
// Plantilla de código para el ejercicio del productor-consumidor con
// buffer intermedio.
//
// *****************************************************************************

#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // necesario para {\ttbf usleep()}
#include <stdlib.h> // necesario para {\ttbf random()}, {\ttbf srandom()}
#include <time.h>   // necesario para {\ttbf time()}

using namespace std;

// ---------------------------------------------------------------------
// constantes configurables:

sem_t mutex, puede_escribir, puede_leer;
const unsigned 
    num_items = 40,
    tam_buffer = 10;

unsigned buffer[tam_buffer];
unsigned primera_ocupada=0;
unsigned primera_libre=0;


// ---------------------------------------------------------------------
// introduce un retraso aleatorio de duración comprendida entre
// 'smin' y 'smax' (dados en segundos)

void retraso_aleatorio( const float smin, const float smax )
{
  static bool primera = true ;
  if ( primera )        // si es la primera vez:
  {  srand(time(NULL)); //   inicializar la semilla del generador
     primera = false ;  //   no repetir la inicialización
  }
  // calcular un número de segundos aleatorio, entre {\ttbf smin} y {\ttbf smax}
  const float tsec = smin+(smax-smin)*((float)random()/(float)RAND_MAX);
  // dormir la hebra (los segundos se pasan a microsegundos, multiplicándos por 1 millón)
  usleep( (useconds_t) (tsec*1000000.0)  );
}

// ---------------------------------------------------------------------
// función que simula la producción de un dato

unsigned producir_dato()
{
    //static int contador=1;
    //return contador++;
    static int contador = 0 ;
    contador = contador + 1 ;
    
    retraso_aleatorio( 0.1, 0.5 );
    cout << "Productor : dato producido: " << contador << endl << flush ;
    return contador ;
}

// ---------------------------------------------------------------------
// función que simula la consumición de un dato
void consumir_dato( int dato )
{
    retraso_aleatorio( 0.1, 1.5 );
    cout << "Consumidor:                              dato consumido: " << dato << endl << flush ;
}

void * funcion_productor ( void * )
{
    for (unsigned i=0; i< num_items;i++)
    {
        int dato = producir_dato();

        sem_wait(&puede_escribir);
        buffer[primera_ocupada]= dato;
        primera_ocupada=(primera_ocupada+1)%tam_buffer;
        sem_post(&puede_leer);       
        
        cout << "Productor : dato insertado: " << dato << endl << flush ;
    }
    return NULL;
}

void * funcion_consumidor ( void * ) 
{
    for (unsigned i=0; i< num_items;i++)
    {
    	int dato;

    	sem_wait(&puede_leer);
    	dato=buffer[primera_libre];
    	primera_libre=(primera_libre+1)%tam_buffer;
    	sem_post(&puede_escribir);
        
        cout << "Consumidor:                              dato extraído : " << dato << endl << flush ;
    	consumir_dato(dato);
    }
    return NULL;
}

int main(){

    pthread_t  hebra_productor,hebra_consumidor;
    
    sem_init(&mutex,0,1);
    sem_init(&puede_escribir,0,tam_buffer);
    sem_init(&puede_leer,0,0);
    
    pthread_create(&hebra_productor,NULL,funcion_productor,NULL);
    pthread_create(&hebra_consumidor,NULL,funcion_consumidor,NULL);

    pthread_join(hebra_productor,NULL);
    pthread_join(hebra_consumidor,NULL);
    
    cout << "***FIN***" << endl;

    sem_destroy(&puede_escribir);
    sem_destroy(&puede_leer);
    sem_destroy(&mutex);
}