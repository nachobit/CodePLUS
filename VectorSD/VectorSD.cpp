#include "VectorSD.h"
#include <cassert>
#include <iostream>

VectorSD::VectorSD(int reserva) {
    assert(reserva > 0);
    reservado = reserva;
    util = 0;
    info = new double[reserva];
}

void VectorSD::anadirElemento(double valor) {

    if(util < reservado) {

        // asignar nuevo valor
        info[util] = valor;

    } else {
        // reservar memoria
        double * nuevoInfo = new double[reservado * 2];

        // copiar valores anteriores
        for(int i=0; i<reservado; i++)
            nuevoInfo[i] = info[i];

        // liberar memoria antigua
        delete [] info;

        // reasignar puntero info
        info = nuevoInfo;

        // actualizar contador de elementos reservados
        reservado = reservado * 2;

        // asignar nuevo valor
        info[util] = valor;
    }

    util++;
}

VectorSD VectorSD::copiar() {
    VectorSD copia{util};
    for(int i=0; i<util; i++) {
        copia.info[i] = info[i];
        copia.util++;
    }
    return copia;
}

VectorSD * VectorSD::copiarPtr() {
    VectorSD *copia = new VectorSD(util);
    for(int i=0; i<util; i++) {
        copia->info[i] = info[i];
        copia->util++;
    }
    return copia;
}

VectorSD & VectorSD::copiarRef() {
    // ¡Esta mezcla de 'new' y referencias no es una buena práctica de programación!
    // Se muestra aquí como ejemplo de cómo devolver una referencia a un objeto creado en una función
    VectorSD * copia = new VectorSD(util);
    for(int i=0; i<util; i++) {
        copia->info[i] = info[i];
        copia->util++;
    }
    return (*copia);
}

void VectorSD::liberar() {
    util = 0;
    reservado = 0;
    delete [] info;
    info = 0;
}


double VectorSD::obtenerElemento(int pos) {
    return info[pos];
}

int VectorSD::obtenerUtiles() {
    return util;
}

void VectorSD::imprimir() {
    for(int i=0; i<util; i++)
        std::cout << info[i] << " ";
    std::cout << "[" << util << "/" << reservado << "]" << std::endl;
}



