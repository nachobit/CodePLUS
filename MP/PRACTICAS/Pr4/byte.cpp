#include "byte.h"
#include "imagen.h"
#include "pgm.h"
#include <iostream>
using namespace std;

/**
@brief enciende el bit @p pos del @c byte @p b
@param b 	el @c byte cuyo bit se quiere activar
@param pos 	el bit dentro de @p b que se quiere activar (0 más a la derecha)
*/
void on(byte &b, int pos){
	byte mask;
	if((pos>=0) && (pos<8)){
		mask = 0x1 << pos;
		b = b | mask;
	}
}

/**
@brief apaga el bit @p pos del  @c byte @p b
@param b 	el @c byte cuyo bit se quiere desactivar
@param pos 	el bit dentro de @p b que se quiere desactivar (0 más a la derecha)
*/
void off(byte &b, int pos){
	byte mask;
	if((pos>=0) && (pos<8)){
		mask = 0x1 << pos;
		mask =~ mask;
		b = b & mask;
	}
}

/**
@brief devuelve el estado del bit (encendido = true, apagado = false) en la posición @p pos
@param b 	el @c byte que se quiere consultar
@param pos 	el bit dentro de @ b que se quiere consultar (0 más a la derecha)
@retval true 	si el bit en la posición @p pos está encendido
@retval false	si el bit en la posición @p pos está apagado
*/
bool getbit(byte b, int pos){
	byte mask;
	mask = 0x1 << pos;
	mask = b & mask;
	if(mask > 0)
		return true;
	else
		return false;
}


/**
@brief devuelve un string conteniendo una secuencia de '0's y '1's correspondiente  al estado de cada bit
@param b el @c byte que se quiere imprimir

Por ejemplo, si en el @c byte @c b están encendidos los bits en posiciones 1 y 3 (0 más a la derecha),
@c byteToString(b); devolverá el string @c "00001010"
*/
string byteToString(byte b){
	string res;
	bool aux;
	for(int i=7; i>=0; i--){
		aux = getbit(b, i);
		if(aux==true)
			res += "1";
		else
			res += "0";
	}
	return res;
}

/**
@brief enciende todos los bits
@param b el @c byte que se quiere encender completamente.
*/
void encender(byte &b){
	b = 0xFF;
}

/**
@brief apaga todos los bits
@param b el @c byte que se quiere apagar completamente.
*/
void apagar(byte &b){
	b = 0x0;
}

/**
@brief enciende los bits según la configuración de @p v
@param b el @c byte sobre el que se quiere actuar
@param v vector de 8 elementos que contiene la secuencia de bitS que se quieren asignar

Asigna a @p b la configuración de bits contenida en @p v. @p v es un vector de 8 booleanos
donde @c true significa encendido y @c false significa apagado.
*/
void asignar(byte &b, const bool v[]){
	int i, j;
	//Si i=0, j=7; si i=1, j=6...
	//El orden de los numeros en v[] va al reves que en el bloque bit
	for(i=0, j=7; i<7; i++, j--){
		if(v[i]==true)
			on(b, j);
		else
			off(b, j);
	}
}

/**
@brief recupera la configuración de todos los bit
@param b el @c byte que se quiere consultar
@param v vector de 8 elementos que contendrá el estado de cada uno de los bits de @ b

Vuelca en @p v la configuración de bits contenida en @p b. @c true significa encendido y @c false significa apagado. El tamaño de @p v debe ser 8.
*/
void volcar(byte b, bool v[]){
	for(int i=0; i<8; i++)
		v[i] = getbit(b, i);
}

/**
@brief devuelve las posiciones de los bits encendidos
@param b el @c byte que se quiere consultar
@param posic vector de enteros (valores entre 0 a 7) que indican la posición de los bits de @p b que están encendidos
@param cuantos número de bits encendidos en @p b (número de elementos usados en el vector @p posic)
*/
void encendidos(byte b, int posic[], int &cuantos){
	cuantos=0;
	for(int i=0; i<8; i++){
		if(getbit(b, i)){
			posic[cuantos] = i;
			cuantos++;
		}
	}
}
