#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>

using namespace std ;


const unsigned 
	num_fumadores = 3;

ptrhead_t 
	hebra_estanquero, 
	hebra_fumador[num_fumadores] ;

sem_t   puede_poner_ingredientes,
        puede_fumar[num_fumadores];

//----------------------------------------------------------------------


void * estanquero( void * )
{
  while (true) {
        int k; 

	sem_wait( &puede_poner_ingredientes ) ;

      //Decide el ingrediente y por tanto, el fumador  
        k= rand() % 3 ;

	switch (k)
	{
	  case 0: cout <<"ESTANQUERO:..... Poniendo tabaco para FUMADOR "<<k<<endl;
          break;
	  case 1: cout <<"ESTANQUERO:..... Poniendo cerillas para FUMADOR "<<k<<endl;
	  break;
	  case 2: cout <<"ESTANQUERO:..... Poniendo papel para FUMADOR "<<k<<endl;
	}

        sem_post( &(puede_fumar[1]) );
  }
    return NULL ;
}

//----------------------------------------------------------------------
/* Función que simula la acción de fumar 
como un retardo aleatoria de la hebra*/
void fumar()
{
  sleep(rand() % 5 );
}


//----------------------------------------------------------------------

void * fumador( void * i)
{
    unsigned long j=(unsigned long)(i);

    while (true) {

	cout<< "FUMADOR "<<j<<":..... esperando su ingrediente"<<endl;

        sem_wait( &(puede_fumar[j]) );

	cout<< "FUMADOR "<<j<<":..... Empieza a fumar"<<endl;

	sem_post( &puede_poner_ingredientes ) ;

        fumar();

	cout<< "FUMADOR "<<j<<":..... Termina de fumar"<<endl;

    }
    return NULL ;
}

//----------------------------------------------------------------------

int main()
{   
  
   /* Inicializa la semilla aleatoria */
   srand ( time(NULL) );
  
   sem_init( puede_poner_ingredientes, 0, 1); 

   for( unsigned i = 0 ; i < 3 ; i++ ) 
      sem_init( &(puede_fumar[i]), 0, 0);

   
   pthread_create( &hebra_estanquero,  NULL, estanquero,  NULL );
   for( unsigned i = 0 ; i < 3 ; i++ )
      pthread_create( &(hebra_fumador[i]), NULL, fumador, (void *) i );
 
      
   pthread_join( hebra_estanquero,  NULL);
   for( unsigned i = 0 ; i < 3 ; i++ )
      pthread_join( (hebra_fumador[i]), NULL);

      
   sem_destroy( &puede_poner_ingredientes);
    for( unsigned i = 0 ; i < 3 ; i++ )
      {sem_destroy( &(puede_fumar[i])); }

}


