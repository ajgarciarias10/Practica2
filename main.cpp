#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "time.h"
#include "string"
using  namespace std;

int main(int argc, const char * argv[]) {
    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    clock_t t_total = clock();
    float latitud, longitud;
    string id = "";
    string iata = "";
    string ident="";
    string tipo="";
    string nombre="";
    string latitud_str="";
    string longitud_str="";
    string continente="";
    string iso_pais="";
    while ( getline(is, fila ) ) {
        //¿Se ha leído una nueva fila?
        if (fila!="") {
            columnas.str(fila);
            //formato de fila: id;ident;tipo;nombre;latitud;longitud;continente;iso_pais
            getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
            getline(columnas, ident, ';');
            getline(columnas, tipo, ';');
            getline(columnas, nombre, ';');
            getline(columnas, latitud_str, ';');
            getline(columnas, longitud_str, ';');
            getline(columnas, continente, ';');
            getline(columnas, iso_pais, ';');
            //  Transformamos la latitud y longitud a float
            latitud = std::stof(latitud_str);
            longitud = std::stof(longitud_str);
            fila = "";
            columnas.clear();
        }




    is.open("../aeropuertos_v2.csv"); //carpeta de proyecto
    return 0;
}
