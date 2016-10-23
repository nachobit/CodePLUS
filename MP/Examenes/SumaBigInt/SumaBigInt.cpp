#include <cstdlib>
#include <iostream>
#include <fstream>

#include "BigInt.h"

using namespace std;

int main(int argc, char *argv[]){
  ifstream flujo;
  BigInt suma,enterolargo;
  
  if(argc<2){
    cerr<<"Error, faltan parámetros: programa ficheroconenteroslargos"<<endl;
    exit(1);
  }
  flujo.open(argv[1]);
  if(flujo){
    while(flujo>>enterolargo){
      suma=suma+enterolargo;
    }
    cout<<"Suma="<<suma<<endl;
  }
  else{
    cerr<<"No se pudo abrir el fichero "<<argv[1]<<endl;
  }
}
