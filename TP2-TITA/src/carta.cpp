
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
		//Condición de que avión esté en el aire
		for(int i = 0; i < 2; i++){
			this->ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);
		}
		break;
	case AgregarBarco:
		//Condición de que barco esté en agua
		for(int i = 0; i < 2; i++){
			this->ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);
		}
		this->ataqueMisil();
		break;
	case Misil:
		this->ataqueMisil();
		break;
	case TeletransportarSoldado:
		this->Teletrasportarse();
		break;
	case SaltearElTurno:
		this->saltearTurno();
		break;
	}
};
// obtener(i)->getNumeroDeSoldados() < 1
void Carta::ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z){
	if (this->tablero->getCasillero(x, y, z)->getFicha() == NULL){
		this->tablero->getCasillero(x, y, z)->setEstado(Inactivo);
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
void Carta::teletrasportarse(unsigned int xAntiguo, unsigned int yAntiguo, unsigned int zAntiguo, unsigned int xNuevo, unsigned int yNuevo, unsigned int zNuevo){
	Ficha* ficha = NULL;
	this->tablero->getCasillero(xAntiguo, yAntiguo, zAntiguo)->setFicha(ficha);
	this->tablero->colocarFicha(xNuevo, yNuevo, zNuevo, Soldado, this->jugadorActual, tablero, jugadores);
};

void Carta::saltearTurno(){
	//avanzar el puntero de la lsita de jugadores un lugar
};

void Carta::agregarSoldado(){
	unsigned int x, y;
	std::cout << "Inrese la fila" << std::endl;
	std::cin >> x;
	std::cout << "Inrese la columna" << std::endl;
	std::cin >> y;
	this->tablero->colocarFicha(x, y, 1, Soldado, this->jugadorActual, tablero, jugadores);
};
