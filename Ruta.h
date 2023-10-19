//
// Created by ajgar on 19/10/2023.
//

#ifndef PRACTICA2_RUTA_H
#define PRACTICA2_RUTA_H
#include <string>
#include "Aeropuerto.h"
using namespace  std;

class Ruta {
private:
    string aerolinea;
    Aeropuerto *origen;
    Aeropuerto *destino;
public:
        //Constructor por defecto
        Ruta();
        //Constructor copia
        Ruta(const Ruta &orig);
        //Constructor parametrizado
        Ruta(const string &aerolinea,Aeropuerto *origer, Aeropuerto *dest);
        //Destructor
        ~Ruta();

    const string &getAerolinea() const;

    void setAerolinea(const string &aerolinea);

    Aeropuerto *getOrigen() const;

    void setOrigen(Aeropuerto *origen);

    Aeropuerto *getDestino() const;

    void setDestino(Aeropuerto *destino);
};


#endif //PRACTICA2_RUTA_H
