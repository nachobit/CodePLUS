#include <iostream>
using namespace std;

struct Celda{
  double dato;
  Celda *sig;
};

void imprimedeFinalaPrincipioLista(const Celda* lista){
  int contador=0;
  const Celda *aux;

  aux=lista;
  while(aux!=0){ // Contar número de elementos en la lista
    aux=aux->sig;
    contador++;
  }

  for(int i=0;i<contador;i++){ // Imprimir cada elemento
    aux=lista;
    for(int j=0;j<(contador-i-1);j++){ // Situarnos en posición i desde el final
      aux=aux->sig;
    }
    cout<<aux->dato<<endl;
  }
}

void imprime2deFinalaPrincipioLista(const Celda* lista){
  const Celda *temp, *temp2;
  
  if(lista){ // Si lista no estaba vacía
    temp=lista;
    while(temp->sig){ // Buscar último elemento
      temp=temp->sig;
    }
    
    while(temp!=lista){ // Mientras no lleguemos al primer nodo
      cout<<temp->dato<<endl;
      
      temp2=lista;
      while(temp2->sig != temp) // Buscar nodo anterior a temp
        temp2 = temp2->sig;
      temp=temp2;
    }
    
    cout<<temp->dato<<endl; // Imprimir primer nodo
  }
}

void insertaFinalLista(Celda* &lista, double numero){
  if(lista==0){ // Si la lista estaba vacía
    lista=new Celda;
    lista->dato=numero;
    lista->sig=0;
  }
  else{
    Celda *aux=lista;
    while(aux->sig!=0){ // Buscar puntero a último nodo
      aux=aux->sig;
    }
    aux->sig=new Celda;
    aux->sig->dato=numero;
    aux->sig->sig=0;
  }
}

void destruirLista(Celda* &lista){
  Celda* aux;
  while(lista){
    aux=lista;
    lista=lista->sig;
    delete aux;
  }
}

int main(){
  Celda *lista=0;
  
  insertaFinalLista(lista,3.0);
  insertaFinalLista(lista,5.0);  
  insertaFinalLista(lista,9.0);  
  
  cout<<"Los elementos de final a principio son:"<<endl;
  imprimedeFinalaPrincipioLista(lista);
  
  cout<<"Los elementos de final a principio son:"<<endl;
  imprime2deFinalaPrincipioLista(lista);
  
  destruirLista(lista);
}