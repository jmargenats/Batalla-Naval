/*
 * NodoX.h
 *
 *  Created on: Jun 2, 2022
 *      Author: juli
 */

#ifndef NODOX_H_
#define NODOX_H_
#include "Casillero.h"

class NodoX{
private:
	NodoX* anterior;
	NodoX* siguiente;
	Casillero* casillero;

public:
	/*
	 * pre: el casillero ingresado no debe estar vacio
	 * pos: se inicializa el casillero apuntando a cierto nodo
	 */
	NodoX(Casillero* casillero);

	/*
	 * pre: -
	 * pos: devuelve el puntero anterior
	 */
	NodoX* getAnterior();

	/*
	 * pre: -
	 * pos: devuevle el puntero que apunta al nodo siguiente
	 */
	NodoX* getSiguiente();

	/*
	 * pre: -
	 * pos: devuelve el puntero que apunta al casillero indicado
	 */
	Casillero* getCasillero();

	/*
	 * pre: -
	 * pos: cambia el lugar al que apunta el puntero anterior
	 */
	void setAnterior(NodoX* ptr);

	/*
	 * pre: -
	 * pos: cambia el lugar al que apunta el puntero siguiente
	 */
	void setSiguiente(NodoX* ptr);

	/*
	 * destructor
	 */
	virtual~NodoX();
};



#endif /* NODOX_H_ */
