//
// Created by ajgar on 18/10/2023.
//
#include "stdexcept"
#ifndef PRACTICA2_LISTAENLAZADA_H
#define PRACTICA2_LISTAENLAZADA_H
#include "iostream"
using namespace std;

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
        Nodo(const N &aDato, Nodo *aSig= nullptr):
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
      private:
          //Donde apuntara cada nodo
          Nodo<T> *nodo;
      public:
          //Constructor parametrizado
          Iterador(Nodo<T> *anodo= nullptr): nodo(anodo){}
          bool fin(){ return nodo == nullptr;}
          //Accedemos al siguiente nodo
          void siguiente(){
              nodo = nodo->sig;
          }
          //Devolvemos el dato al que apunta el nodo
          T &dato(){ return  nodo->dato;}
          //Accedemos a la direccion de memoria del nodo
          T &operator*(){ return  nodo->dato;}
          //Destructor de la clase Iterador
          ~Iterador(){};

          Nodo<T> *getNodo() const {
              return nodo;
          }
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
      Iterador iterador() ;
      //Insertando por el inicio
      void insertaInicio(const T& dato);
      //Insertando por el final
      void insertaFin(const T& dato);
      //Insertar por posicion
      void inserta(Iterador &i,const T &dato);
      //Insertar por detras
      void insertaDetras(Iterador &i,const T &dato);
      //Borrar por el inicio
      void borrarInicio();
      //Borrar por el final
      void borrarFinal();
      //Borrar por elemento
      void borra(Iterador &i);
      //Devolver el tamaño
      int tam();
      //operador +
      ListaEnlazada<T> operator+(const ListaEnlazada &lista);
      //Metodo concatena
      ListaEnlazada<T> &concatena(const ListaEnlazada<T> &l);
     //Destructor
     ~ListaEnlazada();
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
    ListaEnlazada<T> &ListaEnlazada<T>::operator=(const ListaEnlazada<T> &origen){
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
        cabecera = nullptr;
        cola= nullptr;
        Nodo<T> *p = origen.cabecera;
        tama = origen.tama;
        //Mientras podamos recorrer la lista
        while(p){
            //Sobreescribimos en la nueva lista la lista de origen
            Nodo<T> *p = new Nodo<T>(p->dato, nullptr);
            //Si hay algo  en la cola asignamos a lo que apunta la cola el nuevo puntero
            if(cola)
                cola->sig  = p;
            if(!cabecera)
                cabecera = p;
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
    template <typename T>
    typename ListaEnlazada<T>::Iterador ListaEnlazada<T>::iterador()  {
        return  Iterador(cabecera);
    }
    /**
     * @brief Metodo que inserta un nodo por el principio de la lista
     * @tparam T
     * @param dato
     */
    template <class T>
    void ListaEnlazada<T>::insertaInicio(const T &dato) {
        //Aumentamos el tamaño de la lista
        ++tama;
        Nodo <T> *nuevoP =new Nodo<T>(dato,cabecera);
        if(cola)
            cola = nuevoP;
        cabecera = nuevoP;
    }
    /**
     * @Metodo que inserta por el final
     * @tparam T
     * @param dato
     */
    template <class T>
    void  ListaEnlazada<T>::insertaFin(const T &dato) {
        ++tama;
        Nodo <T> *nuevoP = new Nodo<T>(dato,0);
        if(cola)
            cola->sig = nuevoP;
        //Si la lista esta vacia
        if(!cabecera)
            cabecera = nuevoP;
       // cola = nuevoP;

    }
    /**
     * @brief Metodo que inserta en una determinada posicion siempre delante que el anterior
     * @post Hacemos que en funcion de la posicion, inserte el nodo o por el inicio, o
     * @tparam T
     * @param i
     * @param dato
     */
    template <class  T>
    void ListaEnlazada<T>::inserta(Iterador &i, const T &dato) {
        //Si el iterador no ha llegado al final
        if(!i.fin()){
            ++tama;
            //Comprobamos antes de hacer cualquier cosa
            //Si  la posicion que queremos insertar el nodo es por el inciio
            if(i.getNodo() == cabecera){
                insertaInicio(dato);
                //Esto lo que hace es volver a inserta pero sin hacer esta funcion de nueva
                return;
            }
        }
        //Caso general
        Nodo <T> *anterior=0;
        if(cabecera != cola){
            anterior = cabecera;
            //Hasta que no encontremos esa posicion vamos recorriendo
            while(anterior->sig != i.getNodo()){
                //Seguimos moviendonos entre nodos
                anterior = anterior->sig;
            }
            //Si encontramos la posicion
            //Creamos un nodo nuevo
            Nodo<T> *nuevo = new Nodo<T>(dato,i.getNodo());
            //Le asignamos la posicion al anterior como siguiente el nuevo nodo que queriamos meter
            anterior->sig=nuevo;
        }

        if(cola == i.getNodo()){
            insertaFin(dato);
        }
    }
    /**
     * @brief Método Insertar por Detras
     * @post Cogemos el nodo iterado y hacemos que sea apuntado por un nuevo nodo que hemos creado
     * @tparam T
     * @param i
     * @param dato
     */
    template <class T>
    void ListaEnlazada<T>::insertaDetras(ListaEnlazada::Iterador &i, const T &dato) {
        //Si el iterador no ha llegado al final
        if(!i.fin()){
            ++tama;
          //Creamos un nodo nuevo con el dato,y que apunte al nodo que habia antes que el para si moverlo a la drecha
            Nodo<T> *nuevo = new Nodo<T>(dato,i.getNodo()->sig);
            //Asignamos al nuevo nodo la posicion siguiente del iterador
            i.getNodo()->sig = nuevo;
            //Si el nodo iterado esta en la posicion cola
            if(i.getNodo() == cola){
                //Cola apuntara a nuevo y nuevo apuntara al que esta en cola
                cola = nuevo;
            }
        }
    }
    /**
     * @brief Borrar por el inicio
     * @tparam T
     */
    template <class T>
    void ListaEnlazada<T>::borrarInicio() {
        Nodo<T> *borrado = cabecera;
        //Lo que hacemos es apuntar al siguiente para borrar el primer nodo
        cabecera = cabecera ->sig;
        //Borramos el inicial
        delete borrado;

        //En caso que el que hayamos borrado es el ultimo
        if(!cabecera)
            cola = nullptr;
    }
    /**
     * @brief Metodo que borra por el final
     * @tparam T
     */
    template <class T>
    void ListaEnlazada<T>::borrarFinal() {
        Nodo<T> *anterior = nullptr;
        if(cabecera != cola){
            anterior = cabecera;
            --tama;
            while(anterior->sig != cola)
                anterior = anterior ->sig;
            delete cola;

            cola = anterior;
            anterior->sig = nullptr;
        }
        //En caso de que haya solo 1 o ninguno
        else{
            if(cabecera){
                delete cabecera;
                tama = 0;
                cabecera = nullptr;
                cola = nullptr;
            }
        }
    }
/**
 * @brief Metodo borrar por posicion
 * @tparam T
 * @param i
 */
    template <class T>
    void ListaEnlazada<T>::borra(Iterador &i) {
        if(!i.fin()){
            tama--;
            //Si quiere borrar por el principio
            if(i.getNodo() == cabecera){
                borrarInicio();
                return;
            }
            //En caso de que no sea el principio aplicaremos el caso general
            Nodo<T> *anterior = 0;
            if(cabecera != cola){
                anterior = cabecera;
                //Recorremos hasta encontrar el nodo
                while(anterior->sig != i.getNodo()){
                    anterior = anterior ->sig;
                }
                //En caso de haber llegado
                //Hacemos que al borrar el nodo el anterior al que hemos borrado apunte al siguiente
                if(i.getNodo() != cola)
                    anterior -> sig =i.getNodo()->sig;
                    delete i.getNodo();
            }
            //Caso por el final se borra igual al aplicar lo anterior
            if(cola == i.getNodo()){
               borrarFinal();
            }
        }

    }
/**
 * @brief Metodo que devuelve el tmaaño de la lista
 * @tparam T
 * @return
 */
    template <class  T>
    int ListaEnlazada<T>::tam() {
        return tam();
    }
    /**
     * @brief Metodo operator +
     * @tparam T
     * @param lista
     * @return
     */
    template <class T>
    ListaEnlazada<T> ListaEnlazada<T>::operator+(const ListaEnlazada<T> &lista) {
        //Cogemos la actual lista enlazada
        ListaEnlazada<T> list(*this);
        //Creamos un puntero de tipo nodo que sera la cabecera
        Nodo<T> *puntero = lista.cabecera;
        //Mientras que el puntero no sea nulo
        while(puntero){
            Nodo<T> *newNodo = new Nodo(puntero->dato,0);
            //Caso 1 Si la lista esta vacía
            if(lista.cabecera == nullptr ){
                cabecera = newNodo;
            }
            //Caso 2 Si la cola no es nula
            //Concatenamos por el final
            if(lista.cola != 0){
                cola -> sig = newNodo;
            }
            //Caso 3 Si es en la cola
            lista.cola = newNodo;

            puntero = puntero ->sig;

        }
        tama = lista.tama+ tama;

        return lista;


    }
    /**
     * @brief Metodo para concatenar listas
     * @tparam T
     * @param l
     * @return
     */
    template<class T>
    ListaEnlazada<T> &ListaEnlazada<T>::concatena(const ListaEnlazada<T> &l) {
        //Caso 1 Lista que te dan esta vacia y la actual no lo esta
        if(l.tama==0 && this->tama != 0)
            return  l;
        //Caso 2 Lista que te dan no esta vacia y la actual esta
        if(l.tama==0 && this->tama != 0)
            return  *this;
        //Caso 3 Juntamos ambas listas
        //El puntero ultimo de la lista se junta con la vecera de la otra
        cola->sig=l.cabecera;
        //Asignamos como nueva cola la cola de lista ultima
        cola=l.cola;
        //Les sumamos el tamaño
        tama=tama+l.tama;

        //Devolvemos la concatenacion
        return  *this;


    }
    /**
     * @brief Metodo destructor
     * @tparam T
     */
    template<class T>
    ListaEnlazada<T>::~ListaEnlazada() {
        if(cabecera){
            //Creamos esto por que vamos a ir borrando de la cabecera a la cola
            Nodo<T> *aborrarElementos = cabecera;
            while(aborrarElementos != nullptr){
                cabecera = cabecera->sig;
                delete aborrarElementos;
                aborrarElementos = cabecera;
            }
            //Cuando acabe para curarnos en salud
            cola= nullptr;
        }



    }



#endif //PRACTICA2_LISTAENLAZADA_H
