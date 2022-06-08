/*
 * Ficha.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */
#include "Ficha.h"

Ficha :: Ficha (TipoDeFicha tipo, Jugador *jugador){ //, unsigned int numero){
	if(jugador == NULL){
		throw "Este jugador no es valido";
	}
	this->jugador= jugador;
	this->tipo = tipo;
	//this->numero = numero;
}

Ficha :: ~Ficha(){
	delete jugador;
}

//unsigned int Ficha :: getNumero(){
//	return this->numero;
//}

Jugador*& Ficha :: getJugador() {
	return this-> jugador;
}

TipoDeFicha Ficha :: getTipo() const {
	return this-> tipo;
}


