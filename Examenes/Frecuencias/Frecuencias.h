#ifndef __FRECUENCIAS_H
#define __FRECUENCIAS_H

#include <iostream>

struct Pareja{
  int dato;
  int nVeces;
};

class Frecuencias{
  Pareja *parejas; // "npares" datos de tipo "Pareja" ordenados por "dato". 0 si no hay parejas.
  int npares;
  void destruir();
  void crear(int nElementos);
  int buscar(int entero);
public:
  Frecuencias();
  ~Frecuencias();
  Frecuencias(const Frecuencias& otro);
  Frecuencias& operator=(const Frecuencias& otro);
  Frecuencias& operator+=(int entero);
  friend std::ostream& operator<<(std::ostream& flujo, const Frecuencias& frec);
  void add(int entero);
  int repeticiones(int entero);
};

#endif