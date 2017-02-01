#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}


//e1
template <class T>
set<int> diferencia (const set<T> &c1, const set<T> c2){
  set<T> solucion;
  typename set<T>::const_iterator p;

  //Recorrer conjunto1 y ver si el elemento está en conjunto2
  for(p = c1.begin(); p != c1.end(); ++p){
    if(c2.count(*p)==0){
      solucion.insert(*p);
    }
  }
  return solucion;
}



template <class T>
set<T> interseccion(const set<T> & c1, const set<T> & c2, const set<T> & c3){
  set<T> solucion;
  
  typename set<T>::const_iterator p;

  //Recorrer conjunto1 y ver si el elemento está en conjunto2 y 3
  for(p = c1.begin(); p != c1.end(); ++p){
    if(c2.count(*p) != 0 && c3.count(*p) != 0){
      solucion.insert(*p);
    }
  }
  return solucion;
}


template <class T>
set<T> diferencia2(const set<T> & c1, const set<T> & c2, const set<T> & c3){
  set<T> solucion;

  solucion = interseccion(c1,c2,c3);
  typename set<T>::const_iterator p;

  //Recorrer conjunto1 y ver si el elemento está en conjunto2
  for(p = c1.begin(); p != c1.end(); ++p){
    if(c2.count(*p)==0 && c3.count(*p)==0){
      solucion.insert(*p);
    }
  }
  for(p = c2.begin(); p != c2.end(); ++p){
    if(c1.count(*p)==0 && c3.count(*p)==0){
      solucion.insert(*p);
    }
  }
  for(p = c3.begin(); p != c3.end(); ++p){
    if(c1.count(*p)==0 && c2.count(*p)==0){
      solucion.insert(*p);
    }
  }

  return solucion;
}



int main(){

  set<int> c1, c2, c3;  //new
  set<int> ejercicio1,ejercicio2;
  //set<int>::iterator p,q;

  set<int> c;

  //añadir elementos
  c1.insert(1);
  c1.insert(2);
  c1.insert(3);
  c1.insert(4);
  c1.insert(5);

  c2.insert(2);
  c2.insert(4);
  c2.insert(7);
  c2.insert(9);

  c3.insert(2);
  c3.insert(3);
  c3.insert(7);
  c3.insert(10);
  //set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.end()));
  

  /*
  //ejercicio1

    for(p = c1.begin(); p!=c1.end(); ++p){
    q=find(c2.begin(),c2.end(),*p);
    if(q==c2.end())
      c.insert(*q)
  }

  //ejercicio2 PRUEBAS
  //c: conjunto solución

  //intereseccion c1 y c2

  for(p=c1.begin(); p!=c1.end(); ++p)
    if(c2.count(*p))
      c.insert(*p);
  
  //intereseccion c3 y c
  for(p=c3.begin(); p!=c3.end(); ++p)
    if(c.count(*p))
      c.insert(*p);
  */

  InicializarSemilla();



  cout << "La solución 1 es: " ;

  ejercicio1 = diferencia(c1,c2);
  cout << ejercicio1 << endl;

 
  cout << "La solución 2 es: ";
  ejercicio2 = diferencia2(c1,c2,c3); 
  cout << ejercicio2 <<endl;




}  
  