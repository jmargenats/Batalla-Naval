
#include <iostream>
#include<string>
#include "Ficha.h"
#include "carta.h"


Carta :: Carta(TipoDeCarta tipo, Tablero* tablero, Lista<Jugador*>* jugadores, Jugador * jugadorActual){
	this->tipo = tipo;
	this->tablero=tablero;

	this->jugadores = jugadores;
	this->jugadorActual = jugadorActual;

	switch (this->tipo)
	{ //los enums no pueden repetir nombre
	case AgregarAvion:
		unsigned int x, y , z;
		std::cout << "Inrese la fila" << std::endl;
		std::cin >> x;
		std::cout << "Inrese la columna" << std::endl;
		std::cin >> y;
		std::cout << "Inrese la altura" << std::endl;
		std::cin >> z;
		//Condición de que avión esté en el aire
		this->tablero->colocarFicha(x, y, z, Avion, jugadorActual, tablero, jugadores);
		break;
	case AgregarBarco:
		unsigned int x, y , z;
		std::cout << "Inrese la fila" << std::endl;
		std::cin >> x;
		std::cout << "Inrese la columna" << std::endl;
		std::cin >> y;
		std::cout << "Inrese la altura" << std::endl;
		std::cin >> z;
		//Condición de que avión esté en el aire
		this->tablero->colocarFicha(x, y, z, Barco, jugadorActual, tablero, jugadores);
		break;
	case Misil:
		this->ataqueMisil();
		break;
	case TeletransportarSoldado:
		this->teletransportarse();
		break;
	case SaltearElTurno:
		this->saltearTurno();
		break;
	}
};


void Carta::ataqueMisil(){
	//pide el lugar del ataque
	unsigned int x, y , z;
	std::cout << "Inrese la fila" << std::endl;
	std::cin >> x;
	std::cout << "Inrese la columna" << std::endl;
	std::cin >> y;
	std::cout << "Inrese la altura" << std::endl;
	std::cin >> z;
	//Creería que así está bien la implementación para el misil, no entendí bien la verdad
	if (this->tablero->getCasillero(x, y, z)->getFicha() == NULL){
		this->tablero->getCasillero(x, y, z)->setEstado(Inactivo);
		this->casillero->getVecino(x, y, z)->setEstado(Inactivo);
	} else { // Debería ser una función porque se repite varias veces, también hay que tener en cuenta que podría haber armamento (que se eliminaría)
		this->tablero->getCasillero(x, y, z)->getFicha()->getJugador()->restarSoldado();
		for(unsigned int i = 1; i <= this->jugadores->contarElementos(); i++){
			if(this->jugadores->obtener(i)->getNumeroDeSoldados() < 1){
				if(this->jugadores->obtener(i)->getNumeroDeJugador() == batallaCampal->getNumeroDeJUgadores()){
					this->jugadores->remover(i);
				}
			}
		}
	}
};

//que la carta sea para transportar un soldado
//arreglar lo que se pide
void Carta::teletransportarse(){
	int xAntiguo, yAntiguo, xNuevo, yNuevo;
	std::cout <<  "Elija un soldado para transportar, e ingrese sus coordenadas" << std::endl;
	this->jugadorActual->imprimirTableroPersonal();
	std::cout <<  "Ingrese la fila" << std::endl;
	std:: cin >> xAntiguo;
	std::cout <<  "Ingrese la columna" << std::endl;
	std::cin << yAntiguo;
	std::cout <<  "Ingrese la fila nueva" << std::endl;
	std:: cin >> xNuevo;
	std::cout <<  "Ingrese la columna nueva" << std::endl;
	std::cin << yNuevo;
	Ficha* ficha = NULL;
	this->tablero->getCasillero(xAntiguo, yAntiguo, 1)->setFicha(ficha);
	this->tablero->colocarFicha(xNuevo, yNuevo, 1, Soldado, this->jugadorActual, tablero, jugadores);
};

void Carta::saltearTurno(){
	this->jugadores->avanzarCursor();
};


void Carta::agregarSoldado(){
	unsigned int x, y;
	std::cout << "Inrese la fila" << std::endl;
	std::cin >> x;
	std::cout << "Inrese la columna" << std::endl;
	std::cin >> y;
	this->tablero->colocarFicha(x, y, 1, Soldado, this->jugadorActual, tablero, jugadores);
};
