/*
 * Jugador.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#include "Jugador.h"
#include "Tablero.h"
#include "Ficha.h"

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

void Jugador::atacar(Casillero* x, Casillero* y, Casillero* z, Ficha* tipoDeAtaque){
	if (x->getPosicionEnX() < 1 || y->getPosicionEnY() < 1 || z->getPosicionEnZ() < 1){
		throw "Los datos ingresados no son correctos";
	}

	//Chequear que donde se está atacando no haya una ficha de uno mismo
	//Faltaría ver cómo hacer que ataque 2 veces
	if(tipoDeAtaque->getTipo()==Soldado){
		for(int i = 0; i < 3; i++){
			(x)->setEstado(Inactivo);
			(y)->setEstado(Inactivo);
			(z)->setEstado(Inactivo);
		}
	}

	if(tipoDeAtaque->getTipo()==Misil){
		for(int i = 0; i < 3; i++){
			(x + i)->setEstado(Inactivo);
			(y + i)->setEstado(Inactivo);
			(z + i)->setEstado(Inactivo);
		}
	}

	if(tipoDeAtaque->getTipo()==Barco){
		if(z->getPosicionEnZ() == 1 && (x->getTipo() == Agua && y->getTipo() == Agua && z->getTipo() == Agua)){
			//Si se cumple esta condición debería atacar normalmente y con un misil
			for(int i = 0; i < 3; i++){
				(x + i)->setEstado(Inactivo);
				(y + i)->setEstado(Inactivo);
				(z + i)->setEstado(Inactivo);
			}
		}
	}

	if(tipoDeAtaque->getTipo()==Avion){
		if(z->getPosicionEnZ() == 1 && (x->getTipo() == Aire && y->getTipo() == Aire && z->getTipo() == Aire)){
			//Si se cumple esta condición debería atacar 2 veces
			x->setEstado(Inactivo);
			y->setEstado(Inactivo);
			z->setEstado(Inactivo);
		}
	}
};

bool Jugador::validarMovimiento(Casillero* x, Casillero* y, Casillero* z, Casillero* xNueva, Casillero* yNueva, Casillero* zNueva){
	int movimientoEnX = xNueva->getPosicionEnX() - x->getPosicionEnX();
    int movimientoEnY = yNueva->getPosicionEnX() - y->getPosicionEnX();
	int movimientoEnZ = zNueva->getPosicionEnX() - z->getPosicionEnX();
    if (movimientoEnX < 0) {movimientoEnX = movimientoEnX * (-1);}
    if (movimientoEnY < 0) {movimientoEnY = movimientoEnY * (-1);}
	if (movimientoEnZ < 0) {movimientoEnZ = movimientoEnZ * (-1);}

    return(movimientoEnX == 0 || movimientoEnY == 0 || movimientoEnZ == 0 ||
		   movimientoEnX == movimientoEnY || movimientoEnX == movimientoEnZ ||
		   movimientoEnY == movimientoEnZ);
};

void Jugador::moverSoldadoOArmamento(Casillero* x, Casillero* y, Casillero* z, Casillero* xNueva, Casillero* yNueva, Casillero* zNueva){
	if (x->getPosicionEnX() < 1 || y->getPosicionEnY() < 1 || z->getPosicionEnZ() < 1){
		throw "Los datos ingresados no son correctos";
	}

	if(!(validarMovimiento)){
		throw "Movimiento no valido";
	}

	if(x->getEstado() == Ocupado && y->getEstado() == Ocupado && z->getEstado() == Ocupado 
	   /*&& la ficha es igual a la del jugador actual*/
	   /*&& no hay una ficha del jugador actual en la nueva posicion*/){
		x->setEstado(Vacio);
		y->setEstado(Vacio);
		z->setEstado(Vacio);

		//Estos ocupados deberían indicar el tipo de ficha que hay 
		xNueva->setEstado(Ocupado);
		yNueva->setEstado(Ocupado);
		zNueva->setEstado(Ocupado);
	}
};

