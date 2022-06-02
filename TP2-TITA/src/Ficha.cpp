/*
 * Ficha.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */
#include "Ficha.h"

Ficha :: Ficha (TipoDeFicha tipo, Jugador *jugador){
	if(jugador == NULL){
		throw "Este jugador no es valido";
	}
	this->jugador= jugador;
	this->tipo = tipo;
}

Ficha :: ~Ficha(){
	delete jugador;
}
Jugador*& Ficha :: getJugador() {
	return this-> jugador;
}

TipoDeFicha Ficha :: getTipo() const {
	return this-> tipo;
}


