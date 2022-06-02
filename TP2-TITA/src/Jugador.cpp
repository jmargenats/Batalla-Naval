/*
 * Jugador.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#include "Jugador.h"

Jugador :: Jugador(unsigned int numero, std::string nombre){
	if (numero < 1){
		throw "El numero de jugador no es valido";
	}
	if(nombre == ""){
		throw "El nombre ingreasdo no es valido";
	}
	this->numeroDeJugador = numero;
	this->nombreDeJugador = nombre;
}
Jugador ::  ~Jugador(){

}
unsigned int Jugador :: getNumeroDeJugador(){
	return this->numeroDeJugador;
}

std::string Jugador :: getNombreDeJugador(){
	return this->nombreDeJugador;
}


