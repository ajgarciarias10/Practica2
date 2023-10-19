//
// Created by ajgar on 20/10/2023.
//

#include "VuelaFlight.h"

/**
 * @brief Constructor parametrizado
 * @param vector
 * @param ruta
 */
VuelaFlight::VuelaFlight(VDinamico<Aeropuerto> vector, ListaEnlazada<Ruta> ruta):aeropuertos(vector),rutas(ruta) {}
/**
 * @brief BuscarRutasOrigenDestino
 * @param idAerOrig
 * @param idAerDest
 * @return
 */
Ruta &VuelaFlight::buscarRutasOriDeS(string idAerOrig, string idAerDest) {
    //ListaEnlazada<Ruta>::Iterador it ;
    VDinamico<Aeropuerto> aeroport;
}