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

	for(unsigned int Z=1; Z <= zMaximo; Z++){
		Lista<Lista<Casillero*>*> *ejeZ = new Lista<Lista<Casillero*>*>;

		for(unsigned int Y=1; Y<= yMaximo; Y++){

			Lista<Casillero*> *ejeY = new Lista<Casillero*>;

			for(unsigned int X=1; X<= xMaximo; X++){
				if(Z==1){
					if(Y <= tierra){
						Casillero* nuevoCasillero = new Casillero(X, Y, Z, Tierra);
						ejeY->agregar(nuevoCasillero);
					} else {
						Casillero* nuevoCasillero = new Casillero(X, Y, Z, Agua);
						ejeY->agregar(nuevoCasillero);
					}
				} else {
					Casillero* nuevoCasillero = new Casillero(X, Y, Z, Aire);
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
	return this->casilleros->obtener(z)->obtener(y)->obtener(x);
}

void Tablero :: setCasilla(unsigned int x, unsigned int y, unsigned int z, Casillero*){
	this->
}


/*
void Tablero::mostrarTablero() {

	Lista<Lista<Lista<Casillero*>*>*>* auxiliar1 = this->getCasillero();
	int numeroDePlano = 1;
	int numeroDeFila = 1;
	int limiteX = this->xMaximo;
	int limiteY = this->yMaximo;

	auxiliar1->iniciarCursor();
	while (auxiliar1->avanzarCursor()) {

		Lista<Lista<Casillero*>*>* auxiliar2 = auxiliar1->obtenerCursor();
		auxiliar2->iniciarCursor();
		std::cout << std::endl << "nivel " << numeroDePlano << std::endl;
		int y = 1;

		while (auxiliar2->avanzarCursor()){

			Lista<Casillero*>* auxiliar3 = auxiliar2->obtenerCursor();
			auxiliar3->iniciarCursor();
			int x = 1;

			while (auxiliar3->avanzarCursor()){

				Casillero* auxiliar4 = auxiliar3->obtenerCursor();


				std::cout << " " << auxiliar4->getTipo()<< " ";
				if (x != limiteX) {
					std::cout << "|";
				}
				x++;

			}
			std::cout << " " << numeroDeFila << std::endl;
			numeroDeFila++;
			if (y != limiteY) {
				for(int i = 1; i <= limiteX; i++) {
					std::cout << "---";
					if (i != limiteX) {
						std::cout << "|";
					}
				}
				std::cout << std::endl;
			}
			y++;

		}

		for(int i = 1; i <= limiteX; i++) {
			std::cout << " " << i << "  ";
		}
		numeroDeFila = 1;
		numeroDePlano++;
		std::cout<<std::endl;
	}

	std::cout << std::endl;
}
*/

Tablero :: ~Tablero(){
	for(int z = 1; z<= this->zMaximo; z++){
		for(y = 1; y <= this->yMaximo; y++){
			for( x = 1 <= this->xMaximo; x++){
				delete this->casilleros->
			}
		}
	}
}



