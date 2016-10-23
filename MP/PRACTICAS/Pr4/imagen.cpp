#include "pgm.h"
#include "imagen.h"
#include "byte.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


/// Construye una imagen vacia (0 filas, 0 columnas)
Imagen::Imagen(){
  nfilas=0;
  ncolumnas=0;
}


/**
@brief Construye una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen
Construye una imagen de tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
Imagen::Imagen(int filas, int columnas){
  nfilas=filas;
  ncolumnas=columnas;
  for(int i=0; i<(filas*columnas-1); i++){
    datos[i] = 0xFF;
  }
}


/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen
Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
void Imagen::crear(int filas, int columnas){
  Imagen(filas, columnas);
}


/**
@brief Devuelve el número de filas de las imagen
@return el número de filas de la imagen
*/
int Imagen::filas(){
  return nfilas;
}


/**
@brief Devuelve el número de columnas de las imagen
@return el número de columnas de la imagen
*/
int Imagen::columnas(){
  return ncolumnas;
}


/**
@brief Asigna el valor @a v a la posición (@a x,@a y) de la imagen
@param y 	fila de la imagen
@param x 	columna de la imagen
@param v 	valor a asignar
Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
void Imagen::set(int y, int x, byte v){
  int pos = y*ncolumnas + x;
  datos[pos] = v;
}


/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y	 fila de la imagen
@param x	 columna de la imagen
@return el valor de la posición (@a x,@a y) de la imagen
Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
byte Imagen::get(int y, int x){
  int pos = y*ncolumnas + x;
  return datos[pos];
}


/**
@brief Asigna el valor @a v a la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
@param v 	valor a asignar
Asigna el valor @a v a la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
void Imagen::setPos(int i, byte v){
  datos[i] = v;
}


/**
@brief Devuelve el valor de la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
Devuelve el valor de la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
byte Imagen::getPos(int i){
  return datos[i];
}


/**
@brief Carga una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la lectura
@retval false 	si se ha producido algún error en la lectura
Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXPIXELS).
*/
bool Imagen::leerImagen(const char nombreFichero[]){
  int fils, cols;
  bool res = false;
  TipoImagen tipo = infoPGM(nombreFichero, fils, cols);
  if(tipo == IMG_PGM_BINARIO){
    if(fils*cols <= MAXPIXELS)
      res = leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
  }
  else if (tipo == IMG_PGM_TEXTO){
    if(fils*cols <= MAXPIXELS){
      res = leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
  }
  }
  else
    res = false;
  return res;
}


/**
@brief Guarda una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@param esBinario toma el valor @c true si el fichero se escribe en formato binario o @c false en caso contrario.
@retval true 	si ha tenido éxito en la escritura
@retval false 	si se ha producido algún error en la escritura
*/
bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
  //return escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
  if(esBinario)
    return escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
  else
    return escribirPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
}



//extraer plano k
Imagen Imagen::plano(int k){
  Imagen plano (nfilas,ncolumnas);
  for (int i = 0; i < filas()*columnas(); ++i){
    if (getbit(getPos(i),k))
      plano.setPos(i,0x80);
    else
      plano.setPos(i,0);
  }
  return plano;
}



//convertir a arte ASCII
bool Imagen::aArteASCII(const char grises[], char aArteASCII[],int maxlong){
  int cardinal = strlen(grises);
  int contador_char=0;

  if (filas()*(columnas()+1) > maxlong)
    return false;

  for (int i = 0; i < filas(); i++){
    for (int j = 0; j < columnas(); j++){
      aArteASCII[contador_char]=grises[(get(i,j)*cardinal)/256];
      contador_char++;
    }
    aArteASCII[contador_char]='\n';
    contador_char++;
  }
  aArteASCII[contador_char] = '\0';
  return true;
}



void Imagen::insertarplano(Imagen info, int planoinfo, int planosalida){
  // for (int i = 0; i < filas()*columnas(); ++i)
  // {
  //   byte b = getPos(i);
  // }
}
