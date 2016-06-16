#ifndef __BIGINT_H
#define __BIGINT_H

#include <iostream>

class BigInt{
  typedef int TDigito;
  int ndigitos;
  TDigito *arrayDigitos;
  void copia(const BigInt& enterolargo);

public:
  BigInt();
  ~BigInt();
  BigInt(const char cadena[]);
  BigInt(unsigned int entero);
  BigInt(const BigInt& enterolargo);
  BigInt& operator=(const BigInt& enterolargo);
  BigInt operator+(const BigInt& otro) const;
  
  friend std::ostream& operator<<(std::ostream &flujo,const BigInt &enterolargo);
  friend std::istream& operator>>(std::istream &flujo,BigInt &enterolargo);

};

#endif