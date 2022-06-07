/*
 * BatallaCampal.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */
#include "BatallaCampal.h"

BatallaCampal :: BatallaCampal(unsigned int x, unsigned int y, unsigned int z, unsigned int numeroDeJugadores){
	if(x < 1 || y < 1 || z < 1 || numeroDeJugadores < 1){
		throw "Los valores ingresados no son validos";
	}
	this->xMaximo = x;
	this->yMaximo = y;
	this->zMaximo = z;
	this->numeroDeJugadores = numeroDeJugadores;
	this->jugadores = new Lista<Jugador*>;
	this->setJugadores();
	this->tablero = new Tablero(x , y, z);
}


unsigned int BatallaCampal :: getXMaximo(){
	return this->xMaximo;
}


unsigned int BatallaCampal :: getYMaximo(){
	return this->yMaximo;
}


unsigned int BatallaCampal :: getZMaximo(){
	return this->zMaximo;
}


unsigned int BatallaCampal :: getNumeroDeJUgadores(){
	return this->numeroDeJugadores;
}


void BatallaCampal :: setJugadores(){
	for(unsigned int i = 1; i <= this->getNumeroDeJUgadores(); i++){
		Jugador* jugadorNuevo = new Jugador(i);
		this->jugadores->agregar(jugadorNuevo);
	}
}

/*
 * pre: -
 * pos: devuelve true si la longitud de la lista de jugadores es mayor a 1
 */
bool BatallaCampal :: seguirJugando(){
	bool devolver = false;
	if(this->jugadores->contarElementos() > 1){
		devolver = true;
	}
	return devolver;
}

bool BatallaCampal :: validarNumeroDeJugador(unsigned int numero){
	bool devolver  = false;
	for (unsigned int i = 1; i <= this->jugadores->contarElementos(); i++){
		if (this->jugadores->obtener(i)->getNumeroDeJugador() == numero){
			devolver = true;
		}
	}
	return devolver;
}

void  BatallaCampal :: atacar (unsigned int x, unsigned int  y, unsigned int z, TipoDeFicha tipo, unsigned int numeroDeJugador){
	if (this->validarNumeroDeJugador(numeroDeJugador) == false){
		throw "el numero del jugador ingresado no es valido";
	}
	if(x < 1 || y < 1 || z < 1){
		throw "Los valores de las posiciones son muy chicos";
	}
	if(x > this->getXMaximo() || y > this->getYMaximo() || z > this->getZMaximo()){
		throw "Los numeros ingresados son muy chicos"; //muy grandes no será?
	}

	//en caso de soldado
	if (tipo == Soldado){
		if (this->tablero->getCasillero(x, y, z)->getFicha() == NULL){
			this->tablero->getCasillero(x, y, z)->setEstado(Inactivo);
		} else {
			this->tablero->getCasillero(x, y, z)->getFicha()->getJugador()->restarSoldado();
			for(unsigned int i = 1; i <= this->jugadores->contarElementos(); i++){
				if(this->jugadores->obtener(i)->getNumeroDeSoldados() < 1){
					if(this->jugadores->obtener(i)->getNumeroDeJugador() == numeroDeJugador){
						this->jugadores->remover(i);
					}
				}
			}
		}
	}
}


BatallaCampal ::~ BatallaCampal(){

}




