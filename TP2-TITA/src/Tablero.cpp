/*
 * Tablero.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#include "Tablero.h"

Tablero :: Tablero(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo){
	if(xMaximo < 1 || zMaximo < 1 || yMaximo || 1){
		throw "Los valores ingresados no son validos";
	}
	this->casilleros = new Lista<Lista<Lista<Casillero *> *> *> (zMaximo, NULL);
	for(int z =1; z<=zMaximo;z++){
		this->casilleros->agregarFinal(new <Lista<Lista<Casillero *> *>(yMaximo, NULL));
		for(int y = 1; y<=yMaximo; y++){

		}
	}

}


