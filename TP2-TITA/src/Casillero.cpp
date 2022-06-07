/*
 * Casillero.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#include "Casillero.h"

Casillero :: Casillero(unsigned int x, unsigned int y, unsigned int z, TipoDeCasillero tipo){
	if (x < 1 || y < 1 || z < 1){
		throw "Los datos ingresados no son correctos";
	}
	this->posicionEnX = x;
	this->posicionEnY = y;
	this->posicionEnZ = z;
	this->estado = Vacio;
	this->tipo = tipo;
	this->ficha = NULL;
}

Casillero :: ~Casillero(){
	delete ficha;
}

EstadoDeCasillero Casillero :: getEstado() const {
	return this->estado;
}

void Casillero :: setEstado(EstadoDeCasillero estado) {
	this ->estado = estado;
}

unsigned int Casillero :: getPosicionEnX() const {
	return this->posicionEnX;
}

unsigned int Casillero :: getPosicionEnY() const {
	return this->posicionEnY;
}

unsigned int Casillero :: getPosicionEnZ() const {
	return this->posicionEnZ;
}

TipoDeCasillero Casillero :: getTipo() const {
	return this->tipo;
}

Ficha*& Casillero :: getFicha() {
	return this->ficha;
}

void Casillero :: setFicha(Ficha*& ficha) {
	if (ficha == NULL){
		throw "La ficha no puede estar vacia";
	}
	this->ficha = ficha;
	this->estado = Ocupado;
}

void Casillero :: vaciar(){
	if (this->ficha == NULL){
		throw "El casillero ya esta vacio";
	}
	this->ficha = NULL;
	this->estado = Vacio;
}

Casillero* Casillero::getVecino(int x, int y, int z){
	return this->vecinos[x][y][z];
};

void Casillero::setVecino(Casillero* casillero, int x, int y, int z){
	this->vecinos[x + 1][y + 1][z + 1] = casillero;
};

