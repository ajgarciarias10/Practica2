#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "time.h"
#include "string"
#include "Aeropuerto.h"
#include "VDinamico.h"
#include "VuelaFlight.h"

using  namespace std;

int main(int argc, const char * argv[]) {

    ifstream is;
    stringstream  columnas;
    string fila;
    clock_t t_total = clock();
#pragma region Uso de listas
    ListaEnlazada<int>::Iterador it;
    ListaEnlazada<int> listaEnlazada;

    for (int i = 101; i <= 200; ++i) {
        listaEnlazada.insertaFin(i);
    }

    for (int i = 98; i >= 1; --i) {
        listaEnlazada.insertaInicio(i);
    }

    it=listaEnlazada.iterador();
    while (it.dato()!=101){
        it.siguiente();
    }

    listaEnlazada.inserta(it,100);

    it=listaEnlazada.iterador();
    while (it.dato()!=98){
        it.siguiente();
    }

    listaEnlazada.insertaDetras(it,99);

    for (int i = 0; i <10 ; ++i) {
        listaEnlazada.borrarInicio();
    }
    for (int i = 0; i <10 ; ++i) {
        listaEnlazada.borrarFinal();
    }

    for (it=listaEnlazada.iterador();!it.fin();it.siguiente()) {
        if (listaEnlazada.iterador().dato()%10==0){
            listaEnlazada.borra(it);
        }
    }

    std::cout<<"Lista post procesos:"<<std::endl<<std::endl;
    for (it=listaEnlazada.iterador();!it.fin();it.siguiente()) {
        std::cout<<"El dato es: "<< it.dato()<<std::endl;
    }
    std::cout<<std::endl;
#pragma endregion
    //region Aeropuerto valores
        VuelaFlight vl;
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
    //endregion
    //region Valores Rutas
        string aerolinea = "";
        string  origen2 = "";
        string destino2 = "";
        Aeropuerto *origen = nullptr;
        Aeropuerto *destino = nullptr;
    //endregion
    //region Carga aeropuertos
    is.open("../aeropuertos_v2.csv"); //carpeta de proyecto
    if ( is.good() ) {
        while (getline(is, fila)) {
            //¿Se ha leído una nueva fila?
            if (fila != "") {
                columnas.str(fila);
                //formato de fila: id;ident;tipo;nombre;latitud;longitud;continente;iso_pais
                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, iata, ';');
                getline(columnas, tipo, ';');
                getline(columnas, nombre, ';');
                getline(columnas, latitud_str, ';');
                getline(columnas, longitud_str, ';');
                getline(columnas, continente, ';');
                getline(columnas, iso_pais, ';');
                //  Transformamos la latitud y longitud a float
                stof(latitud_str);
                stof(longitud_str);

                fila = "";
                columnas.clear();
                //Insertamos en el Vector Dinamico el Aeropuerto
                vl.añadeAeropuerto(new Aeropuerto(id,iata,tipo,nombre,continente,iso_pais,* new UTM(latitud,longitud)));


            }
        }
        //Tras leer ordenamos el vector por Codigo Iata
        vl.aeropuertos.ordenar();

    }

  //endregion
    //region Carga Ruta
    is.open("../rutas_v1.csv"); //carpeta de proyecto
    if ( is.good() ) {
        while (getline(is, fila)) {
            //¿Se ha leído una nueva fila?
            if (fila != "") {
                columnas.str(fila);
                //formato de fila: id;ident;tipo;nombre;latitud;longitud;continente;iso_pais
                getline(columnas, aerolinea, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, origen2, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, destino2, ';'); //leemos caracteres hasta encontrar y omitir ';'
                fila = "";
                columnas.clear();

                //Declaro un aeropuerto
                Aeropuerto aero;
                aero.setIata(origen2);
                //Compruebo la posicion dentro del vector dinamico en el que esta Tanto la ruta de origen con la de destino
                //Y así descubro el aeropuerto
                int posOrigen = vl.aeropuertos.busquedaBinaria(aero);
                aero.setIata(destino2);
                int posDest = vl.aeropuertos.busquedaBinaria(aero);
                if(posOrigen !=-1 && posDest !=-1){
                    //Añadimos las rutas
                    vl.addNuevaRuta(&vl.aeropuertos[posOrigen],&vl.aeropuertos[posDest],aerolinea);
                }

            }
        }

    }
    //endregion

    return 0;
}
