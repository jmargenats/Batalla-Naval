/*
 * NodoX.cpp
 *
 *  Created on: Jun 2, 2022
 *      Author: juli
 */
#include "NodoX.h"

NodoX :: NodoX(Casillero* casillero){
	this->anterior = NULL;
	this->siguiente = NULL;
	this->casillero = casillero;
}

NodoX* NodoX :: getAnterior(){
	return this->anterior;
}

NodoX* NodoX :: getSiguiente(){
	return this->siguiente;
}

Casillero* NodoX :: getCasillero(){
	return this->casillero;
}

void NodoX :: setAnterior(NodoX* ptr){
	this->anterior=ptr;
}

void NodoX :: setSiguiente(NodoX* ptr){
	this->siguiente=ptr;
}

NodoX :: ~NodoX(){
	delete casillero;
}




