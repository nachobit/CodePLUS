#include <cstring>
#include <string>
#include "BigInt.h"

using namespace std;

//Constructor sin parametros (crea un entero largo de valor 0)
BigInt::BigInt(){
  ndigitos=1;
  arrayDigitos=new TDigito[1];
  arrayDigitos[0]=0;
}

//Destructor
BigInt::~BigInt(){
  delete[] arrayDigitos;
}

//Constructor crear BigInt a partir de una cadena de caracteres
BigInt::BigInt(const char cadena[]){
  ndigitos=strlen(cadena);
  if(ndigitos>0){
    arrayDigitos=new TDigito[ndigitos];
    for(int i=0;i<ndigitos;i++){
      arrayDigitos[i]=cadena[ndigitos-i-1]-'0';
    }
  }
  else{
    ndigitos=1;
    arrayDigitos=new TDigito[1];
    arrayDigitos[0]=0;
  }
}

////Constructor crear BigInt a partir de un unsigned int
BigInt::BigInt(unsigned int entero){
  int enteroaux=entero;
  ndigitos=1;
  while(enteroaux>9){ //Calculamos número de digitos
    enteroaux/=10;
    ndigitos++;
  }
  arrayDigitos=new TDigito[ndigitos];
  for(int i=0;i<ndigitos;i++){
    arrayDigitos[i]=entero%10;
    entero/=10;
  }
}

//Constructor de copia
BigInt::BigInt(const BigInt& enterolargo){
  copia(enterolargo);
}

//Operador de asignación
BigInt& BigInt::operator=(const BigInt& enterolargo)
{
    if (this != &enterolargo){
        delete[] this->arrayDigitos;
        copia(enterolargo);
    }
    return *this;
}

void BigInt::copia(const BigInt& enterolargo){
  ndigitos=enterolargo.ndigitos;
  arrayDigitos=new TDigito[ndigitos];
  for(int i=0;i<ndigitos;i++){
    arrayDigitos[i]=enterolargo.arrayDigitos[i];
  }
}

//Sobrecarga del operador suma + (a partir de 2 BigInt)
BigInt BigInt::operator+(const BigInt& otro) const{
  int acarreo=0; // tiene el acarreo de la suma de dígitos anterior
  const BigInt *pmayor,*pmenor; // punteros a los enteros con más dígitos y con menos dígitos
  pmayor=ndigitos>otro.ndigitos?this:&otro;
  pmenor=ndigitos>otro.ndigitos?&otro:this;
  BigInt resultado(*pmayor); // resultado se copia del nº con más dígitos
  
  int i;
  for(i=0;i<pmenor->ndigitos;i++){ // Sumamos dígitos del menor a resultado
    resultado.arrayDigitos[i]+=(pmenor->arrayDigitos)[i]+acarreo;
    if(resultado.arrayDigitos[i]>9){
      resultado.arrayDigitos[i]-=10;
      acarreo=1;
    }
    else
      acarreo=0;
  }
  /*
   * Si hubo acarreo en la última suma de dígitos es necesario seguir sumando
   */
  while(acarreo && i<resultado.ndigitos){
    resultado.arrayDigitos[i]+=acarreo;
    if(resultado.arrayDigitos[i]>9){
      resultado.arrayDigitos[i]-=10;
      acarreo=1;
    }
    else
      acarreo=0;
    i++;
  }
  
  /*
   * Si hubo acarreo en la última suma de dígitos debemos añadir un dígito más
   */
  if(acarreo){  
    TDigito *arrayaux=new TDigito[ndigitos+1];
    for(int i=0;i<resultado.ndigitos;i++){
      arrayaux[i]=resultado.arrayDigitos[i];
    }
    arrayaux[ndigitos]=1;
    delete[] resultado.arrayDigitos;
    resultado.arrayDigitos=arrayaux;
    resultado.ndigitos++;
  }
  return resultado;   
}

//Sobrecarga del operador << (para escribir el entero largo en un flujo de salida)
std::ostream& operator<<(std::ostream &flujo,const BigInt &enterolargo){
  for(int i=0;i<enterolargo.ndigitos;i++){
    flujo<<enterolargo.arrayDigitos[enterolargo.ndigitos-i-1];
  }
  return flujo;
}

//Sobrecarga del operador >> (para leer el entero largo desde un flujo de entrada)
std::istream& operator>>(std::istream &flujo,BigInt &enterolargo){
  string cadena;

  flujo>>cadena; 
  BigInt enterolargoaux(cadena.c_str());
  enterolargo=enterolargoaux;
    
  return flujo;
}

/*
 * Otra versión de operator>> que evita algún problema de la anterior versión.
 * Por ejemplo, podría leer del flujo cadenas que no representasen un entero largo
 * 
 */

std::istream& operator>>(std::istream &flujo,BigInt &enterolargo){
  string cadena;
  char caracter;
  ios::fmtflags banderas=flujo.flags();
  
  flujo>>skipws>>caracter; // Leemos primer dígito saltando blancos anteriores
  while(!flujo.eof() && isdigit(caracter)){ // leemos dígitos y los almacenamos en un string
    if(isdigit(caracter))
      cadena=cadena+caracter;
    flujo>>noskipws>>caracter;
  }
  if(!flujo.eof()){//Si se salió del bucle por encontrar un caracter que no es dígito
    flujo.unget(); //devolvemos ese carácter al flujo
  }
  
  // Si hemos llegado al final del flujo, pero se ha leido algún dígito, limpiamos banderas del flujo, para indicar
  // que la última lectura de un entero largo tuvo éxito
  if(cadena.length()>0 && flujo.eof()){ 
    flujo.clear();
  }
  
  BigInt enterolargoaux(cadena.c_str());
  enterolargo=enterolargoaux;
  
  flujo.flags(banderas);
    
  return flujo;
}