#include "Frecuencias.h"

Frecuencias::Frecuencias(){
  parejas=0;
  npares=0;
}

Frecuencias::~Frecuencias(){
  destruir();
}

void Frecuencias::destruir(){
  if(parejas)
    delete[] parejas;
}

void Frecuencias::crear(int nElementos){
  if(nElementos>0){
    parejas=new Pareja[nElementos];
    npares=nElementos;
  }
  else{
    parejas=0;
    npares=0;
  }
}

Frecuencias::Frecuencias(const Frecuencias& otro){
  crear(otro.npares);
  for(int i=0;i<npares;i++){
    parejas[i]=otro.parejas[i];
  }
}

Frecuencias& Frecuencias::operator=(const Frecuencias& otro){
  if(this!=&otro){
    destruir();
    crear(otro.npares);
    for(int i=0;i<npares;i++){
      parejas[i]=otro.parejas[i];
    } 
  }
  return *this;
}

void Frecuencias::add(int entero){
  int donde=0;
  while(donde<npares && parejas[donde].dato<entero){
    donde++;
  }
  // Lo anterior podría sustituirse por la siguiente línea: 
  //donde=buscar(entero);
  
  std::cout<<"Insertando "<<entero<<" en posicion "<<donde<<std::endl;
  
  if(donde<npares && parejas[donde].dato==entero){ // Si ya estaba incluido en el array
    parejas[donde].nVeces++;
  }
  else{ // si no estaba incluido, insertar en posición donde
    Pareja *nuevoPares=new Pareja[npares+1];
    for(int i=0;i<donde;i++){
      nuevoPares[i]=parejas[i];
    }
    nuevoPares[donde].dato=entero;
    nuevoPares[donde].nVeces=1;
    for(int i=donde+1;i<npares+1;i++){
      nuevoPares[i]=parejas[i-1];
    }
    destruir();
    parejas=nuevoPares;
    npares++;
  }
}

Frecuencias& Frecuencias::operator+=(int entero){
  add(entero);
  
  return *this;
}

std::ostream& operator<<(std::ostream& flujo, const Frecuencias& frec){
  for(int i=0;i<frec.npares;i++){
    flujo<<frec.parejas[i].dato<<" "<<frec.parejas[i].nVeces<<std::endl;
  }
  return flujo;
}

int Frecuencias::buscar(int entero){
  int inf=0,sup=npares-1,medio;
  while(inf<=sup){
    medio=(inf+sup)/2;
    if(entero==parejas[medio].dato)
      return medio; // se encontró entero en posición medio
    else if(entero>parejas[medio].dato)
      inf=medio+1;
    else
      sup=medio-1;
  }
  return inf; // cuando no se encontró, se devuelve la posicion donde debería estar
}

int Frecuencias::repeticiones(int entero){
  int donde;
  
  donde=buscar(entero);
  if(donde<npares && parejas[donde].dato==entero){
    return parejas[donde].nVeces;
  }
  else
    return 0;
}

