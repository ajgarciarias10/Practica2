//
// Created by ajgar on 19/10/2023.
//

#include "Ruta.h"
/**
 * @brief Constructor por defecto
 */
Ruta::Ruta(): aerolinea(""),origen(nullptr),destino(nullptr) {}
/**
 * @brief Constructor copia
 * @param orig
 */
Ruta::Ruta(const Ruta &orig):aerolinea(orig.aerolinea),origen(orig.origen),destino(orig.destino){}
/**
 * @brief Constructor parametrizado
 * @param aerolinea
 * @param origer
 * @param dest
 */
Ruta::Ruta(const string &aerolinea, Aeropuerto *origen, Aeropuerto *destino): aerolinea(aerolinea),origen(origen),destino(destino) {}
const string &Ruta::getAerolinea() const {
    return aerolinea;
}

void Ruta::setAerolinea(const string &aerolinea) {
    Ruta::aerolinea = aerolinea;
}

Aeropuerto *Ruta::getOrigen() const {
    return origen;
}

void Ruta::setOrigen(Aeropuerto *origen) {
    Ruta::origen = origen;
}

Aeropuerto *Ruta::getDestino() const {
    return destino;
}

void Ruta::setDestino(Aeropuerto *destino) {
    Ruta::destino = destino;
}
