#include <iostream>
#include "Frecuencias.h"

using namespace std;

int main(int argc, char* argv[]){
  Frecuencias frecu;
  
  frecu.add(3);
  frecu.add(3);
  frecu.add(4);
  frecu+=4;
  frecu+=3;
  frecu+=2;
  frecu+=7;
  frecu+=9;
  
  cout<<frecu;
  cout<<"Repeticiones de "<< 1 << ": "<<frecu.repeticiones(1)<<endl;
  cout<<"Repeticiones de "<< 2 << ": "<<frecu.repeticiones(2)<<endl;
  cout<<"Repeticiones de "<< 3 << ": "<<frecu.repeticiones(3)<<endl;
  cout<<"Repeticiones de "<< 4 << ": "<<frecu.repeticiones(4)<<endl;
  cout<<"Repeticiones de "<< 5 << ": "<<frecu.repeticiones(5)<<endl;
  cout<<"Repeticiones de "<< 7 << ": "<<frecu.repeticiones(7)<<endl;
  cout<<"Repeticiones de "<< 9 << ": "<<frecu.repeticiones(9)<<endl;
}