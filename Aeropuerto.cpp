//
// Created by ajgar on 26/09/2023.
//

#include "Aeropuerto.h"
/**
 * @brief Constructor por defecto
 */
Aeropuerto::Aeropuerto() : id(""), iata(""), tipo(""), nombre(""), continente(""),
                           iso_pais(""),posicion(UTM()) {
}

/**
 * @brief   Metodo Constructor de copia
 * @param origen
 */
Aeropuerto::Aeropuerto(const Aeropuerto &origen):id(origen.id),iata(origen.iata),tipo(origen.tipo),nombre(origen.nombre),continente(origen.continente),iso_pais(origen.iso_pais),posicion(origen.posicion) {}
/**
 * @brief Constructor parametrizado
 * @param id
 * @param tipo
 * @param nombre
 * @param continente
 * @param iso_pais
 * @param posicion
 */
Aeropuerto::Aeropuerto(const string &id,const string &iata, const string &tipo, const string &nombre,
                       const string &continente, const string &iso_pais, UTM posicion) : id(id),iata(iata),tipo(tipo),nombre(nombre),continente(continente),iso_pais(iso_pais),posicion(posicion) {

}
bool Aeropuerto::operator==(const Aeropuerto &origen) {
        return  this->iata == origen.iata;
}
/**
 * @brief Metodo Operator =
 * @param origen
 * @return
  */
Aeropuerto &Aeropuerto::operator =(const Aeropuerto &origen){
    //Comprobamos que no sea la misma direccion de memoria
    if(this!= &origen){

        //Asignamos a cada operando  su valor
        id= origen.id;
        iata = origen.iata;
        tipo = origen.tipo;
        nombre = origen.nombre;
        continente = origen.continente;
        iso_pais = origen.iso_pais;
        posicion = origen.posicion;
    }
    //Devolvemos el aeropuerto
    return  *this;

}

/**
 * @brief Metodo operator < para comparar ids
 * @param origen
 * @return
 */
bool Aeropuerto::operator<(const Aeropuerto &origen) const {
    return  iata < origen.iata;

}
/**
 * @brief Get ID
 * @return
 */
const string &Aeropuerto::getId() const {
    return id;
}

/**
 * @brief Get  Nombre
 * @return
 */
const string &Aeropuerto::getNombre() const {
    return nombre;
}

/**
 * @brief Get  Contiente
 * @return
 */
const string &Aeropuerto::getContinente() const {
    return continente;
}
/**
 * @brief Set Id
 * @return
 */
void Aeropuerto::setId(const string &id) {
    Aeropuerto::id = id;
}

const string &Aeropuerto::getIata() const {
    return iata;
}

const string &Aeropuerto::getIsoPais() const {
    return iso_pais;
}

void Aeropuerto::setIata(const string &iata) {
    Aeropuerto::iata = iata;
}




