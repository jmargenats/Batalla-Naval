/*
 * NodoX.h
 *
 *  Created on: Jun 2, 2022
 *      Author: juli
 */

#ifndef NODO_H_
#define NODO_H_

template<class T>
class Nodo{
private:
	Nodo<T>* anterior;
	Nodo<T>* siguiente;
	T* puntero;

public:
	/*
	 * pre: el casillero ingresado no debe estar vacio
	 * pos: se inicializa el casillero apuntando a cierto nodo
	 */
	Nodo(T puntero){
		this->anterior = NULL;
		this->siguiente = NULL;
		this->puntero = puntero;
	}

	/*
	 * pre: -
	 * pos: devuelve el puntero anterior
	 */
	Nodo<T>* getAnterior(){
		return this->anteriorl;
	}

	/*
	 * pre: -
	 * pos: devuevle el puntero que apunta al nodo siguiente
	 */
	Nodo<T>* getSiguiente(){
		return this->siguiente;
	}

	/*
	 * pre: -
	 * pos: devuelve el puntero que apunta al casillero indicado
	 */
	T* getPuntero(){
		return this->puntero;
	}

	/*
	 * pre: -
	 * pos: cambia el lugar al que apunta el puntero anterior
	 */
	void setAnterior(Nodo* ptr){
		this->anterior=ptr;
	}

	/*
	 * pre: -
	 * pos: cambia el lugar al que apunta el puntero siguiente
	 */
	void setSiguiente(Nodo* ptr){
		this->siguiente=ptr;
	}

	/*
	 * destructor
	 */
	virtual~Nodo(){
		delete puntero;
	}
};



#endif /* NODOX_H_ */
