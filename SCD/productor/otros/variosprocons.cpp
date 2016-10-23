// programa para varios productor y consumidor : 5 productores y 4 consumidores y 1 buffer

#include <iostream>
#include "mpi.h"
#include <cmath>
using namespace std;

#define Producir 7
#define Consumir 8
#define Buffer 5
#define ITERS 20
#define TAM 5

//Productor
void Productor_(int rank){
	// como tenemos varios procesos productoras repartimos a cada uno un intervalo de numeros que tiene que producir segun su rank
	for (unsigned int i=rank*(ITERS/5);i<rank*(ITERS/5)+(ITERS/5);i++){
		cout << "Productor " << rank <<" produce valor " << i << endl << flush;
		// proceso productor manda a buffer un dato con etiqueta 10 para que buffer lo reciba con etiqueta 10
		MPI_Ssend( &i, 1, MPI_INT, Buffer, 10, MPI_COMM_WORLD );
	}
}

//Consumidor
void Consumidor_(int rank){
	int value, peticion=1; float raiz; MPI_Status status;
	// aqui hacemos un intervalo a cada proceso consumidor para que consuma cada uno su parte
	for (unsigned int i=0; i<ITERS/4; i++){
		MPI_Ssend(&peticion, 1, MPI_INT, Buffer, 5, MPI_COMM_WORLD);
		// proceso consumidor recibe desde buffer con etiqueta 0
		MPI_Recv(&value, 1, MPI_INT, Buffer, 0, MPI_COMM_WORLD, &status);
		cout << "Consumidor recibe valor "<<value<<" de Buffer "<< endl << flush;
		raiz=sqrt(value);
	}
}

//Buffer
void Buffer_(){
	int value[TAM], pos=0, enviados=0, peticion, turno;
	MPI_Status status;
	
	while(enviados < ITERS){
		if(pos == 0){	//rama=0
			turno=Producir; 
			//comprobamos si hay algun mensaje pendiente con etiquta 10 y si no hay esperamos hasta que haya
			MPI_Probe(MPI_ANY_SOURCE,10,MPI_COMM_WORLD,&status);
		}
		else if(pos == TAM){	//rama=1
			turno = Consumir;
			// comprobamos si hay algun mensaje pendiente con etiquta 5 y si no hay esperamos hasta que haya
			MPI_Probe(MPI_ANY_SOURCE,5,MPI_COMM_WORLD,&status);
		}
			
		else{
			// aqui no determinista comprobamos si hay mensaje pendiente de todos procesos
		    MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);    //se bloquea
		    if(status.MPI_SOURCE >=0 && status.MPI_SOURCE<=4)
				turno = Producir;
		    else
		    	turno = Consumir;
		}
		//rama
		if(turno == Producir){    
			MPI_Recv(&value[pos], 1, MPI_INT, status.MPI_SOURCE, 10, MPI_COMM_WORLD, &status);
			cout << "Buffer recibe " << value[pos] << " de Productor\n" << flush;
			++pos;
		}
		else{
			MPI_Recv(&peticion, 1, MPI_INT, status.MPI_SOURCE, 5, MPI_COMM_WORLD, &status);
			MPI_Ssend(&value[pos-1], 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
		    cout << "Buffer envia " << value[pos-1] << " a Consumidor\n" << flush;
		    ++enviados;
			--pos;
		}		
	}
}

int main(int argc, char* argv[]){
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank>=0 && rank<=4 )  // procesos productores de 0 a 4
		Productor_(rank);
	else if(rank>=6 && rank<=9 ) // procesos consumidores de 6 a 9
		Consumidor_(rank);
	else
		Buffer_();  // proceso 5
	MPI_Finalize();
	return 0;
}