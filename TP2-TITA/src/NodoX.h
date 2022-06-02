/*
 * Nodo.h
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
	Casillero * casillero;
	NodoX* siguiente;

public:
	/*
	 * pre: casillero no debe estar vacio
	 * pos: inicializa el nodo con el puntero adecuado
	 */
	NodoX( Casillero *& casillero);

	/*
	 * 	int getInfo();
	Nodo* getSig();
	void setInfo(int i);
	void setSig(Nodo*);
	 */
	NodoX* getCasillero();

	NodoX* getAnterior();

	NodoX* getSiguiente();

	void setAnterior(NodoX*);

	void setSiguiente(NodoX*);
	/*
	 * pre: -
	 * pos: libera la memoria
	 */
	virtual ~NodoX(){

	}

};




#endif /* NODOX_H_ */
