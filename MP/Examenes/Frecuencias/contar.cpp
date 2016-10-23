#include <iostream>
#include <fstream>
#include "Frecuencias.h"

using namespace std;

/*void leeEnteros(Frecuencias &frecu,istream& flujo){
  int entero;
  while(flujo){
    flujo>>entero;
    if(flujo)
      frecu+=entero;
  }
}*/

void leeEnteros(Frecuencias &frecu,istream& flujo){
  int entero;
  while(flujo>>entero){
    frecu+=entero;
  }
}

int main(int argc, char* argv[]){
  Frecuencias frecu;
  if(argc==1){
    cout<<"Leyendo de cin"<<endl;
    leeEnteros(frecu,cin);
  }
  else{
    ifstream flujo;
    flujo.open(argv[1]);
    if(flujo)
      leeEnteros(frecu,flujo);
  }

  cout<<frecu;
}
