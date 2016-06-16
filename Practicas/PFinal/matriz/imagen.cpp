#include "pgm.h"
#include "imagen.h"
#include "byte.h"
#include "lista.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;


/// Construye una imagen vacia (0 filas, 0 columnas)
Imagen::Imagen(){
    datos=0;
    nfilas=0;
    ncolumnas=0;
}


/**
@brief Construye una imagen negra de tamaño @a filas x @a columnas
@param filas número de filas de la imagen
@param columnas	número de columnas de la imagen
Construye una imagen de tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
Imagen::Imagen(int filas, int columnas){
    datos=0;
    crear(filas, columnas);
}


/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas número de filas de la imagen
@param columnas	número de columnas de la imagen
Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
void Imagen::crear(int filas, int columnas){
    if (datos!=0)
        destruir();

    nfilas=filas;
    ncolumnas=columnas;
    datos = new byte*[nfilas];
    datos[0] = new byte[nfilas*ncolumnas];
    for(int i=1; i<nfilas; i++)
        datos[i] = datos[i-1]+ncolumnas;
    for(int i=0; i<nfilas; i++){
        for(int j=0; j<ncolumnas; j++){
            datos[i][j] = 0;
        }
    }
}

//Constructor de copia
Imagen::Imagen(const Imagen & aux){
    nfilas=aux.nfilas;
    ncolumnas = aux.ncolumnas;
    datos = new byte*[nfilas];
    datos[0] = new byte[nfilas*ncolumnas];
    for(int i=1; i<nfilas; i++)
        datos[i] = datos[i-1]+ncolumnas;
    for(int i=0; i<nfilas; i++){
        for(int j=0; j<ncolumnas; j++)
            datos[i][j] = aux.datos[i][j];
    }
}

//Destructor
Imagen::~Imagen(){
  destruir();
}

/**
@brief Destruye el vector y libera la memoria reservada para el
*/
void Imagen::destruir(){
    nfilas=ncolumnas=0;
    if (datos!=0){
        delete [] datos[0];
        delete [] datos;
    }
    datos=0;
}

//Operador de asignacion
Imagen & Imagen::operator=(const Imagen & aux){
    if(this != &aux){
        nfilas = aux.nfilas;
        ncolumnas = aux.ncolumnas;
        crear(nfilas, ncolumnas);
        for(int i=0; i<nfilas; i++){
            for(int j=0; j<ncolumnas; j++)
                set(i,j, aux.get(i,j));
        }
    }
    return (*this);
}

//Operador de suma
Imagen Imagen::operator+(const Imagen& aux){
  int c = ncolumnas + aux.ncolumnas;
  int f;
  if(nfilas > aux.nfilas)
    f=nfilas;
  else
    f=aux.nfilas;
  Imagen salida(f,c);
  int finalprimera = ncolumnas-1;

  for (int i = 0; i < nfilas; i++) {
    for (int j = 0; j < ncolumnas; j++) {
      byte izda = get(i,j);
      salida.set(i,j,izda);
    }
  }

  for (int i = 0; i < aux.nfilas; i++) {
    for (int j = 0; j < aux.ncolumnas; j++) {
      byte dere = aux.get(i,j);
      salida.set(i,finalprimera+j,dere);
    }
  }

  int inifilas=f;
  int inicol;
  int fincol;
  if (nfilas>aux.nfilas){
    inicol=ncolumnas;
    fincol=c;
  }
  else{
    inicol=0;
    fincol=ncolumnas;
  }
  for(int i=inifilas; i<f; i++){
    for(int j=inicol; j<fincol; j++){
      salida.set(i,j,0);
    }
  }
  return salida;
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
@param y fila de la imagen
@param x columna de la imagen
@param v valor a asignar
Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
void Imagen::set(int y, int x, byte v){
    if(y<=nfilas && x<=ncolumnas)
        datos[y][x] = v;
}


/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y fila de la imagen
@param x columna de la imagen
@return el valor de la posición (@a x,@a y) de la imagen
Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
byte Imagen::get(int y, int x) const{
    return datos[y][x];
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
  if((i< nfilas*ncolumnas) && (i>=0))
    datos[0][i] = v;
}


/**
@brief Devuelve el valor de la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
Devuelve el valor de la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
byte Imagen::getPos(int i) const{
    return datos[0][i];
}


/**
@brief Carga una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@retval true si ha tenido éxito en la lectura
@retval false si se ha producido algún error en la lectura
Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXPIXELS).
*/
bool Imagen::leerImagen(const char nombreFichero[]){
    int fils, cols;
    bool res = false;
    TipoImagen tipo = infoPGM(nombreFichero, fils, cols);
    if(tipo == IMG_PGM_BINARIO){
        crear(fils, cols);
        if(fils*cols <= nfilas*ncolumnas)
          res = leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
    }
    else if(tipo == IMG_PGM_TEXTO){
        crear(fils,cols);
        if(fils*cols <= nfilas*ncolumnas)
              res = leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
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


bool Imagen::listaAArteASCII(const Lista &celdas){
    string nombre;
    //creamos ficheros con cadenas de caracteres
    for(int i=0; i<celdas.longitud(); i++){
        nombre = "ascii" + to_string(i+1) + ".txt";
        const int tama = nfilas*(ncolumnas+1)+1;     //+1 para el \0
        char *final = new char[tama];

        if(aArteASCII(celdas.getCelda(i).c_str(), final, tama)){
            ofstream fsalida;
            fsalida.open(nombre);
            cout << "Exito convirtiendo la imagen a aArteASCII " << i+1 << "." << endl;
            fsalida << final;
            delete [] final;
            fsalida.close();
        }
        else{
            cout << "Error convirtiendo la imagen con ASCII " << i+1 << "..." << endl;
        }
    }
    return true;
}
