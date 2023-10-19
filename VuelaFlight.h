//
// Created by ajgar on 20/10/2023.
//

#ifndef PRACTICA2_VUELAFLIGHT_H
#define PRACTICA2_VUELAFLIGHT_H
#include "VDinamico.h"
#include "Aeropuerto.h"
#include "Ruta.h"
#include "ListaEnlazada.h"
class VuelaFlight {
//Declaramos los metodos privados
private:
    VDinamico<Aeropuerto> aeropuertos;
    ListaEnlazada<Ruta> rutas;
//Declaramos los metodo publicos y constructores
public:
    //Constructor copia
    VuelaFlight(const VuelaFlight &vl);
    //Constructor parametrizado
    VuelaFlight(VDinamico<Aeropuerto> aeropuerto, ListaEnlazada<Ruta> ruta );
    //Destructor VuelaFlight
    ~VuelaFlight();
    //Metodos que tenemos que utilizar en esta practica
    //BuscarRutaDeOrigenDestino
    Ruta& buscarRutasOriDeS(string idAerOrig,string idAerDest);
    //BuscarRutasDeOrigen
    ListaEnlazada<Ruta*> buscarRutasOrigen (string idAerOrig);
    //Buscar AeropuertoPais
    VDinamico<Aeropuerto*> buscarAeropuertoPais(string pais);
    //AñadirNuevaRuta
    void addNuevaRuta(string idAerOrig, string idAerDest, string aerolinea);

};


#endif //PRACTICA2_VUELAFLIGHT_H
