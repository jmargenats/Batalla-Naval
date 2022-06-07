/*
 * Tablero.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#include <iostream>
#include "Tablero.h"

Tablero :: Tablero(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo){
	if(xMaximo < 1 || zMaximo < 1 || yMaximo < 1){
		throw "Los valores ingresados no son validos";
	}
	this->casilleros = new Lista<Lista<Lista<Casillero*>*>*>;
	this->xMaximo = xMaximo;
	this->yMaximo = yMaximo;
	this->zMaximo = zMaximo;
	//int contador = 0;

	//define que parte del suelo es tierra y cual es agua.
	unsigned int tierra;
	if(yMaximo%2==0){
		tierra = yMaximo/2;
	} else {
		tierra = (yMaximo + 1)/2;
	}

	//esta función debería estar con la de abajo (que agrega los casilleros)
	casilleros->iniciarCursor();
	while(casilleros->avanzarCursor()){
		Lista<Lista<Casillero*>*> *ejeZ = new Lista<Lista<Casillero*>*>;
		ejeZ->iniciarCursor();
		while(ejeZ->avanzarCursor()){
			Lista<Casillero*> *ejeY = new Lista<Casillero*>;
			ejeY->iniciarCursor();
			while(ejeY->avanzarCursor()){
				Casillero* casillero = ejeY->obtenerCursor();
				for(unsigned int i = -1; i <= 1; i++){
					for(unsigned int j = -1; j <= 1; j++){
						for(unsigned int k = -1; k <= 1; k++){
							if(i != 0 && j != 0 && k != 0){
								Casillero* casilleroVecino = getCasillero(casillero->getPosicionEnX() + i, casillero->getPosicionEnY() + j, casillero->getPosicionEnZ() + k);
								casilleroVecino->setVecino(casilleroVecino, i, j, k);
							}
						}
					}
				}
			}
		}
	}


	for(unsigned int z=1; z <= zMaximo; z++){
		Lista<Lista<Casillero*>*> *ejeZ = new Lista<Lista<Casillero*>*>;

		for(unsigned int y=1; y<= yMaximo; y++){

			Lista<Casillero*> *ejeY = new Lista<Casillero*>;

			for(unsigned int x=1; x<= xMaximo; x++){
				if(z==1){
					if(y <= tierra){
						Casillero* nuevoCasillero = new Casillero(x, y, z, Tierra);
						ejeY->agregar(nuevoCasillero);
					} else {
						Casillero* nuevoCasillero = new Casillero(x, y, z, Agua);
						ejeY->agregar(nuevoCasillero);
					}
				} else {
					Casillero* nuevoCasillero = new Casillero(x, y, z, Aire);
					ejeY->agregar(nuevoCasillero);
				}

				//contador++;
			}

			ejeZ->agregar(ejeY);
		}
		this->casilleros->agregar(ejeZ);
	}
	//std::cout << contador << std::endl;
}


Casillero* Tablero :: getCasillero(unsigned int x, unsigned int y, unsigned int z){
	if(!this->verificarValoresIngresados(x, y, z)){
		throw "Los valores ingresados no son validos";
	}
	return this->casilleros->obtener(z)->obtener(y)->obtener(x);
}


void Tablero :: setFicha(unsigned int x, unsigned int y, unsigned int z, Ficha* ficha){
	if(!this->verificarValoresIngresados(x, y, z)){
		throw "Los valores ingresados no son validos";
	}
	this->casilleros->obtener(z)->obtener(y)->obtener(x)->setFicha(ficha);
}

bool Tablero :: verificarValoresIngresados(unsigned int x, unsigned int y, unsigned int z){
	bool devolver = true;
	if(x < 1 || y < 1 || z < 1){
		devolver = false;
	}
	else if(x > this->xMaximo || y > this->yMaximo || z > this->zMaximo){
		devolver = false;
	}
	return devolver;
}


void Tablero :: imprimirMapa(){
	for(unsigned int z = 1; z <= this->zMaximo; z++){
		std :: cout << "Nivel numero" << z << std::endl;
		for(unsigned int y = 1; y <= this->yMaximo; y++){
			for(unsigned int x = 1; x <= this->xMaximo; x++){
				if (this->casilleros->obtener(z)->obtener(y)->obtener(x)->getEstado() == Vacio){
					std:: cout << "|" << "Vacio  "<<"|";
				} else if (this->casilleros->obtener(z)->obtener(y)->obtener(x)->getEstado() == Ocupado) {
					std:: cout << "|" << "Ocupado"<<"|";
				}else if (this->casilleros->obtener(z)->obtener(y)->obtener(x)->getEstado() == Inactivo){
					std:: cout << "|" << "Inactivo"<<"|";
					}
				}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
}

Tablero :: ~Tablero(){

	for(unsigned int z = 1; z<= this->zMaximo; z++){
		for(unsigned int y = 1; y <= this->yMaximo; y++){
			for(unsigned int x = 1 ; x <= this->xMaximo; x++){
				delete this->casilleros->obtener(z)->obtener(y)->obtener(x);
			}
			delete this->casilleros->obtener(z)->obtener(y);
		}
		delete this->casilleros->obtener(z);
	}
	delete this->casilleros;

}



