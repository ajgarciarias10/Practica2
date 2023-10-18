//
// Created by ajgar on 18/10/2023.
//
#include "stdexcept"
#ifndef PRACTICA2_LISTAENLAZADA_H
#define PRACTICA2_LISTAENLAZADA_H

template<class T>
class ListaEnlazada {
     /**
      * Utilizaremos nodos enlazados para utilizar Listas Enlazadas
      * @tparam N
      */
     template<class N>
     class Nodo{
     public:
         N dato;
         Nodo *sig;
        //Constructor parametrizado
        Nodo(N &aDato, Nodo *aSig= nullptr):
            dato(aDato),sig(aSig){}
        //Destructor
        ~Nodo(){}
     };
      //Declaramos dos nodos punteros que son importantisimo
      Nodo<T> *cabecera,*cola;
      //Y necesitamos el tamaño de la lista
      unsigned  tama;
public:
     /**
      * @brief Declaramos la clase Iterador que la vamos a utilizar para movernos por las listas Enlazadas
      * @tparam I
      */
      class Iterador{
          //Donde apuntara cada nodo
          Nodo<T> *nodo;
      public:
          //Constructor parametrizado
          Iterador(Nodo<T> *anodo): nodo(anodo){}
          bool fin(){ return nodo == nullptr;}
          //Accedemos al siguiente nodo
          void siguiente(){
              nodo = nodo->sig;
          }
          //Devolvemos el dato al que apunta el nodo
          T &dato(){ return  nodo->dato;}
          //Accedemos a la direccion de memoria del nodo
          T &operator*(){ return  nodo->dato;}


      };
      //Creamos los metodos públicos de la clase ListaEnlazada

      //Constructor por defecto
      ListaEnlazada<T>();
      //Constructor copia
      ListaEnlazada<T>(const ListaEnlazada &orig);
      //Operator =
      ListaEnlazada<T> &operator = (const ListaEnlazada<T> &orig);
      //Devuelve el incio
      /**
       * @brief Metodo que devuelve puntero inicial
       * @return
       */
      T& incio(){
        if(cabecera)
            //Devolvemos el inciio
            return cabecera->dato;
        //Si no devolvemos que no hay inicii
          throw  std::invalid_argument("No hay elemento inicial");
      }
      /**
       * @brief Metodo que devuelve el puntero final
       * @return
       */
      T& fin(){
          if(cola)
              return cola->dato;
          //Si no devolvemos que no hay inicii
          throw  std::invalid_argument("No hay elemento final");

      }
      //Objeto iterador para iterar sobre las listas
      Iterador iterador() const;
      //Insertando por el inicio
      void insertaInicio(T& dato);
      //Insertando por el final
      void insertaFin(T& dato);
};

    /**
     * @brief Constructor por defecto
     * @tparam T
     */
    template <class T>
    ListaEnlazada<T>::ListaEnlazada() : cabecera(0),cola(0),tama(0){}
    /**
     * @brief Constructor copia
     * @tparam T
     * @param orig
     */
    template <class T>
    ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T> &orig) {
        //Puntero que lo utilizaremos para movernos por la lista
        Nodo<T>  *nuevoPunt = new Nodo<T>(nuevoPunt->dato,0);
        //Si la lista está vacia
        if(!orig.cabecera){
            cabecera = nuevoPunt;
        }
       //Mientras podamos recorrer la lista
        while(nuevoPunt){
            //Si hay algo  en la cola asignamos a lo que apunta la cola el nuevo puntero
            if(cola)
                cola->sig  = nuevoPunt;
            cola = nuevoPunt;
            //Vamos recorriendo hasta que el puntero sea nulo
            nuevoPunt = nuevoPunt->sig;
        }
    }
    /**
     * @brief Metodo operator = asigna a lista enlazada
     * @tparam T
     * @param origen
     * @return
     */
    template<class T>
    ListaEnlazada<T> &ListaEnlazada<T>::operator = (const ListaEnlazada<T> &origen){
        //Comprobamos que no sea la misma lista
        if(this!=origen){
            //Si entra hay cabecera si no eestaria vacia
            if(cabecera){
                //Creamos un nodo que sea igual a la cabecera
                Nodo<T> *nodoAux = cabecera;
                while(nodoAux){
                    //Apuntamos la cabecera al siguiente
                    cabecera = cabecera->sig;
                    //Esto es ya que lo que vamos a estar es cortando y pegando al nuevo puntero
                    //Es la cabecera que la vamos cortando y pegando puesto que no esta vacia
                    delete nodoAux;
                    //Le asignamos la nueva cabecera y asi hasta que sea null
                    nodoAux = cabecera;
                }
            }
            cola = nullptr;

        }
        //Actualizamos la cabecera
        cabecera = new Nodo<T>(origen.cabecera->dato, nullptr);
        //Sobreescribimos en la nueva lista la lista de origen
        Nodo<T> *p = new Nodo<T>(p->dato, nullptr);
        //Mientras podamos recorrer la lista
        while(p){
            //Si hay algo  en la cola asignamos a lo que apunta la cola el nuevo puntero
            if(cola)
                cola->sig  = p;
            cola = p;
            //Vamos recorriendo hasta que el puntero sea nulo
            p = p->sig;
        }
        return *this;
    }
    /**
     * @brief Un objeto iterador para iterar sobre la lista: ListaEnlazada<T>::Iterador iterador()
     * @tparam T
     * @return
     */
    template <class T>
    ListaEnlazada<T>::Iterador ListaEnlazada<T>::iterador() const {
        return  Iterador(cabecera);
    }
    /**
     * @brief Metodo que inserta un nodo por el principio de la lista
     * @tparam T
     * @param dato
     */
    template <class T>
    void ListaEnlazada<T>::insertaInicio(T &dato) {
        Nodo <T> *nuevoP =new Nodo<T>(dato,cabecera);
        if(cola)
            cola = nuevoP;
        cabecera = nuevoP;
        //Aumentamos el tamaño de la lista
        ++tama;
    }
    /**
     * @Metodo que inserta por el final
     * @tparam T
     * @param dato
     */
    template <class T>
    void  ListaEnlazada<T>::insertaFin(T &dato) {
        Nodo <T> *nuevoP =new Nodo<T>(dato,0);
        if(cola)
            cola->sig = nuevoP;
        //Si la lista esta vacia
        if(!cabecera)
            cabecera = nuevoP;
        cola = nuevoP;
    }

#endif //PRACTICA2_LISTAENLAZADA_H
